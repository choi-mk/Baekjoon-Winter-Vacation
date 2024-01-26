//https://www.acmicpc.net/problem/10026
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void find(vector<string>& map, int i, int j){
    char color=map[i][j];
    map[i][j]='E';
    if (i>0 && map[i-1][j]==color){
        find(map, i-1, j);
    }
    if (i<map.size()-1 && map[i+1][j]==color){
        find(map, i+1, j);
    }
    if (j>0 && map[i][j-1]==color){
        find(map, i, j-1);
    }
    if (j<map[0].size()-1 && map[i][j+1]==color){
        find(map, i, j+1);
    }
}


int main(){
    int n;
    cin>>n;
    vector<string> map_n;
    vector<string> map_rg;
    for (int i=0; i<n; i++){
        string a;
        cin>>a;
        map_n.push_back(a);
        map_rg.push_back(a);
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<map_rg[0].size(); j++){
            if (map_rg[i][j]=='G') map_rg[i][j]='R';
        }
    }
    int a=0;
    int b=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<map_rg[0].size(); j++){
            if (map_n[i][j]!='E'){
                a+=1;
                find(map_n, i, j);
            }
            if (map_rg[i][j]!='E'){
                b+=1;
                find(map_rg, i, j);
            }
        
        
        }
    }
    cout<<a<<" "<<b;


}