class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> freq;
        int left = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;

            while (freq[s[i]] > 1) {
                freq[s[left]]--;
                left++;
            }

            res = max(res, i - left + 1);
        }

        return res;
    }
};

/* class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> maiorString;
        int l = 0;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            while (maiorString.find(s[i]) != maiorString.end()) {
                maiorString.erase(s[l]);
                l++;
            }

            maiorString.insert(s[i]);
            res = max(res, i - l + 1); // janela atual
        }

        return res;
    }
}; */