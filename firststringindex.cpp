#include <iostream>
#include <string>

using namespace std;
/*
Given two strings needle and haystack, return the index of the first 
occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

/*
PSEUDOCODE
Simple:
    Iterate over haystack, checking for first letter of needle
    If found first letter, save that index
        Iterate for the length of needle, checking each letter
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int first = -1;
        for (int h = 0; h < haystack.length(); h++) {
            if (haystack[h] == needle[0]) {
                first = h;
                for (int i = 1; i < needle.length(); i++) {
                    if (haystack[h + i] != needle[i]) {
                        first = -1;
                        break; 
                    }
                }
                if (first != -1) {
                    return first;
                }
            }
        }
        return -1;
    }
};