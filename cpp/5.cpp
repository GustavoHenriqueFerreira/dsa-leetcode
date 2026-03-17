class Solution {
public:
    string longestPalindrome(string s) {
        int comeco = 0;
        int fim = 0;

        for (int i = 0; i < s.size(); i++) {
            expansao(s, i, i, comeco, fim); // expandir pensando tamanho impar
            expansao(s, i, i+1, comeco, fim); // expandir pensando tamanho par
        }

        return s.substr(comeco, fim); // substr do palindromo
    }

    void expansao(string& s, int l, int r, int& comeco, int& fim) {
        while (l >= 0 && r < s.size() && s[l] == s[r]){ // nao sair da string e caracteres iguais para ser palindromo
            if (r - l + 1 > fim) { // se tamanho atual do palindromo for maior entao substituir
                comeco = l; // comeco vira l
                fim = r - l + 1; // fim vira o fim da janela atual
            }
            l--; // ir saindo do meio da string atual
            r++;
        }
    }
};