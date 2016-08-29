//
//  代理在cocos2dx中的使用.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/6/26.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

//规定的协议
class AppProtocol
{
public:
    virtual int ApplicationDidFinsh() = 0;
};

//协议实现类
class AppDelegate : public AppProtocol
{
public:
    AppDelegate()
    {
        
    }
    
    virtual int ApplicationDidFinsh()   //cocos2dx函数入口点
    {
        cout << "ApplicationDidFinsh do...\n";
        return 0;
    }
};

//代理类
class Application
{
public:
    Application(){ _ap = NULL; }
    void run()
    {
        _ap = new AppDelegate;
        _ap->ApplicationDidFinsh();
        delete _ap;
    }
private:
    AppDelegate *_ap;
};

//好处：main函数不需要修改了
//只需要修改协议实现类
int main()
{
    Application *app = new Application;
    app->run();
    
    if (app) {
        delete app;
    }
    
    return 0;
}
