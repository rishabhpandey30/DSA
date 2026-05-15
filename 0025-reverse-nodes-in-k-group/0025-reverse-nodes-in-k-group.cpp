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
    ListNode* reverse(ListNode* temp){
        ListNode* prev =NULL;
        ListNode* front = NULL;
        ListNode* temp1 = temp;
        while(temp1!=NULL){
            front = temp1->next;
            temp1->next = prev;
            prev = temp1;
            temp1 = front;
        }
        return prev;
    }
    ListNode* KthNode(ListNode* temp, int k){
        int kk = k-1;
        while(temp!=NULL && kk>0){
            temp = temp->next;
            kk--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        while(temp!=NULL){
            ListNode* KNode = KthNode(temp,k);
            if(KNode==NULL){
                if(prev) prev->next = temp;
                break;
            }
            nextNode = KNode->next;
            KNode->next = NULL;
            reverse(temp);
            if(temp==head){
                head = KNode;
            }
            else{
                prev->next = KNode;
            }
            prev = temp;
            temp = nextNode;

        }
        return head;
    }
};