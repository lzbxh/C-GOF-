//
//  建造者模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/5.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

//产品
class House
{
public:
    void setDoor(string door)
    {
        _door = door;
    }
    
    void setWall(string wall)
    {
        _wall = wall;
    }
    
    void setWindow(string window)
    {
        _window = window;
    }
    
    string getDoor()
    {
        cout << _door << endl;
        return _door;
    }
    
    string getWall()
    {
        cout << _wall << endl;
        return _wall;
    }
    
    string getWindow()
    {
        cout << _window << endl;
        return _window;
    }
    
private:
    string _door;
    string _wall;
    string _window;
};

//抽象的建造者
class Builder
{
public:
    virtual ~Builder(){}
    virtual void buildWall() = 0;
    virtual void buildDoor() = 0;
    virtual void buildWindow() = 0;
    virtual House* getHouse() = 0;
};

//公寓工程队
class  FlatBuilder : public Builder
{
public:
    FlatBuilder()
    {
        m_house = new House;
    }
    virtual void buildWall()
    {
        m_house->setWall(" flat wall");
    }
    
    virtual void buildDoor()
    {
        m_house->setDoor("flat door");
    }
    
    virtual void buildWindow()
    {
        m_house->setWindow("flat window");
    }
    
    virtual House* getHouse()
    {
        return m_house;
    }
private:
    House *m_house;
};

//别墅 villa 工程队
class  VillaBuilder : public Builder
{
public:
    VillaBuilder()
    {
        m_house = new House;
    }
    virtual void buildWall()
    {
        m_house->setWall(" villa wall");
    }
    
    virtual void buildDoor()
    {
        m_house->setDoor("villa door");
    }
    
    virtual void buildWindow()
    {
        m_house->setWindow("villa window");
    }
    
    virtual House* getHouse()
    {
        return m_house;
    }
private:
    House *m_house;
};

//设计师(指挥者) 负责建造逻辑
//建筑队 干具体的活
class Director
{
public:
    Director(Builder *build)
    {
        _build = build;
    }
    void Construct()
    {
        //这就是造房子的业务逻辑，被抽象到指挥者的内部，可以随意改变
        _build->buildWall();
        _build->buildWindow();
        _build->buildDoor();
    }
private:
    Builder * _build;
};

int main()
{
    House *house = NULL;
    Builder *builder = NULL;
    Director *director = NULL;
    
    /********造别墅********/
    //建造者
    builder = new VillaBuilder;
    
    //指挥者
    director = new Director(builder);
    //指挥者指挥建造    也就是建造房子的业务逻辑
    director->Construct();
    
    //建造者交货
    house = builder->getHouse();
    
    //验货
    house->getWindow();
    house->getDoor();
    
    delete house;
    delete builder;
    
    /********造公寓********/
    builder = new FlatBuilder;
    director = new Director(builder);
    director->Construct();
    house  =  builder->getHouse();
    house->getWindow();
    house->getDoor();
    delete house;
    delete builder;
    
    delete director;
    
    return 0;
}

