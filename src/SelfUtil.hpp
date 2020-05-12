//
// Created by zorro on 2020/4/21.
//
#ifndef INTERVIEW_PROGRAMMING_SELF_UTIL
#define INTERVIEW_PROGRAMMING_SELF_UTIL

#include "../includes/BaseInclude.h"

class SelfUtil{
public:
    // 生成随机数组，默认数组大小为10000，数组内数据在10000以内
    static vector<int> createRandom(const int valNum = 10000, const int valRange = 10000) {
        vector<int> array(valNum);
        for(int i = 0; i < valNum; ++i) array[i] = (rand() % valRange);
        return array;
    }

    // "1,2,3,45" --> 1->2->3->45
    static ListNode* listNodeFromString (const string ss) {
        if (ss.empty())
            return NULL;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        string tmp = "";
        for (int i = 0; i < ss.size(); i++) {
            if (ss[i] == ',') {
                cur->next = new ListNode(atoi(tmp.c_str()));
                cur = cur->next;
                tmp = "";
            } else {
                tmp += ss[i];
            }
        }
        cur->next = new ListNode(atoi(tmp.c_str()));
        cur = cur->next;
        cur->next = NULL;
        return res->next;
    }

    template<typename T>
    static void printVec(vector<T> vec) {
        if (vec.empty()) return;
        for (int i = 0; i < vec.size(); i ++) cout << vec[i] << " ";
        cout << endl;
    }

    string serialize(TreeNode* root) {
        deque<TreeNode*> dq;

        dq.push_back(root);
        string res = "[";
        string ss = "";
        bool nl;
        while (! dq.empty()) {
            deque<TreeNode*> dq1;
            nl = true;
            ss = "";
            while (! dq.empty()) {
                TreeNode* node = dq.front();
                if (node) {
                    ss = ss + to_string(node->val) + ',';
                    dq1.push_back(node->left);
                    dq1.push_back(node->right);
                    nl = false;
                } else {
                    ss = ss + "null,";
                    dq1.push_back(NULL);
                    dq1.push_back(NULL);
                }
                dq.pop_front();
            }
            if (nl) break;

            res += ss;
            //cout << res << endl;
            dq = dq1;
        }
        res[res.size() - 1] = ']';
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<vector<string>> des = split(data);
        vector<TreeNode*> l1;
        TreeNode* root = new TreeNode(atoi(des[0][0].c_str()));
        l1.push_back(root);

        int p = 1;
        while (p < des.size()) {
            vector<TreeNode*> l2;
            for (int i = 0; i < des[p].size(); i ++) {
                if (des[p][i] == "null") l2.push_back(NULL);
                else l2.push_back(new TreeNode(atoi(des[p][i].c_str())));
            }
            for (int i = 0; i < l1.size(); i ++) {
                l1[i]->left = l2[2 * i];
                l1[i]->right = l2[2 * i + 1];
            }
            p ++;
            l1 = l2;
        }
        return root;
    }

    vector<vector<string>> split(string ss) {
        string s = ss.substr(1, ss.size() - 2);
        int p = 0;
        vector<string> res;
        while (p < s.size()) {
            string path = "";
            while (s[p] != ',' && p < s.size()) {
                path += s[p ++];
            }
            res.push_back(path);
            p ++;
        }
        int sum = 0, cur = 0;
        p = 1;
        vector<vector<string>> ans;
        while (sum < res.size()) {
            sum += p;
            vector<string> path;
            for (; cur < sum; cur ++) {
                path.push_back(res[cur]);
            }
            ans.push_back(path);
            p *= 2;
        }
        return ans;
    }
};

#endif //INTERVIEW_PROGRAMMING_SELF_UTIL