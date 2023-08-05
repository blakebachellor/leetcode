#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

/* You are keeping the scores for a baseball game with strange rules. 
At the beginning of the game, you start with an empty record.
You are given a list of strings operations, where operations[i] is the 
ith operation you must apply to the record and is one of the following:

An integer x.
    Record a new score of x.
'+'.
    Record a new score that is the sum of the previous two scores.
'D'.
    Record a new score that is the double of the previous score.
'C'.
    Invalidate the previous score, removing it from the record.

Return the sum of all the scores on the record after applying 
all the operations.The test cases are generated such that the answer 
and all intermediate calculations fit in a 32-bit integer and 
that all operations are valid.
*/

/* Pseudocode:
Simple: 
    For each entry in operations:
        switch case - each operation's action
    



*/

class Solution {
public:
    static int calPoints(vector<string>& operations) {
        stack<int> score = {};  //{current score, last score, 2 scores ago}
        int total = 0;
        int tmp1, tmp2 = 0;
        for (string op : operations) {
            switch(op[0]) {
                case '+': 
                    tmp1 = score.top();
                    score.pop();
                    tmp2 = score.top();
                    score.push(tmp1);
                    score.push(tmp1 + tmp2);
                    break;
                case 'D':
                    score.push(score.top() * 2);
                    break;
                case 'C':
                    score.pop();
                    break;
                default:
                    score.push(stoi(op));
            }
        }
        while (score.size() > 0) {
            total += score.top();
            score.pop();
        }
        return total;
    }
};

int main() {
    vector<string> test1 = {"5", "2", "C", "D", "+"};
    vector<string> test2 = {"5","-2","4","C","D","9","+","+"};
    cout << "TEST 1 (Expected 30) : " << Solution::calPoints(test1) << endl;
    cout << "TEST 2 (Expected 27) : " << Solution::calPoints(test2) << endl;
    return 0;
}