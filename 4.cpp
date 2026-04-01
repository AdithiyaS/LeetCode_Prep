class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       if(nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int totalLeft = (m+ n+ 1) / 2;

        int lo = 0, hi = m;

        while(lo <= hi){
            int i =lo + (hi- lo) / 2;

            int j = totalLeft - i;

            int Aleft = (i == 0) ? INT_MIN : nums1[i-1];
            int Aright = (i == m) ? INT_MAX : nums1[i];

            int Bleft = (j == 0) ? INT_MIN : nums2[j-1];
            int Bright = (j == n) ? INT_MAX : nums2[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                if ( (m + n) % 2 == 1 )
                    return (double)max(Aleft, Bleft);

                
                int leftMax = max(Aleft, Bleft);
                int rightMin = min(Aright, Bright);

                return ((double)leftMax + (double)rightMin) / 2.0;
            }

            else if (Aleft > Bright) {
                hi = i - 1;
            }
            
            else {
                lo = i + 1;
            }
        }
        return 0.0;
    }
};

/*
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/