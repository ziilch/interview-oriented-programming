//
// Created by zorro on 2020/4/21.
//

#ifndef INTERVIEW_PROGRAMMING_LISTNODE_H
#define INTERVIEW_PROGRAMMING_LISTNODE_H

#include "../includes/base_include.h"

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

    /**
     * L23-H-*****
     * 合并k个有序链表，一道十分经典的题目
     * 有一个简单的思路是合并两个有序的链表
     * 之后遍历这个list,依次合并，也可以过
     * 还有一种思路是通过归并排序的思路去做
     * 走到最底层，然后到上面层层合并
     * @param lists
     * @return
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return dfs(lists, 0, lists.size() - 1);
    }

    ListNode* dfs(vector<ListNode*>& list, int st, int ed) {
        int mid = (st + ed) >> 1;
        if (st >= ed) return list[st];
        ListNode* lt = dfs(list, st, mid);
        ListNode* rt = dfs(list, mid + 1, ed);
        return mergeTwo(lt, rt);
    }

    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        ListNode* dum = new ListNode(0);
        ListNode* res = dum;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                dum->next = l1;
                l1 = l1->next;
            } else {
                dum->next = l2;
                l2 = l2->next;
            }
            dum = dum->next;
        }
        dum->next = l1 == NULL ? l2 : l1;
        return res->next;
    }
};


#endif //INTERVIEW_PROGRAMMING_LISTNODE_H
