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
    void postorder(std::vector<int> &vec, TreeNode* root){
        if(root == NULL) return;
        postorder(vec, root->left);
        postorder(vec, root->right);
        vec.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        postorder(result, root);
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

    std::vector<int> result = tree.postorderTraversal(&a);

    std::cout << "后序遍历结果: ";
    for(auto elemt: result){
        std::cout << elemt << " ";
    }
    std::cout << std::endl;

    return 0;
}