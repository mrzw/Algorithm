#include <iostream>
#include <stack>
#include <vector>
#include <queue>
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
    // 利用队列先入先出的特点
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *tmp = q.front();
            res.push_back(tmp->val);
            q.pop();
            if(tmp->left != NULL) q.push(tmp->left);
            if(tmp->right != NULL) q.push(tmp->right);
        }
        return res;
    }
};
