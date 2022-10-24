#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include <catch2/catch_test_macros.hpp>

class Cell {
private:
    int* value = nullptr;  // can init values in place
    mutable size_t value_accessed_times = 0;  // can change mutable variables in const methods

    // need to allocate space for static variables in this file separately
    static size_t count;

    // C++17: can use inline to avoid extra allocation line
    static inline size_t improved_count = 0;

    Cell() = default;
public:
    explicit Cell(int val) : value(new int(val)) {
        ++count;
        ++improved_count;
    }

    // delegating constructor: can just call another constructor,
    // cannot have other initializers (e.g., for other fields)
    explicit Cell(const std::string& val) : Cell(std::stoi(val)) {}

    // copy constructor (NOTE: not used for assignments)
    // default copy constructor makes *shallow* copies
    Cell(const Cell& another) : Cell(*another.value) {}

    // assignment operator
    Cell& operator=(const Cell& rhs) {
        // always check for self-assignment
        if (this == &rhs) {
            return *this;
        }

        // use copy-and-swap idiom
        Cell tmp(rhs);
        swap(*this, tmp);
        return *this;
    }

    // for copy-and-swap idiom
    friend void swap(Cell& lhs, Cell& rhs) noexcept;

    // move constructor: should always be marked noexcept
    // should be implemented for classes intended to be used with std containers
    Cell(Cell&& src) noexcept : Cell() {
        swap(*this, src);
    }

    // move assignment: should always be marked noexcept
    // should be implemented for classes intended to be used with std containers
    Cell& operator=(Cell&& rhs) noexcept {
        if (this == &rhs) {
            return *this;
        }

        // the old memory will be freed when the destructor of tmp is called
        Cell tmp(std::move(rhs));
        swap(*this, tmp);

        return *this;
    }

    friend bool operator==(const Cell& right, const Cell& left);

    int get_value() const {
        value_accessed_times += 1;
        return *value;
    }

    ~Cell() {
        delete value;
    }
};

// allocating space for static variable
size_t Cell::count = 0;

bool operator==(const Cell& right, const Cell& left) {
    return *(right.value) == *(left.value);
}

void swap(Cell& lhs, Cell& rhs) noexcept {
    std::swap(rhs.value, lhs.value);  // std::swap never throws exceptions
    std::swap(rhs.value_accessed_times, lhs.value_accessed_times);
}

class CellUtils {
public:
    CellUtils() = delete;  // do not create the default constructor
    CellUtils(const CellUtils& other) = delete;  // no copy constructor
    CellUtils& operator=(const CellUtils& other) = delete;  // no assignment operator

    static std::string format(int cell_id, const Cell& cell) {
        std::stringstream ss;
        ss << "Cell " << cell_id << ": " << cell.get_value();
        return ss.str();
    }
};

class CellArray {
    std::vector<Cell> cells;

    // C++17: can allocate storage for a static variable inside the class (inline)
    static inline size_t last_id = 1;
public:
    CellArray(std::initializer_list<Cell> cells) : cells {cells} {}

    // often we need const and non-const versions of the same function...
    const Cell& cell_at(int pos) const {
        return cells.at(pos);
    }

    // we can use const_cast pattern to avoid duplication
    Cell& cell_at(int pos) {
        // delegate to the already defined method
        return const_cast<Cell&>(std::as_const(*this).cell_at(pos));
    }

    // prohibit calling this method with double (implicit conversion)
    const Cell& cell_at(double pos) const = delete;
    Cell& cell_at(double pos) = delete;
};

TEST_CASE( "Classes" ) {
    Cell cell {3};  // allocating on stack
    REQUIRE( CellUtils::format(1, cell) == "Cell 1: 3" );

    auto cell2 = std::make_unique<Cell>(42); // allocating on heap
    REQUIRE( CellUtils::format(2, *cell2) == "Cell 2: 42" );

    Cell cell3 = *cell2;  // using copy constructor
    REQUIRE( CellUtils::format(3, cell3) == "Cell 3: 42" );

    cell3 = cell; // using assignment operator
    REQUIRE( CellUtils::format(3, cell3) == "Cell 3: 3" );

    Cell cell4 {"123"};
    REQUIRE( CellUtils::format(4, cell4) == "Cell 4: 123" );

    Cell cell5 {7};
    cell5 = std::move(cell3);
    REQUIRE( CellUtils::format(5, cell5) == "Cell 5: 3" );

    CellArray array {cell, cell4};
    REQUIRE( array.cell_at(1) == cell4 );

    array.cell_at(0) = cell5;  // using non-const version of the function
    REQUIRE( array.cell_at(0) == cell5 );
}
