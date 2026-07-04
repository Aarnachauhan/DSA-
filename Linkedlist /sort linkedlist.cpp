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
tc-o(nlogn)
sc-O(nlogn)

class Solution {
public:
ListNode* merge(ListNode* left , ListNode* right){
    if(left==nullptr) return right;
    if(right==nullptr) return left;
    ListNode *dummy=new ListNode(0);
    ListNode *temp=dummy;
    while(left!=nullptr && right!=nullptr){
     if(left->val < right->val){
        temp->next=left;
        temp=left;
        left=left->next;
     }
     else{
        temp->next=right;
        temp=right;
        right=right->next;
     }
    }

    while(left!=nullptr){
        temp->next=left;
        temp=left;
        left=left->next;
    }

    while(right!=nullptr){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    dummy=dummy->next;
    return dummy;
}
ListNode* getmiddle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;

    while(fast && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next ==nullptr) return head;

        ListNode* mid=getmiddle(head);

        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=nullptr;

        left=sortList(left);
        right=sortList(right);

        ListNode* result=merge(left,right);

        return result;
    }
};
