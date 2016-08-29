//
//  类比于OC中的代理.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/6/25.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

//协议类(接口类)
class MyProtocol
{
public:
    virtual void MyProtocolFun1() = 0;
};

//遵循协议方法的类(这个类可以用作基类)
class FollowMyProtocol : public MyProtocol
{
public:
    virtual void MyProtocolFun1()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

//被代理类
class DelegateClass
{
public:
    void setDelegate(FollowMyProtocol *delegate)
    {
        _delegate = delegate;
    }
    
    void triggerDelegateDoSomeThing()
    {
        if (_delegate) {
            _delegate->MyProtocolFun1();
        }else {
            cout << "代理类指针为空" << endl;
        }
    }
private:
    FollowMyProtocol *_delegate;
};


int main()
{
    DelegateClass *pDelegateObj = new DelegateClass;
    FollowMyProtocol *pFollowMyProtocolObj = new FollowMyProtocol;
    
    pDelegateObj->setDelegate(pFollowMyProtocolObj);
    pDelegateObj->triggerDelegateDoSomeThing();
    
    return 0;
}
