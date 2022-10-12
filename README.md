# C++ Menu

## О передачи аргументов
 В CppMenu используется типобезопасный конструктор [std::any](https://en.cppreference.com/w/cpp/utility/any) для хранения и передачи используемых в фунциях данных. Аргументы хранятся в векторе с типом [std::any](https://en.cppreference.com/w/cpp/utility/any) ```std::vector<std::any>```, что позволяет исользовать хранить любой тип данных.
