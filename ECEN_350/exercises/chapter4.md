## Chapter 4

#### 4.1

**4.1.1** 
|RegWrite | ALUSrc | AluOP | MemWrite | MemRead | MemtoReg |
|-|-|-|-|-|-|
|0|0|0000|0|0|1|

**4.1.2** All of them, except to Data Memory.
**4.1.3** All outputs are used. 

#### 4.2 

`LDUR` doesn't use a second register, that's why Reg2Loc is marked as "don't care". MemtoReg is irrelevant when the RegWrite signal is 0 (the register is not being writen, so the value on the register isn't used), which is the reason for the don't cares of instructions `STUR` and `CBZ`. 

#### 4.3

**4.3.1** 35%
**4.3.2** 98%
**4.3.3** 13%
**4.3.4** Sign extend works as usual, but his output is ignored. 

#### 4.4 
