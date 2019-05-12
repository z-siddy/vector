//
// Created by zygsi on 5/7/2019.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include "main.h"

namespace vek {
    template <typename T>
    class vector {
    private:
        size_t size_;
        size_t cap_;
        T *elem_;
    public:
        //Konstruktoriai / destruktoriai---------------------------------------
        vector() : size_{ 0 }, elem_{ new T[size_] }, cap_{ 0 } {};
        vector(size_t size) : size_{ size }, elem_{ new T[size] }, cap_{ size } {};
        vector(size_t size, T value) : size_{ size }, elem_{ new T[size] }, cap_{ size } { fill_n(elem_, size, value); }
        ~vector() { delete[] elem_; }

        //Narių tipai----------------------------------------------------------
        typedef T *iterator;
        typedef T &reference;
        typedef const T &const_reference;

        //Elementų pasiekiamumas-----------------------------------------------
        reference operator[](int i) {
            if (i < 0 || i >= size_) throw std::out_of_range("Element is out of range!");
            return elem_[i];
        }
        const_reference operator[](int i) const {
            if (i < 0 || i >= size_) throw std::out_of_range("Element is out of range!");
            return elem_[i];
        }
        reference front() {
            if (size_ == 0) throw std::out_of_range("Empty vector!");
            return elem_[0];
        }
        reference back() {
            if (size_ == 0) throw std::out_of_range("Empty vector!");
            return elem_[size_ - 1];
        }

        //Iteratoriai----------------------------------------------------------
        iterator begin() {
            if (size_ == 0) throw std::out_of_range("Empty vector!");
            return elem_;
        }
        iterator end() {
            if (size_ == 0) throw std::out_of_range("Empty vector!");
            return elem_ + size_;
        }

        //Funkcijos------------------------------------------------------------
        size_t size() const { return size_; }

        size_t capacity() const { return cap_; }

        bool empty() { return size_z == 0; }

        void clear() { size_z = 0; delete[] elem_; elem_ = new T[cap_]; }

        void erase(int i) {
            if (i < 0 || i >= size_)
                return;
            size_--;
            std::move(&elem_[i + 1], &elem_[size_], &elem_[i]);
        }

        void push_back(T el) {
            if (size_ == cap_) resize(size_ * 2);
            elem_[size_] = el;
            size_++;
        }

        void push_front(T n) {
            if (sz == cap) resize(sz * 2);
            std::move(&elem[0], &elem[sz], &elem[1]);
            elem[0] = n;
            sz++;
        }

        void resize(size_t n) {
            size_t end;
            if (n == cap_) return;
            T *resize = new T[n];
            if (n < size_) {
                size_ = n;
                end = n;
            }
            else end = size_;
            std::move(&elem_[0], &elem_[end], resize);
            cap_ = n;
            delete[] elem_;
            elem_ = resize;
        }

        //Operatoriai---------------------------------------------------------
        friend std::ostream & operator << (std::ostream & z, vek::vector<T> vect) {
            for (auto i : vect)
                cout << i << " ";
            return z;
        }
        reference operator[](size_t i) {
            if (i < 0 || capacity() <= i) throw std::out_of_range {"Vector::operator[]"};
            return elem_[i];
        }


    };
}

#endif //VECTOR_VECTOR_H
