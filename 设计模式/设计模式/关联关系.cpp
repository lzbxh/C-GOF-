//
//  关联关系.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/4.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

class Car
{
public:
    void drive()
    {
        
    }
};

class Person
{
public:
    Person()
    {
        _car = new Car;
    }
    void goWork()
    {
        _car->drive();
    }
private:
    Car *_car;
};


int main()
{
    return 0;
}
