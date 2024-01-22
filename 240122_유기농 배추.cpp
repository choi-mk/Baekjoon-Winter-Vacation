//https://www.acmicpc.net/problem/1012
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void dfs(vector<vector<int>>& map, int i, int j, int& n, int& m){
    if (map[i][j]==1) {
        //cout<<i<<j<<endl;
        map[i][j]=0;
        if (i>0) dfs(map, i-1, j, n, m);
        if (i<n-1) dfs(map, i+1, j, n, m);
        if (j>0) dfs(map, i, j-1, n, m);
        if (m-1>j) dfs(map, i, j+1, n, m);
    }
}


int main(){
    int t, m, n, k, x, y;
    cin>>t;
    int num;
    vector<int> answer;
    for (int i=0; i<t; i++){
        cin>>m>>n>>k;
        num=0;
        vector<vector<int>> map(n, vector<int>(m,0));
        for (int j=0; j<k; j++){
            cin>>x>>y;
            map[y][x]=1;
        }
        for(int k=0; k<n; k++){
            for (int j=0; j<m; j++){
                if (map[k][j]==1){
                    //cout<<k<<j<<endl;
                    num+=1;
                    dfs(map, k, j, n, m);
                }
            }
        }
        cout<<num<<endl;
        
    }
    
}