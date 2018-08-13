#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		 val(x), next(NULL) {
	}
};

class Solution {
public:
	// 基于栈特点保存结点数
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head==NULL) return vector<int>();
        stack<int> st;
        while(head!=NULL) {
            st.push(head->val);
            head = head->next;
        }
        vector<int> res;
        while(!st.empty()) {
            int tmp = st.top();
            st.pop();
            res.push_back(tmp);
        }
        return res;
    }
};
