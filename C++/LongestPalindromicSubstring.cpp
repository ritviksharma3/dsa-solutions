// 5. Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.
// A string is called a palindrome string if the reverse of that string is the same as the original string.

// Link : https://leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
string longestPalindrome(string s)
{
    int n = s.length();
    
    vector<vector<int>> dp(n,vector<int>(n,0));
    // vector contains wether th substring from index i to j is pallindromic or not
    
    if(n==1)
        return s;
    if(n==2)
    {
        if(s[0]==s[1])
            return s;
        else
            return s.substr(0,1);
    }
    
    // substring from 0 to 0 or 1 to 1 is one character only hence always pallindromic
    // initialization: -
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    // initialization for substrings of length 2
    int l=0;
    int maxlen=1;
    
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;

            maxlen=2;
            l=i;  
        }      
    }
    
    // calculations:-
    
    // a substring from 0 to 3 is a pallindrome if (char at 0 == char at 3) && (1 to 2) is a       substring
    
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(s[j]==s[j+i] && dp[j+1][j+i-1]==1)
            {
                dp[j][j+i]=1;
                if(i+1>maxlen)
                {
                    maxlen=i+1;
                    l=j;
                }      
            }
        }
    }
    
    return s.substr(l,maxlen);
}
};