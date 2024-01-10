//https://www.acmicpc.net/problem/2447

#include <iostream>

using namespace std; 

void star(int n, int col, int row){
    if ((col/n)%3==1 &&(row/n)%3==1) cout<<' ';
    else{
        if(n/3==0) cout<<'*';
        else star(n/3, row, col);
    }
    
}

int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            star(n, j, i);
        }
        cout<<"\n";
    }

    return 0;
}