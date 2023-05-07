#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; ++i)
        {
            map[inorder[i]] = i;
        }
        return buildTree(preorder, 0, n - 1, inorder, 0, n - 1, map);
    }

    TreeNode *buildTree(vector<int> &preorder, int preLeft, int preRight, vector<int> &inorder, int inLeft, int inRight, unordered_map<int, int> &map)
    {
        if (preLeft > preRight)
        {
            return nullptr;
        }
        int rootVal = preorder[preLeft];
        int rootIndex = map[rootVal];
        int leftSize = rootIndex - inLeft;
        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTree(preorder, preLeft + 1, preLeft + leftSize, inorder, inLeft, rootIndex - 1, map);
        root->right = buildTree(preorder, preLeft + leftSize + 1, preRight, inorder, rootIndex + 1, inRight, map);
        return root;
    }
};

void findKthLeafNode(TreeNode *root, int k)
{
    if (root == nullptr)
    {
        return;
    }
    static int count = 0;
    findKthLeafNode(root->left, k);
    if (root->left == nullptr && root->right == nullptr)
    {
        count++;
        if (count == k)
        {
            cout << root->val << endl;
        }
    }
    findKthLeafNode(root->right, k);
}
int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution solution;
    TreeNode *root = solution.buildTree(preorder, inorder);
    findKthLeafNode(root, 2);
    return 0;
}