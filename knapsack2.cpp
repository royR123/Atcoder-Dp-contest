#include<bits/stdc++.h>
using namespace std;
int weight[105] , value[105];
long long dp[100005][105];
long long getMinWeight(int sz,int valueLeft){ // this function give the minimum weight to acheive the given exact valueLeft.
    if(valueLeft == 0)return 0;
    if(sz <= 0)return 1e15;
    if(dp[valueLeft][sz] != -1)return dp[valueLeft][sz];
    long long ans = getMinWeight(sz-1,valueLeft);
    if(valueLeft-value[sz-1] >= 0){
        ans = min(ans,weight[sz-1] + getMinWeight(sz-1,valueLeft-value[sz-1]));
    }
    return dp[valueLeft][sz] = ans ;
}
int main(){
    int n ;
    int w;
    cin >> n >> w;
    for(int i = 0 ; i < n ; i++){
        cin >> weight[i] ;
        cin >> value[i] ;
    }
    memset(dp,-1,sizeof(dp));
    int max_val = 1e5;
    // cout << w << endl;
    for(int i = max_val ; i >= 0 ; i--){
        // cout << getMinWeight(n,i) << endl;
        if(getMinWeight(n,i) <= w){
            cout << i << endl;
            break;
        }
    }
    return 0;

}