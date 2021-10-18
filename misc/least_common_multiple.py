def lcm(a, b):
    c = max(a, b)
    d = c
    while True:
        if c%a == c%b == 0:
            return c        
        c += d

no_1 = int(input('Enter first number '))
no_2 = int(input('Enter second number '))
print(lcm(no_1, no_2))
