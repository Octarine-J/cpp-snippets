#include <map>

#include <catch2/catch_test_macros.hpp>

/**
 * map is implemented using black-red balanced search tree; insert, delete, lookup: O(log n)
 * it is sorted based on operator<
 * hence implementing operator< is essential for custom keys
 */
TEST_CASE( "Search in Map" ) {
    std::map<int, std::string> numbers {
            {1, "one"},
            {2, "two"},
            {3, "three"}
    };

    REQUIRE( numbers.size() == 3 );
    REQUIRE( numbers[2] =="two" );

    // operator[] inserts a default value if an element is not found!
    REQUIRE( numbers[10].empty() );
    REQUIRE( numbers.size() == 4 );

    // use find() to avoid creating new elements
    REQUIRE( numbers.find(100) == numbers.end() );

    auto it = numbers.find(3);  // returns iterator pointing to the entry
    REQUIRE( it->second == "three" );
}


TEST_CASE( "Insert into Map does not Override Values" ) {
    std::map<std::string, int> ids;

    ids.insert({"John", 10});

    auto [it, success] = ids.insert({"John", 20});  // result is <iterator, bool>

    REQUIRE( success == false );   // insertion failed
    REQUIRE( ids["John"] == 10 );  // old value

    // C++17: new method to allow overriding values
    ids.insert_or_assign("John", 30);  // NOTE: different signature

    REQUIRE( ids["John"] == 30 );
}


TEST_CASE( "Update a Value in Map" ) {
    std::map<int, std::string> numbers {
            {1, "one"},
            {2, "two"},
            {3, "three"}
    };

    // first find the element
    auto it = numbers.find(2);

    REQUIRE( it != numbers.cend() );

    // then update the value using the iterator pointing to the element
    it->second = "zwei";

    REQUIRE( numbers[2] == "zwei" );
}


TEST_CASE( "Remove a Value from Map" ) {
    std::map<int, std::string> numbers {
            {1, "one"},
            {2, "two"},
            {3, "three"}
    };

    // number of elements matching a key
    REQUIRE( numbers.count(1) == 1);

    // erase an element by key
    numbers.erase(1);

    REQUIRE( numbers.count(1) == 0 );
}


TEST_CASE( "Using Map in a For-Loop" ) {
    std::map<std::string, std::string> animals {
            {"cat", "White"},
            {"dog", "Spot"}
    };

    for (const auto& [animal, name] : animals) {
        REQUIRE( (animal == "cat" or animal == "dog") );
        REQUIRE( (name == "White" or name == "Spot") );
    }
}


TEST_CASE( "Move Nodes between Maps" ) {
    std::map<std::string, int> deptA {
            {"John", 10},
            {"Kevin", 11},
            {"Sebastian", 12}
    };

    std::map<std::string, int> deptB;

    // move a node
    auto node_handle = deptA.extract("John");
    deptB.insert(std::move(node_handle));

    REQUIRE( deptA.size() == 2);
    REQUIRE( deptB.size() == 1);

    // move ALL nodes (nodes that cannot be merged remain in the old map)
    deptB.merge(deptA);

    REQUIRE( deptA.empty() );
    REQUIRE( deptB.size() == 3);
}
