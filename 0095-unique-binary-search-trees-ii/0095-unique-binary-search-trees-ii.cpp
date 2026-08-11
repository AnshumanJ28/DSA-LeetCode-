class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo; 

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        if (start > end) return {nullptr};

        int key = start * 100 + end; 
        if (memo.count(key)) return memo[key];

        vector<TreeNode*> allTrees;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = build(start, i - 1);
            vector<TreeNode*> rightSubtrees = build(i + 1, end);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }

        memo[key] = allTrees;
        return allTrees;
    }
};