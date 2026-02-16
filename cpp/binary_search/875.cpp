class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int esquerda = 1;
        int direita = *max_element(piles.begin(), piles.end());

        while (esquerda < direita) {
            int meio = esquerda + (direita - esquerda) / 2;
            long long horas = 0;

            for (int i = 0; i < piles.size(); i++)
                horas += (piles[i] + meio - 1) / meio; // arredonda pra cima

            if (h >= horas)
                direita = meio; // da pra comer mais lento
            else
                esquerda = meio + 1; // da pra comer mais rapido
        }

        return esquerda;
    }
};