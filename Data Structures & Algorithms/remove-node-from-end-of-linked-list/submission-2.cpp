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
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* first = head;
        for(int i=1; i<=n; i++){
            first = first->next;
        }
        if(first == NULL) return head->next;
        ListNode* second = head;
        while(first->next != nullptr){
            second = second->next;
            first = first->next;
        }
        second->next = second->next->next;
        return head;
    }
};
