//https://www.acmicpc.net/problem/11053
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> numbers(n);
    for (int i=0; i<n; i++){
        cin>>numbers[i];
    }
  
    vector<int> result(n,1);
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            if(numbers[j]<numbers[i]){
                result[i]=max(result[i], result[j]+1);
            }
        }
        
    }
    int answer=*max_element(result.begin(), result.end());
    cout<<answer;
    return 0;

}