//125. Valid Palindrome
/***
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
***/

/***
Approach:
Begin parallely from left and right.
Ignore left if not alnum
Ignore right if not alnum
return false if Char at left is not equal to Char at right
At the end of loop, return true
***/

//Complexity: Time: O(n) | Space: O(1)

//Solution:
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j) {
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;
            if(tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};