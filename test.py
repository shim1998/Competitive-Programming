string = input("Please Enter your Own String : ")
alphabets = digits = spaces = 0

for i in range(len(string)):
    if((string[i]>='a' and string[i]<='z') or (string[i]>='A' and string[i]<='Z')):
        alphabets = alphabets + 1
    elif((string[i]>='0' and string[i]<='9')):
        digits = digits + 1
    elif(string[i]==' '):
        spaces = spaces + 1
        
print("\nTotal Number of Alphabets in this String :  ", alphabets)
print("Total Number of Digits in this String :  ", digits)
print("Total Number of Special Characters in this String :  ", spaces)