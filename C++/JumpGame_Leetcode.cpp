#include <bits/stdc++.h>
using namespace std;

// 55. JUMP GAME
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Link : https://leetcode.com/problems/jump-game/

bool canJump(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] >= n - 1 - i)
            dp[i] = true;
        else
        {
            dp[i] = false;
            for (int j = 1; j <= nums[i]; j++)
            {
                if (dp[i + j] == true)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[0];
}

int main()
{
    vector<int> nums={2,3,1,1,4};
    cout<<canJump(nums)<<endl;

}