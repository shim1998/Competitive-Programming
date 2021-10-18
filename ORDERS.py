#https://www.codechef.com/problems/ORDERS
t = int(input())
for i in range(t):
    n = int(input())
    givenli = list(map(int,input().split()))
    ind_li = [i for i in range(len(givenli))]
    # idea: we move the ind_li according to the input_li
    for i in range(len(givenli)):
        if givenli[i]!=0:
            ind_li.insert(i-givenli[i],ind_li.pop(i))
    ans = [0] * len(givenli)
    for i in range(len(ind_li)):
        ans[ind_li[i]] = i+1
    
    for i in range(len(ans)):
        print(ans[i],'',end='')
    print('')
