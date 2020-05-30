#include <exception>
#include <iostream>
#include <string>

// can set a custom handler which runs when the app is terminated by an unchaught exception
void custom_terminate_handler() {
    // usually used to create a crash dump, which can be later examined
    std::cout << "Uncaught exception!" << std::endl;
    exit(0xff);
}

// custom exception class
class InputException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Your input does not contain a number.";
    }
};

int read_number() {
    std::cout << "Enter a number: ";

    int x;
    std::cin >> x;

    if (!std::cin) {
        throw InputException();
    }

    return x;
}

int main() {
    // set custom program terminate handler
    std::set_terminate(custom_terminate_handler);

    try {
        std::cout << read_number() << std::endl;
    } catch (const InputException& e) {
        std::cout << e.what() << std::endl;
        return 1;
    } catch (const std::runtime_error& e) {
        // throw another exception that includes the current exception
        std::throw_with_nested(std::logic_error("includes a runtime_error"));  // see *1
    } catch (const std::overflow_error& e) {
        throw;  // re-throw the current exception (NOTE: do not use 'throw e', it causes slicing)
    } catch (...) {
        // all other exceptions
        return 2;
    }

    /* Standard exception classes:
    - exception    // generic, no args
    
    - runtime_error:
    . range_error
    . overflow_error, underflow_error
    
    - logic_error:
    . domain_error
    . invalid_argument
    . length_error
    . out_of_range
    */

    /* 
    NOTE *1: how to catch a nested exception:
    
    try {
        // ...
    } catch (const std::logic_error& e) {
        try {
            std::rethrow_if_nested(e);
        } catch (const runtime_error& e) {
            // Handle nested exception
            cout << "  Nested exception: " << e.what() << endl;
        }
    }
    */
    
    return 0;
}
