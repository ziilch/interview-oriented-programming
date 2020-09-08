//
// Created by zorro on 2020/4/28.
//

#ifndef INTERVIEW_PROGRAMMING_NORMALALGORITHM_H
#define INTERVIEW_PROGRAMMING_NORMALALGORITHM_H

#include "../includes/base_include.h"
// LRU缓存机制
class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> ht;
    list<pair<int, int>> cache;
    int cap;
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        if (ht.find(key) == ht.end()) return -1;
        int val = ht[key]->second;
        cache.erase(ht[key]);
        cache.push_front({key, val});
        ht[key] = cache.begin();
        return val;
    }

    void put(int key, int value) {
        if (ht.find(key) != ht.end()) {
            cache.erase(ht[key]);
            cache.push_front({key, value});
            ht[key] = cache.begin();
        } else {
            if (cache.size() == cap) {
                ht.erase(cache.back().first);
                cache.pop_back();
                cache.push_front({key, value});
                ht[key] = cache.begin();
            } else {
                cache.push_front({key, value});
                ht[key] = cache.begin();
            }
        }
    }
};

// 设计hash映射
class MyHashMap {
public:
    /** Initialize your data structure here. */
    int help = 1023;
    vector<list<pair<int, int>>> sp = vector<list<pair<int, int>>> (help);
    MyHashMap() {
    }

    list<pair<int, int>>::iterator find (int key) {
        int loc = key % help;
        for (auto p = sp[loc].begin(); p != sp[loc].end(); p++) {
            if (p->first == key) return p;
        }
        return sp[loc].end();
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int loc = key % help;
        list<pair<int, int>>::iterator p = find(key);
        if (p == sp[loc].end()) sp[loc].push_back({key, value});
        else p->second = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int loc = key % help;
        list<pair<int, int>>::iterator p = find(key);
        if (p == sp[loc].end()) return -1;
        else return p->second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int loc = key % help;
        list<pair<int, int>>::iterator p = find(key);
        if (p != sp[loc].end()) sp[loc].erase(p);
    }
};

// 单例模式- 懒汉模式 在第一次使用的时候实例化
class LazySingleton
{
private:
    static LazySingleton* instance;
private:
    LazySingleton() {
        cout << "我是懒汉" << endl;
    };
    ~LazySingleton() {};
public:
    static LazySingleton* getInstance()
    {
        if(instance == NULL)
            instance = new LazySingleton();
        return instance;
    }
};
LazySingleton* LazySingleton::instance = NULL;



#endif //INTERVIEW_PROGRAMMING_NORMALALGORITHM_H
