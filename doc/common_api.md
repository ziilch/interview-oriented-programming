# c++需要记住的语法
1. int转string用to_string()函数。
2. vector<vector<int>> vec(m, vector<int>(n)): 生成一个m行n列的二维数组。
3. hash_table(ht)也就是unordered_map中找出是否存在元素x的api是find，判断是否有用find(x) == ht.end();
4. 单纯判断是否含有元素要使用unordered_set，插入元素用insert，find元素和上面类似。
5. vector函数具有pop_back功能且仅具有pop_back()。
6. stack只有push和pop，也就是永远都是先进先出。
7. 双端队列deque，dq具有push_back和push_front和pop_back和pop_front。
8. 堆priority_queue默认是大顶堆，priority_queue<int, std::vector<int>, std::greater<int>>可以定义小顶堆。