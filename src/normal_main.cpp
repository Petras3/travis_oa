//
// Created by petras on 2020. 02. 17..
//

#include <iostream>
#include <normal_chicken_controller.h>

int main () {

    int line = 0;

    stdChicken_controller controller;

    while  (!line) {
        std::cout << "Choose a menu point" << std::endl;
        std::cout << "1/\tCreate a new chicken" << std::endl;
        std::cout << "2/\tGet chickens status" << std::endl;
        std::cout << "3/\tStop chickens" << std::endl;
        std::cout << "4/\tQuit" << std::endl;

        std::cin >> line;

        if (line == 1 ) {
            controller.createChicken();
            line = 0;
        }
        else if (line == 2 ) {

            for (auto it : controller.getStats()) {
                std::cout << "id: " << it.id << " active: " << it.active << " interval: " << it.interval << " counter: " << it.counter << std::endl;
            }

            line = 0;
        }
        else if (line == 3 ) {
            controller.stopAll();
            line = 0;
        }
        else if (line == 4 ) {
            controller.quit();
        }
        else {
            std::cout << "Wrong input number" << std::endl;
            line = 0;
        }
    }

    return 0;
}
