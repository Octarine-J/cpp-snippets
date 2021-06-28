#pragma once

#include <string>
#include <unordered_map>


struct Arg {
    std::string name;
    std::string value;

    int as_int() {
        if (value.empty()) {
            return 0;
        } else {
            return std::stoi(value);
        }
    }

    std::string or_default(std::string default_value) {
        if (value.empty()) {
            return default_value;
        } else {
            return value;
        }
    }

    int or_default(int default_value) {
        if (value.empty()) {
            return default_value;
        } else {
            return as_int();
        }
    }
};

/* Parses an argument according to the following rules:
 *       value -> ('', value)
 *        -arg -> ('arg', '')
 * --arg=value -> ('arg', 'value')
 */
Arg parse_arg(char *arg) {
    std::string s(arg);

    if (s.size() <= 1 || s[0] != '-') {
        return {"", s};
    }

    if (s[1] != '-' || s.size() == 2) {
        return {std::string(s.begin() + 1, s.end()), ""};
    }

    std::string arg_name, arg_value;
    auto arg_name_begin = s.begin() + 2;

    for (auto it = arg_name_begin; it != s.end(); ++it) {        
        if (*it == '=') {
            arg_name = std::string(arg_name_begin, it);
            arg_value = std::string(it + 1, s.end());
            break;
        }
    }

    return {arg_name, arg_value};
}

std::unordered_map<std::string, Arg> parse_args(int argc, char *argv[]) {
    if (argc <= 1) {
        return {};
    }

    std::unordered_map<std::string, Arg> args;

    for (int i = 1; i < argc; ++i) {
        Arg arg = parse_arg(argv[i]);
        args[arg.name] = arg;
    }

    return args;
}
