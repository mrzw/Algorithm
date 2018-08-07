#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a=0):val(a),left(NULL),right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL) return res;
        tmp.push_back(root->val);
        expectNumber -= root->val;
        // 如果是叶子结点，且路径上的结点和等于输入值则保存
        if(expectNumber==0 && (root->left==NULL && root->right==NULL)) {
            res.push_back(tmp);
        }
        // 如果不是叶子结点，则遍历它的子结点
        FindPath(root->left, expectNumber);
        FindPath(root->right, expectNumber);
        // 在返回父节点前，路径上删除当前结点
        tmp.pop_back();
        return res;
    }
public:
    vector<vector<int> > res;
    vector<int> tmp;
};
