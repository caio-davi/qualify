## Chapter 4

#### 4.1

**4.1.1**
|RegWrite | ALUSrc | AluOP | MemWrite | MemRead | MemtoReg |
|-|-|-|-|-|-|
|1|0|0000|0|0|0|

**4.1.2** All of them, except to Data Memory.
**4.1.3** All outputs are used.

#### 4.2

`LDUR` doesn't use a second register, that's why Reg2Loc is marked as "don't care". MemtoReg is irrelevant when the RegWrite signal is 0 (the register is not being written, so the value on the register isn't used), which is the reason for the don't cares of instructions `STUR` and `CBZ`.

#### 4.3

**4.3.1** 35%
**4.3.2** 100%
**4.3.3** 76%
**4.3.4** Sign extend works as usual, but his output is ignored.

#### 4.4

**4.4.1** LDUR
**4.4.2** LDUR and STUR
**4.4.2** STUR and CBZ

#### 4.5

**4.5.1**

```
0xf8014062 = 1111 1000 000 0 0001 0100 0000 0110 0010

1111 1000 000 => STUR
0 0001 0100 => Data Memory

To 64bits:
0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 0100

Shift 2:
0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0101 0000
```

**4.5.2**
ALU control for STUR is `0010`

**4.5.3**

PC_new = PC + 4

Data path to update PC:
PC -> Adder -> MUX -> PC

**4.5.4**

| MUX      | Control | Input 1 | Input 2          | Output |
| -------- | ------- | ------- | ---------------- | ------ |
| Reg2Loc  | 1       | 00001   | 00010            | 00010  |
| ALUSrc   | 1       | 00010   | 0x50             | 0x50   |
| Branch   | 0       | PC+4    | Add(SIGN-Extend) | PC+4   |
| MemToReg | -       | -       | -                | -      |

**4.5.5**

|       | Input 1 | Input 2 |
| ----- | ------- | ------- |
| ALU   | 00011   | 0x50    |
| ADD 1 | PC      | 4       |
| ADD 2 | PC      | 0x50    |

**4.5.6**
Register 1 -> 00011
Register 2 -> 00010
Write Register -> 00010
Write Data -> Don't care

#### 4.6

**4.6.1**
There is no need for additional logic blocks.

**4.6.2**

| Output   | ADDI |
| -------- | ---- |
| Reg2Loc  | x    |
| ALUSrc   | 1    |
| MemToReg | 0    |
| RegWrite | 1    |
| Branch   | 0    |
| ALUOp1   | 0    |
| ALUOp2   | 0    |

#### 4.7

**4.7.1**
Just need to chack if the opcode is for an R-type instruction.

**4.7.2**
Following the critical path:

```
Register Read =      30 ps
I-Mem =             250 ps
Control =            50 ps
3 Mux =              75 ps
Register File =     150 ps
ALU =               200 ps
Register Setup =     20 ps
                    ------
                    775 ps
```

**4.7.3**
Following the critical path:

```
Register Read =      30 ps
I-Mem =             250 ps
Control =            50 ps
2 Mux =              50 ps
Register File =     150 ps
ALU =               200 ps
D-Mem =             250 ps
Register Setup =     20 ps
                    ------
                    1000 ps
```

**4.7.4**
Following the critical path:

```
Register Read =      30 ps
I-Mem =             250 ps
Control =            50 ps
2 Mux =              50 ps
Register File =     150 ps
ALU =               200 ps
Register Setup =     20 ps
                    ------
                    750 ps
```

**4.7.5**
Following the critical path:

```
Register Read =      30 ps
I-Mem =             250 ps
Control =            50 ps
2 Mux =              50 ps
Register File =     150 ps
ALU =               200 ps
Register Setup =     20 ps
                    ------
                    730 ps
```

**4.7.6**
Following the critical path:

```
Register Read =      30 ps
I-Mem =             250 ps
Control =            50 ps
Adder =             150 ps
1 Mux =              25 ps
Register Setup =     20 ps
                    ------
                    525 ps
```

**4.7.7**
Following the critical path:

```
Register Read =      30 ps
I-Mem =             250 ps
Control =            50 ps
3 Mux =              75 ps
Register File =     150 ps
ALU =               200 ps
Register Setup =     20 ps
                    ------
                    775 ps
```

**4.7.8**
The latency of the longest datapath, 1000 ps.

#### 4.8

Make LDUR instructions faster, they are the slowest one and are present in 25% of the time.

#### 4.16

**4.16.1**
With pipeline: 350 ps.
Without pipeline: 1250 ps.

**4.16.2**
1250 ps for both of them.

**4.16.3**
I would split `ID` and the new clock would be 300 ps.

**4.16.4**
35%

**4.16.5**
65%

#### 4.17

`n*k+(k-1)`
After `n*k` cycles the last instruction will enter in the pipeline, than it will be necessary more `k-1` cycles to finish the execution.

#### 4.18

| Instruction        | CC1  | CC2  | CC3  | CC4   | CC5   | CC6   | CC7  | CC8 | CC9 |
| ------------------ | ---- | ---- | ---- | ----- | ----- | ----- | ---- | --- | --- |
| `ADDI X1, X2, #5`  | `IF` | `ID` | `EX` | `MEM` | `WB`  |
| `ADD X3, X1, X2`   |      | `IF` | `ID` | `EX`  | `MEM` | `WB`  |
| `ADDI X4, X1, #15` |      |      | `IF` | `ID`  | `EX`  | `MEM` | `WB` |

```
ADDI        X1, X2, #5
ADD         X3, X1, X2          // X1 = 11
ADDI        X4, X1, #15         // X1 = 11
```

`X3 = 33` and `X4 = 27`.

#### 4.19

| Instruction        | CC1  | CC2  | CC3  | CC4   | CC5   | CC6   | CC7   | CC8  | CC9 |
| ------------------ | ---- | ---- | ---- | ----- | ----- | ----- | ----- | ---- | --- |
| `ADDI X1, X2, #5`  | `IF` | `ID` | `EX` | `MEM` | `WB`  |
| `ADD X3, X1, X2`   |      | `IF` | `ID` | `EX`  | `MEM` | `WB`  |
| `ADDI X4, X1, #15` |      |      | `IF` | `ID`  | `EX`  | `MEM` | `WB`  |
| `ADD X5, X1, X1`   |      |      |      | `IF`  | `ID`  | `EX`  | `MEM` | `WB` |

```
ADDI        X1, X2, #5
ADD         X3, X1, X2          // X1 = 11
ADDI        X4, X1, #15         // X1 = 11
ADD         X5, X1, X1          // X1 = 25
```

`X5 = 50`

#### 4.20

| Instruction        | CC1  | CC2   | CC3   | CC4   | CC5   | CC6   | CC7   | CC8   | CC9   | CC10  | CC11 | CC12 | CC13  | CC14 |
| ------------------ | ---- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ---- | ---- | ----- | ---- |
| `ADDI X1, X2, #5`  | `IF` | `ID`  | `EX`  | `MEM` | `WB`  |
| `ADD X3, X1, X2`   |      | `NOP` | `NOP` | `IF`  | `ID`  | `EX`  | `MEM` | `WB`  |
| `ADDI X4, X1, #15` |      |       | `NOP` | `NOP` | `NOP` | `NOP` | `IF`  | `ID`  | `EX`  | `MEM` | `WB` |
| `ADD X5, X1, X1`   |      |       |       | `NOP` | `NOP` | `NOP` | `NOP` | `NOP` | `NOP` | `IF`  | `ID` | `EX` | `MEM` | `WB` |


#### 4.21

**4.21.1** 
Without Forwarding hardware: `(n + (n * 0.4)) * 250 = 250 * 1.4n = 350n`
With Forwarding hardware: `(n + (n * 0.05)) * 300 = 300 * 1.05n = 315n`
It will run 0.9x faster. 

**4.21.2** 
```
(n + (n * X)) * 250 = (n + (n * 0.05)) * 300      // x is the amount to both have the same time 
250n + 250nx = 315n
x = 0.26
```
26%, after that it will run slower. 

**4.21.3**
```
(n + (n * y)) * 250 = (n + (n * x)) * 300      // x is the amount to both have the same time 
250n + 250ny = 300n + 300nx
y = (5+30x)/25
```

**4.21.4**
Without Forwarding hardware: `(n + (n * 0.4)) * 250 = 250 * 1.4n = 350n`
With Forwarding hardware: `(n + (n * 0.075)) * 300 = 300 * 1.075n = 322.5n`
Yes, it still runs faster. 


**4.21.5**
```
(n + (n * 0.4)) * 250 = (n + (n * x)) * 300      // x is the amount to both have the same time 
350n = 300n + 300nx
x = 50/300
x = 0.16
```
16%
