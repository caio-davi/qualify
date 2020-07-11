# Chapter 5

#### 5.1

(The (code)[./53.py] for exercise 5.3 may be used to verify those results)
a)

|     |                        |
| --- | ---------------------- |
| 0   |                        |
| 1   | 4371 -->               |
| 2   |                        |
| 3   | 6173 --> 1323          |
| 4   | 4344                   |
| 5   |                        |
| 6   |                        |
| 7   |                        |
| 8   |                        |
| 9   | 1989 --> 9679 --> 4199 |

b)

|     |      |
| --- | ---- |
| 0   | 9679 |
| 1   | 4371 |
| 2   | 1989 |
| 3   | 1323 |
| 4   | 6173 |
| 5   | 4344 |
| 6   |      |
| 7   |      |
| 8   |      |
| 9   | 4199 |

c)

|     |      |
| --- | ---- |
| 0   | 9679 |
| 1   | 4371 |
| 2   |      |
| 3   | 1323 |
| 4   | 6173 |
| 5   | 4344 |
| 6   |      |
| 7   |      |
| 8   | 1989 |
| 9   | 4199 |

d)

|     |      |
| --- | ---- |
| 0   | 9679 |
| 1   | 4371 |
| 2   |      |
| 3   | 1323 |
| 4   | 6173 |
| 5   | 4344 |
| 6   |      |
| 7   |      |
| 8   | 1989 |
| 9   | 4199 |

#### 5.2

We can use [this code](./53.py) to rehash the tables of the last question. There is the rehashing for linear probing using `table_size = 13`:

|     |      |
| --- | ---- |
| 0   | 1989 |
| 1   | 4199 |
| 2   | 4344 |
| 3   | 4371 |
| 4   |      |
| 5   |      |
| 6   |      |
| 7   | 9679 |
| 8   |      |
| 9   |      |
| 10  | 1323 |
| 11  | 6173 |
| 12  |      |

#### 5.3

[Code](./53.py).
All coding considering table_size = 10 \* N.

| Array Size | Linear Probing | Quadratic Probing | Double Hashing |
| ---------- | -------------- | ----------------- | -------------- |
| 10         | 14             | 7                 | 3              |
| 100        | 424            | 133               | 117            |
| 1000       | 12896          | 2101              | 2011           |

#### 5.4
Assuming a table size `N` and `e` elements on it, and a threshould `t`, such `t = e/N` would require a rehash, therefore `e = t*N`. After a rehash, the reduced table have a size `RN = N/2`, with the same number `e` elements. This new table would need `2*RN` elements to do a incresing rehash, wich means `2RN-e` insertions, or `N-tN`. By definition, `t` is the ratio needed to a new rehash, so it would need delete `e = tN` elements to have a new decreasing rehash. In order to optimize the hashtable, we should make the number of insertions equal to the number of deletions. So `N-tN = tN`, which leads to **`t=1/2`**.