//6068 시간관리하기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Task {
    int time;
    int deadline;
};

int main(){
    int N;
    scanf("%d", &N);

    vector<Task> tasks(N);
    for(int i=0; i<N; i++) scanf("%d %d", &tasks[i].time, &tasks[i].deadline);

    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
        return a.deadline > b.deadline;
    });

    int CurrentT = tasks[0].deadline;
    for(const Task& task : tasks){
        if (CurrentT <= task.deadline) {
            CurrentT-=task.time;
        }
        else{
            CurrentT=task.deadline-task.time;
        }
    }

    if(CurrentT<0) printf("-1");
    else printf("%d", CurrentT);
}