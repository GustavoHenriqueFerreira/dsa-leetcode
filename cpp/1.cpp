class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // usar completo do numero atual pra chega no target e ver se tem no map
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++){
            int complemento = target - nums[i];

            if (mp.count(complemento))
                return {mp[complemento], i};

            mp[nums[i]] = i;
        }
    
        return {};
    }
};