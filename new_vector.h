#ifndef OOP4_NEW_VECTOR_H
#define OOP4_NEW_VECTOR_H

#include<iostream>

template <typename T>
class new_vector{
private:
    T* arr;
    size_t vsize{};
    size_t vcapacity{};

public:
    new_vector(){
        arr = new T[1];
        vcapacity = 1;
    }

    class Iterator{
    private:
        T* iterator;

    public:
        Iterator(T* b = nullptr){
            iterator = b;
        }

        T& operator*(){
            return *iterator;
        }

        Iterator& operator++(){
            iterator++;
            return *this;
        }

        Iterator operator=(Iterator b){
            std::swap((*this).iterator, b.iterator);
            return *this;
        }
    };

    size_t capacity(){
        return vcapacity;
    }

    size_t size(){
        return vsize;
    }

    bool isEmpty(){
        return (vsize == 0);
    }

    Iterator end(){
        return Iterator(arr+vsize);
    }

    Iterator begin(){
        return Iterator(arr);
    }

    T& operator[](size_t i){
        return arr[i];
    }

    void addMemory(){
        vcapacity*=2;
        T* tmp = arr;
        arr = new T[vcapacity];
        for(size_t i = 0; i < vsize; i++){
            arr[i] = tmp[i];
        }
        delete[]tmp;
    }

    void pushBack(T& smth){
        if(vsize >= vcapacity){
            addMemory();
        }
        arr[vsize++] = smth;
    }

    void erase(Iterator it){
        for(Iterator i = it; i < std::cend(arr) - 1; i++){
            arr[i] = arr[i + 1];
        }
        vsize--;
    }

    ~new_vector(){
        delete[]arr;
    }
};



#endif //OOP4_NEW_VECTOR_H