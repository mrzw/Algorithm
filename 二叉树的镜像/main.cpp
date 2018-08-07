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
class Solution {
public:
    // 递归思想，对于每个结点将其左子树和右子树交换
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL) return;
        if(pRoot->left==NULL && pRoot->right==NULL) return;
        MirrorCore(pRoot);
    }
    void MirrorCore(TreeNode *pRoot) {
        if(pRoot==NULL) return;
        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        MirrorCore(pRoot->left);
        MirrorCore(pRoot->right);
    }
};
