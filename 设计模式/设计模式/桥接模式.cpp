//
//  桥接模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/6.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

//将抽象部分与实际部分分离，使它们都可以独立的变化。

using namespace std;

class Engine;

//车 装 发动机
class Car
{
public:
    virtual void installEngine() = 0;
protected:
    Engine *_engine;
};

class Engine
{
public:
    virtual void installEngine() = 0;
};

class BMW5 : public Car
{
public:
    BMW5(Engine *engine)
    {
        _engine = engine;
    }
    
    virtual void installEngine()
    {
        cout << "BMW5安装引擎" << endl;
        _engine->installEngine();
    }
};

class BMW7 : public Car
{
public:
    BMW7(Engine *engine)
    {
        _engine = engine;
    }
    
    virtual void installEngine()
    {
        cout << "BMW7安装引擎" << endl;
        _engine->installEngine();
    }
};

class Engine1000CC : public Engine
{
public:
    virtual void installEngine()
    {
        cout << "1000CC引擎被安装" << endl;
    }
};

class Engine2000CC : public Engine
{
public:
    virtual void installEngine()
    {
        cout << "2000CC引擎被安装" << endl;
    }
};

using namespace std;

int main()
{
    Engine1000CC *p1000CCEngine = new Engine1000CC;
    Engine2000CC *p2000CCEngine = new Engine2000CC;
    BMW5 *pBMW5 = new BMW5(p2000CCEngine);
    BMW7 *pBMW7 = new BMW7(p1000CCEngine);
    
    pBMW5->installEngine();
    pBMW7->installEngine();
    
    return 0;
}
