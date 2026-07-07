class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string a = "";
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '0') {
                a += s[i];
                sum += s[i] - '0';
            }
        }

        if (a.empty()) {
            return 0;
        }

        long long num = stoll(a);

        return num * sum;
    }
};