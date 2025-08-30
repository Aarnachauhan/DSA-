
approach 1:
tc-o()
sc-o(123)
 class Solution {
public:
   typedef pair<char, int> P;
    string frequencySort(string s) {
        vector<P> vec(123);

        for (char &ch : s){
            int freq=vec[ch].second;
            vec[ch]={ch , freq+1};
        }
        auto lambda=[&](P &p1 , P &p2){
            return p1.second > p2.second;
        };
        sort(begin(vec), end(vec), lambda);

        string result="";
        for(int i=0;i<=122;i++){
            if(vec[i].second>0){
                char ch=vec[i].first;
                int freq=vec[i].second;
                string temp= string(freq,ch);
                result+=temp;
            }
        }
        return result;
    }
};

approach 2 : priority queue and map
tc-
sc-

class Solution {
public:
    typedef pair<char, int> P;
    struct lambda{
        bool operator()(P &p1 , P &p2){
               return p1.second < p2.second ; //heap to store max freq element at the top
        }
    };

    string frequencySort(string s) {
        priority_queue <P , vector<P>, lambda> pq;

        unordered_map<char , int> mpp;

        for(char &ch:s){
            mpp[ch]++;
        }

        for(auto &it : mpp){
            pq.push({it.first , it.second});
        }
         string result="";
         while(!pq.empty()){
            P temp = pq.top();
            pq.pop();

            result +=string(temp.second , temp.first);
         }
        return result;
    }
};
