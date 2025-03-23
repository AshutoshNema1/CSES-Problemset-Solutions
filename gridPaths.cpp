#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

class Solution{
  
  public:
  int f(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&dp){
      if(i < 0 or j < 0) return 0;
      if(grid[i][j] == '*') return dp[i][j] = 0;
      if(i == 0 and j == 0) return dp[0][0] = 1;
      // Since we are moving from n,n to the point 0,0 we may get out of bounds at some point.
      
      
      
      if(dp[i][j] != -1) return dp[i][j];
      
      int top = f(i-1, j, grid, dp);
      int left = f(i, j-1, grid, dp);
      
      return dp[i][j] = (top + left)%MOD;
  }  
  
};


int main(){
    int n;
    cin>>n;
    char x;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
    Solution obj1;
    cout<<obj1.f(n-1,n-1,grid,dp);
}