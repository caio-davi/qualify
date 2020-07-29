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