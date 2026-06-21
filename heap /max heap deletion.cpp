
void heapify(vector<int>& heap, int idx){

    int largest = idx;

    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if(left < heap.size() &&
       heap[left] > heap[largest])
        largest = left;

    if(right < heap.size() &&
       heap[right] > heap[largest])
        largest = right;

    if(largest != idx){

        swap(heap[idx], heap[largest]);

        heapify(heap, largest);
    }
}

int extractMax(vector<int>& heap){

    if(heap.empty())
        return -1;

    int ans = heap[0];

    heap[0] = heap.back();

    heap.pop_back();

    if(!heap.empty())
        heapify(heap,0);

    return ans;
}
