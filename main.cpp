//
// Created by zorro on 2020/4/20.
//

#include "includes/base_include.h"
#include "src/self_util.hpp"
#include "src/list_node.hpp"
#include "src/heap_method.hpp"
#include "src/double_pointer.hpp"
#include "src/normal_algorithm.hpp"

int main(int argc, char* argv[])
{
    vector<int> ps;
    stack<int> st;
    deque<int>dq;
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    int a = pq.top();
    cout << a << endl;
    return 0;
}


