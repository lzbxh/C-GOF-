//
//  命令模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/8.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

//医生类
class Doctor
{
public:
    void treatEye()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    void treatNose()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

//命令类
class Command
{
public:
    virtual void treat() = 0;
    virtual ~Command() {}
};

class CommandTreatEye : public Command
{
public:
    CommandTreatEye(Doctor *doctor)
    {
        _doctor = doctor;
    }
    virtual void treat()
    {
        _doctor->treatEye();
    }
private:
    Doctor *_doctor;
};

class CommandTreatNose : public Command
{
public:
    CommandTreatNose(Doctor *doctor)
    {
        _doctor = doctor;
    }
    void treat()
    {
        _doctor->treatNose();
    }
private:
    Doctor *_doctor;
};

//调用者（护士）
class BeautyNurse
{
public:
    BeautyNurse(Command *command)
    {
        _command = command;
    }
public:
    void SubmittedCase() //提交病例 下单命令
    {
        _command->treat();
    }
protected:
private:
    Command *_command;
};

//护士长
class HeadNurse
{
public:
    HeadNurse()
    {
        _list.clear();
    }
    
public:
    void setCommand(Command *command)
    {
        _list.push_back(command);
    }
    void SubmittedCase() //提交病例 下单命令
    {
        for (list<Command *>::iterator it=_list.begin(); it!=_list.end(); it++)
        {
            (*it)->treat();
        }
    }
private:
    list<Command *> _list;
};


int main()
{
    {
        //护士提交简历 给医生看病
        BeautyNurse		*beautynurse = NULL;
        Doctor			*doctor = NULL;
        Command			*command  = NULL;
        
        doctor = new Doctor ;
        
        //command = new CommandTreatEye(doctor);
        command = new CommandTreatNose(doctor);
        beautynurse = new BeautyNurse(command);
        beautynurse->SubmittedCase();
        
        delete doctor;
        delete command;
        delete beautynurse;
    }
    
    {
        //护士提交简历 给以上看病
        HeadNurse		*headnurse = NULL;
        Doctor			*doctor = NULL;
        Command			*command1  = NULL;
        Command			*command2  = NULL;
        
        doctor = new Doctor ;
        
        command1 = new CommandTreatEye(doctor);
        command2 = new CommandTreatNose(doctor);
        headnurse = new HeadNurse(); //new 护士长
        headnurse->setCommand(command1);
        headnurse->setCommand(command2);
        
        headnurse->SubmittedCase(); // 护士长 批量下单命令
        
        delete doctor;
        delete command1;
        delete command2;
        delete headnurse;
    }
    return 0;
}















