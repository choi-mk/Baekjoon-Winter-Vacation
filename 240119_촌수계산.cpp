//https://www.acmicpc.net/problem/2644
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int main(){

    int n, m, a, b;
    cin>>n>>a>>b>>m;
    int x, y;
    vector<bool> visited(n+1,false);
    vector<vector<int>> map(n+1, vector<int>());
    for (int i=0; i<m; i++){
        cin>>x>>y;
        map[x].push_back(y);
        map[y].push_back(x);
    }
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    int times=0;
    while(!q.empty()){
        a=q.front().first;
        times=q.front().second;
        q.pop();
        visited[a]=true;
        if(a==b) break;
        for(int i=0; i<map[a].size(); i++){
            if (visited[map[a][i]]==false){
                q.push(make_pair(map[a][i], times+1));
            }
        }
    }
    if (a==b) cout<<times;
    else cout<<-1;

    return 0;
}