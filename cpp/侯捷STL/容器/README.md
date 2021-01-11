# 容器

## 容器分类
1. 寻序式容器: Array, Vector, Deque, List, Forward-List
  * Array: 数组连续不可增长，定义的时候必须给出数组长度
  * Vector: 单项可增长,空间不够时候分配器件会自动扩充(2倍增长)
  * Deque: 双向队列,两端可进可出
  * List: 链表双向链表,每个节点带有两个字节(连个指针)
  * Forward: 单向链表,每个节点带有一个字节(一个指针)

2. 关联式容器: Set(不可重复)/Multiset(可重复), Map(不可重复)/Multimap(可重复), Unordered(不定性) Set/Multiset, Unordered(不定性) Map/Multima
  * map: STL用高度平衡红黑树实现, map包含key和value
  * set: STL用高度平衡红黑树实现, set的key就是value
  * Unordered map: 底部用Hash_table实现
  * Unordered set: 底部用Hash_table实现

  > hash_map和map的区别:
  > 1. 构造函数: hash_map构造时候需要hash函数和等于函数, map只需要比较函数
  > 2. 存储结构: hash_map是利用hash表存储, map是利用红黑树．
  > 什么时候用hash_map及什么时候使用map:
  > 总体来说hash_map[O(n)]的查找速度比map[O(longn)]快,如果考虑效率的话推荐使用hash_map,如果考虑内存的话建议使用map,因为hash_map构造起来比较慢.