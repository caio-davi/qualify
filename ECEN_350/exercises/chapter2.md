## Chapter 2

#### 2.1

```
SUBI    X0, X2, 5
ADD     X0, X0, X1
```

#### 2.2

```
f = i + g + h
```

#### 2.3

```
SUBI    X0, X3, X4
LSL     X1, X0, 2
ADD     X6, X1, X6
LDUR    X2, [X6, 0]
STUR    X2, [X7 32]
```

#### 2.4

```
ADDI    X11, X9, #8         // X11 = &a[f+1]
LDUR    X9, [X11, #0]       // X9 = A[f+1]
ADD     X9, X9, X0          // X9 = A[f] + A[f+1]
STUR    X9, [X10, #0]       // f = A[f]
```

In C:

```C
B[g] = A[f] + A[f+1]
```

#### 2.9

```
ADDI    X9, X6, #8          // X9 = &A[1]
ADD     X10, X6, XZR        // X10 = &A[0]
STUR    X10, [X9, #0]       // A[1] = &A[0]
LDUR    X9, [X9, #0]        // X9 = &A[0]
ADD     X0, X9, X10         // f = &A[0] + &A[0]
```

In C:

```C
A[1]=&A[0]
f = &A[0] + &A[0]
```

#### 2.10

| code                 | type   | opcode | Rn  | Rd  | Rt  | immediate |
| -------------------- | ------ | ------ | --- | --- | --- | --------- |
| `ADDI X9, X6, #8`    | I-type | 580    | 6   | 9   | -   | 8         |
| `ADD X10, X6, XZR`   | R-type | 1112   | 6   | 10  | 31  | -         |
| `STUR X10, [X9, #0]` | D-type | 1984   | 9   | -   | 10  | 0         |
| `LDUR X9, [X9, #0]`  | D-type | 1986   | 9   | -   | 9   | 0         |
| `ADD X0, X9, X10`    | R-type | 1112   | 9   | 0   | 10  | -         |

#### 2.11

**2.11.1** 0X5000000000000000
**2.11.2** There was an overflow.
**2.11.3** 0X5000000000000000
**2.11.4** There was no overflow.
**2.11.5** 0XD000000000000000.
**2.11.6** There was no overflow in ther first instruction.

#### 2.18

**2.18.1** 0X1234AAAAAAAA5678

```
LSL     X12, X10, #4        // X12 = 0X0000AAAAAAAA0000
ORR     X12, X12, X11       // X12 = 0X1234AAAAAAAA5678 
```

 **2.18.2** 0X5678123456780000
 **2.18.3** 0X00000000000AAFEF


#### 2.21
```
LDUR    X9, [X13, 0]        // X9 = C[0]
LSL     X10, X9, 4          // X10 = C[0] << 4
ADD     X11, X10, XZR       // X11 = X10  -> A = C[0] << 4
```
