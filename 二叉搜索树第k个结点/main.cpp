#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
// 二叉搜索树第k个结点利用中序遍历
class Solution {
public:
    void zhongxu(TreeNode* pRoot, TreeNode* &root, int &k) {
        if(pRoot==NULL) return;
        zhongxu(pRoot->left,root,k);
        --k;
        if(k==0) {
            root = pRoot;
            return;
        }
        zhongxu(pRoot->right,root,k);
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL || k==0) return NULL;
        TreeNode *root = NULL;
        zhongxu(pRoot, root, k);
        return root;
    }


};
