#include<iostream>

using namespace std;

typedef int datatype;

typedef struct lrNode{

    datatype data;
    lrNode *lc,*rc;
    lrNode():lc(NULL),rc(NULL){}

}*lrTree;

lrTree CreateTree(lrTree t,datatype data)
{
    if(t) return t;

    t = new lrNode;
    t->data = data;
    return t;
}

void MidTravel(lrTree t)
{
    if(!t) return;
    MidTravel(t->lc);
    cout << t->data << endl;
    MidTravel(t->rc);
}


int main()
{
    lrTree t = NULL;  // 树指针必须初始化！
    t = CreateTree(t,-1);
    MidTravel(t);
    return 0;
}