#include "Menu.hpp"
#include <any>
#include <vector>

namespace YMM {
    Menu::Menu(std::string lable, func function) { 
        this->lable = lable;
        this->function = function;
    }

    Menu::Menu(std::string lable, std::vector<Menu> menus) {
        this->lable = lable;
        this->menus = menus;
    }

    Menu::Menu(std::string lable, func function, std::vector<std::any> params) { 
        this->lable = lable;
        this->function = function;
        this->params = params;
    }

    Menu::Menu(std::string lable, std::vector<Menu> menus, std::vector<std::any> params) {
        this->lable = lable;
        this->menus = menus;
        this->params = params;
    }

    Menu::Menu(const Menu& menu) {
        this->lable = menu.lable;
        this->menus = menu.menus;
        this->function = menu.function;
        this->params = menu.params;
    }

    void Menu::run(std::vector<std::any> params) {
        bool flag = true;
        while (flag) {
            this->printMenu();

            int select = -1;
            if (this->function == nullptr) {
                while (select < 0 || select > this->menus.size()) {
                    std::cout << "Select >> ";
                    select = input<int>();
                    std::cout << std::endl;
                }
                select--;

                if (select == -1) {
                    // exit
                    flag = false;
                } else {
                    // run submenu
                    if (this->params.empty()) {
                        menus[select].run(params);
                    } else {
                        menus[select].run(this->params);
                    }
                }

            } else {
                // run function
                if (this->params.empty()) {
                    function(params);
                } else {
                    function(this->params);
                }
                flag = false;
            }
        }
    }

    void Menu::printMenu() {
        if (this->function == nullptr) {
            std::cout << "\n\n";
            std::cout << "MENU:" << this->getLable() << std::endl;
            std::cout << "**====**" << std::endl;
        }

        for (int i = 0; i < this->menus.size(); i++) {
            std::cout << i + 1 << ". " << this->menus[i].getLable() << std::endl;
        }
    }

    std::string Menu::getLable() {
        return this->lable;
    }
}
