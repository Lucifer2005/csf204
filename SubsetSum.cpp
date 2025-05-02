#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1]<=j) {
             // Include or exclude
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];  
            }
            else {
		// Exclude the current element
                dp[i][j] = dp[i - 1][j]; 
                 }//End of else
        }//End of inner loop
    }//End of outer loop
    return dp[n][sum];
}//End of function

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    if (isSubsetSum(arr, sum))
             cout << "Yes, the subset exists" << endl;
    else
        cout << "No, the subset does not exist" << endl;
    return 0;
}//End main