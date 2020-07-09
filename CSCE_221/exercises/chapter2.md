# Chapter 2

There is no easy way to write math formulas in markdown. So, I'm skipping the first questions. 

#### 2.6

a) 2^ (2^(N-1))
b) 

#### 2.7

| Code # | Big-Oh | N=10 | N =100  | N = 1000 |
| ------ | ------ | ---- | ------- | -------- |
| 1      | O(N)   | 1us  | 10us    | 114us    |
| 2      | O(N^2) | 20us | 1008us  | 43764us  |
| 3      | O(N^3) | 93us | 49.9 ms | 34.84s   |
| 4      | O(N^2) | 6us  | 227us   | 15295us  |

| Code # | Big-Oh | N=10 | N =20 | N = 40 |
| ------ | ------ | ---- | ----- | ------ |
| 5      | O(N^5) | 1ms  | 16ms  | 266ms  |
| 6      | O(N^4) | 3us  | 0.2ms | 1.9ms  |

#### 2.9

| Input         | 1              | 2        | 3          | 4        |
| ------------- | -------------- | -------- | ---------- | -------- |
| Size          | O(N^3)         | O(N^2)   | O(N log N) | O(N)     |
| N = 100       | 0.000159       | 0.000006 | 0.000005   | 0.000002 |
| N = 1,000     | 0.095857       | 0.000371 | 0.000060   | 0.000022 |
| N = 10,000    | 86.67          | 0.033322 | 0.000619   | 0.000222 |
| N = 100,000   | **86670**      | 3.33     | 0.006700   | 0.002205 |
| N = 1,000,000 | **86670x10^5** | **333**  | 0.074870   | 0.022711 |

#### 2.10

a) Sum each of the N digits one by one: **O(N)**
b) Repeatedly sum each of the N digits(N times): **O(n^2)**
c) Same as multiply, but using subtraction instead of sum: **O(n^2)**

#### 2.11

a)2.5ms
b)3.375 ms
c)12.5 ms
d)62.5 ms

#### 2.12

a) 12000000
b) 
c) 34641
d) 4932

#### 2.13

a)N times to run all the itens in the Sum. N times to solve each one of the exponentiations. 
**O(N^2)**.
b)N times to run all the itens in the Sum. Log N times to solve the exponentiation. **O(NlogN)**.

#### 2.14

a) [code in python](./214,py)
```
('3 * ', 0, ' + ', 4) =
('3 * ', 4, ' + ', 8) =
('3 * ', 20, ' + ', 0) =
('3 * ', 60, ' + ', 1) = 
('3 * ', 181, ' + ', 2) = 545
```
b) This algorithm works optimizing the exponentiation task. As all the exponentiations have the same base (*x*), the algorithm run the list of elements doing all the multiplications in *a* just one time.
c) It will run over the list just one time, so it will run in **O(N)**.

#### 2.15 
Binary Search. Running time: **O(logN)**. [Code](./215.py)