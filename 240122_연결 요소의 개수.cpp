//https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

void dfs(vector<bool>& visited, vector<vector<int>>& map, int num){
    visited[num]=true;
    for(int i=0; i<map[num].size(); i++){
        if (visited[map[num][i]]==false){
            dfs(visited, map, map[num][i]);
        }
    }
}



int main(){
    int n, m, u, v;
    int answer=0;
    cin>>n>>m;
    vector<vector<int>> map(n+1, vector<int>());
    vector<bool> visited(n+1, false);
    for (int i=0; i<m; i++){
        cin>>u>>v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        if(visited[i]==false){
            answer+=1;
            dfs(visited, map, i);
        }
    }
    cout<<answer;

}