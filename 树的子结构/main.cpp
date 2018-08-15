/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	// 首先在pRoot1中找到与pRoot2根结点值一样的结点R，然后判断R为根结点的子树是不是包含和pRoot2一样的结构
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL || pRoot2==NULL) return false;
        bool res = false;
        if(pRoot1->val == pRoot2->val)
            res = isSubtree(pRoot1, pRoot2);
        if(!res)
            res = HasSubtree(pRoot1->left, pRoot2);
        if(!res)
            res = HasSubtree(pRoot1->right, pRoot2);
        return res;
    }
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2==NULL) return true;
        if(pRoot1==NULL) return false;
        if(pRoot1->val!=pRoot2->val) return false;
        return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
    }
};
