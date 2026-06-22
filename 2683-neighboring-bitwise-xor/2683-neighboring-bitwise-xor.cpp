class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        
        for (int initial = 0; initial <= 1; ++initial) {
            vector<int> original(n);
            original[0] = initial;
            
            for (int i = 1; i < n; ++i) {
                original[i] = original[i - 1] ^ derived[i - 1];
            }
            if ((original[n - 1] ^ original[0]) == derived[n - 1]) {
                return true;
            }
        }
        
        return false;
    }
};
