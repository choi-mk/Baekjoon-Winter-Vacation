//https://www.acmicpc.net/problem/5567
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> friends(n+1, vector<int>());
    vector<bool> visit(n+1, false);
    int a, b;
    for (int i=0; i<m; i++){
        cin>>a>>b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    visit[1]=true;
    for (int i=0; i<friends[1].size(); i++){
        int c=friends[1][i];
        visit[c]=true;
        for(int j=0; j<friends[c].size(); j++){
            visit[friends[c][j]]=true;
        }
    }
    int answer=0;
    for (int i=1; i<n+1; i++){
        if (visit[i])answer++;
    }
    cout<<answer-1;
}
