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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* first = temp;
        while(n>0){
            first = first->next;
            n--;
        }
        ListNode* second = temp;
        while(first->next != nullptr){
            second = second->next;
            first = first->next;
        }
        second->next = second->next->next;
        return temp->next;
    }
};
