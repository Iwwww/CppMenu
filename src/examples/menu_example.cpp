#include "../Menu/Menu.hpp"
#include <any>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

void add_number(vector<any> params) {
    auto* numbers = any_cast<vector<int>*>(params[0]);
    cout << "input num:";
    int num = YMM::Menu::input<int>();
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

void func1(vector<any> params) {
    std::cout << "func1" << std::endl;
}

void func2(vector<any> params) {
    std::cout << "func2" << std::endl;
}

void func3(vector<any> params) {
    std::cout << "func3" << std::endl;
}

void func4(vector<any> params) {
    std::cout << "func4" << std::endl;
}

void func5(vector<any> params) {
    std::cout << "func5" << std::endl;
}

void func6(vector<any> params) {
    std::cout << "func6" << std::endl;
}

void func7(vector<any> params) {
    std::cout << "func7" << std::endl;
}

void func8(vector<any> params) {
    std::cout << "func8" << std::endl;
}

int main() {
    using namespace YMM;

    // init data
    vector<int> numbers{1, 2, 3, 4};

    vector<std::any> params{
        &numbers
    };
    
    Menu menu = Menu("Main", vector<Menu>{
            Menu("numbers", vector<Menu>{
                    Menu("add_number", add_number),
                    Menu("print_numbers", print_numbers)
                    }),
            Menu("functions 1", vector<Menu>{
                    Menu("func1", func1),
                    Menu("func2", func2)
                    }),
            Menu("functions 2", vector<Menu>{
                    Menu("func3", func3),
                    Menu("func4", func4)
                    })
            });

    menu.run(params);
 
    return 0;
}
