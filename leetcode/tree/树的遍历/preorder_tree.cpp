#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    //递归调用自己完成前序遍历
    void preorder(std::vector<int> &vec, TreeNode* root){
        if(root == NULL) return;
        vec.push_back(root->val);
        preorder(vec, root->left);
        preorder(vec, root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(result, root);
        return result;
    }
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

    std::vector<int> result = tree.preorderTraversal(&a);

    std::cout << "前序遍历结果: ";
    for(auto elemt: result){
        std::cout << elemt << " ";
    }
    std::cout << std::endl;

    return 0;
}