class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        for (int i = 0; i < nums1.size(); i++) {
            int numberToFind = nums1[i];

            bool find = false;
            int numToRes = -1;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == numberToFind) 
                    find = true;

                if (find && numberToFind < nums2[j]) {
                    numToRes = nums2[j];
                    break;
                }
            }

            res.push_back(numToRes);
        }

        return res;
    }
};