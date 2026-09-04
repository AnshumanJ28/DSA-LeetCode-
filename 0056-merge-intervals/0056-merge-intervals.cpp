class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        if (n == 0) return result;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];   
        });

        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            int c = intervals[i][0];
            int d = intervals[i][1];

            int &b = result.back()[1];    

            if (c <= b) {
                b = max(b,d);
            } else {
                result.push_back({c,d});
            }
        }

        return result;
    }
};