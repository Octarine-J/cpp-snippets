#include <iostream>

#include <catch2/catch_test_macros.hpp>

class Animal {
protected:
    // overridable method
    virtual std::string get_description() const {
        return "animal";
    }
public:
    virtual std::string greet() const = 0;  // pure virtual method

    // abstract classes must always have the virtual destructor;
    // copy assignment operator and copy constructor,
    // as well as move assignment operator and move constructors
    // are not generated if the user-defined destructor is present
    virtual ~Animal() = default;

    void sleep() const {
        std::cout << get_description() << " sleeps\n";
    }
};

class Cat final : public Animal {
public:
    std::string greet() const override {
        return "meow!";
    }

    std::string get_description() const override {
        // call superclass implementation
        return Animal::get_description() + " (cat)";
    }

    // cannot now call the original method with no parameters
    void sleep(int seconds) const {
        std::cout << get_description() << " sleeps for " << seconds << " s.\n";
    };
    // unless we explicitly pull it from the parent:
    using Animal::sleep;  // it pulls all overloads with the same name at once
};

TEST_CASE( "Class Hierarchy" ) {
    Cat cat;
    cat.sleep();
    cat.sleep(5);

    REQUIRE( cat.get_description() == "animal (cat)" );

    Animal& animal = cat;
    REQUIRE( animal.greet() == "meow!" );

    // typeid operator (a class must have vtable)
    REQUIRE( typeid(animal) == typeid(Cat) );

    // printable class name, differs between compilers
    // g++: 3Cat, MSVC: class Cat
    std::string printable_name = std::string(typeid(animal).name());
    REQUIRE( printable_name.find("Cat") != std::string::npos );
}
