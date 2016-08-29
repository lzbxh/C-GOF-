//
//  解释器模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/20.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>

using namespace std;

class Context
{
public:
    Context(int num)
    {
        this->m_num = num;
    }
    int getNum()
    {
        return m_num;
    }
    int getRes()
    {
        return m_res;
    }
    
    void setNum(int num)
    {
        this->m_num = num;
    }
    void  setRes(int res)
    {
        this->m_res = res;
    }
    
private:
    int m_num;
    int m_res;
};

class Expression
{
public:
    virtual void  interpreter(Context *context) = 0;
private:
    Context		*m_context;
};

class PlusExpression : public Expression
{
public:
    PlusExpression()
    {
        this->context = NULL;
    }
    virtual void  interpreter(Context *context)
    {
        int num = context->getNum();
        num ++;
        context->setNum(num);
        context->setRes(num);
    }
private:
    Context *context;
};

class MinusExpression : public Expression
{
public:
    MinusExpression()
    {
        this->context = NULL;
    }
    virtual void  interpreter(Context *context)
    {
        int num = context->getNum();
        num -- ;
        context->setNum(num);
        context->setRes(num);
    }
private:
    Context *context;
};

int main()
{
    Expression		*expression = NULL;
    
    Context			*context = NULL;
    
    Expression		*expression2 = NULL;
    
    context = new Context(10);
    cout << context->getNum() << endl;
    
    expression = new PlusExpression;
    expression->interpreter(context);
    cout << context->getRes() << endl;
    
    expression2 = new MinusExpression;
    expression2->interpreter(context);
    cout << context->getRes() << endl;
    
    return 0;
}
