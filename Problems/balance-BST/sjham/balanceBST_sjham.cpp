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
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<TreeNode*>    nodeList = make_nodelist(root);
        return balance_node(nodeList);
    }
    
    std::vector<TreeNode*> make_nodelist(TreeNode* root){        
        std::vector<TreeNode*> nodeList;
        
        nodeList.push_back(root);
        
        if (root->left == nullptr && root->right == nullptr)
            return nodeList;
        
        if (root->left != nullptr){
            std::vector<TreeNode*> temp = make_nodelist(root->left);
            nodeList.insert(nodeList.begin(), temp.begin(), temp.end());
        }
        if (root->right != nullptr){
            std::vector<TreeNode*> temp = make_nodelist(root->right);
            nodeList.insert(nodeList.end(), temp.begin(), temp.end());
        }
            
        return nodeList;
    }
    
    TreeNode* balance_node(std::vector<TreeNode*>& list){
        if (list.size() == 0)
            return nullptr;
        
        TreeNode*   result        = nullptr;        
        int         medium_node   = (list.size() - 1) / 2;
        
        result = list[medium_node];
        
        std::vector<TreeNode*> temp;
        temp.assign(list.begin(), list.begin() + medium_node);
        result->left = balance_node(temp);
        
        temp.clear();
        temp.assign(list.begin() + medium_node + 1, list.end());
        result->right = balance_node(temp);
        
        return result;
    }
};
