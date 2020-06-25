//
// Created by zorro on 2020/4/20.
//

#include "includes/BaseInclude.h"
#include "src/SelfUtil.hpp"
#include "src/ListNode.hpp"
#include <iomanip>
#include <regex>

#include <cctype>

int main(int argc, char* argv[])
{
    //Solution solution;
    unordered_map<string, bool> ht;
    ht["123"] = true;
    cout << ht["123"];
    //solution.permutation("aab");
    //cout << ss.substr(1);
    ListNodeSolution listNodeSolution;
    cout << listNodeSolution.copyRandomList(NULL);
}


