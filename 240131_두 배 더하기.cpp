//https://www.acmicpc.net/problem/12931
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n, a;
    cin>>n;

    vector<int> lst(n, 0);
    for (int i=0; i<n; i++){
        cin>>a;
        lst[i]=a;
    }
    int answer=0;
    
    while(true){
        bool zero=true;
        for (int i=0; i<n; i++){
            if (lst[i]%2==1){
                answer+=1;
                lst[i]-=1;
            }
        }
        for (int i=0; i<n; i++){
            if (lst[i]!=0){
                zero=false;
                break;
            }
        }
        if (zero==false){
            answer+=1;
            for (int i=0; i<n; i++) lst[i]=lst[i]/2;
        }
        else break;
        //for (int i=0; i<n; i++) cout<<lst[i]<<" ";

    }
    cout<<answer;
    
}