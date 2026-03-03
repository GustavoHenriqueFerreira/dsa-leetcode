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
        ListNode copia;
        copia.next = head;

        ListNode* slow = &copia;
        ListNode* fast = &copia;

        // avança fast n+1 passos
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // anda os dois juntos
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // remove o nó
        slow->next = slow->next->next;

        return copia.next;
    }
};