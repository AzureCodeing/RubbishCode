/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        int t = sum - root->val;
        if(root->left == NULL && root->right ==NULL) return t == 0 ? true : false;

        return (hasPathSum(root->left, t) || hasPathSum(root->right, t));
    }

};

int main(int argc, char *argv[])
{
       /*
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
    */
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(14);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode i(1);

    a.left = &b;
    a.right = &c;
    b.left = &d;

    c.left = &e;
    c.right = &f;

    d.left = &g;
    d.right = &h;

    g.right = &i;

    Solution tree;

    int num = 22;

    std::cout << "是否存在一条路径的和为: " << num  << "-"<< tree.hasPathSum(&a, num) << std::endl;

    return 0;
}