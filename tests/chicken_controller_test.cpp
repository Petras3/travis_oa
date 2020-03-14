//
// Created by petras on 2020. 02. 19..
//

#include "catch.hpp"

#include <normal_chicken_controller.h>

class cMock : public stdChicken_controller {
public:
    int getCount() {
        return count;
    }

    int getSize() {
        return container.size();
    }

    int runExsist(){//TODO: semantic reformat -- ok
        int e = 0;

        for (auto it : container) {
            if(it.second.first->getActive()) {
                ++e;
            }
        }
        return  e;
    }
};

TEST_CASE("chicken_controller init") {
    cMock c;

    REQUIRE(c.getSize() == 0);
    REQUIRE(c.getCount() == 0);
}

TEST_CASE("chicken_controller create") {
    cMock c;

    c.createChicken();

    REQUIRE(c.getSize() == 1);
    REQUIRE(c.getCount() == 1);
}

TEST_CASE("chicken_controller stats") {
    cMock c;

    for(int i = 0; i < 5; i++ ) {
        c.createChicken();
    }

    //TODO: reformat stats and tests for stats -- ok
    REQUIRE(c.getStats().size() == 5);

    for (auto stat : c.getStats()) {
        REQUIRE(stat.active);
        REQUIRE(stat.interval > 1);
        REQUIRE(stat.interval < 11);
    }
}

TEST_CASE("chicken_controller stop") {
    cMock c;

    for(int i = 0; i < 5; i++ ) {
        c.createChicken();
    }

    REQUIRE(c.runExsist() == 5);

    c.stopAll();

    REQUIRE(!c.runExsist());
}

TEST_CASE("chicken_controller continue") {
    cMock c;

    for(int i = 0; i < 5; i++ ) {
        c.createChicken();
    }

    REQUIRE(c.getStats().size() == 5);

    for (auto stat : c.getStats()) {
        REQUIRE(stat.active);
        REQUIRE(stat.interval > 1);
        REQUIRE(stat.interval < 11);
    }

    REQUIRE(c.runExsist() == 5);

    c.stopAll();

    REQUIRE(!c.runExsist());

    for(int i = 0; i < 5; i++ ) {
        c.createChicken();
    }

    REQUIRE(c.getStats().size() == 10);
    REQUIRE(c.runExsist() == 5);
}

TEST_CASE("chicken_controller quit running") {
    cMock c;

    for(int i = 0; i < 5; i++ ) {
        c.createChicken();
    }

    c.quit();

    REQUIRE(!c.getSize());
}

TEST_CASE("chicken_controller quit stopped") {
    cMock c;

    for(int i = 0; i < 5; i++ ) {
        c.createChicken();
    }

    REQUIRE(c.runExsist() == 5);

    c.stopAll();

    REQUIRE(c.runExsist() == 0);

    c.quit();

    REQUIRE(!c.getSize());
}

TEST_CASE("chicken_controller quit all") {
    cMock c;

    for(int i = 0; i < 5; i++ ) {
        c.createChicken();
    }

    REQUIRE(c.getSize() == 5);

    c.stopAll();

    for(int i = 0; i < 5; i++ ) {
        c.createChicken();
    }

    REQUIRE(c.getSize() == 10);
    REQUIRE(c.runExsist() == 5);

    c.quit();

    REQUIRE(!c.getSize());
}
