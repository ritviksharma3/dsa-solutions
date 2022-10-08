
// 39. Combination Sum
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.


// Link : https://leetcode.com/problems/combination-sum/

#include <bits/sttdc++.h>
using namespace std;

class Solution {
public:
    void recur(vector<int>& a, int target,int index, vector<int> &curr,vector<vector<int>> &ans)
    {
        if(target==0)
        {
            ans.push_back(curr);
            return;
        }
        if(index>=a.size())
            return;
        
        if(a[index]<=target)
        {
            curr.push_back(a[index]);
            recur(a,target-a[index],index,curr,ans);
            
            curr.pop_back();
        }
        
        recur(a,target,index+1,curr,ans);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        
        vector<vector<int>> ans;
        
        vector<int> curr;
        
        recur(a,target,0,curr,ans);
        return ans;
        
        
    }
};