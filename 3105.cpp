class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;

        int best = 1;         // longest length so far
        int len  = 1;         // current run length
        int dir  = 0;         // 0 = unknown, +1 = increasing, -1 = decreasing

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                // equal breaks monotonicity
                len = 1;
                dir = 0;
            } else {
                int d = (nums[i] > nums[i - 1]) ? +1 : -1;
                if (dir == 0 || d == dir) {
                    // continuing same direction (or just established)
                    ++len;
                    dir = d;
                } else {
                    // direction flipped → start new run from the last pair
                    len = 2;
                    dir = d;
                }
            }
            if (len > best) best = len;
        }
        return best;
    }
};

/*
3105. Longest Strictly Increasing or Strictly Decreasing Subarray

You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.

 

Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.

 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
*/