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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode *res = MergeRec(pHead1, pHead2);
        return res;
    }
    // 基于递归思想，每次让res指向val小的结点
    ListNode* MergeRec(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode* res = NULL;
        if(pHead1->val < pHead2->val) {
            res = pHead1;
            res->next = MergeRec(pHead1->next, pHead2);
        } else {
            res = pHead2;
            res->next = MergeRec(pHead1, pHead2->next);
        }
        return res;
    }
};
