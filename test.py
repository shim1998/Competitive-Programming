def dictCompare(A, B):
    totalCost = 0
    countDelKeys = 0
    for i in A.keys():
        try:
            B[i] -= 1
            A[i] -= 1
            countDelKeys += 1
        except KeyError:
            if(A[i] % 2 == 0 and A[i] > 0):
                y1 = N
                y2 = N
                y = 0
                while(y1 != 0):
                    for j in B.keys():
                        if(B[j] % 2 == 0 and B[j] > 0):
                            y1 = int(A[i]/2)
                            y2 = int(B[j]/2)
                            y = min(y1, y2)
                            totalCost += y*min(int(i), int(j))
                            A[i] -= 2*y
                            B[j] -= 2*y
                            countDelKeys += 2*y
                            y1 -= y
                            y2 -= y
                            if(y1 == 0):
                                break
                    else:
                        return(-1)
            else:
                return(-1)
    if(countDelKeys != N):
        return(-1)
    return(totalCost)


def dictCreator(A):
    a = {}
    for i in A:
        try:
            a[i] += 1
        except KeyError:
            a[i] = 1
    return(a)


T = int(input())
for i in range(T):
    N = int(input())
    A = input().split(" ")
    B = input().split(" ")
    A2 = dictCreator(A)
    B2 = dictCreator(B)
    print(dictCompare(A2, B2))