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

class Cat : public Animal {
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

class Siberian final : public Cat {};

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

TEST_CASE( "Dynamic Cast" ) {
    Siberian siberian;
    Cat* p_cat = &siberian;

    // having a pointer to Cat, we want to restore a pointer to Siberian
    // NOTE: class must have at least 1 virtual method for dynamic_cast to work
    Siberian* p_siberian = dynamic_cast<Siberian*>(p_cat);
    REQUIRE( p_siberian == &siberian );
}

TEST_CASE( "Dynamic Cast Failure" ) {
    Cat cat;
    Cat* p_cat = &cat;

    // cast down the hierarchy, but p_cat points to Cat, not Siberian
    Siberian* p_siberian = dynamic_cast<Siberian*>(p_cat);
    REQUIRE( p_siberian == nullptr );  // cast fails, Cat is not Siberian

    // in case of a reference
    Cat& r_cat = cat;
    REQUIRE_THROWS_AS( dynamic_cast<Siberian&>(r_cat), std::bad_cast );
}
