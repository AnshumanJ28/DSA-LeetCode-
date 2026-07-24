class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> pairXor(MAXX, false);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        vector<bool> ans(MAXX, false);

        for (int x = 0; x < MAXX; x++) {
            if (!pairXor[x]) continue;
            for (int v : nums) {
                ans[x ^ v] = true;
            }
        }

        int res = 0;
        for (bool ok : ans)
            if (ok) res++;

        return res;
    }
};