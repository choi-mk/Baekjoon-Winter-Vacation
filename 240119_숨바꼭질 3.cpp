//https://www.acmicpc.net/problem/13549
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    queue<pair<int, int>> q;
    queue<pair<int, int>> next_q;
    vector<bool> visited(100001,false);
    q.push(make_pair(n,0));
    //visited[n]=true;
    while(true){
        int num=q.front().first;
        int times=q.front().second;
        q.pop();
        visited[num]=true; ///왜인지 모르겠으나 여기다 두지 않으면 정답률 99%..
        if (num==k) {
            cout<< times<<endl;
            break;
        }
        if (num<k && num*2<100001 && !visited[num*2]){
            //visited[num*2]=true;
            q.push(make_pair(num*2,times));
        }
        if (num<100000 && !visited[num+1]){
            //visited[num+1]=true;
            next_q.push(make_pair(num+1, times+1));
        }
        if (num>0 && !visited[num-1]){
            //visited[num-1]=true;
            next_q.push(make_pair(num-1, times+1));
            
        }
        if (q.empty()){
            while(!next_q.empty()){
                q.push(next_q.front());
                next_q.pop();
            }
        }
    }
}