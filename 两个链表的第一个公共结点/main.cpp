#include <iostream>
#include <vector>
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
    // 先让长链表指针走多的一部分，然后两个链表分别向后移动直到指向同一结点
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *head1 = pHead1;
        ListNode *head2 = pHead2;
        if(head1==NULL || head2==NULL) return NULL;
        int len1 = 0, len2 = 0;
        while(head1!=NULL) {
            head1 = head1->next;
            ++len1;
        }
        while(head2!=NULL) {
            head2 = head2->next;
            ++len2;
        }
        if(len1>len2) {
            int tmp = len1-len2;
            while(tmp--) {
                pHead1 = pHead1->next;
            }
        } else if(len1<len2) {
            int tmp = len2-len1;
            while(tmp--) {
                pHead2 = pHead2->next;
            }
        }
        while(pHead1!=NULL && pHead2!=NULL) {
            if(pHead1==pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
};
