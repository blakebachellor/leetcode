#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

/*
Given an integer array nums, move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

/*
Pseudocode:
    Simple:
        iterate over every element, 
        if 0 is found, remove it and add it to the end
        Count number of zeros and concatenate a list at the end?
    Advanced:
        Use a modified stable sort? Heapsort?
            Recursively look for zeros, move to the end

*/
private:
    static bool IsZero(int n) {
        return (n==0);
    }

public:
    static void moveZeroes(vector<int>& nums) {
        int origlen = nums.size();
        nums.erase(remove_if(nums.begin(), nums.end(), [](const int& x) {return x==0;}), nums.end());
        vector<int> zeros(origlen - nums.size(), 0);
        nums.insert(nums.end(), zeros.begin(), zeros.end());
    }
};

int main() {
    vector<int> test1{0, 1, 0, 3, 12};
    vector<int> test2{0};
    vector<int> test3{0, 0, 1, 0, 2};
    
    Solution::moveZeroes(test1);
    Solution::moveZeroes(test2);
    Solution::moveZeroes(test3);

    cout << "test1: ";
    for (int i : test1) {
        cout << i << ", ";
    }
    cout << endl;
    cout << "test2: ";
    for (int i : test2) {
        cout << i << ", ";
    }
    cout << endl;
    cout << "test3: ";
    for (int i : test3) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}