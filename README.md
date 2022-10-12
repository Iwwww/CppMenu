# CppMenu

 CppMenu позволяет быстро создавать меню с неограниченной вложенностью. Меню может содержать функции с любыми параметрами.

- [Cpp Menu](#cpp-menu)
  - [Создание меню](#создание-меню)
    - [Меню с одним уровнем вложенности](#меню-с-одним-уровнем-вложенности)
    - [Многовложенное меню](#многовложенное-меню)
  - [Аргументы](#аргументы)
 
## Создание меню

 Экземпляр класс ```YMM::Menu``` может хранить как вектор с экземплярами класса ```YMM::Menu```, так и указатели на функции.

```c++
// указатель на фунцию "func"
Menu menu("Function", func);
```

```c++
// вектор Menu
Menu menu("Menu", vector<Menu>{});
```

### Меню с одним уровнем вложенности

```c++
Menu menu = Menu("Main", vector<Menu>{
        Menu("func1", func1),
        Menu("func2", func2),
        Menu("func3", func3),
        });
```

### Многовложенное меню

```c++
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

```
 
## Аргументы
 В CppMenu используется типобезопасный контейнер [std::any](https://en.cppreference.com/w/cpp/utility/any) для хранения и передачи аргументов в функии. Аргументы хранятся в векторе с типом [std::any](https://en.cppreference.com/w/cpp/utility/any) ```std::vector<std::any>```, что позволяет передавать любой тип данных:

```c++
vector<int> numbers{1, 2, 3, 4};

vector<any> params{
    &numbers
};
```

 В теле каждой используемой фунуции необходимо приводить параметры к типу, используя ```std::any_cast```:

```c++
auto* numbers_ptr = any_cast<vector<int>*>(params[0]);
```
