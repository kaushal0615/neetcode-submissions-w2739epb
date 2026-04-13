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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==0 || head == nullptr) return head;
        ListNode* curr = head;
        int count = 0;
        while(curr && count<k){
            curr = curr->next;
            count++;
        }
        if(count<k) return head;
        ListNode* newCurr = head;
        ListNode* prev = nullptr;
        int cnt=k;
        while(cnt>0 && newCurr){
            ListNode* temp = newCurr->next;
            newCurr->next = prev;
            prev = newCurr;
            newCurr = temp;
            cnt--;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
