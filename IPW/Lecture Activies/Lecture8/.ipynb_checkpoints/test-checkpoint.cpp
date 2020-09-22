#define CATCH_CONFIG_MAIN
#include "functions_to_implement.cpp"
#include <catch.hpp>
#include <vector>
#include <string>

TEST_CASE ( "Sum is computed", *Sum*){
    std::vector<int> v{1,2,3};
    REQUIRE( Sum(v) == 6);
    std::vector<int> b{1,5,0};
    REQUIRE( Sum(b) == 6);
    std::vector<int> c{1,2,-1};
    REQUIRE( Sum(c) == 2);
}

TEST_CASE ("Sign is computed", *Sign*){
    double n = 1.2;
    REQUIRE( Sign(n) == 1);
    n = -10;
    REQUIRE( Sign(n) == -1);
    n = 0;
    REQUIRE( Sign(n) == 1);
}