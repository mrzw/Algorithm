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
    // 由前序和中序找到根结点的位置和左右子树，递归
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len1 = pre.size();
        int len2 = vin.size();
        if(len1<=0 || len2<=0 || len1!=len2) return NULL;
        return constructCore(pre,0,len1-1,vin,0,len2-1);
    }
    TreeNode* constructCore(const vector<int>& pre, int left1, int right1, const vector<int>& vin, int left2, int right2) {
        TreeNode *root = new TreeNode(pre[left1]);
        if(left1==right1 && left2==right2 && pre[left1]==vin[left2]) {
            return root;
        }
        // 从中序遍历中找根结点的位置
        int rootInorder = left2;
        while(left2<=right2 && vin[rootInorder]!=pre[left1]) {
            ++rootInorder;
        }
        int leftLength = rootInorder - left2;
        int leftPreEnd = left1 + leftLength;
        if(leftLength>0) {
            root->left = constructCore(pre,left1+1,leftPreEnd,vin,left2,rootInorder-1);
        }
        if(leftPreEnd<right1) {
            root->right = constructCore(pre,leftPreEnd+1,right1,vin,rootInorder+1,right2);
        }
        return root;
    }
};
