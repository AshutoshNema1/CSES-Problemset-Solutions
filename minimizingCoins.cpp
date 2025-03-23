#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:   
    
  int f(int x,vector<int>&arr){
     vector<int>dp(x+1, 1e8);
     dp[0] = 0;
     
     int noOfCoins = 0;
     for(int i = 1; i<=x; i++){
         int totalNoOfCoins = 1e8;
         for(int coins = 0; coins < arr.size(); coins++){
             if(i - arr[coins] >= 0){
                noOfCoins = 1 + dp[i- arr[coins]];
                totalNoOfCoins = min(noOfCoins, totalNoOfCoins);
             }
            
            
         }
         
         dp[i] = totalNoOfCoins; 
     }
    
    return dp[x];
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
    int ans = obj1.f(x, arr);
    if(ans == 1e8){
        cout<<-1;
        return 0;
    }
    cout<< ans;
}