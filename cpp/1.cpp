class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp; // {numero, indice no array}

        for (int i = 0; i < nums.size(); i++) {
            int complemento = target - nums[i]; // pega complemento

            if (mp.count(complemento)) // ver se complemento está no map
                return {mp[complemento], i}; // se estiver retornar indice atual e do complemento

            mp[nums[i]] = i; // senao guardar indice do numero atual
        }

        return {}; // retornar vazio se não tiver nada
    }
};