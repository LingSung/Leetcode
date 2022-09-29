/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> qu;
        
        qu.push(root);
        while(!qu.empty()) {
            int sz = qu.size();
            double sum = 0;
            for (int i=0; i<sz; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                
                sum += node->val;
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            
            ans.push_back(sum / sz);
        }
        
        return ans;
    }
};