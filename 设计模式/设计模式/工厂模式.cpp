//
//  工厂模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/6/25.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

/*水果部分*/
class Fruit
{
public:
    virtual void sayName() = 0;
    virtual ~Fruit()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Banana : public Fruit
{
public:
    virtual void sayName()
    {
        cout << "Banana" << endl;
    }
    virtual ~Banana()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Apple : public Fruit
{
public:
    virtual void sayName()
    {
        cout << "Apple" << endl;
    }
    virtual ~Apple()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

/*工厂部分*/
class Factory
{
public:
    virtual Fruit *getFruit() = 0;
    virtual ~Factory()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class BananaFactory : public Factory
{
public:
    virtual Fruit *getFruit()
    {
        return new Banana;
    }
    
    virtual ~BananaFactory()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class AppleFactory : public Factory
{
public:
    virtual Fruit *getFruit()
    {
        return new Apple;
    }
    
    virtual ~AppleFactory()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};


int main()
{
    Factory *pBananaFactor = new BananaFactory;
    Fruit *pBanana = pBananaFactor->getFruit();
    pBanana->sayName();
    if (pBananaFactor) {
        delete pBananaFactor;
        pBananaFactor = nullptr;
    }
    
    if (pBanana) {
        delete pBanana;
        pBanana = nullptr;
    }
    
    Factory *pAppleFactor = new AppleFactory;
    Fruit *pApple = pAppleFactor->getFruit();
    pApple->sayName();
    
    if (pAppleFactor) {
        delete pAppleFactor;
        pAppleFactor = nullptr;
    }
    
    if (pApple) {
        delete pApple;
        pApple = nullptr;
    }
    
    return 0;
}
