a = [0,1,2,3,4,5,6,7,8,9,10]

def numberEqualPosition(arr):
    size = len(arr)
    if(size == 1):
        if(arr[0] == 0):
            return True
        else:
            return False
    mid = int(size/2)
    if (arr[mid] == mid):
        return True
    if (arr[mid] > mid):
        numberEqualPosition(arr[:mid])
    return False

print(numberEqualPosition(a))