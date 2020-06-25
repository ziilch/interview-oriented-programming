//
// Created by zorro on 2020/4/21.
//

#ifndef INTERVIEW_PROGRAMMING_LISTNODE_H
#define INTERVIEW_PROGRAMMING_LISTNODE_H

#include "../includes/BaseInclude.h"

class ListNodeSolution {
public:

    // E-L206-*****
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* post = NULL;
        while (cur) {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        return pre;
    }


    // M-L2-**
    // 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    //输出：7 -> 0 -> 8
    //原因：342 + 465 = 807
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int bp = 0;
        ListNode * res = new ListNode(0);
        ListNode* cur = res;
        while (l1 || l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = v1 + v2 + bp;
            bp = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (bp) cur->next = new ListNode(1);
        return res->next;
    }

    /**
     * M-L138-**
     * 这道题目的复杂点主要在于随机节点的存储
     * 因为要新建一个链表，在新的链表还没建立完全的时候，无法找到新旧随机节点的对应关系
     * 所以找到新老的同位置节点的对应关系
     * 走完一遍老的，新的就都出来了
     * 然后老的random和新的random的对应关系就知道了
     * 直接把指针指过去就ok了
     * @param head
     * @return
     */
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* res = dummy;
        Node* tmp = head;
        unordered_map<Node*, Node*> ht;
        while (tmp) {
            dummy->next = new Node(tmp->val);
            dummy = dummy->next;
            ht[tmp] = dummy;
            tmp = tmp->next;
        }
        tmp = head;
        Node* cur = res->next;
        while (tmp) {
            cur->random = ht[tmp->random];
            tmp = tmp->next;
            cur = cur->next;
        }
        return res->next;
    }
};


#endif //INTERVIEW_PROGRAMMING_LISTNODE_H
