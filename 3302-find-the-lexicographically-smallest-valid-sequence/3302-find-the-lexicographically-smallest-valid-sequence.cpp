class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        int j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> ans;
        int skip = 0;
        j = 0;

        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (skip == 0 && (j == m - 1 || i < last[j + 1])) {
                ans.push_back(i);
                j++;
                skip = 1;
            }
        }

        if (j != m) {
            return {};
        }

        return ans;
    }
};