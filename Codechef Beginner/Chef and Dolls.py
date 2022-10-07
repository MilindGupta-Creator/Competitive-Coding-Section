for _ in range(int(input())):
    n=int(input())
    l=[]
    for i in range(n):
        a = int(input())
        if a in l:
            l.remove(a)
        else:
            l.append(a)
    print(*l)
    