//https://www.acmicpc.net/problem/14889
#include <iostream>
using namespace std;

int people[21][21];
bool visit[21];
int n;
int mindiff=987654321;


void math(int team, int idx){
    if (team==n/2){
        int start=0;
        int link=0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (visit[i] && visit[j]) {
                    start+=people[i][j];
                    start+=people[j][i];
                }
                else if (!visit[i] && !visit[j]) {
                    link+=people[i][j];
                    link+=people[j][i];
                }
            }
        }
        if (mindiff>abs(start-link)) mindiff=abs(start-link);
    }
    else{
        for (int i=idx; i<n; i++){
            visit[i]=true;
            math(team+1, i+1);
            visit[i]=false;
        }
    }

}


int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> people[i][j];
        }
    }
    
    math(0, 0);
    cout << mindiff;

}