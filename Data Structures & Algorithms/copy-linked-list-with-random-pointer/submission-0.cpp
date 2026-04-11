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
        unordered_map<Node*, Node*> mp;
        if(head == NULL) return NULL;
        Node* curr = head;
        Node* newHead = nullptr;
        Node* prev = nullptr;
        while(curr){
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            if(newHead == nullptr){
                newHead = temp;
                prev = newHead;
            }
            else{
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }
        curr = head;
        Node* newCurr = newHead;
        while(curr){
            if(curr->random == nullptr){
                newCurr->random = nullptr;
            }
            else{
                newCurr->random = mp[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};
