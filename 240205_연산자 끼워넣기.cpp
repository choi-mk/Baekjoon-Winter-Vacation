//https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector> 
using namespace std;

void math(vector<int> op, int& max, int& min, int result, vector<int>& num, int place){
    if(place!=num.size()){
        for (int i=0; i<4; i++){
            if (op[i]!=0){
                vector<int> new_op=op;
                new_op[i]--;
                int new_result=result;
                if (i==0) new_result+=num[place];
                else if (i==1) new_result-=num[place];
                else if (i==2) new_result*=num[place];
                else new_result/=num[place];
                math(new_op, max, min, new_result, num, place+1);
            } 
        }
    }
    else{
        if (max<result) max=result;
        if (min>result) min=result;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> num(n, 0);

    for (int i=0; i<n; i++){
        cin>>num[i];
    }
    vector<int> op(4,0); //+-*/
    for (int i=0; i<4; i++){
        cin>>op[i];
    }
    int max=-1000000000;
    int min=1000000000;
    math(op, max, min, num[0], num, 1);
    cout<<max<<endl;
    cout<<min;
}