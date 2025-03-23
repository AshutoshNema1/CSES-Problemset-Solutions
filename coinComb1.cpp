#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

class Solution{
    public:   
    int fRec(int x, vector<int>&arr, vector<int>&dp){
        if(x < 0) return 0;
        if(x == 0) return 1;
        
        // for every value of x we have choice to choose any value from arr and move forward : 
        if(dp[x]!= -1) return dp[x];
        int count = 0;
        for(int i = 0; i<arr.size(); i++){
            count= ((count + fRec(x-arr[i], arr,dp))%MOD); 
        }
        
        return dp[x] = count;
    }
  int f(int x,vector<int>&arr){
     vector<int>dp(x+1, -1);
     
     return fRec(x, arr,dp);
     
  }  
    
    
};

int main(){
    int n, x;
    cin>>n>>x;
    vector<int>arr;
    int i;
    
    while(n--){
        cin>>i;
        arr.push_back(i);
    }
    Solution obj1;
    cout<<obj1.f(x,arr);
}