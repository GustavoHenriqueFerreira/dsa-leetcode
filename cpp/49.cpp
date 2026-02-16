class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // criar map com chave sendo a palavra ordenada e juntar as palavras assim (palavra ordenada vale pra anagrama)
        map<string, vector<string>> mp;

        for (string s : strs) {
            string copia = s;
            sort(copia.begin(), copia.end());
            // nao reclama se não estiver no map
            mp[copia].push_back(s);
        }

        vector<vector<string>> strings;
        for (auto ele : mp)
            strings.push_back(ele.second);

        return strings;
    }
};