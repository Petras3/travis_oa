//
// Created by petras on 2020. 02. 17..
//

#include "normal_chicken_controller.h"

#include <iostream>
#include <random>

void stdChicken_controller::createChicken() {
    //int p;
    //p = std::rand() % 10 + 2;//TODO: std::random_device + mt19937 -- ok

    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution <int> rnd(2,10);

    container[count].first = new stdChicken(rnd(mt));
    container[count].second = new std::thread(running,container[count].first);
    ++count;
}

 std::vector<Stats> stdChicken_controller::getStats() {
    std::vector<Stats> out;

    for (auto it : container) {
        Stats temp {it.first,it.second.first->getAll().interval,it.second.first->getAll().counter,it.second.first->getAll().active};
        out.push_back(temp);
    }
    return out;
}

void stdChicken_controller::stopAll() {
    for (auto it : container) {
        it.second.first->deactivate();
    }
}

void stdChicken_controller::quit() {
    for (auto it : container) {
        it.second.first->deactivate();
    }

    for (auto &it : container) {
        it.second.second->join();
        delete  it.second.second;
        delete  it.second.first;
    }

    container.clear();
}
