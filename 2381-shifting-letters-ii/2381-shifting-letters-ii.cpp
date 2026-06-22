class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> shiftDelta(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 1) {
                shiftDelta[start] += 1;
                shiftDelta[end + 1] -= 1;
            } else {
                shiftDelta[start] -= 1;
                shiftDelta[end + 1] += 1;
            }
        }

        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += shiftDelta[i];
            int shiftAmount = (cumulativeShift % 26 + 26) % 26; // Normalize the shift
            s[i] = 'a' + (s[i] - 'a' + shiftAmount) % 26;
        }

        return s;
    }
};
