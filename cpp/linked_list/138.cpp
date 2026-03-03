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
        // caso base
        if (head == nullptr)
            return nullptr;

        // nó original e nó copiado
        unordered_map<Node*, Node*> mapa;

        // criar todos os nós
        Node* atual = head;
        while (atual != nullptr) {
            Node* copia = new Node(atual->val);
            mapa[atual] = copia;
            atual = atual->next;
        }

        // ligar next e random
        atual = head;
        while (atual != nullptr) {
            Node* novoNo = mapa[atual];

            // trata o next
            if (atual->next != nullptr) {
                Node* proximoOriginal = atual->next;
                Node* proximoCopia = mapa[proximoOriginal];
                novoNo->next = proximoCopia;
            } else
                novoNo->next = nullptr;

            // trata o random
            if (atual->random != nullptr) {
                Node* randomOriginal = atual->random;
                Node* randomCopia = mapa[randomOriginal];
                novoNo->random = randomCopia;
            } else
                novoNo->random = nullptr;

            atual = atual->next;
        }

        // head da lista copiada
        return mapa[head];
    }
};