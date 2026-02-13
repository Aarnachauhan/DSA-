from fastapi import FastAPI
from pydantic import BaseModel
from transformers import AutoModelForSequenceClassification, AutoTokenizer
from fastapi.middleware.cors import CORSMiddleware
import torch

# -------------------------------
# Initialize FastAPI app
# -------------------------------
app = FastAPI()

# Enable CORS (allow React frontend to connect)
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],  # Change to your frontend URL in production
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# -------------------------------
# Load Model & Tokenizer
# -------------------------------
model_path = "./cyberbullying_slm"

tokenizer = AutoTokenizer.from_pretrained(model_path)
model = AutoModelForSequenceClassification.from_pretrained(model_path)

# Try to automatically get labels from model config
if hasattr(model.config, "id2label") and model.config.id2label:
    label_map = model.config.id2label
else:
    # Fallback mapping (edit if needed)
    label_map = {
        0: "religion",
        1: "age",
        2: "gender",
        3: "ethnicity",
        4: "not bullying",
        5: "other cyber bullying"
    }

# Confidence threshold
CONFIDENCE_THRESHOLD = 0.6

# -------------------------------
# Request Schema
# -------------------------------
class TextInput(BaseModel):
    text: str

# -------------------------------
# Health Check Route
# -------------------------------
@app.get("/")
def home():
    return {"status": "ML server is running"}

# -------------------------------
# Prediction Endpoint
# -------------------------------
@app.post("/predict")
def predict(input: TextInput):
    # Tokenize input text
    inputs = tokenizer(
        input.text,
        return_tensors="pt",
        truncation=True,
        padding=True
    )

    # Run model inference
    with torch.no_grad():
        outputs = model(**inputs)
        probs = torch.nn.functional.softmax(outputs.logits, dim=1)
        prediction_index = torch.argmax(probs).item()
        confidence = torch.max(probs).item()

    # Get label name
    category = label_map[prediction_index]

    # Apply confidence threshold
    if confidence < CONFIDENCE_THRESHOLD:
        category = "uncertain"

    # Determine if bullying
    is_bullying = category != "not bullying" and category != "uncertain"

    # Return structured response
    return {
        "category": category,
        "confidence": round(float(confidence), 3),
        "is_bullying": is_bullying
    }
