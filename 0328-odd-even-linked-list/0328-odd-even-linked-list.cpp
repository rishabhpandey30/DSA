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
    ListNode* oddEvenList(ListNode* head) {
        // vector<int>v;
        // ListNode* temp=head;
        // if(head==NULL || head->next==NULL){
        //     return head;
        // }
        // while( temp!=NULL && temp->next!=NULL){
        //     v.push_back(temp->val);
        //     temp=temp->next->next;
        // }
        // if(temp!=NULL){
        //     v.push_back(temp->val);
        // }
        // temp=head->next;
        // while(temp!=NULL && temp->next !=NULL){
        //     v.push_back(temp->val);
        //     temp=temp->next->next;
        // }
        // if(temp!=NULL){
        //     v.push_back(temp->val);
        // }
        // temp=head;
        // for(int i=0;i<v.size();i++){
        //     temp->val=v[i];
        //     temp=temp->next;
        // }
        // return head;

        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenH=even;
        while(even!=NULL && even->next !=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd = odd->next;
            even =even->next;
        }
        odd->next=evenH;
        return head;
    }
};