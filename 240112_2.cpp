//https://www.acmicpc.net/problem/16953
#include <iostream>
#include <vector>
using namespace std; 



int main(){
    int a, b;
    cin>>a>>b;
    int count=1;
    while(b>a){
        if (b%2==0)b=b/2;
        else{
            if (b%10==1)b=b/10;
            else b=-1;
        }
        count++;
    }
    if (a==b) cout<<count;
    else cout<<-1;

    return 0;
}