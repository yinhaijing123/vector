#define _CRT_SECURE_NO_WARNINGS
#include"Vector.h"
#define TEST_HEADER printf("==========================%s===========================\n",__FUNCTION__)

void TestPush()
{
    TEST_HEADER;
    Vector v1;
    Vector v2(v1);
    v1.Print();
    v2.Print();
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    v1.PushBack(4);
    v1.Print();
    Vector v3(v1);
    v3.Print();
    v3.PushFront(0);
    v3.Print();
    v2 = v3;
    v2.Print();
}

void TestPop()
{
    TEST_HEADER;
    Vector v1;
  
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    v1.PushBack(4);
    v1.Insert(0, 0);
    Vector v2(v1);
    v1.Print();
    v2.Print();

    v1.PopBack();
    v1.Print();
    v1.PopFront();
    v1.Print();
    v1.PopBack();
    v1.PopBack();
    v1.PopBack();
    v1.PopBack();
    v1.Print();
    cout << v2.Find(2) << endl;
    v2.Erase(0);
    v2.Print();
    v2.Erase(2);
    v2.Print();
    v2.Reserve(2);
    v2.Print();
}

int main()
{
    TestPush();
    TestPop();

    system("pause");
    return 0;
}