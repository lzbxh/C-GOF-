//
//  饿汉单例模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/6/24.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>
#include <unistd.h>

using namespace std;

//单例模式（懒汉式）
class Singelton
{
public:
    static Singelton *getInstance()
    {
        if (singe == NULL) {
            singe = new Singelton;
        }
        return singe;
    }
    
private:
    //隐藏构造函数，构造函数不能保障线程安全
    Singelton()
    {
        printf("--begin--\n");
        sleep(5);
        printf("--end--\n");
    }
    
    static Singelton *singe;
};

//饿汉式
//缺点：会浪费空间
Singelton * Singelton::singe = new Singelton;

void *thread_routine(void *arg)
{
    pthread_t tid = pthread_self();
    //    cout << "当前线程号:" << tid << endl;
    
    //调用构造
    Singelton::getInstance();
    
    //    cout << "子线程退出" << endl;
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    //    Singelton *ps1 = Singelton::getInstance();
    //    Singelton *ps2 = Singelton::getInstance();
    //
    //    if (ps1 == ps2) {
    //        cout << "相等" << endl;
    //    }else {
    //        cout << "不相等" << endl;
    //    }
    
    pthread_t tid[3];
    int i = 0;
    
    for(i = 0 ;i < 3 ;i++)
    {
        pthread_create(tid + i, NULL, thread_routine, NULL);
    }
    
    for (i = 0; i < 3; i++) {
        //等待子线程结束
        pthread_join(tid[i], NULL);
    }
    
    return 0;
}
