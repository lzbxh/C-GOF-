//
//  备忘录模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/19.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

//Caretaker 管理者
// MememTo  备忘录

//备忘录
class MememTo
{
public:
    MememTo(string name,int age )
    {
        m_name = name;
        m_age = age;
    }
    
    string getName()
    {
        return m_name;
    }
    
    int getAge()
    {
        return m_age;
    }
    
    void setName(string name)
    {
        this->m_name = name;
    }
    
    void setAge(int age)
    {
        this->m_age = age;
    }
private:
    string	m_name;
    int		m_age;
};

//原生者
class  Person
{
public:
    Person(string name,int age )
    {
        m_name = name;
        m_age = age;
    }
    
    string getName()
    {
        return m_name;
    }
    
    int getAge()
    {
        return m_age;
    }
    
    void setName(string name)
    {
        this->m_name = name;
    }
    void setAge(int age)
    {
        this->m_age = age;
    }
    
    //保存
    MememTo* createMememTo()
    {
        return new MememTo(m_name, m_age);
    }
    //还原
    void setMememTo(MememTo* memto)
    {
        this->m_age = memto->getAge();
        this->m_name = memto->getName();
    }
public:
    void printT()
    {
        cout << "m_name:" << m_name << " m_age:" << m_age << endl;
    }
private:
    string	m_name;
    int		m_age;
};

//管理者
class Caretaker
{
public:
    Caretaker(MememTo *memto)
    {
        this->memto = memto;
    }
    
    MememTo *getMememTo()
    {
        return memto;
    }
    
    void setMememTo(MememTo *memto)
    {
        this->memto = memto;
    }
protected:
private:
    MememTo *memto;
};

int main()
{
    {
        /******不使用管理者******/
        Person *pPerson = new Person("person1" ,66);
        pPerson->printT();
        
        //创建备忘录
        MememTo *pMememto = pPerson->createMememTo();
        
        //修改状态
        pPerson->setAge(88);
        pPerson->printT();
        
        //回复状态
        pPerson->setMememTo(pMememto);
        pPerson->printT();
        
        delete pMememto;
        delete pPerson;
    }
    
    cout << "=================" << endl;
    
    {
        /******使用管理者******/
        
        Person *pPerson = new Person("person1" ,66);
        pPerson->printT();
        
        //创建备忘录
        MememTo *pMememto = pPerson->createMememTo();
        
        /*管理者
            管理者可以用list管理多个状态
        */
        Caretaker *pCareTaker = new Caretaker(pMememto);
        
        //修改状态
        pPerson->setAge(88);
        pPerson->printT();
        
        //从管理者恢复状态
        pPerson->setMememTo(pCareTaker->getMememTo());
        pPerson->printT();
        
        delete pMememto;
        delete pPerson;

    }
    
    return 0;
}

