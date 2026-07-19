class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int low = 0;
        int high = s.size();
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                result.push_back(low);
                low++;
            } else {
                result.push_back(high);
                high--;
            }
        }
        
        result.push_back(low);
        return result;
    }
};