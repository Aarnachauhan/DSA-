leetcode
tx-o(n)
sc-O(1)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int sum=1;
        int i=1;
        while(i<n){
            //equal surface
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            //increasing slope
            while(i<n && ratings[i-1]<ratings[i]){
                peak+=1;
                sum+=peak;
                i++;
            }
            //decreasing slope
            int down=0;
            while(i < n && ratings[i-1] > ratings[i]){
                down+=1;
                sum+=down;
                i++;
            }
            down+=1;
            if(down>peak){
                sum+=(down-peak);
            }
        }
        return sum;
    }
};
