class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size() - 1;
        int count = 0;
        for (int n = len; n >= 0; n--) {
            if (s[n] == ' ' && count > 0) {
                break;
            }
            else if (s[n] == ' '){
                continue;
            }
            count++;
        }
        return count;
    }
};