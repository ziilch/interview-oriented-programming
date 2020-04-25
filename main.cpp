//
// Created by zorro on 2020/4/20.
//

#include <iostream>
#include <algorithm>
#include "src/BinarySearch.hpp"
#include "src/SortMethod.hpp"
#include "src/SelfTest.hpp"
#include "src/SelfUtil.hpp"
#include "src/BinaryTree.hpp"

int main() {
    priority_queue<int> pq;
    pq.push(4);
    pq.push(5);
    pq.push(3);
    cout << pq.top();

    vector<int> va;
    sort(va.begin(), va.end());

    return 0;
}

