class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long curr = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            curr +=  i * nums[i];
        }

        long long ans = curr;

        for(int i = n - 1; i >= 1; i--) {
            curr = curr + sum -  n * nums[i];
            ans = max(ans, curr);
        }

        return ans;
    }
};