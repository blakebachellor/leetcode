#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

/* Given an integer array nums, return the largest perimeter of a triangle
 with a non-zero area, formed from three of these lengths. 
 If it is impossible to form any triangle of a non-zero area, return 0.
 
 A triangle must satisfy the constraints:
    1. sum of any two sides must be greater than the third side 
    2. difference of any two sides is less than the length of the third side
 */

/* Pseudocode:

        Simple: 
            Sort the array from highest to lowest
                heapsort? quicksort?
                Numbers must be consecutive
            Check if the largest 3 values form a triangle
                check difference rule - checkDiff
                    if fails, repeat with next largest sum 
                        use getNext
                check sum rule
                    if passes, return the sum of those 3 values
                    if fails, repeat with next largest sum
                        use getNext
            Stop condition - if can't search smaller, return 0


        Advanced:
            avoid repeated work by skipping duplicate triangles?
            find the first pair of numbers that singly pass the 
            track a running perimeter value
        
        Expert:
            A* search our way down



*/

public:
    
    bool checkDiff (vector<int>& sides) {
        return (abs(sides[0] - sides[1]) < sides[2] && 
            abs(sides[0] - sides[2]) < sides[1] && 
            abs(sides[1] - sides[2]) < sides[1]); 
    }

    bool checkSum (vector<int>& sides) {
        return (sides[1] + sides[2] > sides[0]);
    }

    vector<int> getNext(vector<int>& nums, vector<int>& curr) {
        if (curr.empty() || nums.size() ==3) {
            return {nums[0], nums[1], nums[2]};
        }
        vector<int> sides = {nums[0], nums[1], nums[2]};
        

        return {nums[0], nums[1], nums[3]};
    }
    
    static int largestPerimeter(vector<int>& nums) {
        //int perim = 0;
        //vector<int> sides;
        //int i, j, k = 0;

        sort(nums.begin(), nums.end());
        
        //while (nums.size() > 2) {
            
            //sides = getNext(nums, sides);
            //if (checkDiff(sides)){
                //if (checkSum(sides)) {
                    //perim = sum(sides);
                //}
            //}
            //nums.erase(nums.begin());
        //}

        while (nums[nums.size() - 1] >= nums[nums.size() - 3] + nums[nums.size() - 2]) {
            nums.pop_back(); 
            if (nums.size() < 3) {return 0;}
        }
        return nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1];

    }
};

int main() {
    vector<int> test1 = {2, 1, 2};
    vector<int> test2 = {1, 2, 1, 10};
    vector<int> test3 = {6, 2, 3, 10, 2}; 
    cout << endl;
    cout << "[2, 1, 2]'s Perimeter is: " << Solution::largestPerimeter(test1) << endl;;
    cout << "[1, 2, 1, 10]'s Perimeter is: " << Solution::largestPerimeter(test2) << endl;;
    cout << "[6, 2, 3, 10, 2]'s Perimeter is: " << Solution::largestPerimeter(test3) << endl;;

    return 0;
}