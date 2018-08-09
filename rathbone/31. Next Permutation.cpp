//31. Next Permutation
/****
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
***/

/***
Solution:
1) If all digits sorted in descending order, then output is always “Not Possible”. For example, 4321.
2) If all digits are sorted in ascending order, then we need to swap last two digits. For example, 1234.
3) For other cases, we need to process the number from rightmost side (why? because we need to find the smallest of all greater numbers)
***/

//Complexity: Size: O(1), Time: O(n)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for( i=n-1;i>0;i--) {
            if(nums[i] > nums[i-1]) 
                break;
        }
        
        if(i==0) {
            reverse(nums.begin(), nums.end()); return;
        }
        
        int x = nums[i-1];
        int smallest = i;
        
        for(int j=i;j<n;j++) {
            if(nums[j] > x && nums[j] < nums[smallest]) {
                smallest = j;
            }
        }
        
        swap(nums[i-1], nums[smallest]);
        
        sort(nums.begin()+i, nums.end());
        
    }
};