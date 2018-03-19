#include <iostream>
using namespace std;

template<typename T>
class SmartPointer {
public:
    SmartPointer(SmartPointer& sp){
        m_obj = sp.m_obj;
        m_count = sp.m_count;
        (*m_count)++;
    }
    SmartPointer(SmartPointer&& sp){
        m_obj = sp.m_obj;
        m_count = sp.m_count;
    }
    SmartPointer(T* ptr){
        m_obj = ptr;
        m_count = new int;
        *m_count = 1;
    }
    SmartPointer& operator=(SmartPointer& sp){
        reduce();
        m_obj = sp.m_obj;
        *m_count = *sp.m_count+1;
    }
    T& operator*(){
        return *m_obj;
    }
    ~SmartPointer(){
        reduce();
    }
    int refCount(){
        return *m_count;
    }
private:
    SmartPointer(){ }

    void reduce(){
        if(*m_count == 1) {
            *m_count = 0;
            delete m_obj;
        } else {
            (*m_count)--;
        }
    }
    T* m_obj;
    int* m_count;
};
int main()
{
    SmartPointer<int> ptr1 = new int;
    cout << "a - ptr1 count: "<< ptr1.refCount()<<endl;

    SmartPointer<int> ptr2 = new int;
    cout << "b - ptr1 count: "<< ptr1.refCount()<<" ptr2 count: "<< ptr2.refCount()<<endl;

    SmartPointer<int> ptr3 = ptr1;
    cout << "c - ptr1 count: "<< ptr1.refCount()<<" ptr2 count: "<< ptr2.refCount()<<" ptr3 count: "<< ptr3.refCount()<<endl;

    ptr2 = ptr1;
    cout << "d - ptr1 count: "<< ptr1.refCount()<<" ptr2 count: "<< ptr2.refCount()<<" ptr3 count: "<< ptr3.refCount()<<endl;

    *ptr1 = 3;
    cout << "e - ptr2 value "<<*ptr2 << endl;
    return 0;
}
