class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        vector<int> freq1 (26,0), freq2(26,0);

        for (int i = 0; i < s1.size(); i++)
            freq1[s1[i] - 'a']++; // contagem do ASCII

        int tamanhoJanela = s1.size();
        for (int i = 0; i < s2.size(); i++) {
            int caracterAtual = s2[i] - 'a';
            freq2[caracterAtual]++;

            if (i >= tamanhoJanela) {
                char caracterRetirado = s2[i - tamanhoJanela];
                freq2[caracterRetirado - 'a']--;
            }

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};