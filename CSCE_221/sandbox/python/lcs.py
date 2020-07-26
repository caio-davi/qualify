# Solving the longest common subsequence problem using dynamic programming

def printMatrix(m):
    print("Subsequence Matrix: ")
    for row in m:
        print(row)
    print("\n")

def lcs(X , Y): 
    m = len(X) 
    n = len(Y) 
  
    L = [[None]*(n+1) for i in xrange(m+1)] 

    for i in range(m+1): 
        for j in range(n+1): 
            if i == 0 or j == 0 : 
                L[i][j] = 0
            elif X[i-1] == Y[j-1]: 
                L[i][j] = L[i-1][j-1]+1
            else: 
                L[i][j] = max(L[i-1][j] , L[i][j-1]) 
  
    printMatrix(L)
    return L[m][n] 

X = "qwesterdeqwfcvb"
Y = "sdfeqwertasddfg"
lcs = lcs(X, Y)
print "Length of LCS is ", lcs