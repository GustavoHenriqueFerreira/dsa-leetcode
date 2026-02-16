class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) 
                continue;

            int esquerda = i + 1;
            int direita = nums.size() - 1;

            while (esquerda < direita) {
                int soma = nums[i] + nums[esquerda] + nums[direita];

                if (soma == 0) {
                    res.push_back({nums[i], nums[esquerda], nums[direita]});

                    while (esquerda < direita && nums[esquerda] == nums[esquerda+1]) 
                        esquerda++;
                    while (esquerda < direita && nums[direita] == nums[direita-1]) 
                        direita--;

                    esquerda++;
                    direita--;
                }
                else if (soma < 0)
                    esquerda++;
                else
                    direita--;
            }
        }

        return res;
    }
};