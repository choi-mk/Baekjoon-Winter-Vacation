//https://www.acmicpc.net/problem/2667
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int& num, vector<string>& map, int i, int j, int& n){
    if (map[i][j]=='1') {
        map[i][j]='0';
        num+=1;
        if (i>0) dfs(num, map, i-1, j, n);
        if (i<n-1) dfs(num, map, i+1, j, n);
        if (j>0) dfs(num, map, i, j-1, n);
        if (n-1>j) dfs(num, map, i, j+1, n);
    }
}



int main(){
    int n;
    cin>>n;
    vector<string> map(n);
    for (int i=0; i<n; i++){
        cin>>map[i];
    }
    vector<int> answer;

    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (map[i][j]=='1'){
                int num=0;
                dfs(num, map, i, j, n);
                answer.push_back(num);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    cout<<answer.size()<<endl;
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}