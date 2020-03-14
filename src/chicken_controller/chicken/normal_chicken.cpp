//
// Created by petras on 2020. 02. 17..
//

#include "normal_chicken.h"

stdChicken::stdChicken(int _interval) :
    interval(_interval)
{

}

stdStat stdChicken::getAll() {

    stdStat s{interval,counter,active};

    return  s;
}

bool &stdChicken::getActive() {
    return active;
}

int stdChicken::getCounter() {
    return counter;
}

int stdChicken::getInterval() {
    return interval;
}

void stdChicken::deactivate() {
    active = false;
}

void stdChicken::incCounter() {
    ++counter;
}
