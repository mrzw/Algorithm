#include <iostream>
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
	// 三个指针，一个指向当前结点，一个指向前驱结点，一个指向后继结点。
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        ListNode *p_pre = NULL, *p = pHead, *p_next = NULL;
        ListNode *head = NULL;
        while(p != NULL) {
            p_next = p->next;
            if(p_next == NULL) head = p;
            p->next = p_pre;
            p_pre = p;
            p = p_next;
        }
        return head;
    }
};
