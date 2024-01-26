//https://www.acmicpc.net/problem/7576
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int m, n, t;
    cin>>m>>n;
    vector<vector<int>> box(n, vector<int>(m,0));
    queue<pair<int, int>> q;
    queue<pair<int, int>> next_q;
    int tomato=0;
    int answer=-1;
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>t;
            box[i][j]=t;
            if (t==1){
                q.push(make_pair(i, j));
            }
            if (t==0 || t==1) tomato+=1;
        }
    }
    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        tomato-=1;
        if (a>0 && box[a-1][b]==0){
            box[a-1][b]=1;
            next_q.push(make_pair(a-1, b));
        }
        if (a<n-1 && box[a+1][b]==0){
            box[a+1][b]=1;
            next_q.push(make_pair(a+1, b));
        }
        if (b>0 && box[a][b-1]==0){
            box[a][b-1]=1;
            next_q.push(make_pair(a, b-1));
        }
        if (b<m-1 && box[a][b+1]==0){
            box[a][b+1]=1;
            next_q.push(make_pair(a, b+1));
        }
        if (q.empty()){
            while(!next_q.empty()){
                q.push(next_q.front());
                next_q.pop();
            } 
            answer+=1;
        }
    }
    if (tomato==0) cout<< answer;
    else cout<<-1;
}
