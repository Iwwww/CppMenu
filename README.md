# C++ Menu

 CppMenu позволяет быстро создавать меню с неограниченной вложенностью. Меню может содержать функции с любыми параметрами.
 
## Создание меню

 Экземпляр класс ```YMM::Menu``` может хранить как вектор с экземплярами класса ```YMM::Menu```, так и указатели на функции.

```
// указатель на фунцию "func"
Menu menu("Function", func);
```

```
// вектор Menu
Menu menu("Menu", vector<Menu>{});
```

### Меню с одним уровнем вложенности

```
Menu menu = Menu("Main", vector<Menu>{
        Menu("func1", func1),
        Menu("func2", func2),
        Menu("func3", func3),
        });
```

### Многовложенное меню

 ```
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
 
## Передачи аргументов
 В CppMenu используется типобезопасный конструктор [std::any](https://en.cppreference.com/w/cpp/utility/any) для хранения и передачи используемых в фунциях аргументов. Аргументы хранятся в векторе с типом [std::any](https://en.cppreference.com/w/cpp/utility/any) ```std::vector<std::any>```, что позволяет исользовать хранить любой тип данных:

```
vector<int> numbers{1, 2, 3, 4};

vector<any> params{
    &numbers
};
```

 В каждой используемой фунуции необходимо приводить параметры к типу:
```
auto* numbers_ptr = any_cast<vector<int>*>(params[0]);
```
