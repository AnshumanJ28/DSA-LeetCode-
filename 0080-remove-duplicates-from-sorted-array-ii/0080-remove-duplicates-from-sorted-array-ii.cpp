class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int left = 0;
        int right = 1;
        int count = 1;

        while (right < nums.size()) {
            if (nums[left] == nums[right]) {
                count++;

                if (count > 2) {
                    nums.erase(nums.begin() + right);
                } else {
                    left++;
                    right++;
                }
            } else {
                count = 1;
                left = right;
                right++;
            }
        }

        return nums.size();
    }
};