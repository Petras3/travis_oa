//
// Created by petras on 2020. 02. 19..
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <normal_chicken.h>

TEST_CASE("chicken init") {
    stdChicken c(5);

    REQUIRE(c.getActive());
    REQUIRE(c.getCounter() == 0);
    REQUIRE(c.getInterval() == 5);
}

TEST_CASE("chicken inc") {
    stdChicken c(5);

    REQUIRE(c.getCounter() == 0);

    c.incCounter();

    REQUIRE(c.getCounter() == 1);
}

TEST_CASE("chicken set") {
    stdChicken c(5);

    REQUIRE(c.getActive());

    c.deactivate();

    REQUIRE(!c.getActive());
}

TEST_CASE("chicken all") {
    stdChicken c(5);

    REQUIRE(c.getAll().counter == 0);
    REQUIRE(c.getAll().interval == 5);
    REQUIRE(c.getAll().active);
}

TEST_CASE("chicken running") {
    stdChicken c(5);

    std::thread t(running,&c);

    std::this_thread::sleep_for(std::chrono::seconds(25));//TODO: if sleep == 25 test runtime = 25.001, if sleep == 26 test runtime = 30.002 ??

//    for(int i = 0; i < 5; i++) {
//        std::this_thread::sleep_for(std::chrono::seconds(5));
//    }
    //TODO: set waiting time inside an interval and test for that -- ok
    c.deactivate();

    t.join();

    REQUIRE(c.getCounter() == 5);
//    REQUIRE(c.getCounter() > 3);
//    REQUIRE(c.getCounter() < 7);
}
