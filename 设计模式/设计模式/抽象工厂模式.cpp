//
//  抽象工厂模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/6/25.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

//开闭原则
//扩展开放，修改关闭

#include <iostream>

using namespace std;

/*水果类*/
class Fruit
{
public:
    virtual void sayName() = 0;
    virtual ~Fruit(){}
};

class NorthBanana : public Fruit
{
public:
    virtual void sayName()
    {
        cout << "NorthBanana" << endl;
    }
};

class SouthBanana : public Fruit
{
public:
    virtual void sayName()
    {
        cout << "SouthBanana" << endl;
    }
};

class NorthApple : public Fruit
{
public:
    virtual void sayName()
    {
        cout << "NorthApple" << endl;
    }
};

class SouthApple : public Fruit
{
public:
    virtual void sayName()
    {
        cout << "SouthApple" << endl;
    }
};

//抽象工厂   产品的细化
class FruitFactory
{
public:
    virtual Fruit *getBanana() = 0;
    virtual Fruit *getApple() = 0;
    virtual ~FruitFactory(){}
};

//北方工厂生产北方水果
class NorthFactory : public FruitFactory
{
    virtual Fruit *getBanana()
    {
        return new NorthBanana;
    }
    
    virtual Fruit *getApple()
    {
        return new NorthApple;
    }
};

//南方工厂生产南方水果
class SouthFactory : public FruitFactory
{
    virtual Fruit *getBanana()
    {
        return new SouthBanana;
    }
    
    virtual Fruit *getApple()
    {
        return new SouthApple;
    }
};

int main()
{
    //一类工厂生产一个产品族
    //eg:北方工厂 生产 北方苹果/香蕉...
    //   南方工厂 生产 南方苹果/香蕉...
    FruitFactory *pNorthFactory = new NorthFactory;
    FruitFactory *pSouthFactory = new SouthFactory;
    
    Fruit *pNorthApple = pNorthFactory->getApple();
    Fruit *pNorthBanana = pNorthFactory->getBanana();
    
    Fruit *pSouthApple = pSouthFactory->getApple();
    Fruit *pSouthBanana = pSouthFactory->getBanana();
    
    pNorthApple->sayName();
    pNorthBanana->sayName();
    
    pSouthApple->sayName();
    pSouthBanana->sayName();
    
    delete pNorthFactory;
    pNorthFactory = nullptr;
    
    delete pSouthFactory;
    pSouthFactory = nullptr;
    
    delete pNorthApple;
    delete pNorthBanana;
    pNorthApple = nullptr;
    pNorthBanana = nullptr;
    
    delete pSouthApple;
    delete pSouthBanana;
    pSouthApple = nullptr;
    pSouthBanana = nullptr;
    
    return 0;
}
