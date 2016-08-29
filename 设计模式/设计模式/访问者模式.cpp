//
//  访问者模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/19.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

class ParkElement;

//抽象访问者
class Visitor
{
public:
    virtual void visit(ParkElement *pParkElement) = 0;
};

//抽象节点
class ParkElement
{
public:
    virtual void accept(Visitor *pVisitor) = 0;
};

class ParkA : public ParkElement
{
public:
    virtual void accept(Visitor *pVisitor)
    {
        pVisitor->visit(this);      //具体节点接收访问者访问，让访问者做操作
    }
};

class ParkB : public ParkElement
{
public:
    virtual void accept(Visitor *pVisitor)
    {
        pVisitor->visit(this);
    }
};

//***整个公园
//结构对象（ObiectStructure）角色：有如下的一些责任，可以遍历结构中的所有元素；如果需要，提供一个高层次的接口让访问者对象可以访问每一个元素；如果需要，可以设计成一个复合对象或者一个聚集，如列（List）或集合（Set）。
class Park : public ParkElement
{
public:
    Park()
    {
        _list.clear();
    }
    
    void setParkElement(ParkElement *pParkElement)
    {
        _list.push_back(pParkElement);
    }
    
    virtual void accept(Visitor *pVisitor)
    {
        list<ParkElement *>::iterator it = _list.begin();
        for (; it != _list.end(); it++) {
            (*it)->accept(pVisitor);
        }
    }
private:
    list<ParkElement *> _list;
};

//具体的访问者
class VisitorA : public Visitor
{
public:
    virtual void visit(ParkElement *pParkElement)
    {
        cout << "VisitorA do something..." << endl;
    }
};

class VisitorB : public Visitor
{
public:
    virtual void visit(ParkElement *pParkElement)
    {
        cout << "VisitorB do something..." << endl;
    }
};

//***管理者
class ManagerVisitor : public Visitor
{
public:
    virtual void visit(ParkElement *pParkElement)
    {
        cout << "ManagerVisitor do something..." << endl;
    }
};

int main()
{
    {
        //不同角色只能访问一部分
        Visitor *pVA = new VisitorA;
        Visitor *pVB = new VisitorB;
        
        ParkElement *pPA = new ParkA;
        ParkElement *pPB = new ParkB;
        
        pPA->accept(pVA);
        pPB->accept(pVB);
        
        delete pVA;
        delete pVB;
        delete pPA;
        delete pPB;
    }
    
    cout << "===================" << endl;
    
    {
        //管理者可以访问整个公园
        Visitor *pManager = new ManagerVisitor;
        Park *pPark = new Park;
        
        ParkElement *pPA = new ParkA;
        ParkElement *pPB = new ParkB;
        pPark->setParkElement(pPA);
        pPark->setParkElement(pPB);
        
        pPark->accept(pManager);
        
        delete pManager;
        delete pPA;
        delete pPB;
        delete pPark;
    }
    
    return 0;
}












