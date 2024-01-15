//https://www.acmicpc.net/problem/1697
#include <iostream>
#include <vector> 
#include <utility>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> queue;
    vector<int> test(100001,0);
    queue.push_back(make_pair(n, 0));
    test[n]=1;
    int answer;
    for (int i=0; i<100002; i++){
        n=queue[i].first;
        //cout<<n<<endl;
        answer=queue[i].second;
        if (n==k) break;
        else{
            if(n>0 && test[n-1]==0){
                queue.push_back(make_pair(n-1, answer+1));
                test[n-1]=1;
            }
            if(n<100000 && test[n+1]==0){
                queue.push_back(make_pair(n+1, answer+1));
                test[n+1]=1;
            }
            if (n<=50000 && test[n*2]==0){
                queue.push_back(make_pair(n*2, answer+1));
                test[n*2]=1;
            }
        }
    }
    cout<< answer;

}