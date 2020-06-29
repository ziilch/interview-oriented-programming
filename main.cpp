//
// Created by zorro on 2020/4/20.
//

#include "includes/BaseInclude.h"
#include "src/SelfUtil.hpp"
#include "src/ListNode.hpp"
#include "src/HeapMethod.hpp"
vector<int> constructArr(vector<int>& a) {
    if (a.empty()) return a;
    int n = a.size();
    vector<int> l(n);
    vector<int> r(n);
    l[0] = 1;
    r[n - 1] = 1;
    for (int i = 1; i < n; i ++) {
        l[i] = l[i - 1] * a[i - 1];
        r[n - i - 1] = r[n - i] * a[n - i];
    }
    vector<int> res;
    for (int i = 0; i < n; i ++) {
        res.push_back(l[i] * r[i]);
    }
    return res;
}

int main(int argc, char* argv[])
{
    map<int, int> mp;
    cout << mp[0];
    string s1 = "123";
    string s2 = "456";
    vector<int> v = {1,2,3,4,5};
    constructArr(v);
    // 101 ^ 110 = 011
}


