n=int(input())
a=list(map(int,input().split()))
x=0
for i in range(len(a)-2):
    x^=a[i]
print(x)
while(len(a)!=1):
    for i in range(len(a)-1):
        a[i]=a[i]^a[i+1]
    a.pop()
    print(a)
