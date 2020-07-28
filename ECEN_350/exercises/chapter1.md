## Chapter 1

#### 1.1

There are many. Laptops, wrist bands, embedded car systems, video-games...

#### 1.2

The matches:

**a.** Performance via Pipelining;
**b.** Dependability via Redundancy;
**c.** Performance via Prediction;
**d.** Performance via Paralelism;
**e.** Hierarchy of Memories;
**f.** Make the common case fast;
**g.** Design for Moore's Law;
**h.** Use abstraction to simplify Design.

#### 1.3

Compile --> Assemble --> Michine Language.

#### 1.4

**a.** npixels x 3 (R,G,B) = 1,280 x 1,024 X 3 = 3,932,160 bytes/frame.
**b.** 3,932,160 x 8 / 100 x (2^20) = 0.3 s

#### 1.5

**a.**
clock = clock cycles/ 1 second

CPI = clock cycles / 1 instruction

Instructions / second = clock x 1/CPI

(To simplify, since all of them are expressed in GHz and we have to compare them at the end, I will remove it from all)

P1 = 3 X (1 / 1.5) = 2

P2 = 2.5 / 1 = 2.5

P3 = 4/ 2.2 = 1.82

Thereforem P2 has the highest performance expressed in instructions per second.

**b.**

| Processor | Number of Cylces                | Number of Instructions            |
| --------- | ------------------------------- | --------------------------------- |
| P1        | (3 x 10^9) x 10 = 3 x 10^10     | (2 x 10^9) x 10 = 2 x 10^10       |
| P2        | (2.5 x 10^9) x 10 = 2.5 x 10^10 | (2.5 x 10^9) x 10 = 2.5 x 10^10   |
| P3        | (4 x 10^9) x 10 = 4 x 10^10     | (1.82 x 10^9) x 10 = 1.82 x 10^10 |

**c.**

CPI(P1) = 1.8, CPI(P2) = 1.2, CPI(P3) = 2.6
Clock Rate = (No. instr. x CPI)/time, then
P1 = (2 x 10^10 x 1.8/7) = 5.14 GHz
P2 = (2.5 x 10^10 x 1.2/7) = 4.28 GHz
P1 = (1.82 x 10^10 x 2.6/7) = 6.75 GHz

#### 1.6

|     | Clk  | A   | B   | C   | D   |
| --- | ---- | --- | --- | --- | --- |
| P1  | 2GHZ | 1   | 2   | 3   | 3   |
| P2  | 3GHz | 2   | 2   | 2   | 2   |

Program:
| Class | % |
| ----- | --- |
| A | 10% |
| B | 20% |
| C | 50% |
| D | 20% |

**a.**
P1:
(1*10 + 2*20 + 3*50 + 3*20) / 100 = **2.6**

P2:
(2*10 + 2*20 + 2*50 + 2*20) / 100 = **2**

**b.**

`num Clk cycles = CPI * (num Instructions)`.
So it will be `2.6*numInstuctions` for P1 and `2*numInstrunctions` for P2.

#### 1.7

| Compiler   | A   | B     |
| ---------- | --- | ----- |
| `numInst`  | 1E9 | 1.2E9 |
| `execTime` | 1.1 | 1.5   |

**a.**
```
CPU Time = numInst * CPI * clock cycle
CPI = CPU Time / (numInst * clock cycle)

CPI_A = 1.1 / 10^9 * 1 *10^(-9)
CPI_A = 1.1

CPI_B = 1.5 / 1.2 * 10^9 * 10^(-9)
CPI_B = 1.25
```

**b.**
```
(numInst_A * CPI_A) * Clk_A = (numInst_B * CPI_B) * Clk_B
(1 * 1.1) * Clk_A = (1.2 * 1.25) * Clk_B
Clk_A = 1.36 * Clk_B
```

***c.**
```
excTime_C = 6 * 10^8 * 1.1 * 1 * 10^(-9)
excTime_C = 0.66 
```
The new compiler's program will run in 0.66 seconds, 1.67 faster than compiler A and 2.27 faster than compiler B.


#### 1.8

```
Cload = (2 * dynamicPower) / (voltage^2 * frequency)
```

**a.**
For the Pentium 4:
```
Cload = (2*90)/(1.25^2 * 3.6 * 10^6)  
Cload = 3.2 * 10^-8  
```
For the i5:
```
Cload = (2*40)/(0.9^2 * 3.4 * 10^6)  
Cload = 2.9 * 10^-8  
```

#### 1.11.1
 0.9418
#### 1.11.2
 12.86
#### 1.11.3
 10%
#### 1.11.4
 1.1 x 1.05 = 1.155 = 15.5%
#### 1.11.5
 new SPECratio = 0.86 = 14% decrease.
#### 1.11.6
 1.3879
#### 1.11.7
 The CPI increased in 47.36%, while the clock rate increased in 33.33%. The instruction set had changed and the execution time as well, all those variables affects the CPI.
#### 1.11.8
 50s, or 6.66% decrease.
#### 1.11.9
 2146.58 x 10^9
#### 1.11.10
 3.6 Ghz


#### 1.12.1

| | P1 | P2 | 
|- | -| -| 
Clock| 4Ghz | 3GHz |
CPI | 0.9 | 0.75 |
Num Instructions | 5 * 10^9 | 1 * 10^9

```
CPU Time = (numInst * CPI)/ clock rate

time_P1 = (5 * 10^9 * 0.9 )/ 7 *10^9
time_P1 = 1.125 s

time_P2 = (*0^9 * 0.75) / 3 * 10^9
time_P2 = 0.25 s
```

This is false, **P2** has a better performance.

#### 1.12.2

```
clkCycles = CPI * numInstructions

clkCycles_P1 = 0.9 * 1 * 10^9
clkCycles_P1 = 0.9 * 10^9

numInst_P2 = (0.9 * 10^9) / 0.75
numInst_P2 = (0.9 * 10^9) / 0.75
numInst_P2 = 1.2 * 10^9

```

#### 1.12.3

P1 clock rate = 4GHz -> 4 * 10^9 clocks cycles per second
P2 clock rate = 3GHz -> 3 * 10^9 clocks cycles per second

```
4*10^9 = 0.9 * numInst_P1
num_InstP1 = 4.4 * 10^9
num_InstP1 = 4400 MIPS

3*10^9 = 0.75 * numInst_P1
num_InstP2 = 4 * 10^9
num_InstP2 = 4000 MIPS
```

False, as well. As we had saw in the exercise **1.12.2**, P2 has better performance, although P1 has a larger MIPS. 

#### 1.12.4

```
num_InstP1 = 4.4 * 10^9
MFLOPS_P1 = (0.4 * 4.4*10^9) / (1 * 10^6)
MFLOPS_P1 = 1760

num_InstP2 = 4 * 10^9
MFLOPS_P2 = (0.4 * 4*10^9) / (1*10^6)
MFLOPS_P2 = 1600
```