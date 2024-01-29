//https://www.acmicpc.net/problem/14891
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string turn(int dir, string cycle){
    string new_cycle;
    if (dir==1){
        new_cycle.push_back(cycle[7]);
        for(int i=0; i<7; i++){
            new_cycle.push_back(cycle[i]);
        }
    }
    else{
        for(int i=1; i<8; i++){
            new_cycle.push_back(cycle[i]);
        }
        new_cycle.push_back(cycle[0]);
    }
    return new_cycle;
}

int main(){
    vector<string> cycles(4,"0");
    for (int i=0; i<4; i++){
        cin>>cycles[i];
    }
    int k;
    cin>>k;
    int cycle, dir;
    for(int i=0; i<k; i++){
        cin>>cycle>>dir;
        if (cycle==1){
            if (cycles[0][2]!=cycles[1][6]){
                if(cycles[1][2]!=cycles[2][6]){
                    if(cycles[2][2]!=cycles[3][6]){
                        cycles[3]=turn(0-dir, cycles[3]);
                    }
                    cycles[2]=turn(dir, cycles[2]);
                }
                cycles[1]=turn(0-dir, cycles[1]);
            }
            cycles[0]=turn(dir, cycles[0]);
        }
        if (cycle==4){
            if (cycles[3][6]!=cycles[2][2]){
                if(cycles[2][6]!=cycles[1][2]){
                    if(cycles[1][6]!=cycles[0][2]){
                        cycles[0]=turn(0-dir, cycles[0]);
                    }
                    cycles[1]=turn(dir, cycles[1]);
                }
                cycles[2]=turn(0-dir, cycles[2]);
            }
            cycles[3]=turn(dir, cycles[3]);
        }
        if (cycle==2){
            if(cycles[1][2]!=cycles[2][6]){
                if(cycles[2][2]!=cycles[3][6]){
                    cycles[3]=turn(dir, cycles[3]);
                }
            cycles[2]=turn(0-dir, cycles[2]);
            }
            if(cycles[1][6]!=cycles[0][2]){
                cycles[0]=turn(0-dir, cycles[0]);
            }
            cycles[1]=turn(dir, cycles[1]);
        }
        if (cycle==3){
            if(cycles[2][6]!=cycles[1][2]){
                if(cycles[1][6]!=cycles[0][2]){
                    cycles[0]=turn(dir, cycles[0]);
                }
            cycles[1]=turn(0-dir, cycles[1]);
            }
            if(cycles[2][2]!=cycles[3][6]){
                cycles[3]=turn(0-dir, cycles[3]);
            }
            cycles[2]=turn(dir, cycles[2]);
        }
    }



    int answer=0;
    if (cycles[0][0]=='1') answer+=1;
    if (cycles[1][0]=='1') answer+=2;
    if (cycles[2][0]=='1') answer+=4;
    if (cycles[3][0]=='1') answer+=8;
    cout<< answer;
}