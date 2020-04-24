//
// Created by zorro on 2020/4/23.
//

#ifndef INTERVIEW_PROGRAMMING_BINARYTREE_H
#define INTERVIEW_PROGRAMMING_BINARYTREE_H

#include "../includes/BaseInclude.h"

// 九阳真经-树
// 树是一个天然递归的结构
// 做树问题的时候往往要想树的每一层需要做什么
// 然后想想怎么把每一层做的东西返回
// 最后形成一个新的结构
// 二叉树的题目最开始接触的时候会不知所云，挠头苦想
// 这个时候不要纠结，看看答案，在没有完全理解的时候也去做后面的题目
// 做多了，回头看，感觉就有了
// 再巩固一下，一般的题目就可以做出来了。

class BinaryTree{
public:
    // M-L105-****
    // 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfsL105(preorder, inorder);
    }

    // E-L226-****
    // 返回一个二叉树的镜像
    TreeNode* mirrorTree(TreeNode* root) {
        dfsL226(root);
        return root;
    }

    // E-L101-****
    // 判断一个二叉树是不是对称的
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return dfsL101(root->left, root->right);
    }

    // E-J54-***
    // 输出一颗二叉搜索树的第k大节点
    int kthLargest(TreeNode* root, int k) {
        int cnt = 1, res = 0;
        dfsJ54(root, cnt, k, res);
        return res;
    }

    // E-L104-****
    // 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // E-L110-***
    // 判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    // E-L235-**
    // 二叉搜索树的最近公共祖先
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        if (p->val < root->val && q->val < root->val) return lowestCommonAncestor1(root->left, p, q);
        else if (p->val > root->val && q->val > root->val) return lowestCommonAncestor1(root->right, p, q);
        else return root;
    }

    // M-L236-****
    // 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
    // 所有节点的值都是唯一的。p、q 为不同节点且均存在于给定的二叉树中。
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 假设这不是一个递归函数，我们怎么看待这个方法：
        // 前提：一定存在这样一个节点
        // left为p或者q其中一个的父节点
        // right为p或者q其中一个的父节点
        // 如果left为空 那么right一定就是需要的节点
        // 反之亦然
        // 如果left和right都不为空，说明这两个一个是左节点的父节点，一个是又节点的父节点，所以要返回root

        if (root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL) return right;
        if (right == NULL) return left;
        return root;
    }

    // M-J32-*****
    // 层次遍历二叉树
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        if (! root) return ans;
        queue<TreeNode*> level;
        level.push(root);
        while (! level.empty()) {
            queue<TreeNode*> temp;
            while (! level.empty()) {
                TreeNode* tmp = level.front();
                ans.push_back(tmp->val);
                level.pop();
                if (tmp->left) temp.push(tmp->left);
                if (tmp->right) temp.push(tmp->right);
            }
            level = temp;
        }
        return ans;
    }

    // M-J26-**
    // 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return dfsJ26(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

private:
    bool dfsJ26(TreeNode* A, TreeNode* B) {
        if (! B) return true;
        if (! A) return false;
        if (A->val == B->val) return dfsJ26(A->left, B->left) && dfsJ26(A->right, B->right);
        else return false;
    }

    void dfsJ54(TreeNode* root, int& cnt, int k, int& res) {
        if (root == NULL) return;
        dfsJ54(root->right, cnt, k, res);
        if (cnt++ == k) {
            res = root->val;
            return;
        }
        dfsJ54(root->left, cnt, k, res);
    }

    TreeNode* dfsL105(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int pos = 0;
        while (inorder[pos] != preorder[0]) pos++;
        vector<int> nPre, nIn, mPre, mIn;
        for (int i = 1; i < pos + 1; i++) nPre.push_back(preorder[i]);
        for (int i = 0; i < pos; i++) nIn.push_back(inorder[i]);

        for (int i = pos + 1; i < preorder.size(); i++) mPre.push_back(preorder[i]);
        for (int i = pos + 1; i < preorder.size(); i++) mIn.push_back(inorder[i]);

        root->left = dfsL105(nPre, nIn);
        root->right = dfsL105(mPre, mIn);
        return root;
    }

    void dfsL226(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        dfsL226(root->left);
        dfsL226(root->right);
    }

    bool dfsL101(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL || t2 == NULL)
            return (t1 == NULL && t2 == NULL);
        else
            if (t1->val == t2->val)
                return dfsL101(t1->left, t2->right) && dfsL101(t1->right, t2->left);
            else
                return false;
    }
};

#endif //INTERVIEW_PROGRAMMING_BINARYTREE_H
