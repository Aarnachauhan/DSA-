lc 148
naive solution

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        sort(arr.begin(),arr.end());
        temp=head;
        int i=0;
        while(temp!=nullptr && i<arr.size()){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};

optimal:


