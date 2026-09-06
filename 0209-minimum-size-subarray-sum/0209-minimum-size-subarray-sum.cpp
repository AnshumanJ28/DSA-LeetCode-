class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = nums.size();
        int mins =INT_MAX;
        int cmin =0;
        int l = 0;
        for(int r = 0; r<s;r++){
            cmin += nums[r];
            while(cmin>=target){
                mins = min(mins, r - l + 1);
                cmin -= nums[l];
                l++;
            }

        }
        if(mins == INT_MAX){
            mins =0;
        }
    return mins;
    }
};