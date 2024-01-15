//https://www.acmicpc.net/problem/9251

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    string a;
    string b;
    cin>>a>>b;
    vector<vector<int>> LCS(a.size()+1, vector<int>(b.size()+1,0));
    for (int i=0; i<a.size()+1; i++){
        for (int j=0; j<b.size()+1; j++){
            if (i==0 || j==0){
                LCS[i][j]=0;
            }
            else if (a[i-1]==b[j-1]){
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else{
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
    cout<<LCS[a.size()][b.size()];

    return 0;
}
