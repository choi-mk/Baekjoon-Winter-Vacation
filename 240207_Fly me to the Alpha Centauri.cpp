//https://www.acmicpc.net/problem/1011
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    int x, y, num;
    for (int i=0; i<t; i++){
        int answer=0;
        cin>>x>>y;
        num=static_cast<int>(sqrt(y-x));
        while(answer*num<y-x-pow(num, 2)) answer++;
        cout<<answer+2*num-1<<endl;


    }
}