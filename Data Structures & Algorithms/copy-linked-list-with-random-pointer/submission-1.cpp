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
        if(!head) return nullptr;
        Node* curr = head;
        while(curr){
            Node* temp = curr->next;    // storing original node - B
            curr->next = new Node(curr->val);  // A->x
            curr->next->next = temp;          // A->x->B
            curr = temp;     // curr = B
        }

        curr = head;
        while(curr && curr->next){
            if(curr->random == nullptr){
                curr->next->random = nullptr;
            }
            else{
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;
        while(curr && newCurr){
            curr->next = (curr->next != nullptr) ? curr->next->next : nullptr;
            newCurr->next = (newCurr->next != nullptr) ? newCurr->next->next : nullptr;

            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};
