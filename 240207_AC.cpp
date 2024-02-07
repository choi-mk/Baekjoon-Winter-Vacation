//https://www.acmicpc.net/problem/5430

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

int main(){
    int t, n;
    string p, num;
    cin>>t;
    for (int i=0; i<t; i++){
        string answer="";
        bool front=true;
        cin>>p>>n>>num;
        deque<int> number;
        num.erase(num.begin());
        num.pop_back();
        string a="";
        for (int j=0; j<num.size(); j++){
            if (num[j]==','){
                number.push_back(stoi(a));
                a="";
            }
            else{
                a+=num[j];
            }
        } 
        if (a!="") number.push_back(stoi(a));
        for (int j=0; j<p.size(); j++){
            if (p[j]=='R'){
                front=!front;
            }
            else{
                if(number.size()>0) {
                    if (front)number.pop_front();
                    else number.pop_back();
                }
                else{
                    answer="error";
                    break;
                }
            }
        }
        if (answer!="error"){
            answer="[";
            if (!front){
                for (int j=number.size()-1; j>=0; j--){
                    answer+=to_string(number[j]);
                    if (j!=0)answer+=',';
                }
            }
            else{
                for (int j=0; j<number.size(); j++){
                    answer+=to_string(number[j]);
                    if (j!=number.size()-1)answer+=',';
                }
            }
            
            answer+=']';
        }
        cout<<answer<<endl;
    }
}