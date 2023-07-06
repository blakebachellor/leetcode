class Solution:
    def tribonacci(self, n: int) -> int:
        #The Tribonacci sequence Tn is defined as follows: 
        # T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
        # Given n, return the value of Tn.

        #Constraints: 0 <= n <= 37

        #Pseudocode:
        
        a, b, c = 0, 1, 1
        if n == 0:
            return a

        for _ in range(3, n + 1):
            a, b, c = b, c, c + b + a 
        
        return c

print('/nT_3: ')
print(Solution.tribonacci(Solution, 3))
print('/nT_4: ')
print(Solution.tribonacci(Solution, 4))
print('/nT_2: ')
print(Solution.tribonacci(Solution, 2))
print('/nT_37: ')
print(Solution.tribonacci(Solution, 37))