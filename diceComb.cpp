#include<bits/stdc++.h>
using namespace std;

class Solution{
 public:
 const int MOD =1e9+7;
  int diceCom(int n,vector<int>&dp){
      if(n < 0) return 0;
      if(n == 0) return 1;
      if(dp[n]!=-1) return dp[n];
      int count = 0;
      for(int thr = 1; thr<=6; thr++){
          count = (count + diceCom(n-thr,dp))%MOD;
      }
      
      return dp[n] = count;
  }  
  
  int diceCom(int n){
      vector<int>dp(n+1,-1);
      return diceCom(n, dp);
  }
  
};


int main(){
    int n;
    cin>>n;
    Solution obj1;
    cout<<obj1.diceCom(n);
}