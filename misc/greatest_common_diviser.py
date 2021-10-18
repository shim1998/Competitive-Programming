def gcd(a, b):
    c = min(a, b)
    while True:
        if a%c == b%c == 0:
            return c
        c -= 1
no_1 = int(input('Enter first number '))
no_2 = int(input('Enter second number '))
print(gcd(no_1, no_2))
