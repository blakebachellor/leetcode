class Solution:
    def climbStairs(self, n: int) -> int:
        # You are climbing a staircase. It takes n steps to reach the top.
        # Each time you can either climb 1 or 2 steps. 
        # In how many distinct ways can you climb to the top?
        # Constraint: 1 <= n <= 45

        # Pseudocode
        # n = 2: 2 ways: 1 + 1, or 2 
        # n = 3: 3 ways: 1 + 1 + 1, or 1 + 2, or 2 + 1
        # n = 4: 5 ways: 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2  
        # n = 5: 8 ways: 1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1, 1+2+2, 2+1+2, 2+2+1
        # Dynamic Programming Approach:
        # make a list, append each amount to it 
        # n = f(n-1) + f(n-2)

        f = [1, 2]
        if n < 1 or n > 45:
            return -1
        for i in range(2, n + 1):
            f.append(f[i - 1] + f[i - 2])

        return f[n - 1]

print('\nn = 1: ')
print(Solution.climbStairs(Solution, 1))
print('\nn = 3: ')
print(Solution.climbStairs(Solution, 3))
print('\nn = 5: ')
print(Solution.climbStairs(Solution, 5))
print('\nn = 45: ')
print(Solution.climbStairs(Solution, 45))