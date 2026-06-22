lc 23
Time Complexity
Let:
k = number of lists
N = total number of nodes across all lists

Each node:
inserted into heap once , removed from heap once ,Heap size never exceeds k.
Therefore:TC = O(N log k)
Space Complexity : Heap stores at most one node from each list.
SC = O(k)

  
class Solution {
public:
struct cmp{
    bool operator()(ListNode* a , ListNode* b){
        return a->val> b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , cmp> pq;

        for(auto node: lists){
           if(node) pq.push(node);
        }

        ListNode* dummy= new ListNode(-1);
        ListNode* tail=dummy;

        while(!pq.empty()){
            ListNode* curr=pq.top();
            pq.pop();

            tail->next=curr;
            tail=tail->next;

            if(curr->next){
                pq.push(curr->next);
            }
        }
       return dummy->next;
    }
};
