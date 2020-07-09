x = 3
a = [4, 8, 0, 1, 2]
n = 5
poly = 0

for i in range(5):
    print("3 * ", poly, " + ", a[i])
    poly = x * poly + a[i]

print("")
print(poly)