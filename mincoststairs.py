class Solution:
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        #You are given an integer array cost where cost[i] is the cost 
        # of ith step on a staircase. Once you pay the cost, 
        # you can either climb one or two steps.
        # You can either start from the step with index 0, 
        # or the step with index 1.
        #
        # Return the minimum cost to reach the top of the floor.
        # Constraints:
        # 2 <= cost.length <= 1000
        # 0 <= cost[i] <= 999

        # Pseudocode
        # Depth First Search recursion
        # start off the stairs, add runningcost to the queue
        tot, currstep, delta = 0, -1, 0
        #cost += [1000, 1000]
        
        print('\nDEBUGGING-------------')
        print(cost)
        print('currstep: ' + str(currstep))
        
        while currstep < len(cost)-2:
            print('cost[currstep+1]: ' + str(cost[currstep+1]))
            if cost[currstep+1] < cost[currstep+2]:
                delta = 1
            else:
                delta = 2
            currstep += delta
            tot += cost[currstep]
            print('delta: ' + str(delta))
            print('currstep: ' + str(currstep))

        print('\nEND OF DEBUGGING--------------')
        return tot

cost = [10,15,20]
print('\n' + str(cost))
print(Solution.minCostClimbingStairs(Solution, cost))