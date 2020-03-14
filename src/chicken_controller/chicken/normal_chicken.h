//
// Created by petras on 2020. 02. 17..
//

#ifndef CHICKEN_FARM_CHICKEN_H
#define CHICKEN_FARM_CHICKEN_H

#include <thread>

struct stdStat{
    int interval;
    int counter;
    bool active;
};

class stdChicken {
public:

    explicit stdChicken(int _interval);

public:

    stdStat getAll();

    int getInterval();
    int getCounter();
    bool &getActive();

    void incCounter();
    void deactivate();//TODO: naming -- ok

private:

    int interval;
    int counter = 0;

    bool active = true;
};

//static function

static void running(stdChicken *c){
    while (c->getActive()) {
        std::this_thread::sleep_for(std::chrono::seconds(c->getInterval()));
        c->incCounter();
    }
}

#endif //CHICKEN_FARM_CHICKEN_H
