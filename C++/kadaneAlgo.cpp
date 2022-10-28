#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum=0;
        
        for(auto i:nums){
            sum+=i;
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }

int main() {
	vector<int> a = { -2, -3, 4, -1, -2, 1, 5, -3};
	int sum = maxSubArray(a);
	cout << "Maximum contiguous sum is " << sum;
	return 0;
}
