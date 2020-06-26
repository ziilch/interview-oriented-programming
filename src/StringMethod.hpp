//
// Created by zilch on 2020/6/8.
//

#ifndef INTERVIEW_PROGRAMMING_STRINGMETHOD_HPP
#define INTERVIEW_PROGRAMMING_STRINGMETHOD_HPP
#include "../includes/BaseInclude.h"

class StringMethod {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p[1] == '*') {
            return isMatch(s, p.substr(2)) || (! s.empty() && (s[0] == p[0] || p[0] == '.')) && isMatch(s.substr(1), p);
        } else {
            return ! s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }

    /**
     * M-L3-***
     * 本题采用双指针做法，有两个地方很有迷惑性：
     * 一是在不重复的时候也需要更新max长度
     * 二是在判断是否有重复元素的时候，后面的指针判断要忽略前指针之前的字母
     * @param s
     * @return
     */
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ht;
        int max = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            // 如果没有这个元素，或者这个元素出现在左指针之前，那么就更新
            if (ht.find(s[j]) == ht.end() || ht[s[j]] < i) {
                ht[s[j]] = j;
                if (j - i + 1 > max) max = j - i + 1;
            } else {
                if (j - i > max) max = j - i;
                i = ++ ht[s[j]];
                ht[s[j]] = j;
            }
        }
        return max;
    }

    // 对上面的答案做了一些优化
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ht;
        int len = 0;
        for (int i = 0, j = 0; j < s.size(); j ++) {
            if (ht.find(s[j]) != ht.end() && ht[s[j]] >= i) {
                i = ++ ht[s[j]];
            }
            if (j - i + 1 > len) len = j - i + 1;
            ht[s[j]] = j;
        }
        return len;
    }
};

#endif //INTERVIEW_PROGRAMMING_STRINGMETHOD_HPP
