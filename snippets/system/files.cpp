#include <filesystem>
#include <fstream>
#include <vector>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Check File Exists" ) {
    std::filesystem::path p = "CMakeFiles/TargetDirectories.txt";

    REQUIRE( std::filesystem::exists(p) );  // file exists
    REQUIRE( std::filesystem::is_regular_file(p) );
}

TEST_CASE( "Read File by Path" ) {
    std::filesystem::path p = "./CMakeCache.txt";
    std::ifstream f {p};

    std::string token;
    f >> token;

    REQUIRE( token == "#" );
}

std::vector<std::filesystem::path> list_dir(const std::filesystem::path& p) {
    using namespace std::filesystem;

    if (!is_directory(p)) {
        return {};
    }

    std::vector<path> result;

    // use recursive_directory_iterator to include all subdirectories
    for (const directory_entry& entry : directory_iterator(p)) {
        result.push_back(entry);
    }
    return result;
}

TEST_CASE( "Enumerate Directory" ) {
    std::vector<std::filesystem::path> result = list_dir(".");
    REQUIRE( !result.empty() );
}

TEST_CASE( "Get Filename and Extension" ) {
    std::filesystem::path p = "./CMakeCache.txt";

    REQUIRE( p.stem() == "CMakeCache" );
    REQUIRE( p.extension() == ".txt" );
}

TEST_CASE( "Current Working Directory" ) {
    std::filesystem::path p = std::filesystem::current_path();
    REQUIRE( !p.empty() );
}

TEST_CASE( "File Operations" ) {
    using namespace std::filesystem;
    const path tmp_dir {"tmp"};
    const path filename {"CMakeCache.txt"};

    bool result = create_directory(tmp_dir);
    REQUIRE( result );

    copy(filename, tmp_dir);
    size_t sz = file_size(tmp_dir / filename);
    REQUIRE( sz > 0 );

    remove(tmp_dir / filename );
    remove(tmp_dir);
}
