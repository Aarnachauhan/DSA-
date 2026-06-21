no platform


vector<int> nearlySorted(vector<int>& arr, int k) {

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;

    vector<int> ans;

    for(int x : arr) {

        pq.push(x);

        if(pq.size() > k) {

            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while(!pq.empty()) {

        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}
