class Solution:
    def __init__(self):
        self.prevone = 1
        self.prevtwo = 0

    def fib(self, n: int) -> int:
        #The Fibonacci numbers, commonly denoted F(n) form a sequence, 
        # called the Fibonacci sequence, such that each number is the sum of 
        # the two preceding ones, starting from 0 and 1.
        # Given n, calculate F(n)

        #Pseudocode:
        # Recursively find F(n) - end up double calling recursions
        # Instead, use a for loop, only track previous two entries

        if n <= 0:
            return 0
        else:
            prevone = 1
            prevtwo = 0
            for _ in range(2, n):
                prevtwo, prevone = prevone, prevtwo + prevone
            return prevone + prevtwo



print('\nfib(1): ')
print(Solution.fib(Solution, 1))
print('\nfib(2): ')
print(Solution.fib(Solution, 2))
print('\nfib(30): ')
print(Solution.fib(Solution, 30))