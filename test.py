import math

inpu=input().split()
n=int(inpu[0])
k=int(inpu[1])
b=input().split()
a=[int(b[i]) for i in range(n)]
mi=[0 for i in range(n)]
ans=[-1 for i in range(n)]
mi[0]=math.log10(a[0])
ans[0]=a[0]

for i in range(1,n):
    starter=max(0,i-k)
    minj=starter
    for j in range(starter,i):
        if mi[j]<mi[minj]:
            minj=j
    mi[i]=math.log10(a[i])+mi[minj]
    ans[i]=(a[i]*ans[minj])%1000000007

print(ans[n-1])