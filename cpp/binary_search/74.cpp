class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int esquerda = 0;
        int direita = m * n - 1;

        while (direita >= esquerda) {
            int meio = esquerda + (direita - esquerda) / 2;

            int linha = meio / n;
            int coluna = meio % n;

            int valor = matrix[linha][coluna];

            if (valor == target) 
                return true;
            if (valor < target)
                esquerda = meio + 1;
            else
                direita = meio - 1;
        }

        return false;
    }
};