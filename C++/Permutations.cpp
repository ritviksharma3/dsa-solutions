// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

/// Link : https://leetcode.com/problems/permutations/

class Solution {
public:
    
    void recur(vector<int> &nums, vector<vector<int>> &ans,int index)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        cout<<index<<" ";
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            
            recur(nums,ans,index+1);
            
            swap(nums[index],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        
        vector<vector<int>> ans;
        
        recur(nums,ans,0);
        
        return ans;
        
    }
};