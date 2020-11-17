# cook your dish here
# cook your dish here
yu = int(input())
for i in range(yu):
    a = input()
    a = a.split()
    k = int(a[1])
    n = int(a[0])
    s = input()
    s = s.split()
    dic = {}
    for j in range(k):
        d = input()
        d = d.split()
        for w in range(1, len(d)):
            dic[d[w]] = dic.get(d[w], 0) + 1
    lst = []
    for k in dic.keys():
        lst.append(k)
    for h in s:
        z=0
        for b in lst:
            if h == b:
                z += 1
                break
        if z==0:
            print("NO ", end='')
        else:
            print("YES ", end='')
    print()
    