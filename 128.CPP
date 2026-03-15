class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=0;
        unordered_set<int> sh(nums.begin(), nums.end());

        for(auto it=sh.begin(); it != sh.end();it++){
            int x=*it;
            if(!sh.count(x-1)){
                int current = x;
                int length = 1;
                while(sh.count(current+1))
                {
                    ++current;
                    ++length;
                }
                if(count<length) count = length;
            }
        }
        return count;
    }
};

/*
128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/