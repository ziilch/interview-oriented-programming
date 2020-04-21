//
// Created by zorro on 2020/4/21.
//

#ifndef SELF_TEST
#define SELF_TEST

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

private:
    SortMethod* sortMethod = new SortMethod;
    SelfUtil* selfUtil = new SelfUtil;
};

#endif //SELF_TEST