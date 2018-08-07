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
    // 第一次遍历找出list总长度len，则第二次遍历倒数第k个结点即为正数第len-k个结点
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *p = pListHead;
        int len = 0;
        while(p != NULL) {
            ++len;
            p = p->next;
        }
        if(k==0 || k>len || pListHead==NULL) return NULL;
        for(int i=0; i<len-k; ++i) {
            pListHead = pListHead->next;
        }
        return pListHead;
    }
    // 一次遍历即可。两个指针，一个指向头，一个向后走k-1位，当后一个到达尾部前一个即为所求
    ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k) {
        if(k==0 || pListHead==NULL) return NULL;
        ListNode *p1 = pListHead, *p2 = pListHead;
        for(int i=0; i<k-1; ++i) {
            p2 = p2->next;
            if (p2 == NULL) return NULL;
        }
        while(p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
