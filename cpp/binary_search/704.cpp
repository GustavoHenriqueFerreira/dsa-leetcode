class Solution {
public:
    int search(vector<int>& nums, int target) {
        int esquerda = 0;
        int direita = nums.size() - 1;
        
        while (esquerda <= direita) {
            int meio = esquerda + (direita - esquerda) / 2;
            
            if (nums[meio] == target)
                return meio;
            else if (nums[meio] < target)
                esquerda = meio + 1;
            else
                direita = meio - 1;
        }
        
        return -1;
    }
};