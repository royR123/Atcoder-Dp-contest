#include<bits/stdc++.h>
using namespace std;
long long n , w;
vector<long long> weight , value;
long long dp[101][100001];
long long knapsack(int n,int w){
    if(n == 0){
        return 0;
    }
    if(w == 0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(weight[n-1] <= w){
        return dp[n][w] = max(knapsack(n-1,w),value[n-1]+knapsack(n-1,w-weight[n-1]));
    }else{
        return dp[n][w] = knapsack(n-1,w);
    }
}
int main(){
    cin >> n >> w;
    weight.resize(n);
    value.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> weight[i] ;
        cin >> value[i] ;
    }
    memset(dp,-1,sizeof(dp));
    cout << knapsack(n,w) <<endl;
    return 0;

}