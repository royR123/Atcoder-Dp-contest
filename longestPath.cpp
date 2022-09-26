#include<bits/stdc++.h>
using namespace std;
vector<int> dis;
int longestPath(vector<int> adj[],int st){
    if(dis[st] != -1){
        return dis[st];
    }
    int ans = 0;
    for(auto node : adj[st]){
        ans = max(ans,1+longestPath(adj,node));
    }
    return dis[st] = ans;
}
int main(){
    int n , m ;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0 ; i < m ; i++){
        int e , b ;
        cin >> e >> b;
        adj[e].push_back(b);
    }
    int ans = 0;
    dis.resize(n+1,-1); // cache the computed values of longest path from node 'i' . 
    for(int i = 1 ; i <= n ; i++){
        ans = max(ans,longestPath(adj,i)) ;
    }
    cout << ans << endl;
    return 0;
}