//
// Created by zorro on 2020/4/23.
//

#ifndef INTERVIEW_PROGRAMMING_BINARYTREE_H
#define INTERVIEW_PROGRAMMING_BINARYTREE_H

#include "../includes/BaseInclude.h"

class BinaryTree{
public:
    // M-L105-****
    // 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfsJ7(preorder, inorder);
    }

private:
    TreeNode* dfsJ7(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int pos = 0;
        while (inorder[pos] != preorder[0]) pos++;
        vector<int> nPre, nIn, mPre, mIn;
        for (int i = 1; i < pos + 1; i++) nPre.push_back(preorder[i]);
        for (int i = 0; i < pos; i++) nIn.push_back(inorder[i]);

        for (int i = pos + 1; i < preorder.size(); i++) mPre.push_back(preorder[i]);
        for (int i = pos + 1; i < preorder.size(); i++) mIn.push_back(inorder[i]);

        root->left = dfsJ7(nPre, nIn);
        root->right = dfsJ7(mPre, mIn);
        return root;
    }
};

#endif //INTERVIEW_PROGRAMMING_BINARYTREE_H
