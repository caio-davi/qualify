# Chapter 4



#### 4.1 to 4.7
*Component Design*

#### 4.8

To avoid draw in markdown, I'm listing the values in the folloing tables:

| CLOCK 1 | Ci  | A   | B   | Co  | S     |
| ------- | --- | --- | --- | --- | ----- |
|         |     | 1   | 1   | 1   | **0** |
|         | 1   | 1   | 1   | 0   | 0     |
|         |     | 1   | 0   | 1   | 1     |
|         |     | 0   | 0   | 0   | 0     |

| CLOCK 2 | Ci  | A   | B   | Co  | S     |
| ------- | --- | --- | --- | --- | ----- |
|         |     | 1   | 1   | 1   | **0** |
|         | 1   | 1   | 1   | 1   | **1** |
|         |     | 1   | 0   | 0   | 0     |
|         | 1   | 0   | 0   | 0   | 1     |

| CLOCK 3 | Ci  | A   | B   | Co  | S     |
| ------- | --- | --- | --- | --- | ----- |
|         |     | 1   | 1   | 1   | **0** |
|         | 1   | 1   | 1   | 1   | **1** |
|         | 1   | 1   | 0   | 1   | **0** |
|         | 1   | 0   | 0   | 0   | **1** |

#### 4.9
15ns. It will need 7 full-adders and a half-adder. Each full-adder will spend 2 gate-delays and the half-adder has just one gate-delay. 

#### 4.10

24ns. Same logic of the previous question, but now both half-adders and full-adders will have a 3ns delay. 

#### 4.11
*Component Design*


#### 4.28 

(a) 15
(b) 0
(c) -127
(d) -1
(e) -107