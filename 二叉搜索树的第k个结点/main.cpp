#include <iostream>
#include <vector>
#include <stack>
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
	// 中序遍历查找第k个点
    void zhongxu(TreeNode* pRoot, vector<TreeNode*>& da) {
        if(pRoot==NULL) return;
        zhongxu(pRoot->left, da);
        da.push_back(pRoot);
        zhongxu(pRoot->right, da);
    }
    void zhongxu1(TreeNode* pRoot, vector<TreeNode*>& da) {
        TreeNode* tmp = pRoot;
        if(tmp==NULL) return;
        stack<TreeNode*> st;
        while(tmp!=NULL || !st.empty()) {
            while(tmp!=NULL) {
                st.push(tmp);
                tmp = tmp->left;
            }
            if(!st.empty()) {
                tmp = st.top();
                st.pop();
                da.push_back(tmp);
                tmp = tmp->right;
            }
        }
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL || k<=0) return NULL;
        vector<TreeNode*> input;
        zhongxu(pRoot, input);
        if(k>input.size()) return NULL;
        return input[k-1];
    }

};
