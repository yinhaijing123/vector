#define _CRT_SECURE_NO_WARNINGS
#include"Vector.h"

Vector::Vector()
    :_first(NULL),
    _finish(NULL),
    _endofstorage(NULL)
{}
Vector::Vector(const Vector& v)
    : _first(new DataType[v.Size()])
{
    memcpy(_first, v._first, sizeof(DataType)*v.Size());
    _finish = _first + v.Size();
    _endofstorage = _first + v.Size();
}
Vector& Vector::operator=(const Vector& v)
{
    if (this != &v)
    {
        DataType* tmp = new DataType[v.Size()];      //先开辟新空间，后释放_first。防止开辟空间失败
        memcpy(tmp, v._first, sizeof(DataType)*v.Size());

        delete[]_first;
        _first = tmp;
        _finish = _first + v.Size();
        _endofstorage = _first + v.Size();
    }
    return *this;
}

Vector::~Vector()
{
    delete []_first;
}

size_t Vector::Size()const
{
    return (_finish - _first);
}

size_t Vector::Capacity()const
{
    return (_endofstorage - _first);
}

void Vector::Expand(size_t n)
{
    if (n > Capacity())
    {
        size_t size = Size();                        //当_first改变指向时,Size()将变化且结果无法估量，故先保存有效元素的个数

        DataType *tmp = new DataType[n];
        memcpy(tmp, _first,sizeof(DataType)*size);   //memcpy()是按照字节数进行拷贝的。
        delete []_first;
        _first = tmp;
        _finish = _first + size;
        _endofstorage =_first + n;
    }
}

void Vector::Reserve(size_t n)
{
    if (n < Capacity())
    {
        _finish = _first + n;
    }
}

void Vector::PushBack(DataType x)
{
    if (Capacity() == 0)
    {
        Expand(2);
    }
    if (Size() == Capacity())
    {
        Expand(Capacity() * 2);
    }
    *(_finish++) = x;
}
void Vector::PopBack()
{
    if (Size() == 0)
    {
        return;
    }
    --_finish;
}
void Vector::PushFront(DataType x)
{
    if (Capacity() == 0)
    {
        Expand(2);
    }
    if (Size() >= Capacity())
    {
        Expand(Capacity() * 2);
    }
    int i = 0;
    for (i = Size()-1; i >= 0; i--)
    {
        _first[i + 1] = _first[i];
    }
    _first[0] = x;
    _finish++;
}

void Vector::PopFront()
{
    if (Size() == 0)
    {
        return;
    }
    int i = 0;
    for (i = 0; i < (int)Size() - 1; i++)
    {
        _first[i] = _first[i + 1];
    }
    _finish--;
}

void Vector::Insert(size_t pos, DataType x)
{
    if (Capacity() == 0)
    {
        Expand(2);
    }
    if (Size() >= Capacity())
    {
        Expand(Capacity() * 2);
    }
    int i = 0;
    for (i = Size() - 1; i >= (int)pos; i--)              //将pos强制转换为int类型，防止循环判断时出现类型提升，以致变成死循环
    {
        _first[i + 1] = _first[i];
    }
    _first[pos] = x;
    _finish++;
}

void Vector::Erase(size_t pos)
{
    assert(pos < Size());
    if (Size() == 0)
    {
        return;
    }
    int i = 0;
    for (i = pos; i < (int)Size() - 1; i++)
    {
        _first[i] = _first[i + 1];
    }
    _finish--;
}

size_t Vector::Find(DataType x)
{
    int i = 0;
    for (i = 0; i <= (int)Size() - 1; i++)
    {
        if (_first[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void Vector::Print()
{
    int i = 0;
    for (i = 0; i <= (int)Size() - 1; i++)
    {
        cout << _first[i] << ' ';
    }
    cout << endl;
}