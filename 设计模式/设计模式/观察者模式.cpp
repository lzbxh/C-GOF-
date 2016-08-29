//
//  观察者模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/19.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

class Secretary;

//观察者
class PlayerObserver
{
public:
    PlayerObserver(Secretary *secretary)
    {
        _secretary = secretary;
    }
    
    void update(string action)
    {
        cout << "action:" << action << endl;
    }
private:
    Secretary *_secretary;
};

//被观察者
class Secretary
{
public:
    Secretary()
    {
        _list.clear();
    }
    
    void notify(string info)
    {
        list<PlayerObserver *>::iterator it = _list.begin();
        for (; it != _list.end(); it++) {
            (*it)->update(info);
        }
    }
    
    void addPlayerObserver(PlayerObserver *o)
    {
        _list.push_back(o);
    }
private:
    list<PlayerObserver *>_list;
};

int main()
{
    Secretary			*secretary = NULL;
    PlayerObserver		*po1 = NULL;
    PlayerObserver		*po2 = NULL;
    
    secretary = new Secretary;
    po1 = new PlayerObserver(secretary);
    po2 = new PlayerObserver(secretary);
    
    secretary->addPlayerObserver(po1);
    secretary->addPlayerObserver(po2);
    
    secretary->notify("老板来了") ;
    secretary->notify("老板走了");
    delete secretary ;
    delete po1 ;
    delete po2 ;
    return 0;

}











