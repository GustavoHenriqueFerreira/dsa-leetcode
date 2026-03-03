class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // menor array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int l = 0, r = m;

        // quantos elementos devem ficar do lado esquerdo
        int metade = (m + n + 1) / 2;

        while (l <= r) {
            int i = l + (r - l) / 2; // corte em nums1
            int j = metade - i; // corte em nums2

            // valores das bordas (com proteção de limites)
            int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];

            int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];

            // se a partição é válida
            if (left1 <= right2 && left2 <= right1) {

                // total ímpar
                if ((m + n) % 2 != 0)
                    return max(left1, left2);

                // total par
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            // busca binária
            else if (left1 > right2)
                r = i - 1; // longe demais
            else
                l = i + 1; // foi pouco
        }

        return 0.0;
    }
};