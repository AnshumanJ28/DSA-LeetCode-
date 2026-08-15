class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
        }

        if (xr != 0) {
            return n;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                return n - 1;
            }
        }

        return 0;
    }
};