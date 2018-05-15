//Largest Number
/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
//Solution
string Solution::largestNumber(const vector<int> &A) {
    vector<int> nums = A;
    sort(nums.begin(), nums.end(), [](const int a, const int b){
        return to_string(a)+to_string(b) > to_string(b)+to_string(a);
    });
    string ans="";
    for(auto num: nums) {
        ans+=to_string(num);
    }
    return ans[0]=='0' ? "0" : ans;
}
