#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Meeting {
    unsigned int start = 0; 
    unsigned int end = 0;
};

struct Room {
    unsigned int endtime = 0;
};

struct CompareRooms {
    bool operator()(const Room& room1, const Room& room2) const {
        return room1.endtime > room2.endtime;
    }
};

int main() {
    int N;
    scanf("%d", &N);
    vector<Room> rooms;

    Meeting *Meetings = new Meeting[N];
    int totalrooms = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &Meetings[i].start, &Meetings[i].end);
    }

    sort(Meetings, Meetings + N, [](const Meeting& m1, const Meeting& m2) {
        return m1.start < m2.start;
    });

    priority_queue<Room, vector<Room>, CompareRooms> pq;

    for (int i = 0; i < N; i++) {
        if (pq.empty() || pq.top().endtime > Meetings[i].start) {
            // Allocate a new room
            Room newroom;
            newroom.endtime = Meetings[i].end;
            rooms.push_back(newroom);
            pq.push(newroom);
            totalrooms++;
        } else {
            // Use an existing room
            Room room = pq.top();
            pq.pop();
            room.endtime = Meetings[i].end;
            pq.push(room);
        }
    }

    printf("%d", totalrooms);

    return 0;
}
