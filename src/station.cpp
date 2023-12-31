#include <station.h>

void Station_A::DoWork(int& workpiece) {
        workpiece++;
}

int Station_A::GetNextStation() {
        return 1;
};

void Station_B::DoWork(int& workpiece) {
    workpiece--;
}
int Station_B::GetNextStation() {
    return 1;
}

void Station_C::DoWork(int& workpiece) {
    if(workpiece%2 == 0) {
        skip_next_station = true;
    } else {
        skip_next_station = false;
    }
}

int Station_C::GetNextStation() {
    return (skip_next_station == true) ? 2 : 1;
}