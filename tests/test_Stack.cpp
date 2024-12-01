#include "catch2/matchers/catch_matchers_string.hpp"
#include <string>
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "data_structures/Stack.hpp"

TEST_CASE("Stack Basic operations", "[stack]") {
    Stack<int> stack;

    stack.push(2);

    REQUIRE(stack.peek() == 2);
    REQUIRE(stack.pop() == 2);

    REQUIRE(stack.is_empty());

    for (int i = 0; i < 10; i++) {
        stack.push(i);
    }

    CHECK_FALSE(stack.is_empty());
    REQUIRE(stack.size() == 10);

    for (int i = 9; i >= 0; i--) {
        REQUIRE(stack.pop() == i);
    }

    REQUIRE(stack.is_empty());
}

TEST_CASE("Stack operations on string", "[stack-string]") {
    Stack<std::string> stack;

    REQUIRE(stack.is_empty());

    stack.push("abderrahmane");
    CHECK_THAT(stack.peek(), Catch::Matchers::Equals("abderrahmane"));

    stack.push("ismail");
    CHECK_THAT(stack.peek(), Catch::Matchers::Equals("ismail"));

    stack.push("test");
    CHECK_THAT(stack.peek(), Catch::Matchers::Equals("test"));

    stack.push("test2");
    CHECK_THAT(stack.peek(), Catch::Matchers::Equals("test2"));

    CHECK_FALSE(stack.is_empty());

    REQUIRE(stack.size() == 4);

    CHECK_THAT(stack.pop(), Catch::Matchers::Equals("test2"));
    CHECK_THAT(stack.pop(), Catch::Matchers::Equals("test"));
    CHECK_THAT(stack.pop(), Catch::Matchers::Equals("ismail"));
    CHECK_THAT(stack.pop(), Catch::Matchers::Equals("abderrahmane"));

    REQUIRE(stack.is_empty());
    REQUIRE(stack.size() == 0);
}
