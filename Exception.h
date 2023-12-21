//
// Created by 沈嘉瑞 on 2023.10.15.
//

#ifndef SIMPLE_CALCULATOR_EXCEPTION_H
#define SIMPLE_CALCULATOR_EXCEPTION_H
#include <stdexcept> // 包含stdexcept头文件以使用标准异常类
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <list>
#include <array>
#include <queue>
using namespace std;

const int MaxSize = 100;

//异常父类
class MyException:public exception{
public:
    explicit MyException(const char* message):errorMessage(message){}
    const char * what() const noexcept override{
        return errorMessage.c_str();
    }
private:
    string errorMessage;
};

//手动退出
class ExitException:public MyException{
public:
    ExitException(const char* message): MyException(message){}
};

//列表空异常
class ListEmptyExpection:public MyException{
public:
    ListEmptyExpection(const char* message): MyException(message){}
};

//数组空异常
class SqEmptyExpection:public MyException{
public:
    SqEmptyExpection(const char* message): MyException(message){}
};

//数组满异常
class SqFullExpection:public MyException{
public:
    SqFullExpection(const char* message): MyException(message){}
};

//数组下标异常
class SqIExpection:public MyException{
public:
    SqIExpection(const char* message): MyException(message){}
};

//没有找到异常
class NoFoundExpection:public MyException{
public:
    NoFoundExpection(const char* message): MyException(message){}
};

//重复添加异常
class AddSameExpection:public MyException{
public:
    AddSameExpection(const char* message): MyException(message){}
};

//数字异常
class NumberException:public MyException{
public:
    NumberException(const char* message): MyException(message){}
};

//AOV网有环异常
class AOVHasLoopException:public MyException{
public:
    AOVHasLoopException(const char* message): MyException(message){}
};
#endif //SIMPLE_CALCULATOR_EXCEPTION_H