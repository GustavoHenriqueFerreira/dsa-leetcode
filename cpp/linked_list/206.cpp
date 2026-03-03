class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* prox = curr->next;
            curr->next = prev; // usar next pra o antigo
            prev = curr; // andar pra frente as variaveis temporaria
            curr = prox;
        } 

        return prev;
    }
};