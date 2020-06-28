# Computer Organization and Design ARM Edition: The Hardware Software Interface

Patterson, David A., and John L. Hennessy.

## Chapter 1

### 1.1 There are many. Laptops, wrist bands, embebed car systems, video-games....

### 1.2 The matches:

a. Performance via Pipelining;

b. Dependability via Redundancy;

c. Performance via Prediction;

d. Performance via Paralelism;

e. Hierarchy of Memories;

f. Make the common case fast;

g. Design for Moore's Law;

h. Use abstraction to simplify Design.

### 1.3 Compile --> Assemble --> Michine Language.

### 1.4:

a. npixels x 3 (R,G,B) = 1,280 x 1,024 X 3 = 3,932,160 bytes/frame.

b. 3,932,160 x 8 / 100 x (2^20) = 0.3 s

### 1.5:

a.
clock = clock cycles/ 1 second

CPI = clock cycles / 1 instruction

Instructions / second = clock x 1/CPI

(To simplify, since all of them are expressed in GHz and we have to compare them at the end, I will remove it from all)

P1 = 3 X (1 / 1.5) = 2

P2 = 2.5 / 1 = 2.5

P3 = 4/ 2.2 = 1.82

Thereforem P1 has the highest performance expressed in instructions per second.

b.

| Processor | Number of Cylces                | Number of Instructions            |
| --------- | ------------------------------- | --------------------------------- |
| P1        | (3 x 10^9) x 10 = 3 x 10^10     | (2 x 10^9) x 10 = 2 x 10^10       |
| P2        | (2.5 x 10^9) x 10 = 2.5 x 10^10 | (2.5 x 10^9) x 10 = 2.5 x 10^10   |
| P3        | (4 x 10^9) x 10 = 4 x 10^10     | (1.82 x 10^9) x 10 = 1.82 x 10^10 |

c.

CPI(P1) = 1.8, CPI(P2) = 1.2, CPI(P3) = 2.6
Clock Rate = (No. instr. x CPI)/time, then
P1 = (2 x 10^10 x 1.8/7) = 5.14 GHz
P2 = (2.5 x 10^10 x 1.2/7) = 4.28 GHz
P1 = (1.82 x 10^10 x 2.6/7) = 6.75 GHz

### 1.11:

**1.11.1** 0.9418
**1.11.2** 12.86
**1.11.3** 10%
**1.11.4** 1.1 x 1.05 = 1.155 = 15.5%
**1.11.5** new SPECratio = 0.86 = 14% decrease.
**1.11.6** 1.3879
**1.11.7** The CPI increased in 47.36%, while the clock rate increased in 33.33%. The instruction set had changed and the execution time as well, all those variables affects the CPI.
**1.11.8** 50s, or 6.66% decrease.
**1.11.9** 2146.58 x 10^9
**1.11.10** 3.6 Ghz

## Chapter 2

### 2.1

```
SUBI    X0, X2, 5
ADD     X0, X0, X1
```

### 2.2

```
f = i + g + h
```

### 2.3

```
SUBI    X0, X3, X4
LSL     X1, X0, 2
ADD     X6, X1, X6
LDUR    X2, [X6, 0]
STUR    X2, [X7 32]
```

### 2.4

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

### 2.9

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

### 2.10

| code                 | type   | opcode | Rn  | Rd  | Rt  | immediate |
| -------------------- | ------ | ------ | --- | --- | --- | --------- |
| `ADDI X9, X6, #8`    | I-type | 580    | 6   | 9   | -   | 8         |
| `ADD X10, X6, XZR`   | R-type | 1112   | 6   | 10  | 31  | -         |
| `STUR X10, [X9, #0]` | D-type | 1984   | 9   | -   | 10  | 0         |
| `LDUR X9, [X9, #0]`  | D-type | 1986   | 9   | -   | 9   | 0         |
| `ADD X0, X9, X10`    | R-type | 1112   | 9   | 0   | 10  | -         |

### 2.11

**2.11.1** 0X5000000000000000
**2.11.2** There was an overflow.
**2.11.3** 0X5000000000000000
**2.11.4** There was no overflow.
**2.11.5** 0XD000000000000000.
**2.11.6** There was no overflow in ther first instruction.

### 2.18

**2.18.1** 0X1234AAAAAAAA5678
```
LSL     X12, X10, #4        // X12 = 0X0000AAAAAAAA0000
ORR     X12, X12, X11       // X12 = 0X1234AAAAAAAA5678 
```
 **2.18.2** 0X5678123456780000
 **2.18.3** 0X00000000000AAFEF


### 2.21
```
LDUR    X9, [X13, 0]        // X9 = C[0]
LSL     X10, X9, 4          // X10 = C[0] << 4
ADD     X11, X10, XZR       // X11 = X10  -> A = C[0] << 4