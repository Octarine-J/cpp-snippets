#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Cell {
private:
    int* value = nullptr;  // can init values in place
    mutable size_t value_accessed_times = 0;  // can change mutable variables in const methods 

    Cell() = default;
public:
    Cell(int val) : value(new int(val)) {}

    // delegating constructor: can just call another constructor,
    // cannot have other initializers (e.g., for other fields)
    explicit Cell(std::string val) : Cell(std::stoi(val)) {}

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

    // move constructor
    Cell(Cell&& src) noexcept : Cell() {
        swap(*this, src);
    }

    // move assignment
    Cell& operator=(Cell&& rhs) noexcept {
        if (this == &rhs) {
            return *this;
        }

        // the old memory will be freed when the destructor of tmp is called
        Cell tmp(std::move(rhs));
        swap(*this, tmp);

        return *this;
    }

    int get_value() const {
        value_accessed_times += 1;
        return *value;
    }

    ~Cell() {
        delete value;
    }
};

void swap(Cell& rhs, Cell& lhs) noexcept {
    std::swap(rhs.value, lhs.value);  // std::swap never throws exceptions
    std::swap(rhs.value_accessed_times, lhs.value_accessed_times);
}

class CellUtils {
public:
    CellUtils() = delete;  // do not create the default constructor
    CellUtils(const CellUtils& other) = delete;  // no copy constructor
    CellUtils& operator=(const CellUtils& other) = delete;  // no assignment operator

    static void print(int cell_id, const Cell& cell) {
        std::cout << "Cell " << cell_id << ": " << cell.get_value() << std::endl;
    }
};

class CellArray {
    std::vector<Cell> cells;

    // C++17: can allocate storage for a static variable inside the class (inline)
    static inline size_t last_id = 1;  
public:
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

int main() {
    Cell cell {3};  // allocating on stack
    CellUtils::print(1, cell);

    auto cell2 = std::make_unique<Cell>(42); // allocating on heap
    CellUtils::print(2, *cell2);

    Cell cell3 = *cell2;  // using copy constructor
    CellUtils::print(3, cell3);

    cell3 = cell; // using assignment operator 
    CellUtils::print(3, cell3);

    Cell cell4 {"123"};
    CellUtils::print(4, cell4);

    Cell cell5 {7};
    cell5 = std::move(cell3);
    CellUtils::print(5, cell5);
}
