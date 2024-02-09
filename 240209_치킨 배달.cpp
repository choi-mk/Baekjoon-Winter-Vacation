//https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int min_dis=987654321;
vector<bool> visit(13,0);
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<vector<int>> chic_distance;
int n, m;
void count(int num, int idx){
    if(num==m){
        int min_chi=0;
        for (int i=0; i<home.size(); i++){
            vector<int> new_chicken;
            for (int j=0; j<chicken.size(); j++){
                if (visit[j]){
                    new_chicken.push_back(chic_distance[i][j]);
                }
            }
            min_chi+= *min_element(new_chicken.begin(), new_chicken.end());
            
        }
        if(min_dis>min_chi)min_dis=min_chi;
    }
    else{
        for (int i=idx; i<chicken.size(); i++){
            visit[i]=true;
            count(num+1, i+1);
            visit[i]=false;
        }
    }
}





int main(){
    cin>>n>>m;
    vector<vector<int>> map(n, vector<int>(n,0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>map[i][j];
            if (map[i][j]==1){
                home.push_back(make_pair(i, j));
            }
            else if(map[i][j]==2){
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    for (int i=0; i<home.size(); i++){
        vector<int> house;
        for (int j=0; j<chicken.size(); j++){
            house.push_back(abs(home[i].first-chicken[j].first)+abs(home[i].second-chicken[j].second));
        }
        chic_distance.push_back(house);
    }
    count(0,0);
    cout<<min_dis;

}