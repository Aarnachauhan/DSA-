

class MedianFinder {
public:
priority_queue<int>  lowerhalf ;//max heap
priority_queue<int, vector<int> , greater<int> > upperhalf; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lowerhalf.empty () || num<=lowerhalf.top()){
            lowerhalf.push(num);
        }else{
            upperhalf.push(num);
        }
        //balance
        if(lowerhalf.size() > upperhalf.size()+1){
         upperhalf.push(lowerhalf.top());
         lowerhalf.pop();
        }
        else if(upperhalf.size()> lowerhalf.size()){
            lowerhalf.push(upperhalf.top());
            upperhalf.pop();
        }
    }
    
    double findMedian() {
        if(lowerhalf.size() > upperhalf.size()){
            return lowerhalf.top();
        }
        else{
            return (lowerhalf.top() + upperhalf.top())/2.0;
        }
    }
};

