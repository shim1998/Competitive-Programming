import sys

''' First take all the input in memory as buffer, then process each input separately from the buffer '''
input = sys.stdin.buffer.readline # This is for fast input

def rl(): return list(map(int, input().split()))  # Read a list of integers
def rs(): return input().decode().rstrip('\n\r')  # Read a string


def main():
    pass


Testcase, = rl()  # for taking single integers, use a comma(,) after the variable name
for testcase in range(Testcase):
    main()
