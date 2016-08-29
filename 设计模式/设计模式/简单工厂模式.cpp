//
//  简单工厂模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/6/25.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

class Fruit
{
public:
    virtual void getFruit() = 0;
    virtual ~Fruit()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Banana : public Fruit
{
public:
    virtual void getFruit()
    {
        cout << "Banana" << endl;
    }
    
    virtual ~Banana()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Pear : public Fruit
{
public:
    virtual void getFruit()
    {
        cout << "Pear" << endl;
    }
    
    virtual ~Pear()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

//简单工厂类
//工厂类与水果是 依赖 关系
//所有的创建逻辑都在工厂类中
//由于工厂类集中了所有实例的创建逻辑，所以“高内聚”方面做的并不好。
//另外，当系统中的具体产品类不断增多时，可能会出现要求工厂类也要做相应的修改，
//扩展性并不很好。
class Factory
{
public:
    static Fruit *Creat(const char *name)     //依赖关系
    {
        if (strcmp("Banana", name) == 0)
        {
            return new Banana;
        }
        else if (strcmp("Pear", name) == 0)
        {
            return new Pear;
        }
        else
        {
            cout << "不能生产" << endl;
            return NULL;
        }
    }
};

int main()
{
    Fruit *f1 = Factory::Creat("Banana");
    Fruit *f2 = Factory::Creat("Pear");
    Fruit *f3 = Factory::Creat("Apple");
    if (f1)
    {
        f1->getFruit();
        delete f1;
        f1 = NULL;
    }
    
    if (f2)
    {
        f2->getFruit();
        delete f2;
        f2 = NULL;
    }
    
    if (f3)
    {
        f3->getFruit();
        delete f3;
        f3 = NULL;
    }
    
    return 0;
}
