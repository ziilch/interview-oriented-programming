//
// Created by zilch on 2020/6/25.
//

#ifndef INTERVIEW_PROGRAMMING_HEAP_METHOD
#define INTERVIEW_PROGRAMMING_HEAP_METHOD
#include "../includes/base_include.h"
class heap_method {
public:

};

/**
 * H-L295-***
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> bh;
    priority_queue<int, vector<int>, greater<int>> sh;
    MedianFinder() {

    }

    void addNum(int num) {
        if (bh.size() == sh.size()) {
            bh.push(num);
            sh.push(bh.top());
            bh.pop();
        } else {
            sh.push(num);
            bh.push(sh.top());
            sh.pop();
        }
    }

    double findMedian() {
        return (sh.size() + bh.size()) & 1 ? (double) sh.top() : (double) (sh.top() + bh.top()) / 2;
    }
};

#endif //INTERVIEW_PROGRAMMING_HEAP_METHOD

