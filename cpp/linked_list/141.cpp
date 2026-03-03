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
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;

        ListNode* lento = head;
        ListNode* rapido = head;

        while (rapido != nullptr && rapido->next != nullptr) {
            lento = lento->next;
            rapido = rapido->next->next;

            if (rapido == lento)
                return true;
        }

        return false;
    }
};