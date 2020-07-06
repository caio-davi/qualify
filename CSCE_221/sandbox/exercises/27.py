import time

def code1(n):
    start_time = time.time()
    sum = 0
    for i in range(n):
        sum = sum + 1
    return (time.time() - start_time)

def code2(n):
    start_time = time.time()
    sum = 0
    for i in range(n):
        for j in range(n):
            sum = sum + 1
    return (time.time() - start_time)

def code3(n):
    start_time = time.time()
    sum = 0
    for i in range(n):
        for j in range(n*n):
            sum = sum + 1
    return (time.time() - start_time)

def code4(n):
    start_time = time.time()
    sum = 0
    for i in range(n):
        for j in range(i):
            sum = sum + 1
    return (time.time() - start_time)

def code5(n):
    start_time = time.time()
    sum = 0
    for i in range(n):
        for j in range(i*i):
            for j in range(j):
                sum = sum + 1
    return (time.time() - start_time)

def code6(n):
    start_time = time.time()
    sum = 0
    for i in range(n):
        for j in range(i*i):
            j = j+1
            if(i%j==0):
                for j in range(j):
                    sum = sum + 1
    return (time.time() - start_time)

Ns = [10, 20, 40]

for n in Ns:
    runTime= code5(n)
    print("For N=", n, " : --- %s seconds ---" %runTime)