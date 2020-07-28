## Chapter 2

> Disclosure: I didn't have a ARMv8 simulator at the time, so most of the assembly questions weren't tested. 

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

#### 2.5

The following lines:

```
ADDI    X11, X9, #8         // X11 = &a[f+1]
LDUR    X9, [X11, #0]       // X9 = A[f+1]
```

May be rewritten as:

```
LDUR    X9, [X9, #8]       // X9 = A[f+1]
```

#### 2.6

Big Endian: `ab cd ef 12`
Little Endian: `12 ef cd ab`

#### 2.7

0xabcdef12 = 2882400018

#### 2.8

```
LSL     X9, X3, #3      // X9 = i*8
ADD     X9, X6, X9      // X9 = &A[i]
LSL     X10, X4, #3     // X10 = j*8
ADD     X10, X6, X10     // X10 = &A[j]
LDUR    X9, [X9, 0]     // X9 = A[i]
LDUR    X10, [X10, 0]   // X10 = A[j]
ADD     X12, X9, X10    // X12 = A[i] + A[j]
STUR    X12, [X7, #64]  // B[8] = A[i] + A[j]
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
**2.11.6** There was no overflow in the first instruction.

#### 2.12

**2.12.1** From 9,223,372,036,854,775,680 to 9,223,372,036,854,775,807.
**2.12.2** From -9,223,372,036,854,775,680 to -9,223,372,036,854,775,808.
**2.12.3** From -9,223,372,036,854,775,681 to -9,223,372,036,854,775,808.

#### 2.13

| opcode      | Rm    | shamt | Rn    | Rd    |
| ----------- | ----- | ----- | ----- | ----- |
| 10001011000 | 00000 | 00000 | 00000 | 00000 |
| ADD         | X0    |       | X0    | X0    |

#### 2.14

| opcode      | Address   | op2 | Rn    | Rt    |
| ----------- | --------- | --- | ----- | ----- |
| STUR        | 32        |     | X10   | X9    |
| 11111000000 | 000100000 | 00  | 01010 | 01001 |

#### 2.15

op = `SUB` , R-format
Assembly Instruction:

```
SUB     X17, X15, X13
```

Binary Representation:

| opcode      | Rm    | shamt | Rn    | Rd    |
| ----------- | ----- | ----- | ----- | ----- |
| 11001011000 | 01101 | 00000 | 01111 | 10001 |
| SUB         | X13   | 0     | X15   | X17   |

#### 2.16

op = `LDUR` , D-format
Assembly Instruction:

```
LDUR     X3, [X12, #4]
```

Binary Representation:

| opcode      | Address   | op2 | Rn    | Rt    |
| ----------- | --------- | --- | ----- | ----- |
| LTUR        | 4         |     | X12   | X3    |
| 11111000010 | 000000100 | 00  | 10010 | 00011 |

#### 2.17

**2.17.1**

R-format:

| Language  | opcode  | Rm     | shamt  | Rn     | Rd     |
| --------- | ------- | ------ | ------ | ------ | ------ |
| LEGv8     | 11 bits | 5 bits | 6 bits | 5 bits | 5 bits |
| LEGv8_Ext | 13 bits | 7 bits | 6 bits | 7 bits | 7 bits |

**2.17.2**

I-format:

| Language  | opcode  | Immediate | Rn     | Rd     |
| --------- | ------- | --------- | ------ | ------ |
| LEGv8     | 11 bits | 11 bits   | 5 bits | 5 bits |
| LEGv8_Ext | 13 bits | 11 bits   | 7 bits | 7 bits |

**2.17.3**

With more space in the opcodes field, the language can comport a bigger sort of commands, opening space for more complex commands. Commands for multiplication and division, for example, could be implemented without a loop, thus reducing the size of the code. By the other hand, each command will increase at least in 2 more bits. All the original commands would have this increase in size as well. I overall, if the program have more native commands, the code will be bigger than the original (using the original LEGv8).

With more registers, it would be less need to overwrite the registers, and it could bring a smaller code. Similarly to what happens with the increase in the size if opcodes, the increase of the number of registers will increase the size of each command as well. So, if a program does not use more than 32 registers, it will necessarily be bigger to its equivalent program in native LEGv8.

#### 2.18

**2.18.1** 0X1234AAAAAAAA5678

```
LSL     X12, X10, #4        // X12 = 0X0000AAAAAAAA0000
ORR     X12, X12, X11       // X12 = 0X1234AAAAAAAA5678
```

**2.18.2** 0X5678123456780000
**2.18.3** 0X00000000000AAFEF

#### 2.20

```
EOR     X10, X11
```

#### 2.21

```
LDUR    X9, [X13, 0]        // X9 = C[0]
LSL     X10, X9, 4          // X10 = C[0] << 4
ADD     X11, X10, XZR       // X11 = X10  -> A = C[0] << 4
```

#### 2.22

The value in register `X1` is not changed.

#### 2.25

```
LOOP:   SUBIS   X1, X1, #0  // X1 == 0 ?
        B.LE    DONE        // Go to Done
        SUBI    X1, X1, #1  // X1 = X1 - 1
        ADDI    X0, X0, #2  // X0 = X0 + 2
        B LOOP
DONE:
```
 
**2.25.1**
At the end X1 = 0 and X0 = 20.

**2.25.2**
```c
acc = 0;
for(int i = 10; i > 0; i--){
    acc = acc + 2;
}
```

**2.25.3**
|N| num instructions |
|-|-|
|1|6|
|2|10|
|3|14|
|4|18|

`Num Inst = 4N + 2`

**2.25.4**

**2.25.5**

**2.25.6**
Check the conditional.

**2.25.7**
```
        ADDI    X1, X1, #1
LOOP:   SUBIS   X1, X1, #1  // --X1 == 0 ?
        B.LE    DONE        // Go to Done
        SUBI    X1, X1, #1  // X1 = X1 - 1
        ADDI    X0, X0, #2  // X0 = X0 + 2
        B LOOP
DONE:
```