#include <bits/stdc++.h>
using namespace std;

void checkRepeating(int arr[], int n)
{
    int arrindx[n], mn = INT_MAX;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        arrindx[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (arrindx[arr[i]] != -1)
        {
            mn = min(mn, arrindx[arr[i]]);
            arrindx[arr[i]] = i;            
        }
        else
        {
            arrindx[arr[i]] = i;  
            // mn = min(mn, i);  
        }
    }
    cout << mn + 1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    checkRepeating(arr, n);
}