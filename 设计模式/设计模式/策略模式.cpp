//
//  策略模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/18.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

class Strategy
{
public:
    virtual void crypt() = 0;       //加密
};

//对称加密
class AES : public Strategy
{
public:
    virtual void crypt()
    {
        cout << "AES加密算法" << endl;
    }
};

//非对称加密
class DES : public Strategy
{
public:
    virtual void crypt()
    {
        cout << "DES加密算法" << endl;
    }
};

//上下文
class Context
{
public:
    void setStrategy(Strategy *strategy)
    {
        _strategy = strategy;
    }
    
    void myOperator()
    {
        _strategy->crypt();
    }
private:
    Strategy *_strategy;
};

int main()
{
    Context *pContext = new Context;
    Strategy *pDes = new DES;
    pContext->setStrategy(pDes);        //设置到上下文
    pContext->myOperator();
    delete pDes;
    pDes = NULL;
    
    Strategy *pAES = new AES;
    pContext->setStrategy(pAES);
    pContext->myOperator();
    delete pAES;
    pAES = NULL;
    delete pContext;
    
    return 0;
}









