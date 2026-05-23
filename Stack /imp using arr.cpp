https://www.naukri.com/code360/problems/stack-implementation-using-array_3210209


class Stack {

    

public:
    int Top = -1;
   int Max = 0;
 vector<int> st;

    

    Stack(int capacity) {

        Max = capacity;

        st.reserve(capacity);

    }

 

    void push(int num) {

        if(Top < Max - 1){

            Top++;

            st.push_back(num);

        }

    }

 

    int pop() {

        if(Top == -1){

            return -1;

        }

        else{

            int n = st[Top];

            Top--;

            st.pop_back();

            return n;

        } 

        

    }

    

    int top() {

        if(Top < 0){

            return -1;

        }

        else return st[Top];

    }

    

    int isEmpty() {

        if(Top == -1){

            return 1;

        }else{

            return 0;

        }

    }

    

    int isFull() {

        if(Top == Max - 1)return 1;

        else return 0;

    }

    

};

 
