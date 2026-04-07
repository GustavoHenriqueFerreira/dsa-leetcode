class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> frequency;

        int res = 0, left = 0, maxFreqWindow = 0;
        for (int i = 0; i < s.size(); i++) {
            frequency[s[i]]++;
            maxFreqWindow = max(maxFreqWindow, frequency[s[i]]);
            int sizeWindow = i - left + 1;
            int changesNeed = sizeWindow - maxFreqWindow;

            while (changesNeed > k) {
                frequency[s[left]]--;
                left++;
                changesNeed--;
            }

            res = max(res, i - left + 1);
        }

        return res;
    }
};