#include <iostream>

class Animal {
protected:
    virtual std::string get_description() const {
        return "animal";
    }
public:
    virtual std::string greet() const = 0;

    // abstract classes must always have the virtual destructor;
    // copy assignment operator and copy constructor,
    // as well as move assignment operator and move constructors
    // are not generated if the user-defined destructor is present
    virtual ~Animal() = default;

    void sleep() {}
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
    void sleep(int seconds) {};
    // unless we explicitly pull it from the parent:
    using Animal::sleep;  // it pulls all overloads with the same name at once
};

int main() {
    Cat cat;
    std::cout << cat.get_description() << std::endl;
    cat.sleep();

    Animal& animal = cat;
    std::cout << animal.greet() << std::endl;

    // typeid operator (a class must have vtable)
    std::cout << "Animal is a cat: " << (typeid(animal) == typeid(Cat)) << std::endl;
    std::cout << "Animal is a " << typeid(animal).name() << "." << std::endl;
}
