def fact(n):
    if n<=1:
        return 1
    return n*fact(n-1)

a = int(input('Enter a number '))
print(fact(a))
