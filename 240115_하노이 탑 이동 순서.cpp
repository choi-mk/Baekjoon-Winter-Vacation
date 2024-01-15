//https://www.acmicpc.net/problem/11729
//cout쓰면 느려서 틀림 printf 써야함
#include <iostream>
#include <vector> 


using namespace std;


void move(int source, int des, int num){
    if (num==1){
        printf("%d %d\n", source, des);
        //cout<<source<<" "<<des<<endl;
    }
    else{
        move(source,6-source-des, num-1);
        printf("%d %d\n", source, des);
        //cout<<source<<" "<<des<<endl;
        move(6-source-des, des, num-1);
    }

}

int main(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    move(1, 3, n);

}