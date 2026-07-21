class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int len = 1; len <= n / 2; len++) {
            if (n % len != 0)
                continue;

            stack<char> st;

            for (int i = 0; i < len; i++)
                st.push(s[i]);

            bool ok = true;

            for (int start = len; start < n && ok; start += len) {
                stack<char> temp = st;

                for (int j = start + len - 1; j >= start; j--) {
                    if (temp.empty() || temp.top() != s[j]) {
                        ok = false;
                        break;
                    }
                    temp.pop();
                }
            }

            if (ok)
                return true;
        }

        return false;
    }
};