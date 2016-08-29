//
//  组合模式.cpp
//  设计模式
//
//  Created by 刘智滨 on 16/7/7.
//  Copyright © 2016年 刘智滨. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

class IFile
{
public:
    virtual void display() = 0;
    virtual int add(IFile *ifile) = 0;
    virtual int remove(IFile *ifile) = 0;
    virtual list<IFile *>* getChild() = 0;
};

//等同于叶子节点
class File : public IFile
{
public:
    File(string name)
    {
        mName = name;
    }
    
    virtual void display()
    {
        cout << mName << endl;
    }
    
    virtual int add(IFile *ifile)
    {
        return -1;
    }
    
    virtual int remove(IFile *ifile)
    {
        return -1;
    }
    
    virtual list<IFile *>* getChild()
    {
        return NULL;
    }
private:
    string mName;
};

//等同于枝节点
class Dir : public IFile
{
public:
    Dir(string name)
    {
        mName = name;
        mList = new list<IFile *>;
        mList->clear();     //置空
    }
    
    virtual void display()
    {
        cout << mName << endl;
    }
    
    virtual int add(IFile *ifile)
    {
        mList->push_back(ifile);
        return 0;
    }
    
    virtual int remove(IFile *ifile)
    {
        mList->remove(ifile);
        return 0;
    }
    
    virtual list<IFile *>* getChild()
    {
        return mList;
    }
private:
    string mName;
    list<IFile *> *mList;
};

// 递归的显示树
void showTree(IFile *root, int level)
{
    int i = 0;
    if (root == NULL)
    {
        return ;
    }
    for (i=0; i<level; i++)
    {
        printf("\t");
    }
    //1 显示根 结点
    root->display();
    
    //2  若根结点 有孩子
    //判读孩子是文件,显示名字 )
    //判断孩子是目录,showTree(子目录)
    
    list<IFile *>  *mylist = root->getChild();
    if (mylist != NULL) //说明是一个目录
    {
        for (list<IFile *>::iterator it=mylist->begin(); it!=mylist->end(); it++)
        {
            if ( (*it)->getChild() == NULL )
            {
                for (i=0; i<=level; i++) //注意 <=
                {
                    printf("\t");
                }
                (*it)->display();
            }
            else
            {
                showTree(*it, level+1);
            }
        }
    }
}

int main()
{
    Dir *root = new Dir("/");
//    root->display();
    
    Dir *dir1 = new Dir("dir1");
//    Dir *dir2 = new Dir("dir2");
    
    File *file1 = new File("file1");
    File *file2 = new File("file2");
    
    dir1->add(file1);
    root->add(file2);
    
    root->add(dir1);
    
    list<IFile *> *rootList = root->getChild();
    list<IFile *>::iterator it1 = rootList->begin();
    for ( ;it1 != rootList->end(); it1++) {
        (*it1)->display();
    }
    
    //写个函数递归显示所有的文件及文件夹名称
    cout << "=============" << endl;
    showTree(root, 0);
    
    return 0;
}

































