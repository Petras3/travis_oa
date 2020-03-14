//
// Created by petras on 2020. 02. 17..
//

#ifndef CHICKEN_FARM_CHICKEN_CONTROLLER_H
#define CHICKEN_FARM_CHICKEN_CONTROLLER_H

#include <map>
#include <vector>

#include "chicken/normal_chicken.h"

struct Stats{
    int id;
    int interval;
    int counter;
    bool active;
};

class stdChicken_controller {
public:

    void createChicken();

    std::vector<Stats> getStats();//TODO: reformat stats -- ok

    void stopAll();

    void quit();

protected:

    int count = 0;

    std::map<int, std::pair<stdChicken* ,std::thread*>> container;
};


#endif //CHICKEN_FARM_CHICKEN_CONTROLLER_H
