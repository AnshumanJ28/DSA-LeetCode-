class Solution {
public:
    string reverseWords(string s) {
    int n = s.size();
    int right = n - 1;
    vector<string> words;

    while (right >= 0) {
        while (right >= 0 && s[right] == ' ') {
            right--;
        }
        if (right < 0) break;

        int left = right;
        while (left >= 0 && s[left] != ' ') {
            left--;
        }

        string word = s.substr(left + 1, right - left);
        words.push_back(word);

        right = left;
    }

    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) result += " ";
    }

    return result;
}
};