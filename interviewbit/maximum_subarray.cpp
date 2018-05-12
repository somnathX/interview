//Maximum Subarray

/*
Problem Statement:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

//Solution

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int totalSum = INT_MIN;
        
        for(auto num: nums) {
            currentSum += num;
            
            totalSum = max(totalSum, currentSum);
            currentSum = max(0, currentSum);
        }
        return totalSum;
    }
};