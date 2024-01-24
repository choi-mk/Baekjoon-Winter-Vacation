//https://www.acmicpc.net/problem/1149

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> red(n, 0);
    vector<int> green(n, 0);
    vector<int> blue(n, 0);
    int r, g, b;
    vector<int> answer; //r,g, b
    for (int i=0; i<n; i++){
        cin>>r>>g>>b;
        red[i]=r;
        green[i]=g;
        blue[i]=b;
    }
    answer.push_back(min(green[0], blue[0])+red[1]);
    answer.push_back(min(red[0], blue[0])+green[1]);
    answer.push_back(min(red[0], green[0])+blue[1]);
      /*for (int j=0; j<answer.size(); j++){
        cout<<answer[j]<<" ";
    }*/

    for (int i=2; i<n; i++){
        r=min(answer[1], answer[2])+red[i];
        g=min(answer[0], answer[2])+green[i];
        b=min(answer[0], answer[1])+blue[i];
        answer[0]=r;
        answer[1]=g;
        answer[2]=b;
          /*for (int j=0; j<answer.size(); j++){
        cout<<answer[j]<<" ";
    }*/

    }
    auto result=min_element(answer.begin(), answer.end());
    cout<<*result;

    
}