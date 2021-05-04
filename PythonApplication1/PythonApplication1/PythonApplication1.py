n = int(input())

array = []
s=0
for i in range(n):
        array.append(int(input()))

for i in array:
        s+=i
print(s)