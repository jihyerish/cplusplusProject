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
    void findValue(TreeNode* root) {
        if (0 < root->val)
            input.push_back(root->val);
        
        if (nullptr != root->left)
        {
            findValue(root->left);
        }
        
        if (nullptr != root->right)
        {
            findValue(root->right);
        }
    }
    
    void makeBalance(TreeNode*root, size_t start, size_t end)
    {
        std::cout << "start: " << start << " end: " << end << endl;
        int mid = start;
        if (start != end)
        {
            mid = ((end - start)/2) + start;
        }
        
        TreeNode* newNode = new TreeNode(input[mid]);
        
        if (root->val > newNode->val)
        {
            root->left = newNode;
        }
        else
        {
            root->right = newNode;
        }
        
        if (start < mid)
            makeBalance(newNode, start, mid - 1);
        
        if (mid < end)
            makeBalance(newNode, mid + 1, end);
    }

    TreeNode* balanceBST(TreeNode* root) {
        input.clear();
        findValue(root);
        
        std::sort(input.begin(), input.end());
        
        for(auto num : input)
        {
            std::cout << num << " ";
        }
        
        std::cout << std::endl;
        
        auto mid = input.size()/2;
        TreeNode* balanced = new TreeNode(input[mid]);
        
        makeBalance(balanced, 0, mid - 1);
        makeBalance(balanced, mid + 1, input.size() - 1);
        
        return balanced;
    }
private:
    std::vector<int> input;
};