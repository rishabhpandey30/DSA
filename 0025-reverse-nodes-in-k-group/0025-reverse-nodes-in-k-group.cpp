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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(curr!=NULL){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    ListNode* kthNode(ListNode* temp, int k){
        k=k-1;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp= head;
        ListNode* prevNode= NULL;
        while(temp!=NULL){
        ListNode* kNode = kthNode(temp,k);
        if(kNode==NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }
       ListNode* nextNode =kNode->next;
       kNode->next = NULL;
       reverse(temp);
       if(temp == head){
        head= kNode;
       }
       else{
          prevNode->next = kNode;
       }
       prevNode = temp;
        temp = nextNode;
    }
    return head;
    }
};