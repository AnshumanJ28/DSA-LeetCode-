class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> merged(m + n);

        for (int i = 0; i < m; i++) {
            merged[i] = nums1[i];
        }

        for (int i = m; i < m + n; i++) {
            merged[i] = nums2[i - m];
        }

        sort(merged.begin(), merged.end());

        int size = merged.size();

        if (size % 2 == 1) {
            return merged[size / 2];
        }

        return (merged[size / 2] + merged[size / 2 - 1]) / 2.0;
    }
};