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
        // if(headA == NULL ||  headB ==NULL){
        //     return NULL;
        // }
        // ListNode* temp1= headA;
        // ListNode* temp2= headB;
        // map<ListNode* ,int> mp;
        // while(temp1!=NULL){
        //     mp[temp1]=1;
        //     temp1=temp1->next;
        // }
        // while(temp2!=NULL){
        //     if(mp.find(temp2)!=mp.end()){
        //         return temp2;
        //     }
        //     temp2=temp2->next;
        // }
        // return NULL;

// Method 2-> counting the node of both and then shift the smaller node and then starting the traversal of the both node at same
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int count1=0;
        while(temp1!=NULL){
            temp1=temp1->next;
            count1++;
        }
        int count2=0;
        while(temp2!=NULL){
            temp2=temp2->next;
            count2++;
        }
        temp1 = headA;
        temp2 = headB;
        if(count1<count2){
            int shift = count2-count1;
            while(shift){
                temp2=temp2->next;
                shift--;
            }
            while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
        }
        else{
            int shift = count1-count2;
            while(shift){
                temp1=temp1->next;
                shift--;
            }
            while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
        }
        return NULL;
    }
};