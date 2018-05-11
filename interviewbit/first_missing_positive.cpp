/* First Missing Positive */

/*
Problem Statement
Given an unsorted integer array, find the smallest missing positive integer.

Input: [1,2,0]
Output: 3

Input: [3,4,-1,1]
Output: 2

Input: [7,8,9,11,12]
Output: 1

Input:  [2, 3, 7, 6, 8, -1, -10, 15]
Output: 1

Input:  [2, 3, -7, 6, 8, 1, -10, 15]
Output: 4

Input: [1, 1, 0, -1, -2]
Output: 2 
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int i=0;i<n;i++) {
            if(nums[i] != i+1) return i+1;
        }
        
        return n+1;
    }
};