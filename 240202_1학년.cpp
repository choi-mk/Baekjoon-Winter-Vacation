//https://www.acmicpc.net/problem/5557
#include <iostream>
#include <vector> 

using namespace std; 

int main(){
    vector<long long> num(21,0);
    vector<long long> new_num(21, 0);
    int n;
    cin>>n;
    vector<int> sang(n, 0);
    for (int i=0; i<n; i++){
        cin>>sang[i];
    }
    num[sang[0]]=1;
    for (int i=1; i<n-1; i++){
        for (int j=0; j<21; j++){
            if (j>=sang[i]) new_num[j-sang[i]]+=num[j];
            if (j+sang[i]<=20) new_num[j+sang[i]]+=num[j];
        }
        for (int k = 0; k < new_num.size(); ++k) {
            num[k]=new_num[k];
            new_num[k]=0;
        }
        //new_num.clear();
        /*for (int k = 0; k < new_num.size(); ++k) {
            cout<<num[k]<<" ";
        }*/
    }
    cout<<num[sang[n-1]];
}