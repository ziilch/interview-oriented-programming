//
// Created by zorro on 2020/4/20.
//

#include "includes/base_include.h"
#include "src/SelfUtil.hpp"
#include "src/list_node.hpp"
#include "src/heap_method.hpp"
#include "src/double_pointer.hpp"

SelfUtil selfUtil;
bool bigger(ListNode* a, ListNode* b){return a->val > b->val;}

struct cmp{
    bool operator()(ListNode *a,ListNode *b){
        return a->val > b->val;
    };

int main(int argc, char* argv[])
{
    vector<int> tt = {2,3,1,2,4,3};
    reverse(tt.begin(), tt.end());
    selfUtil.printVec(tt);
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
}


