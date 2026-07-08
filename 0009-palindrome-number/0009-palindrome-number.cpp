class Solution {
public:
    bool isPalindrome(int x) {
    string s = to_string(x);
    int len = s.length();
    int l = 0;
    int r = len-1;
    for(int i = 0 ;i<len/2;i++){
        if(s[i] == s[r]){
            l++;
            r--;
        }else{
            return false;
        }
    }
    return true;

    }
};