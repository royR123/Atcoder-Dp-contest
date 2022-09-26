#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int> > tasks(n,vector<int>(3));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin >> tasks[i][j];
        }
    }
    vector<vector<int> > happiness(n+1,vector<int>(3,0));
    for(int i = 1 ; i <= n ; i++){
        happiness[i][0] = tasks[i-1][0] + max(happiness[i-1][1],happiness[i-1][2]) ;
        happiness[i][1] = tasks[i-1][1] + max(happiness[i-1][0],happiness[i-1][2]) ;
        happiness[i][2] = tasks[i-1][2] + max(happiness[i-1][1],happiness[i-1][0]) ;
    }
    cout << max(max(happiness[n][0],happiness[n][1]),happiness[n][2]) << endl;
    return 0;
}