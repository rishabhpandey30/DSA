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
    ListNode* reversell(ListNode* curr){
        ListNode* front=curr->next;
        ListNode*prev=NULL;
        while(curr!=NULL){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // ListNode* temp= head;
        // stack<int>st;
        // while(temp!=NULL){
        //     st.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=NULL){
        //     if(temp->val!=st.top()){
        //         return false;
        //     }
        //     st.pop();
        //     temp=temp->next;
        // }
        // return true;
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=reversell(slow->next);
        ListNode* second=newhead;
        ListNode* first=head;
        while(second!=NULL){
            if(second->val != first->val){
                reversell(newhead);
                return false;
            }
            second=second->next;
            first=first->next;


        }
         reversell(newhead);
        return true;
    }
};