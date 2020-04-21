//
// Created by zilch on 2019/8/24.
//

#ifndef INTERVIEW_PROGRAMMING_BASEINCLUDE_H
#define INTERVIEW_PROGRAMMING_BASEINCLUDE_H

#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif //INTERVIEW_PROGRAMMING_BASEINCLUDE_H
