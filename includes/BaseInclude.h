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
#include <list>
#include <map>
#include <set>
#include <iomanip>
#include <regex>
#include <cctype>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


#endif //INTERVIEW_PROGRAMMING_BASEINCLUDE_H
