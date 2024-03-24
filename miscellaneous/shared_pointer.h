#include <iostream>

/**
 * This is a simple comceptual implementation of shared_ptr.
 * The key is reference counter and RAII.
 */

class reference_counter{
    private:
        int count;
    public:
        reference_counter(): count(0){}
        void AddRef(){
            ++count;
        }
        int Release(){
            return --count;
        }
};

template<typename T>
class shared_pointer{
    private:
        T* pData;
        reference_counter* rc;
    public:
        shared_pointer(): pData(nullptr), rc(0){
            rc = new reference_counter();
            rc->AddRef();
        }
        shared_pointer(T* pData_){
            pData = pData;
            rc = new reference_counter();
            rc->AddRef();
        }
        shared_pointer(const shared_pointer<T>& sp){
            pData = sp.pData;
            rc = sp.rc;
            rc->AddRef();
        }
        shared_pointer& operator= (const shared_pointer<T>& sp){
            pData = sp.pData;
            rc = sp.rc;
            rc->AddRef();
            return *this;
        }
        shared_pointer(shared_pointer<T>&& sp){
            if(this == &sp){
                return;
            }
            pData = sp.pData;
            rc = sp.rc;
            sp.pData = nullptr;
            sp.rc = nullptr;
        }
        shared_pointer& operator= (shared_pointer<T>&& sp){
            if(this == &sp){
                return *this;
            }
            pData = sp.pData;
            rc = sp.rc;
            sp.pData = nullptr;
            sp.rc = nullptr;
        }
        ~shared_pointer(){
            if(rc->Release() == 0){
                delete pData;
                delete rc;
            }
        }

        T& operator*(){
            return *pData;
        }
        T* operator->(){
            return pData;
        }
};

int main(void){
    shared_pointer<int> sp;
    return 0;
}