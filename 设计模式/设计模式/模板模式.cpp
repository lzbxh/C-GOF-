//
//  模板模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/7.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

class MakeCar
{
protected:
    virtual void makeHead() = 0;
    virtual void makeBody() = 0;
    virtual void makeTail() = 0;
    
public:
    void make()     //模板函数 把 业务逻辑做好了
    {
        makeHead();
        makeBody();
        makeTail();
    }
};

class Jeep : public MakeCar
{
public:
    virtual void makeHead()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    virtual void makeBody()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    virtual void makeTail()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Bus : public MakeCar
{
public:
    virtual void makeHead()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    virtual void makeBody()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    virtual void makeTail()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};


int main()
{
    MakeCar *car = new Bus;
    car->make();
    
    MakeCar *car2 = new Jeep;
    car2->make();
    
    return 0;
}
