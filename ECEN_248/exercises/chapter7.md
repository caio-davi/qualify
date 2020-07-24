# Chapter 7

#### 7.1

While full-custom ICs require a lot of time to have their layout design created before production. Gate arrays IC are chips whose transistors are predesigned, meaning that only the wires remain to be fabricated. This shortens the production time since only the very last steps of fabrication are made.

#### 7.2

Because gate arrays implemented using NAND/NOR gates are more efficient than those implemented using AND/OR/NOT. Also, the NAND gate is a universal gate, which means any boolean circuit can be implemented using only it.

#### 7.3

![](./images/73.png)

I'm jumping some question, my major interest in this chapter are FPGAs.

#### 7.18

Truth Table:
| a | b | c | F(a,b,c) |
| --- | --- | --- | -------- |
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |

The implementation is a simple single access to the memory array containing the outputs in the truth table.

#### 7.19

**LUP1 d1** --> implementing: `ab*1`| inputs: a b 1 | output: d1
**LUP1 d0** --> Not used.
**LUP2 d1** --> implementing: `d1 + cd`| inputs: a b d1 | output: d1
**LUP2 d0** --> Not used.
| LUP1 d1 | LUP1 d0 | | LUP2 d1 | LUP2 d0 |
| ------- | ------- | --- | ------- | ------- |
| 0 | _0_ | | 0 | _0_ |
| 0 | _0_ | | 0 | _0_ |
| 0 | _0_ | | 0 | _0_ |
| 1 | _0_ | | 1 | _0_ |
| 0 | _0_ | | 1 | _0_ |
| 0 | _0_ | | 1 | _0_ |
| 0 | _0_ | | 1 | _0_ |
| 1 | _0_ | | 1 | _0_ |

#### 7.20

```
F(a,b,c,d) = a'bd + b'cd'
F(a,b,c,d) = a'bd + (b'd' * c)
```

**LUP1 d1** --> implementing: `a'bd`| inputs: a b d | output: d1
**LUP1 d0** --> implementing: `b'd'`| inputs: a b | output: d0
**LUP2 d1** --> implementing: `d1 + (d0c)` | inputs: d1, d0, c | output: d1 (F)
**LUP2 d0** --> Not used.

| LUP1 d1 | LUP1 d0 |     | LUP2 d1 | LUP2 d0 |
| ------- | ------- | --- | ------- | ------- |
| 0       | 1       |     | 0       | _0_     |
| 0       | 0       |     | 0       | _0_     |
| 0       | 0       |     | 0       | _0_     |
| 1       | 0       |     | 1       | _0_     |
| 0       | 1       |     | 1       | _0_     |
| 0       | 0       |     | 1       | _0_     |
| 0       | 0       |     | 1       | _0_     |
| 0       | 0       |     | 1       | _0_     |

#### 7.21

```
F(x,y,z) = x'y + xyz'
G(w,x,y,z) = w'x'y + w'xyz'
G(w,x,y,z) = w' (x'y + xyz')
```

**LUP1 d1** --> implementing: `x'y'`| inputs: w y z | output: d1
**LUP1 d0** --> implementing: `xyz'`| inputs: a b | output: d0
**LUP2 d1** --> implementing: `(d1 + d0)` | inputs: d1, d0, w | output: d1 (F)
**LUP2 d0** --> implementing: `w' (d1 + d0)` | inputs: d1, d0, c | output: d1 (G)

| LUP1 d1 | LUP1 d0 |     | LUP2 d1 | LUP2 d0 |
| ------- | ------- | --- | ------- | ------- |
| 0       | 0       |     | 0       | 0       |
| 0       | 0       |     | 0       | 0       |
| 1       | 0       |     | 1       | 1       |
| 1       | 0       |     | 1       | 0       |
| 0       | 0       |     | 1       | 1       |
| 0       | 0       |     | 1       | 0       |
| 0       | 1       |     | 1       | 1       |
| 0       | 1       |     | 1       | 0       |
