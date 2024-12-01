#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "data_structures/Dequeue.hpp"

TEST_CASE("Dequeue Basic operations", "[dequeue]") {
    Dequeue<int> dequeue;

    REQUIRE(dequeue.is_empty());

    dequeue.push_back(1); // 1
    dequeue.push_back(2); // 1, 2
    dequeue.push_front(2); // 2, 1, 2
    REQUIRE(dequeue.pop_front() == 2); // 1, 2
    REQUIRE(dequeue.size() == 2);
    dequeue.push_front(3); // 3, 1, 2
    REQUIRE(dequeue.pop_front() == 3); // 1, 2
    REQUIRE(dequeue.pop_front() == 1); // 2
    REQUIRE(dequeue.pop_front() == 2); // []
    
    REQUIRE(dequeue.is_empty());

    dequeue.push_back(1);
    dequeue.push_back(2);
    dequeue.push_back(3);
    dequeue.push_back(4);
    dequeue.push_back(5);
    dequeue.push_back(6);

    CHECK_FALSE(dequeue.is_empty());

    REQUIRE(dequeue.get_front() == 1);
    REQUIRE(dequeue.get_back() == 6);
}
