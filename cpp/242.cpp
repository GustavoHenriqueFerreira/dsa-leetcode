class Solution {
public:
    bool isAnagram(string s, string t) {
        // apenas saber frequencias, usar vetor simples pra conta
        if (s.size() != t.size())
            return false;

        vector<int> freqS (26), freqT (26);
        for (int i = 0; i < s.size(); i++) {
            freqS[s[i] - 'a']++;
            freqT[t[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); i++)
            if (freqS[i] != freqT[i])
                return false;

        return true;
    }
};