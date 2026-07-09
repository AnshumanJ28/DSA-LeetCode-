class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> seen;
    unordered_set<string> added;
    vector<string> result;

    for (int i = 0; i + 10 <= s.size(); i++) {
        string window = s.substr(i, 10);
        if (seen.count(window)) {
            if (!added.count(window)) {
                added.insert(window);
                result.push_back(window);
            }
        } else {
            seen.insert(window);
        }
    }

    return result;
}
};