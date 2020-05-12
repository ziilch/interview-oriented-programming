//
// Created by zorro on 2020/4/20.
//

#include "includes/BaseInclude.h"
#include "src/SelfUtil.hpp"
#include <iomanip>

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> ht;
    int p1 = 0, p2 = 0, n = s.size(), res = 0;
    while (p2 < n) {
        if (ht.find(s[p2]) != ht.end() && ht[s[p2]] >= p1) {
            //res = max(p2 - p1, res);
            p1 = ht[s[p2]] + 1;
        }
        ht[s[p2]] = p2;
        res = max(res, p2 - p1 + 1);
        if (res == 5) cout << p2 << p1;
        p2 ++;
    }
    return res;
}



int main(int argc, char* argv[])
{
    string ss = "[1,2,3,null,null,4,5]";
    SelfUtil selfUtil;
    vector<vector<string>> v = selfUtil.split(ss);
    int a = atoi(v[0][0].c_str());
    TreeNode* root = selfUtil.deserialize(ss);
    vector<TreeNode*> l1, l2;
    //cout << setprecision(18) << a;
    //cout << "a";
}


