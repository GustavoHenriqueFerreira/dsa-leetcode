class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mapa;
        
        for (int i = 0; i < nums.size(); i++) {
            if (mapa.count(nums[i]))
                if (abs(i - mapa[nums[i]]) <= k)
                    return true;

            mapa[nums[i]] = i;
        }

        return false;
    }
};

/* class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            if (window.contains(nums[i]))
                return true;

            window.insert(nums[i]);

            if (window.size() > k)
                window.erase(nums[i-k]);
        }

        return false;
    }
}; */