n = int(input())

while n > 0:
    l = int(input())
    s = input()

    d ={}
    flag = False

    if l%2==0:
        for i in s:
            if i not in d.keys():
                d[i] = 1
            else:
                d[i] += 1
        for i in d.keys():
            if d[i] % 2 != 0:
                flag = False
                break
        else:
            flag = True
    
    if flag:
        print("YES")
    else:
        print("NO")
    
    n-=1
