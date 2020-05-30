#include <string>
#include <queue>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

/**
 * Priority Queue is a container adapter, by default based on Deque.
 * It automatically sorts the values based on the priority.
 * For that to work, the type stored in the queue needs to define operator<
 */

struct process {
    std::string id;
    int priority;
};

bool operator<(const process& p1, const process& p2) {
    return p1.priority < p2.priority;
}


TEST_CASE( "Priority Queue Automatically Sorts by Priority" ) {
    std::priority_queue<process> queue;

    queue.emplace(process{"java", 2});
    queue.emplace(process{"gcc", 5});

    REQUIRE( queue.top().id == "gcc" );

    queue.emplace(process{"firefox", 3});

    REQUIRE( queue.top().id == "gcc" );

    queue.emplace(process{"system", 100});

    REQUIRE( queue.top().id == "system" );

    queue.pop();  // remove the top element

    REQUIRE( queue.top().id == "gcc" );

    queue.pop();

    REQUIRE( queue.top().id == "firefox" );
}

TEST_CASE( "Add and Remove from Priority Queue" ) {
    std::priority_queue<process> queue;

    REQUIRE( queue.empty() );

    process p1 {"firefox", 3};
    queue.push(p1);

    REQUIRE( queue.size() == 1 );

    queue.pop();

    REQUIRE( queue.empty() );
}
