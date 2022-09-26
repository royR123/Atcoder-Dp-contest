#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> ht(n);
    for(int i = 0 ; i < n ; i++){
        cin >> ht[i];
    }
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2 ; i <= n ; i++){
        int steps = 1;
        int ans = INT_MAX;
        for(int j = i-1 ; j >= 1 ; j--){
            if(steps > k){
                break;
            }
            ans = min(ans,dp[j] + abs(ht[j-1] - ht[i-1]));
            steps++;
        }
        dp[i] = ans;
    }
    cout << dp[n] << endl;
    return 0;
}