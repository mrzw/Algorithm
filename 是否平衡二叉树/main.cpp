#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a=0):val(a),left(NULL),right(NULL) {}
};

bool IsBalanced(TreeNode *root, int *depth) {
    if(root==NULL) {
        *depth = 0;
        return true;
    }
    int left = 0, right = 0;
    if(IsBalanced(root->left, &left) && IsBalanced(root->right, &right)) {
        int diff = left - right;
        if(diff>=-1 && diff<=1) {
            *depth = (left>right?left+1:right+1);
            return true;
        }
    }
    return false;
}
// 基于后序遍历思想，在遍历到一个结点前先遍历左右子树，同时遍历时候记录结点深度，就可以一边遍历一边判断每个结点是否平衡
bool IsBalanced_Solution(TreeNode* pRoot) {
    int depth = 0;
    return IsBalanced(pRoot, &depth);
}
int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left  = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    if(IsBalanced_Solution(root)) cout << "balance" << endl;
    else cout << "not balance" << endl;
}
