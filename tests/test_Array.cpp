#include "catch2/matchers/catch_matchers_string.hpp"
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <string>

#include "data_structures/Array.hpp"

TEST_CASE("Array Basic operations", "[array]") {
    Array<int> array;

    REQUIRE(array.size() == 0);

    array.push_back(1);
    array.push_back(2);

    REQUIRE(array.size() == 2);
    REQUIRE(array.pop_back() == 2);
    REQUIRE(array.size() == 1);

    array.push_back(3);

    REQUIRE(array.size() == 2);
    REQUIRE(array.pop_back() == 3);
    REQUIRE(array.size() == 1);
    REQUIRE(array.pop_back() == 1);
    REQUIRE(array.size() == 0);

    array.push_back(1);
    array.push_back(2);
    array.push_back(4);
    array.insert(2, 3);

    REQUIRE(array[0] == 1);
    REQUIRE(array[1] == 2);
    REQUIRE(array[2] == 3);
    REQUIRE(array[3] == 4);

    array.remove(1);

    REQUIRE(array[0] == 1);
    REQUIRE(array[1] == 3);
    REQUIRE(array[2] == 4);
}

TEST_CASE("Array string operations", "[array-string]") {
    Array<std::string> array;

    array.push_back("abderrahmane");
    array.push_back("abdallah");
    array.push_back("puss-puss");
    array.insert(1, "rob");

    CHECK_THAT(array[0], Catch::Matchers::Equals("abderrahmane"));
    CHECK_THAT(array[1], Catch::Matchers::Equals("rob"));
    CHECK_THAT(array[2], Catch::Matchers::Equals("abdallah"));
    CHECK_THAT(array[3], Catch::Matchers::Equals("puss-puss"));
}
