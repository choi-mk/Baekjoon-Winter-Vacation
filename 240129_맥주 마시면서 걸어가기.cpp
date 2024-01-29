//https://www.acmicpc.net/problem/9205
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main(){
    int t, n;
    cin>>t;
    
    for (int i=0; i<t; i++){
        string answer="sad";
        cin>>n;
        vector<bool> visited(n+2,false);
        vector<vector<int>> map(n+2, vector<int>(2,0));
        for(int j=0; j<n+2; j++){
            cin>>map[j][0]>>map[j][1];
        }
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            vector<int> cur=map[q.front()];
            visited[q.front()]=true;
            //cout<<q.front()<<" ";
            if(q.front()==n+1) answer="happy";
            q.pop();
            for(int j=1; j<n+2; j++){
                //cout<<cur[0]<<cur[1]<<endl;
                //cout<<abs(map[j][0]-cur[0])+abs(map[j][1]-cur[1])<<endl;
                if(abs(map[j][0]-cur[0])+abs(map[j][1]-cur[1])<=1000 && visited[j]==false){
                    
                    q.push(j);
                }
            }
        }
        cout<<answer<<endl;
    }
    
}