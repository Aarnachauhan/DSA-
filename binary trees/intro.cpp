gfg
tc- O(1)
  sc-o(1)

note: root node  level is always 1.
  
class Solution {
  public:
    int countNodes(int i) {
        // your code here
        return pow(2,i-1);
    }
