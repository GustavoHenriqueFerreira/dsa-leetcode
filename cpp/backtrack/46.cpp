class Solution {
public:
    void backtracking(vector<int>& nums, vector<int>& atual, vector<vector<int>>& res, vector<bool>& usados) {
        if(atual.size() == nums.size()) {
            res.push_back(atual);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (usados[i] == true)
                continue;
            
            usados[i] = true;
            atual.push_back(nums[i]);

            backtracking(nums, atual, res, usados);

            atual.pop_back();
            usados[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> atual;
        vector<bool> usados (nums.size(), false);
        backtracking(nums, atual, res, usados);

        return res;
    }
};