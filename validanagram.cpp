#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
Given two strings s and t, return true 
if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters 
of a different word or phrase, typically using all the original 
letters exactly once.
*/

/*
PSEUDOCODE:
    Simple: 
        Iterate over both strings, maintain a count of each letter
        check if the counts are the same
    Intermediate:
        Sort each string, check if they are equal
    Expert:
        Convert to ASCII and check if they are equal ints
            Issue - there are multiple ways to add up to the same string
        Instead,
            First - Check if each string is the same length, quick one
            Next - Sort 
            Next - Check first N chars  
                Skip some because probability that a clash occurs 
                rapidly goes to 0 due to string input length limit
*/

class Solution {
public:
    static bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};


int main() {
    string test1 = "ABCDE";
    string test2 = "EDCBA";
    string test3 = "AAABB";
    string test4 = "BAAAB";
    string test5, test6;
    for (int i = 0; i < int('B'); i++) {
        test5.push_back('A');
    }
    for (int i = 0; i < int('A'); i++) {
        test6.push_back('B');
    }

    cout << test1 << " & " << test2 << ":  " << Solution::isAnagram(test1, test2) << endl;
    cout << test3 << " & " << test4 << ":  " << Solution::isAnagram(test3, test4) << endl;
    cout << "LOTTA A's & B's:  " << Solution::isAnagram(test5, test6) << endl;

    return 0;
}