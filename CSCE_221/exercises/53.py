import random

colisions = 0
long_random_size = 1000
table_size = long_random_size *10
hash = [None] * table_size

def linear_hash (num):
    global colisions
    h = num % table_size
    if(hash[h] == None):
        return h
    else:
        colisions = colisions + 1
        return linear_hash(h + 1)

def quadratic_hash (num, i):
    global colisions
    h = num % table_size
    i = i + 1
    if(hash[h] == None):
        return h
    else:
        colisions = colisions + 1
        return quadratic_hash(h + i**2 , i)

def double_hash (num, i):
    global colisions
    h = num % table_size
    h2 =  7 - (num % 7)
    i = i + 1
    if(hash[h] == None):
        return h
    else:
        colisions = colisions + 1
        return quadratic_hash(h + (i*h2) , i)

def linear_insert(num):
    hash[linear_hash(num)] = num

def quadratic_insert(num):
    hash[quadratic_hash(num, 0)] = num


def double_insert(num):
    hash[quadratic_hash(num, 0)] = num

def print_hash():
    for i in range(table_size):
        print(hash[i])


for i in range(long_random_size):
    double_insert(random.randint(0, long_random_size))

print(colisions)
