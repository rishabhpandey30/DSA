/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Method 1 -> hashing
        if(headA == NULL ||  headB ==NULL){
            return NULL;
        }
        ListNode* temp1= headA;
        ListNode* temp2= headB;
        map<ListNode* ,int> mp;
        while(temp1!=NULL){
            mp[temp1]=1;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            if(mp.find(temp2)!=mp.end()){
                return temp2;
            }
            temp2=temp2->next;
        }
        return NULL;
    }
};