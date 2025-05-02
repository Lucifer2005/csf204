#include<bits/stdc++.h>
using namespace std;
int minCoins(vector<int> &coins, int sum) {
    vector<vector<int>> dp(coins.size(), vector<int>(sum+1, 0));
    for (int i=coins.size()-1; i>=0; i--) {
        for (int j=1; j<=sum; j++) {
            dp[i][j] = INT_MAX;
            int take = INT_MAX;
	    int noTake = INT_MAX;
            
            // If we take coins[i] coin
            if (j-coins[i]>=0) {
                take = dp[i][j-coins[i]];
                if (take != INT_MAX) 
                    take++;
            }
            
            if (i+1<coins.size())
            // not take the coin 
                noTake = dp[i+1][j];
            dp[i][j] = min(take, noTake);
        }
    }
    if (dp[0][sum]!=INT_MAX) 
          return dp[0][sum];
    return -1;
}

int main() {
    vector<int> coins =  {9, 6, 5, 1};
    int sum = 19;
    int no_of_coins=minCoins(coins, sum);
    if(no_of_coins!=-1)
	cout<<no_of_coins<<" are needed"<<endl;
    else
	cout<<"Not possible"<<endl;
    return 0;
}
