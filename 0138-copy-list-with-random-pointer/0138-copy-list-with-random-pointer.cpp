/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Method 1 -- using hash map T.C - O(2n), S.C-O(n)
    //     map<Node*, Node*> mpp;
    //     Node* temp = head;
    //     while(temp!=NULL){
    //         Node* newNode = new Node(temp->val);
    //         mpp[temp] = newNode;
    //         temp = temp->next;
    //     }
    // temp = head;
    //     while(temp!=NULL){
    //         Node* copy = mpp[temp];
    //         copy->next = mpp[temp->next];
    //         copy->random = mpp[temp->random];
    //         temp= temp->next;
    //     }
    //     return mpp[head];

    //Method 2 -- inseting in between the nodes
        Node* temp =head;
        while(temp!=NULL){
           Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp =temp->next->next;
        }
        temp =head;
        while(temp!=NULL){
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while(temp!=NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp =temp->next;

        }
        return dummy->next;
    }
};