//
//  装饰模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/6.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

//动态的给一个对象添加一些额外的职责。就增加功能来说，此模式比生成子类更为灵活。

using namespace std;

class Car
{
public:
    virtual void show() = 0;
};

class RunCar : public Car
{
public:
    virtual void show()
    {
        cout << "run" << endl;
    }
};

//对传入的Car进行修饰，依赖关系
class SwimCarDirector : public Car
{
public:
    SwimCarDirector(Car *car)
    {
        _car = car;
    }
    
    void swim()
    {
        cout << "swim" << endl;
    }
    
    virtual void show()
    {
        _car->show();
        swim();
    }
private:
    Car *_car;
};

class FlyCarDirector : public Car
{
public:
    FlyCarDirector(Car *car)
    {
        _car = car;
    }
    
    void fly()
    {
        cout << "fly" << endl;
    }
    
    virtual void show()
    {
        _car->show();
        fly();
    }
private:
    Car *_car;
};

int main()
{
    RunCar rc;
    rc.show();
    
    cout << "==========" << endl;
    //装饰
    SwimCarDirector sc(&rc);
    sc.show();
    
    cout << "==========" << endl;
    FlyCarDirector fc(&rc);
    fc.show();
    
    return 0;
}
















