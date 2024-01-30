#include <iostream>
#include <algorithm>
using namespace std;

struct Task{
    int time;
    int deadline;
};

int main(){
    int N;
    scanf("%d", &N);
    Task* tasks = new Task[N];
    for(int i=0; i<N; i++) scanf("%d %d", &tasks[i].time, &tasks[i].deadline);

    sort(tasks, tasks+N, [](const Task& task1, const Task& task2){
        return task1.deadline > task2.deadline;
    });

    int currenttime = tasks[0].deadline;
    for(int i=0; i<N; i++){
        if(currenttime>=tasks[i].deadline){
            currenttime = tasks[i].deadline - tasks[i].time;
        }
        else currenttime-=tasks[i].time;
    }
    if(currenttime<0) printf("-1");
    else printf("%d", currenttime);

    return 0;
}

