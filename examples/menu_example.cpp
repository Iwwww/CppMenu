#include "../src/Menu/Menu.hpp"
#include <any>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

void add_number(vector<any> params) {
    auto* numbers = any_cast<vector<int>*>(params[0]);
    int num = YMM::Menu::input<int>("input num: ");
    numbers->push_back(num);

}

void print_numbers(vector<any> params) {
    auto* numbers = any_cast<vector<int>*>(params[0]);
    cout << "numbers:";
    for (auto n: *numbers) {
        cout << n << " ";
    }
    cout << endl;
}

void print_strings(vector<any> params) {
    auto* strings = any_cast<vector<string>*>(params[0]);
    std::cout << "strings: ";
    for (auto s: *strings) {
        std::cout << s << " ";
    }
}

void input_string(vector<any> params) {
    auto* strings = any_cast<vector<string>*>(params[0]);
    string str = YMM::Menu::input<string>("input string: ");
    std::cout << std::endl;
    strings->push_back(str);
}

void func1(vector<any> params) {
    std::cout << "func1" << std::endl;
}

void func2(vector<any> params) {
    std::cout << "func2" << std::endl;
}


int main() {
    using namespace YMM;

    // init data
    vector<int> numbers{1, 2, 3, 4};
    vector<string> strings{"hello", "world"};
    vector<string> strings2{"other", "strings"};

    vector<std::any> params{
        &numbers
    };

    vector<std::any> params_string{
        &strings
    };

    vector<std::any> params_string2{
        &strings2
    };

    Menu menu = Menu("Main", vector<Menu>{
            Menu("numbers", vector<Menu>{
                    Menu("add_number", add_number),
                    Menu("print_numbers", print_numbers)
                    }),
            Menu("strings", vector<Menu>{
                    Menu("print_strings", print_strings),
                    Menu("input_string", input_string),
                    // params_string2 have priority over the params_string
                    Menu("print_strings2", print_strings, params_string2),
                    Menu("input_string2", input_string, params_string2),
                    }, params_string),
            Menu("functions 1", vector<Menu>{
                    Menu("func1", func1),
                    Menu("func2", func2)
                    }),
            }, params);
 
    menu.run();
 
    return 0;
}
