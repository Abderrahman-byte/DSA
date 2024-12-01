#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "data_structures/Queue.hpp"

// TODO write more tests

TEST_CASE("Queue Basic operations", "[queue]") {
    Queue<int> queue;

    REQUIRE(queue.is_empty());

    queue.enqueue(0);

    CHECK_FALSE(queue.is_empty());
    REQUIRE(queue.peek() == 0);

    queue.enqueue(1);

    REQUIRE(queue.peek() == 0);
    REQUIRE(queue.dequeue() == 0);
    REQUIRE(queue.dequeue() == 1);
    REQUIRE(queue.is_empty());

    for (int i = 0; i < 10; i++) {
        queue.enqueue(i);
    }

    CHECK_FALSE(queue.is_empty());
    REQUIRE(queue.peek() == 0);

    for (int i = 0; i < 10; i++) {
        REQUIRE(queue.dequeue() == i);
    }

    REQUIRE(queue.is_empty());
}
