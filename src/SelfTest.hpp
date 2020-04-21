//
// Created by zorro on 2020/4/21.
//

#ifndef INTERVIEW_PROGRAMMING_SELF_TEST
#define INTERVIEW_PROGRAMMING_SELF_TEST

#include "SortMethod.hpp"
#include "SelfUtil.hpp"
class SelfTest {
public:
    void sortCompare(int amount) {
        vector<int> random = selfUtil->createRandom(amount);
        vector<int> tmp = random;

        clock_t tc = clock();
        sortMethod->quickSort(random);
        cout << "快速排序：" << (clock() - tc) * 1.0 / CLOCKS_PER_SEC * 1000 << endl;

        random = tmp;
        tc = clock();
        sortMethod->heapSort(random);
        cout << "堆排序 ：" << (clock() - tc) * 1.0 / CLOCKS_PER_SEC * 1000 << endl;

        random = tmp;
        tc = clock();
        sortMethod->mergeSort(random);
        cout << "归并排序：" << (clock() - tc) * 1.0 / CLOCKS_PER_SEC * 1000 << endl;
    }

    void createListNode(const string ss) {
        SelfUtil selfUtil;
        ListNode* ls = selfUtil.listNodeFromString(ss);
        cout << "创建链表为: ";
        while (ls->next) {
            cout << ls->val << "->";
            ls = ls->next;
        }
        cout << ls->val << ";" << endl;
    }

private:
    SortMethod* sortMethod = new SortMethod;
    SelfUtil* selfUtil = new SelfUtil;
};

#endif //INTERVIEW_PROGRAMMING_