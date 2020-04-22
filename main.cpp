//
// Created by zorro on 2020/4/20.
//

#include <iostream>
#include <algorithm>
#include "src/BinarySearch.hpp"
#include "src/SortMethod.hpp"
#include "src/SelfTest.hpp"
#include "src/SelfUtil.hpp"
#include "src/BinaryTree.hpp"

int main() {
    BinaryTree binaryTree;
    vector<int> v1 = {3,9,20,15,7}, v2 = {9,3,15,20,7};

    binaryTree.buildTree(v1, v2);
    return 0;
}

