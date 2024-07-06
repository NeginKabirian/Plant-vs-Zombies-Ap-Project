#ifndef VECTORCLIENT_H
#define VECTORCLIENT_H
#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class vectorclient{
private:
    std::vector<T> data;
    size_t maxsize;
public:
    vectorclient(size_t max=2):maxsize(max){}
    void push_back(const T& item){
        if(data.size() >=maxsize){
            throw std::length_error("Exceeded maximum size of the vector.");
        }
        data.push_back(item);
    }
    size_t size()const{
        return data.size();
    }
    const T& operator[](size_t index) const{
        return data[index];
    }
    T& operator[](size_t index) {
            return data[index];
    }
};
#endif // VECTORCLIENT_H
