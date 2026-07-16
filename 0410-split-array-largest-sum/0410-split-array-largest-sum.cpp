class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int count = 1;
        long long currSum = 0;

        for (int num : nums) {
            if (currSum + num <= maxSum) {
                currSum += num;
            } else {
                count++;
                currSum = num;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = 0;
        long long high = 0;

        for (int num : nums) {
            low = max(low, (long long)num);
            high += num;
        }

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};