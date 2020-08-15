//
// Created by zorro on 2020/4/1.
//

#ifndef INTERVIEW_PROGRAMMING_SORT_METHOD
#define INTERVIEW_PROGRAMMING_SORT_METHOD

#include "../includes/base_include.h"

class SortMethod {
public:
    void quickSort(vector<int> &arr) {
        dfsQuick(arr, 0, arr.size() - 1);
    }

    void mergeSort(vector<int>& arr) {
        dfsMerge(arr, 0, arr.size() - 1);
    }

    void heapSort(vector<int>& arr) {
        int len = arr.size();
        for (int i = len / 2 - 1; i >= 0; i--) maxHeapify(arr, i, len - 1);
        for (int i = len - 1; i > 0; --i) {
            maxHeapify(arr, 0, i);
            swap(arr[0], arr[i]);
        }
    }

private:

    void maxHeapify(vector<int>& arr, int l, int r) {
        int fa = l, son = 2 * l + 1;
        while (son <= r) {
            if (son + 1 <= r && arr[son] < arr[son + 1]) son++;
            if (arr[fa] >= arr[son]) return;
            swap(arr[fa], arr[son]);
            fa = son, son = 2 * fa + 1;
        }
    }

    void dfsQuick(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int l = left + 1, r = right;
        int val = arr[left];
        while (l < r) {
            while (arr[l] <= val && l < r) l++;
            while (arr[r] > val && l < r) r--;
            swap(arr[l], arr[r]);
        }
        if (arr[l] > val) l--;
        swap(arr[left], arr[l]);
        dfsQuick(arr, left, l - 1);
        dfsQuick(arr, l + 1, right);
    }

    void dfsMerge(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) >> 1;
        dfsMerge(arr, left, mid);
        dfsMerge(arr, mid + 1, right);
        mergeTwo(arr, left, mid, right);
    }

    void mergeTwo(vector<int>& arr, int left, int mid, int right) {
        vector<int> tmp;
        int p = mid + 1, l = left;
        while (l <= mid && p <= right) {
            if (arr[l] <= arr[p]) tmp.push_back(arr[l ++]);
            else tmp.push_back(arr[p ++]);
        }
        while (l <= mid) tmp.push_back(arr[l ++]);
        while (p <= right) tmp.push_back(arr[p ++]);
        for (auto v : tmp) arr[left ++] = v;
    }
};

#endif //INTERVIEW_PROGRAMMING_SORT_METHOD
