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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

ListNode* merge(ListNode* list1, ListNode* list2) {
        // Create a dummy node
        ListNode* dummyNode = new ListNode(-1);
        
        // Temp pointer to build merged list
        ListNode* temp = dummyNode;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            // Choose smaller node
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move temp pointer
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode->next;
    }
ListNode* findmid(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return  head;
    }
     ListNode* slow = head;
        ListNode* fast = head->next;


        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
}


    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* middle=findmid(head);

        ListNode* right=middle->next;
        middle->next=nullptr;
        ListNode* left=head;

        left=sortList(left);
        right=sortList(right);

        return merge(left,right);
    }
};
