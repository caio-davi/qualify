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

| Processor | Number of Cylces | Number of Instructions |
|----------|------------------|------------------------|
| P1 | (3 x 10^9) x 10 = 3 x 10^10 | (2 x 10^9) x 10 = 2 x 10^10 |
| P2 | (2.5 x 10^9) x 10 = 2.5 x 10^10 | (2.5 x 10^9) x 10 = 2.5 x 10^10 |
| P3 | (4 x 10^9) x 10 = 4 x 10^10 | (1.82 x 10^9) x 10 = 1.82 x 10^10 |