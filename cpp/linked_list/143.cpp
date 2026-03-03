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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        // encontrar meio da lista, lento estara no meio da lista quando rapido acaba
        ListNode* lento = head;
        ListNode* rapido = head;
        while (rapido->next != nullptr && rapido->next->next != nullptr) {
            lento = lento->next;
            rapido = rapido->next->next;
        }

        // pegar a metade final da lista
        ListNode* segundaLista = lento->next;
        lento->next = nullptr;

        // reverte segunda metade da lista
        ListNode* prev = nullptr;
        ListNode* atual = segundaLista;

        while (atual != nullptr){
            ListNode* temp = atual->next;
            atual->next = prev;
            prev = atual;
            atual = temp; 
        }

        segundaLista = prev;
        ListNode* primeiraLista = head;
        while (segundaLista != nullptr) {
            ListNode* temp1 = primeiraLista->next;
            ListNode* temp2 = segundaLista->next;

            primeiraLista->next = segundaLista;
            segundaLista->next = temp1;

            primeiraLista = temp1;
            segundaLista = temp2;
        }
    }
};