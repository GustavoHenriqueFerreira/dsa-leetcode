class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // max heap só precisa do <int>

        for (int i = 0; i < stones.size(); i++)
            pq.push(stones[i]); // adiciona pedra no heap

        while (pq.size() > 1) {
            int x = pq.top(); // pega o maior do heap
            pq.pop(); // remove o maior do priority_queue

            int y = pq.top(); // pega o segundo maior do heap (agora ele virou o maior)
            pq.pop(); // remove ele

            if (x != y) // compara se eles não são iguais, se forem já estão excluidos do heap
                pq.push(x - y); // adiciona x-y por que y nunca será maior que x
        }

        return pq.empty() ? 0 : pq.top(); // se heap vazio retorna 0, senão o topo
    }
};