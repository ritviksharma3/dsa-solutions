#include <bits/stdc++.h>
using namespace std;

// LeetCode - 4. Median of Two Sorted Arrays
//  Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median          of the two sorted arrays.

//  The overall run time complexity should be O(log (m+n)).

// link - https://leetcode.com/problems/median-of-two-sorted-arrays/

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 < n2)
        return findMedianSortedArrays(nums2, nums1);

    int m = (n1 + n2 + 1) / 2;

    if (n1 == 0)
    {
        if (n2 % 2 == 0)
        {
            return (nums2[m] + nums2[m - 1]) / 2.0;
        }

        return nums2[m - 1];
    }
    if (n2 == 0)
    {
        if (n1 % 2 == 0)
        {
            return (nums1[m] + nums1[m - 1]) / 2.0;
        }

        return nums1[m - 1];
    }

    int low = 0, high = n1;

    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;

        int cut2 = m - cut1;

        if (cut1 > m)
        {
            high = cut1 - 1;
            continue;
        }
        if (cut2 > n2)
        {
            low = cut1 + 1;
            continue;
        }
        // cout<<cut1<<endl;
        int l1 = (cut1 - 1 >= 0) ? nums1[cut1 - 1] : INT_MIN;
        int l2 = (cut2 - 1 >= 0) ? nums2[cut2 - 1] : INT_MIN;

        int r1 = (cut1 < n1) ? nums1[cut1] : INT_MAX;
        int r2 = (cut2 < n2) ? nums2[cut2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1)
        {

            if ((n1 + n2) % 2 == 0)
            {
                return (long)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            return max(l1, l2);
        }
        else if (l1 > r2)
        {

            high = cut1 - 1;
        }
        else if (l2 > r1)
        {

            low = cut1 + 1;
        }
    }

    return (long)0;
}
