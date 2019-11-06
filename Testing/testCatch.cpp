#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by stu on 01/11/2019.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Characters are uppercased", "[alphanumeric]")
{
  REQUIRE(1+1==2);
}
#pragma clang diagnostic pop