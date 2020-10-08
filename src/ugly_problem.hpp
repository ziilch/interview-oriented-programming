//
// Created by zilch on 2020/10/9.
//

#ifndef INTERVIEW_PROGRAMMING_UGLY_PROBLEM_H
#define INTERVIEW_PROGRAMMING_UGLY_PROBLEM_H
#include "../includes/base_include.h"

class UglyProblem {
public:
    string bigNumMinus(const string& a, const string& b) {
        string s1 = a, s2 = b;
        int m = s1.size() - 1, n = s2.size() - 1, bit = 0;
        string res = "";
        while (m >= 0 || n >= 0) {
            int va = m >= 0 ? s1[m] - '0' : 0;
            int vb = n >= 0 ? s2[n] - '0' : 0;
            if (va - vb - bit < 0) {
                va += 10;
                res = to_string(va - vb - bit) + res;
                bit = 1;
            } else {
                res = to_string(va - vb - bit) + res;
                bit = 0;
            }
            m --;
            n --;
        }
        // 如果前面几位是0，那么要消除0
        for (int i = 0; i < res.size(); i ++) {
            // 移除0
            if (res[i] != '0') {
                res = res.substr(i, res.size() - i);
                break;
            }
            // 防止都为0的情况
            if (i == res.size() - 1 && res[i] == '0') res = "0";
        }
        return res;
    }

// 两数相加的情景
    string bigNumAdd(const string& a, const string& b) {
        string s1 = a, s2 = b;
        int m = s1.size() - 1, n = s2.size() - 1, bit = 0;
        string res = "";
        while (m >= 0 || n >= 0) {
            int va = m >= 0 ? s1[m] - '0' : 0;
            int vb = n >= 0 ? s2[n] - '0' : 0;
            if (va + vb + bit >= 10) {
                res = to_string(va + vb + bit - 10) + res;
                bit = 1;
            } else {
                res = to_string(va + vb + bit) + res;
                bit = 0;
            }
            m --;
            n --;
        }
        // bit有位说明之前最后一位又进位了
        if (bit) res = "1" + res;
        return res;
    }

// 判断两个字符串的大小
    bool bigger(const string& s1, const string& s2) {
        if (s1.size() == s2.size()) return s1 > s2;
        else return s1.size() > s2.size();
    }

    string twoNumMinus(const string& a, const string& b) {
        // 判断 a,b符号并去除 true为负，false为正
        string s1 = a, s2 = b;
        vector<bool> symbol(2);
        if (a[0] == '-'){
            symbol[0] = true;
            s1 = a.substr(1, a.size() - 1);
        }
        if (b[0] == '-') {
            symbol[1] = true;
            s2 = b.substr(1, b.size() - 1);
        }
        if (symbol[0] && symbol[1]) {
            // 两者都为负
            if (bigger(s1, s2)) return "-" + bigNumMinus(s1, s2);
            else return bigNumMinus(s2, s1);
        } else if (! symbol[0] && ! symbol[1]) {
            // 两者都为正
            if (bigger(s1, s2)) return bigNumMinus(s1, s2);
            else return "-" + bigNumMinus(s2, s1);
        } else {
            if (! symbol[0] && symbol[1]) return bigNumAdd(s1, s2);
            else return "-" + bigNumAdd(s1, s2);
        }
    }
};


#endif //INTERVIEW_PROGRAMMING_UGLY_PROBLEM_H
