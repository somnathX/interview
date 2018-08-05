273. Integer to English Words
//https://leetcode.com/problems/integer-to-english-words/description/
/***
123 - "One Hundred Twenty Three"

12345 - "Twelve Thousand Three Hundred Forty Five"
1234567 -"One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

1234567891 - "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
***/

/***
Approach:
Divide the number into chunks of 3 digits. Example: 123 456 789
Pick the chunk and convert it into english words 
Append the denomination
Repeat until last chunk.

Time Complexity: O(1).. Why? 
Maximum iteration = 4 (EMPTY, thousand, million, billion)
Maximum recursive calls for each chunk = 3
Total complexity = 4*3= O(12) = O(1)
***/

class Solution {
private:
    const vector<string> LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
    const vector<string> TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> HUNDERED = {"", "Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        if(!num) return "Zero";
        
        int i=0;
        string res = "";
        while(num) {
            if(num%1000) {
                res = helper(num%1000) + " " + HUNDERED[i] + " " + res;
            }
            num/=1000;
            i++;
        }
        while(res.back()==' ') res.pop_back();
        return res;
    }
    
    string helper(int num) {
        if(num<20) return LESS_THAN_20[num];
        if(num<100) return TENS[num/10] + (num%10==0 ? "" : (" " + LESS_THAN_20[num%10]));
        return LESS_THAN_20[num/100] + " Hundred" + (num%100==0? "" : (" " + helper(num%100)));
    }
};