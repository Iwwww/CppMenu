# C++ Menu
 CppMenu позволяет быстро создавать меню с неограниченной вложенностью. Меню может содержать функции с любыми параметрами.
 
## О передачи аргументов
 В CppMenu используется типобезопасный конструктор [std::any](https://en.cppreference.com/w/cpp/utility/any) для хранения и передачи используемых в фунциях данных. Аргументы хранятся в векторе с типом [std::any](https://en.cppreference.com/w/cpp/utility/any) ```std::vector<std::any>```, что позволяет исользовать хранить любой тип данных:

```
vector<int> numbers{1, 2, 3, 4};

vector<std::any> params{
    &numbers
};
```

 В каждой используемой фунуции необходимо приводить параметры к нужному типу:
```
auto* numbers_ptr = any_cast<vector<int>*>(params[0]);
```
