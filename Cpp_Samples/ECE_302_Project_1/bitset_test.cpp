#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

TEST_CASE("Test bitset default constructor, and size and good functions", "[bitset]")
{
    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE("Test bit set alternate constructor a", "[bitset]") 
{
    Bitset b(12);  
    REQUIRE(b.size() == 12);
    REQUIRE(b.good());
}

TEST_CASE("Test bit set alternate constructor b and test function", "[bitset]") 
{
    Bitset b("0010101000000") ;
    REQUIRE(b.size() == 13) ;
    REQUIRE(b.good()) ;
    REQUIRE(b.test(2)) ;
    REQUIRE(b.test(4)) ;
    REQUIRE(b.test(6)) ;
}

TEST_CASE("Test toggle function", "[bitset]") 
{
    Bitset b ("01");
    b.toggle(0) ;
    b.toggle(1) ;
    REQUIRE(b.good()) ;
    REQUIRE(b.test(0)) ;
    REQUIRE(!b.test(1)) ;
}

TEST_CASE("Test reset function", "[bitset]") 
{
    Bitset b ;
    b.toggle(0) ;
    b.reset(0) ;
    REQUIRE(b.good()) ;
    REQUIRE(!b.test(0)) ;
}

TEST_CASE("Test set function", "[bitset]") 
{
    Bitset b ;
    b.set(0) ;
    REQUIRE(b.good()) ;
    REQUIRE(b.test(0)) ;
}

TEST_CASE("Test asString function", "[bitset]") 
{
    Bitset b ;
    REQUIRE(b.asString() == "00000000") ;
}