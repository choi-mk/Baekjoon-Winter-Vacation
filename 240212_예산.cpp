//https://www.acmicpc.net/problem/2512
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> money(n,0);
    long long a=0;
    for (int i=0;i<n; i++){
        cin>>money[i];
        a+=money[i];
    }
    sort(money.begin(), money.end());
    long long maxmoney;
    cin>>maxmoney;
    int answer=0;
    if (a<=maxmoney)cout<<money[n-1];
    else{
        int left=1;
        int right=money[n-1];
        while(left<=right){
            int mid=(left+right)/2;
            long long sum=0;
            for (int i=0; i<n; i++){
                sum+=min(mid, money[i]);
            }
            if (sum<=maxmoney){
                answer=mid;
                left=mid+1;
                
            }
            else right =mid -1;
        }
        cout<<answer;
    }
    
    
}
