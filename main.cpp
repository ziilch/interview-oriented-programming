//
// Created by zorro on 2020/4/20.
//

#include "includes/BaseInclude.h"
#include "src/SelfUtil.hpp"
#include "src/ListNode.hpp"
#include "src/HeapMethod.hpp"

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> ht;
    int len = 0;
    for (int i = 0, j = 0; j < s.size(); j ++) {
        if (ht.find(s[j]) != ht.end() && ht[s[j]] >= i) {
            i = ++ ht[s[j]];
        }
        if (j -i + 1 > len) len = j - i + 1;
        ht[s[j]] = j;
    }
    return len;
}

int main(int argc, char* argv[])
{
    unordered_set<int> st;
    st.insert(3);
    cout << lengthOfLongestSubstring("abcabcbb");
    //cout << (ht.find('a') == ht.end());
}


