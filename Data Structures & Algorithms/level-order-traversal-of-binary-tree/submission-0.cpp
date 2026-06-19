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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int level = q.size();
            vector<int> vecLevel;
            for(int i =0; i< level; ++i){
                TreeNode* removed = q.front();
                q.pop();
                vecLevel.push_back(removed->val);
                if(removed->left) q.push(removed->left);
                if(removed->right) q.push(removed->right);

            }
            result.push_back(vecLevel);
        }
        return result;
        
    }
};
