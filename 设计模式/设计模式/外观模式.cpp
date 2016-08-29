//
//  外观模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/7.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

class SubSystemA
{
public:
    void doThing()
    {
        cout << "SubSystemA run" << endl;
    }
};

class SubSystemB
{
public:
    void doThing()
    {
        cout << "SubSystemB run" << endl;
    }
};

class SubSystemC
{
public:
    void doThing()
    {
        cout << "SubSystemC run" << endl;
    }
};

//外观提供子系统同一的操作接口
class Facade
{
public:
    Facade()
    {
        sysA = new SubSystemA;
        sysB = new SubSystemB;
        sysC = new SubSystemC;
    }
    ~Facade()
    {
        delete sysA;
        delete sysB;
        delete sysC;
    }
public:
    void doThing()
    {
        sysA->doThing();
        sysB->doThing();
        sysC->doThing();
    }
protected:
private:
    SubSystemA *sysA;
    SubSystemB *sysB;
    SubSystemC *sysC;
};

int main()
{
    Facade *f = new Facade;
    f->doThing();
    delete f;
    
    return 0;
}
