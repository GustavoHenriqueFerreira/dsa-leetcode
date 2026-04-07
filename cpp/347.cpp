class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> map;
        for (auto element : nums)
            map[element]++;

        vector<vector<int>> bucket (nums.size() + 1);
        for (auto element : map)
            bucket[element.second].push_back(element.first);

        vector<int> frequentElements;
        for (int i = bucket.size() - 1; i > 0; i--) {
            for (int j = 0; j < bucket[i].size(); j++) {
                int element = bucket[i][j];
                frequentElements.push_back(element);
                if (frequentElements.size() == k)
                    return frequentElements;
            }
        }
    
        return frequentElements;
    }
};

/* class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequencyOfNums;

        for (int i = 0; i < nums.size(); i++)
            frequencyOfNums[nums[i]]++;

        vector<pair<int,int>> topElement;
        for (auto freq : frequencyOfNums) 
            topElement.push_back({freq.second, freq.first}); // freq first

        sort(topElement.rbegin(), topElement.rend());

        vector<int> res (k);
        for (int i = 0; i < k; i++) 
            res[i] = topElement[i].second; // return number

        return res;
    }
}; */