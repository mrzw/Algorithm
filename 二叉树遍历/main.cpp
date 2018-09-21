#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a=0):val(a),left(NULL),right(NULL) {}
};

void preOrder(TreeNode* root) {
    if(root==NULL) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
/*
 * 二叉树非递归遍历
 * 根据前序遍历的访问顺序，优先访问根节点，然后再分别访问左孩子和右孩子，即对于任一节点，其可以看做是根节点
 * 因此可以直接访问，访问完以后若其左孩子不为空，则按照相同的规则访问它的左子树；当访问其左子树时，再访问它的右子树
 */

/*
 * 处理流程：
 * 对于任一一节点P
 * (1)访问节点P,并将节点P入栈
 * (2）判断节点P的左孩子是否为空，若为空，则取栈顶节点进行出栈操作，并将栈顶节点的右孩子置为当前节点P,循环至1；
 *      若不为空，则将P的左孩子置为当前节点P
 * (3)直到P为NULL，并且栈为空，则遍历结束
 */
void preOrder1(TreeNode* root) {
    if(root==NULL) return;
    stack<TreeNode*> st;
    TreeNode *current = root;
    while(current!=NULL || !st.empty()) {
        while(current != NULL) {
            cout << current->val << " ";
            st.push(current);
            current = current->left;
        }
        if(!st.empty()) {
            current = st.top();
            st.pop();
            current = current->right;
        }
    }
}

void inOrder(TreeNode* root) {
    if(root==NULL) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
// 非递归中序遍历
void inOrder1(TreeNode* root) {
    if(root==NULL) return;
    stack<TreeNode*> st;
    TreeNode *current = root;
    while(current!=NULL || !st.empty()) {
        while(current!=NULL) {
            st.push(current);
            current = current->left;
        }
        if(!st.empty()) {
            current = st.top();
            st.pop();
            cout << current->val << " ";
            current = current->right;
        }
    }
}

void postOrder(TreeNode* root) {
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}
/*
 * 非递归后序遍历
 * 在后序遍历中，要保证左孩子和右孩子都已经被访问并且左孩子在右孩子访问前才能访问根节点
 *
 * 思路： 要保证根节点在左孩子和右孩子之后才能访问，因此对于任意一个节点P,先将其入栈。
 * 如果p不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已经访问过了，则同样可以直接访问该节点；
 * 若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候左孩子在右孩子的前面被访问， 左孩子和右孩子在根节点的前面被访问
 */
void postOrder1(TreeNode* root) {
    if(root==NULL) return;
    stack<TreeNode*> st;
    TreeNode *current = root;
    TreeNode *previous = NULL;
    st.push(root);
    while(!st.empty()) {
        current = st.top();
        if((current->left==NULL && current->right==NULL) ||  //当前节点的左孩子和右孩子都为空
           (previous!=NULL && (previous==current->left || previous==current->right)))  //当前节点的孩子节点都已经被访问过了
        {
            cout<<current->val<<" ";
            st.pop();
            previous = current;
        } else { //若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候左孩子在右孩子的前面被访问， 左孩子和右孩子在根节点的前面被访问
            if(current->right!=NULL) st.push(current->right);
            if(current->left!=NULL) st.push(current->left);
        }
    }
}
// 水平遍历，分层打印
void levelOrder1(TreeNode* root) {
    if(root==NULL) return 0;
    int count = 0;
    queue<TreeNode*> qu;
    qu.push(root);
    while(!qu.empty()) {
    	int size = qu.size();
    	while(size>0) {
    		TreeNode *tmp = qu.front();
        	qu.pop_front();
        	--size;
        	cout << tmp->val << " ";
        	if(tmp->left) qu.push(tmp->left);
            if(tmp->right) qu.push(tmp->right); 
    	}
    	cout << endl;
    }
}
// 水平遍历
void levelOrder(TreeNode* root) {
    if(root==NULL) return;
    queue<TreeNode*> qu;
    qu.push(root);
    while(!qu.empty()) {
        TreeNode *tmp = qu.front();
        qu.pop();
        cout << tmp->val << " ";
        if(tmp->left != NULL) qu.push(tmp->left);
        if(tmp->right != NULL) qu.push(tmp->right);
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left  = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    preOrder(root);
    cout << endl;
    preOrder1(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    inOrder1(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    postOrder1(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    levelOrder1(root);
}


