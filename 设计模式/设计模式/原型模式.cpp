//
//  原型模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/6.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

class Person
{
public:
    virtual Person *clone() = 0;
    virtual void printT() = 0;
};

class CPlusPlusProgramer : public Person
{
public:
    CPlusPlusProgramer()
    {
        _name = "";
        _age = 0;
        _desc = NULL;
    }
    
    CPlusPlusProgramer(string name ,int age)
    {
        _name = name;
        _age = age;
        _desc = NULL;
    }
    
    void setDesc(const char *desc)
    {
        if (desc) {            
            if (_desc) {
                delete _desc;
            }
            _desc = new char[strlen(desc) + 1];
            strcpy(_desc, desc);
        }
    }
    
    virtual void printT()
    {
        if (_desc) {
            cout << "name:" << _name << " age:" << _age << " desc:" << _desc << endl;
        }else {
            cout << "name:" << _name << " age:" << _age << " desc:" << "" << endl;
        }
    }
    
    virtual Person *clone()
    {
        CPlusPlusProgramer *tmp = new CPlusPlusProgramer;
        *tmp = *this;
        tmp->setDesc(this->_desc);
        return tmp;
    }
    
private:
    string _name;
    int _age;
    char *_desc;
};

int main()
{
    CPlusPlusProgramer *c1 = new CPlusPlusProgramer("张三" ,26);
    c1->setDesc("c1_descc1_descc1_descc1_descc1_descc1_desc");
    Person *c2 = c1->clone();
    c2->printT();
    return 0;
}
