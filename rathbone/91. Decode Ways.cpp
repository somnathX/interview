/***
91. Decode Ways
https://leetcode.com/problems/decode-ways/description/

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
***/

/***
Test:
"" // empty string
"0" // invalid encoding number
"&*^.abc" // invalid input char
"201" -> 1 // 0 can only be at the units of a two-digit number
"12" -> 2
***/

/***
Note: Ask if the input is all numbers, otherwise you need to detect other illegal characters.
***/

//DP Solution
//Complexity - Space: O(n) | Time: O(n)
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s.front()=='0') return 0;
        
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++) {
            if(s[i-1]!='0') dp[i]=dp[i-1];
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')) dp[i]+=dp[i-2];
        }
        return dp.back();
    }
};

