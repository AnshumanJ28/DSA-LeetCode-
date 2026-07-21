class Solution {
public:
    bool isSame(string &word, string &str2, int i, int m) {
        for (int j = 0; j < m; j++) {
            if (word[i] != str2[j]) {
                return false;
            }
            i++;
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;

        string word(N, '$');
        vector<bool> can(N, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                int pos = i;
                for (int j = 0; j < m; j++) {
                    if (word[pos] != '$' && word[pos] != str2[j]) {
                        return "";
                    }
                    word[pos] = str2[j];
                    pos++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (word[i] == '$') {
                word[i] = 'a';
                can[i] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                if (isSame(word, str2, i, m)) {
                    bool changed = false;

                    for (int pos = i + m - 1; pos >= i; pos--) {
                        if (can[pos]) {
                            word[pos] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if (!changed) {
                        return "";
                    }
                }
            }
        }

        return word;
    }
};