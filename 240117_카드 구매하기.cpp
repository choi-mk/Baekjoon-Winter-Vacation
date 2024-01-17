//https://www.acmicpc.net/problem/11052
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> cardpack;
    int num;
    cardpack.push_back(0);
    for (int i=1; i<=n; i++){
        cin>>num;
        cardpack.push_back(num);
    }
    vector<int> cardnum(n+1,0);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            cardnum[i]=max(cardnum[i],cardnum[i-j]+cardpack[j]);
        }
        
    }
    cout<<cardnum[n];
}