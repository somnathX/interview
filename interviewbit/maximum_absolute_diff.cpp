//Maximum Absolute Difference
/*You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.*/

//Solution
int Solution::maxArr(vector<int> &nums) {
    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    
    for(int i=0;i<nums.size();i++) {
        max1 = max(max1, nums[i] + i);
        min1 = min(min1, nums[i] + i);
        max2 = max(max2, nums[i] - i);
        min2 = min(min2, nums[i] - i);
    }
    
    return max(max1-min1, max2-min2);
}