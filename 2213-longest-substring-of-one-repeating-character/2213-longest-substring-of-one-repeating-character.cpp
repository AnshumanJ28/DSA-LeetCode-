class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int leftMax, rightMax, maxLen, len;

        Node() {
            leftChar = rightChar = ' ';
            leftMax = rightMax = maxLen = len = 0;
        }
    };

    vector<Node> tree;

    void merge(int idx) {
        Node &left = tree[2 * idx];
        Node &right = tree[2 * idx + 1];
        Node &cur = tree[idx];

        cur.len = left.len + right.len;
        cur.leftChar = left.leftChar;
        cur.rightChar = right.rightChar;

        cur.leftMax = left.leftMax;

        if (left.leftMax == left.len &&
            left.rightChar == right.leftChar) {
            cur.leftMax = left.len + right.leftMax;
        }

        cur.rightMax = right.rightMax;

        if (right.rightMax == right.len &&
            left.rightChar == right.leftChar) {
            cur.rightMax = right.len + left.rightMax;
        }

        cur.maxLen = max(left.maxLen, right.maxLen);

        if (left.rightChar == right.leftChar) {
            cur.maxLen = max(cur.maxLen,
                             left.rightMax + right.leftMax);
        }
    }

    void build(string &s, int idx, int l, int r) {
        if (l == r) {
            tree[idx].leftChar = s[l];
            tree[idx].rightChar = s[l];
            tree[idx].leftMax = 1;
            tree[idx].rightMax = 1;
            tree[idx].maxLen = 1;
            tree[idx].len = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        build(s, 2 * idx, l, mid);
        build(s, 2 * idx + 1, mid + 1, r);

        merge(idx);
    }

    void update(int idx, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[idx].leftChar = ch;
            tree[idx].rightChar = ch;
            tree[idx].leftMax = 1;
            tree[idx].rightMax = 1;
            tree[idx].maxLen = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, ch);
        else
            update(2 * idx + 1, mid + 1, r, pos, ch);

        merge(idx);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

            ans.push_back(tree[1].maxLen);
        }

        return ans;
    }
};