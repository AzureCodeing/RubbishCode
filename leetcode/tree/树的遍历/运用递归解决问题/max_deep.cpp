#include <iostream>
#include <algorithm>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    Solution():max_deep(0) {}
    //自底向上
    int maxDepth(TreeNode* root) 
    {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int maxDepth(TreeNode* root, int deep)
    {
        if(root == NULL) return 0;
        if(!root->left && !root->right) max_deep = max(deep, max_deep);
        maxDepth(root->left, deep+1);
        maxDepth(root->right, deep+1);

        return max_deep;
    }
private:
    int max_deep;
};


int main(int argc, char *argv[])
{
   /*
             a
            / \
           b   c
          / \   \
         d   e   f
                / \
               g   h
    */

    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);
    TreeNode h(8);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    f.left = &g;
    f.right = &h;

    Solution tree;

    std::cout << "最大深度: " << tree.maxDepth(&a) << std::endl;
    std::cout << "最大深度: " << tree.maxDepth(&a, 1) << std::endl;
    return 0;
}