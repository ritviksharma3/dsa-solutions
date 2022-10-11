
// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

// LINK: https://leetcode.com/problems/increasing-triplet-subsequence/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first = INT_MAX,second=INT_MAX;
        
        if(nums.size()<3)
            return false;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>second)
                return true;
            
            if(nums[i]>first && nums[i]<second)
                second = nums[i];
            
            if(nums[i]<first)
                first = nums[i];
        }
        
        return false;
    }
};