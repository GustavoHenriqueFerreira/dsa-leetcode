class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // saber distintos, apenas usar set pra isso
        set<int> unicos;
    
        for (int i = 0; i < nums.size(); i++) {
            if (unicos.count(nums[i]))
                return true;
            else
                unicos.insert(nums[i]);
        }

        return false;
    }
};