#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a=0):val(a),left(NULL),right(NULL) {}
};

int TreeDepth(TreeNode* pRoot)
{
    if(pRoot==NULL) return 0;
    return TreeDepth(pRoot->left) > TreeDepth(pRoot->right) ? TreeDepth(pRoot->left)+1:TreeDepth(pRoot->right)+1;
}
int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left  = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << TreeDepth(root) << endl;
}
