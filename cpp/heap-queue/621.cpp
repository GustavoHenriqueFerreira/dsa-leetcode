class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size(); // nao precisa intercalar

        vector<int> freq (26);

        for (int i = 0; i < tasks.size(); i++)
            freq[tasks[i] - 'A']++; // freq das tasks

        int maxFreq = *max_element(freq.begin(), freq.end()); // maior freq
        int countMaxs = 0;
        for (int i = 0; i < freq.size(); i++)
            if (maxFreq == freq[i])
                countMaxs++; // quantidade de maiores

        int blocos = maxFreq - 1; // quantia de bloco ex: A__ A__ A__ A 4-1
        int tamanhoBloco = n + 1; // letra mais n

        int tempoMinimo = blocos * tamanhoBloco + countMaxs; // contar maxs tambem
        return max(tempoMinimo, (int)tasks.size());
    }
};