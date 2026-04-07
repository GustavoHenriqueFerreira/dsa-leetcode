class Solution {
public:
    bool canJump(vector<int>& nums) {
        int posAtual = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > posAtual)
                return false;
                
            posAtual = max(posAtual, i + nums[i]);
        }

        return true;
    }
};