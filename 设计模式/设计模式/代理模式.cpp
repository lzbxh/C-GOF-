//
//  代理模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/6/25.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

//代理对象
//被代理对象

//书店
class BookStore
{
public:
    virtual void saleBook()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

//实体店
class RealStore : public BookStore
{
public:
    virtual void saleBook()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

//代理  （淘宝）
//我觉得代理类并不需要继承BookStore，
//只需要在触发方法中执行真实书店的saleBook方法即可
class ProxyObject : public BookStore
{
public:
    //代理卖书
    virtual void saleBook()
    {
        //代理实体店卖书
        realStore.saleBook();
        //增加自己的动作
        onSales();          //促销
        disCounts(0.6);     //打折
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    //促销卖书
    void onSales()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    //打折
    void disCounts(float disCountsNum)
    {
        cout << "打" << disCountsNum << "折" << endl;
    }
    
    //包含一个实体书店(组合)
    RealStore realStore;
};

int main()
{
    ProxyObject *proxyObj = new ProxyObject;
    proxyObj->saleBook();
    return 0;
}
