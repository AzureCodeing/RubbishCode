#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*递归 按照左中右的方式遍历*/
class Solution {
public:
    //递归方法
    bool isSymmetric1(TreeNode* left, TreeNode *right) {
        if(left == NULL || right == NULL) return left == right;
        if(left->val != right->val) return false;
        // std::cout << "left->val: " << left->val << "right->val: " << right->val << std::endl;
        return (isSymmetric1(left->left,right->right) && isSymmetric1(left->right, right->left));
    }
    bool isSymmetric1(TreeNode* root) {
        if(!root) return true;
        return isSymmetric1(root->left, root->right);
    }
//栈辅助方法
    bool isSymmetric2(TreeNode* root) {
    if(root == NULL) return false;
    stack<TreeNode*> temp_stack;
    temp_stack.push(root->left);
    temp_stack.push(root->right);
    while(!temp_stack.empty()){
        TreeNode* node_right = temp_stack.top(); temp_stack.pop();
        TreeNode* node_left = temp_stack.top(); temp_stack.pop();
        if(node_right == NULL && node_left == NULL) continue;
        if(node_left == NULL || node_right == NULL || (node_right->val != node_left->val)) return false;

        temp_stack.push(node_left->left);
        temp_stack.push(node_right->right);
        temp_stack.push(node_left->right);
        temp_stack.push(node_right->left);
        }
    return true;
    }
};

/* 
题目: 对称二叉树
要求: 给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    a1
   /   \
  b2    c2
 /  \  /  \
d3  e4 f4 g3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3
   
*/
int main(int argc, char *argv[])
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(4);
    TreeNode g(3);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    Solution tree;

    std::cout << "是否是对称二叉树" << tree.isSymmetric1(&a) << std::endl;
    std::cout << "是否是对称二叉树" << tree.isSymmetric2(&a) << std::endl;

    return 0;
}