# cook your dish here
for i in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    l1 = []
    for num in l:
        if num not in l1:
            l1.append(num)
    print(len(l1))