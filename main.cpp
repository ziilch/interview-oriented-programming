//
// Created by zorro on 2020/4/20.
//

#include "includes/BaseInclude.h"
#include "src/SelfUtil.hpp"
#include "src/ListNode.hpp"
#include "src/HeapMethod.hpp"
#include <iomanip>
#include <regex>

#include <cctype>

int main(int argc, char* argv[])
{
    MedianFinder me;
    priority_queue<int, vector<int>, less<int>> lh;
    lh.push(2);
    lh.push(1);
    lh.push(3);
    lh.push(4);
    lh.pop();
    cout << lh.size();

}


