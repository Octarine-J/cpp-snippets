#include <catch2/catch_test_macros.hpp>

class Animal {
protected:
    [[nodiscard]]
    virtual std::string get_description() const {
        return "animal";
    }
public:
    [[nodiscard]]
    virtual std::string greet() const = 0;  // pure virtual method

    // abstract classes must always have the virtual destructor;
    // copy assignment operator and copy constructor,
    // as well as move assignment operator and move constructors
    // are not generated if the user-defined destructor is present
    virtual ~Animal() = default;

    void sleep() {}
};

class Cat final : public Animal {
public:
    [[nodiscard]]
    std::string greet() const override {
        return "meow!";
    }

    [[nodiscard]]
    std::string get_description() const override {
        // call superclass implementation
        return Animal::get_description() + " (cat)";
    }

    // cannot now call the original method with no parameters
    void sleep(int seconds) {};
    // unless we explicitly pull it from the parent:
    using Animal::sleep;  // it pulls all overloads with the same name at once
};

TEST_CASE( "Class Hierarchy" ) {
    Cat cat;
    cat.sleep();

    REQUIRE( cat.get_description() == "animal (cat)" );

    Animal& animal = cat;
    REQUIRE( animal.greet() == "meow!" );

    // typeid operator (a class must have vtable)
    REQUIRE( typeid(animal) == typeid(Cat) );
    REQUIRE( typeid(animal).name() == std::string("class Cat") );
}
