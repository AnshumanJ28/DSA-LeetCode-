class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        unordered_map<string, int> freq;

        for (string &word : words)
            freq[word]++;

        int len = s.size();
        int n = words.size();
        int wordSize = words[0].size();
        int windowSize = n * wordSize;

        if (windowSize > len)
            return ans;

        for (int offset = 0; offset < wordSize; offset++) {

            unordered_map<string, int> curr;
            int left = offset;
            int count = 0;

            for (int right = offset; right + wordSize <= len; right += wordSize) {

                string word = s.substr(right, wordSize);

                if (freq.count(word)) {

                    curr[word]++;
                    count++;

                    while (curr[word] > freq[word]) {
                        string leftWord = s.substr(left, wordSize);
                        curr[leftWord]--;
                        left += wordSize;
                        count--;
                    }

                    if (count == n) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordSize);
                        curr[leftWord]--;
                        left += wordSize;
                        count--;
                    }
                }
                else {
                    curr.clear();
                    count = 0;
                    left = right + wordSize;
                }
            }
        }

        return ans;
    }
};