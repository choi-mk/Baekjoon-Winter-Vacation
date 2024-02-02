//https://www.acmicpc.net/problem/2668
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void find(vector<bool>& visited, vector<int>& two, int i, int j, vector<int>& answer){
    if (visited[j]){
        if(j==i) answer.push_back(i);
    }
    else{
        visited[j]=true;
        find(visited, two, i, two[j], answer);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> two(n+1, 0);
    vector<int> answer;
    
    for (int i=1; i<=n; i++){
        cin>>two[i];
    }
    vector<int> q;
    for (int i=1; i<=n; i++){
        vector<bool> visited(n+1, false);

        visited[i]=true;
        find(visited, two, i, two[i], answer);
    }

    cout<<answer.size()<<endl;
    sort(answer.begin(), answer.end());
    for (int i=0; i<answer.size(); i++){
        cout<<answer[i]<<endl;
    }



}