class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string current = "";
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '[') {
                st.push({current, num});
                current = "";
                num = 0;
            } 
            else if (c == ']') {
                auto [prevStr, count] = st.top();
                st.pop();
                string repeated = "";
                for (int i = 0; i < count; i++) repeated += current;
                current = prevStr + repeated;
            } 
            else {
                current += c;
            }
        }
        
        return current;
    }
};