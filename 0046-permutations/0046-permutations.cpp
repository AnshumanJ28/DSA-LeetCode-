class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        int fact = factorial(n);

        for (int k = 0; k < fact; k++) {
            vector<int> temp = nums;     
            vector<int> perm;
            int num = k;

            for (int i = n; i >= 1; i--) {
                int f = factorial(i - 1);
                int index = num / f;

                perm.push_back(temp[index]);
                temp.erase(temp.begin() + index);

                num = num % f;
            }

            result.push_back(perm);
        }

        return result;
    }

private:
    int factorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
};