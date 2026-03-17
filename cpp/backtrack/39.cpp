class Solution {
public:
    void backtracking(vector<int>& candidates, int target, int comeco, vector<int>& atual, vector<vector<int>>& res){
        if (target == 0){
            res.push_back(atual);
            return;
        }

        for (int i = comeco; i < candidates.size(); i++) {
            if (candidates[i] > target) 
                continue; // se passou do target vai pro próximo

            atual.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i, atual, res); // simular com o mesmo número
            atual.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> atual;
        backtracking(candidates, target, 0, atual, res);

        return res;
    }
};