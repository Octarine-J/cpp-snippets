#include <charconv>

#include <catch2/catch_test_macros.hpp>


// High-level conversions

TEST_CASE( "Numbers to String" ) {
    REQUIRE( std::to_string(12345) == "12345" );
    REQUIRE( std::to_string(1.23e+3) == "1230.000000" );
}

TEST_CASE( "String to Int" ) {
    // leading spaces are ignored
    REQUIRE( std::stoi("12345") == 12345 );
    REQUIRE( std::stoi("0xa", nullptr, 16) == 10 );  // hex
    REQUIRE( std::stoi("  00100 ", nullptr, 2) == 4 );  // bin

    // partial conversion
    size_t pos = -1;
    REQUIRE( std::stoi("12eur", &pos) == 12 );
    REQUIRE( pos == 2 );  // position of the first not converted character

    // if pos is provided, but there were no failures, pos points past last char:
    REQUIRE( std::stoi("12345", &pos) == 12345 );
    REQUIRE( pos == 5 );
}

TEST_CASE( "String to Unsigned Long Long" ) {
    REQUIRE( std::stoull("9000000000000") == 9000000000000ull );
}

TEST_CASE( "String to Double" ) {
    REQUIRE( std::stod("3.1415") == 3.1415 );
}


// C++17: Low-level conversions
// they are low-level, because no memory is allocated (a buffer is required)

TEST_CASE( "Low Level Conversion: Int to String" ) {
    int value = 1234567;
    std::string buffer(10, ' ');

    std::to_chars_result result = std::to_chars(buffer.data(), buffer.data() + buffer.size(), value);

    REQUIRE( result.ec == std::errc() );  // conversion successful
    REQUIRE( buffer == "1234567   " );
}

TEST_CASE( "Low Level Conversion: Int to String (Failure)" ) {
    int value = 1234567;
    std::string buffer(5, ' ');

    std::to_chars_result result = std::to_chars(buffer.data(), buffer.data() + buffer.size(), value);

    REQUIRE( result.ec == std::errc::value_too_large );
}

TEST_CASE( "Low Level Conversion: String to Int" ) {
    int value;
    std::string buffer = "1234567  ";

    std::from_chars_result result = std::from_chars(buffer.data(), buffer.data() + buffer.size(), value);

    REQUIRE( result.ec == std::errc() );
    REQUIRE( value == 1234567 );
}

TEST_CASE( "Low Level Conversion: String to Int (Partial)" ) {
    int value;
    std::string buffer = "1234567usd";

    auto result = std::from_chars(buffer.data(), buffer.data() + buffer.size(), value);

    REQUIRE( result.ec == std::errc() );
    REQUIRE( value == 1234567 );
}

TEST_CASE( "Low Level Conversion: StrToInt (Failure due to Leading Whitespace)" ) {
    int value;
    std::string buffer = " 1234567";

    auto result = std::from_chars(buffer.data(), buffer.data() + buffer.size(), value);

    REQUIRE( result.ec == std::errc::invalid_argument );
}

TEST_CASE( "Low Level Conversion: Full Roundtrip" ) {
    double x = 0.312;

    const size_t buf_size = 8;
    std::string buffer(buf_size, ' ');

    // int to str
    auto [ptr_encode, err_encode] = std::to_chars(buffer.data(), buffer.data() + buf_size, x);
    REQUIRE( err_encode == std::errc{} );  // no error
    REQUIRE( buffer == "0.312   " );

    // str to int from the same buffer
    double y;
    auto [ptr_decode, err_decode] = std::from_chars(buffer.data(), buffer.data() + buf_size, y);
    REQUIRE( err_decode == std::errc{} );
    REQUIRE( y == 0.312 );
}
