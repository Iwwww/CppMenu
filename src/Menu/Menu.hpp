#pragma once
#include <any>
#include <iostream>
#include <string>
#include <vector>

namespace YMM {

class Menu {
public:
  using func = void (*)(std::vector<std::any>);
  Menu(std::string lable, func function);
  Menu(std::string lable, std::vector<Menu> menus);
  Menu(std::string lable, func function, std::vector<std::any> params);
  Menu(std::string lable, std::vector<Menu> menus,
       std::vector<std::any> params);
  Menu(const Menu &menu);

  void run(std::vector<std::any> params);
  void printMenu();
  std::string getLable();

  template <typename T> static T input() { return input<T>(""); }

  template <typename T> static T input(std::string str) {
    T input_str{};
    bool flag = true;
    while (flag) {
      std::cout << str;
      if (std::cin >> input_str) {
        flag = false;
      } else {
        std::cin.clear();
        while (std::cin.get() != '\n')
          ;
      }
    }

    return input_str;
  }

private:
  std::vector<std::any> params{};
  std::string lable{};
  std::vector<Menu> menus{};
  func function = nullptr;
};
} // namespace YMM
