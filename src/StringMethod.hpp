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
};

#endif //INTERVIEW_PROGRAMMING_STRINGMETHOD_HPP
