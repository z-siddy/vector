//
// Created by zygsi on 5/7/2019.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include "main.h"

namespace vek {
    template < typename T >
    class vector;

    template < typename T >
    bool operator== (const vector <T>&, const vector <T>&);

    template < typename T >
    bool operator!= (const vector <T>&, const vector <T>&);

    template < typename T >
    bool operator< (const vector <T>&, const vector <T>&);

    template < typename T >
    bool operator> (const vector <T>&, const vector <T>&);

    template < typename T >
    bool operator<= (const vector <T>&, const vector <T>&);

    template < typename T >
    bool operator>= (const vector <T>&, const vector <T>&);

    template < typename T >
    class vector {
    private:
        size_t size_;
        size_t cap_;
        T *elem_;
    public:
        //Konstruktoriai / destruktoriai---------------------------------------
        vector() : size_{ 0 }, elem_{ new T[size_] }, cap_{ 0 } {};
        vector(size_t size) : size_{ size }, elem_{ new T[size] }, cap_{ size } {};
        vector(size_t size, T value) : size_{ size }, elem_{ new T[size] }, cap_{ size } { std::fill_n(elem_, size, value); }
        vector(vector&& a)
                : size_{ a.size_ },
                  elem_{ a.elem_ }, cap_{ a.cap_ } {
            a.elem_ = nullptr;
            a.size_ = 0;
            a.cap_ = 0;
        }
        vector(std::initializer_list<T> il)
                : size_{ static_cast<std::size_t>(il.size()) },
                  cap_{ size_ },
                  elem_{ new T[il.size()] } {
            std::copy(il.begin(), il.end(), elem_);
        }
        ~vector() { delete[] elem_; }

        vector& operator= (const vector& v){
            if(&v == this) return *this;
            T *p = new T[v.size_];
            for(int i = 0; i != v.size_; i++) p[i] = v.elem_[i];
            delete[] elem_;
            elem_ = p;
            size_ = v.size_;
            return *this;
        }

        vector& operator= (const vector&& v){
            if(&v == this) return *this;
            delete[] elem_;
            elem_ = v.elem_;
            size_ = v.size_;
            v.elem_ = nullptr;
            v.size_ = 0;
            return *this;
        }

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
            if (size_ > 0)
                return elem_;
        }
        iterator end() {
            if (size_ > 0)
                return elem_ + size_;
        }

        //Funkcijos------------------------------------------------------------
        size_t size() const { return size_; }

        size_t capacity() const { return cap_; }

        bool empty() { return size_ == 0; }

        void clear() { size_ = 0; delete[] elem_; elem_ = new T[cap_]; }

        void erase(int i) {
            if (i < 0 || i >= size_)
                return;
            size_--;
            std::move(&elem_[i + 1], &elem_[size_], &elem_[i]);
        }

        void push_back(const_reference value ) {
            if (cap_ == 0) {
                elem_ = new T[1];
                elem_[0] = value;
                cap_ = 1;
                size_ = 1;
            } else {
                if (!(size_ < cap_)) {
                    reserve(cap_ * 2);
                }
                elem_[size_++] = value;
            }
        }

        void reserve(size_t ncap) {
            if (cap_ < ncap) {
                T *temp = new T[ncap];
                for (auto i = 0; i < size_; i++)
                    temp[i] = elem_[i];
                delete[] elem_;
                elem_ = temp;
                cap_ = ncap;
            }
        }

        void push_front(T n) {
            if (size_ == cap_) resize(size_ * 2);
            std::move(&elem_[0], &elem_[size_], &elem_[1]);
            elem_[0] = n;
            size_++;
        }

        iterator resize(size_t n, iterator it = 0) {
            if (n == 0) {
                size_ = 0;
                cap_ = 2;
                T *resize = new T[2];
                delete[] elem_;
                elem_ = resize;
                return 0;
            }
            size_t end;
            if (n == cap_) return it;
            T *resize = new T[n];
            if (n < size_) {
                size_ = n;
                end = n;
            }
            else end = size_;
            auto pos = it - begin();
            std::move(&elem_[0], &elem_[end], resize);
            cap_ = n;
            delete[] elem_;
            elem_ = resize;
            return begin() + pos;
        }

        void shrink_to_fit() {
            if (size_ == cap_) return;
            T *resize = new T[size_];
            std::move(&elem_[0], &elem_[size_], resize);
            cap_ = size_;
            delete[] elem_;
            elem_ = resize;
        }

        void swap(vector<T> & vec) {
            size_t sw_sz = vec.size_;
            size_t sw_cap = vec.cap_;
            vector<T> sw_c(vec.size());
            vector<T> sw_o(size_);
            std::move(vec.begin(), vec.end(), sw_c.elem_);
            std::move(&elem_[0], &elem_[size_], sw_o.elem_);
            vec.size_ = size_;
            vec.cap_ = cap_;
            delete[] vec.elem_;
            delete[] elem_;
            size_ = sw_sz;
            cap_ = sw_cap;
            elem_ = sw_c.elem_;
            vec.elem_ = sw_o.elem_;
        }

        T& at(size_t pos) {
            if ((pos < 0) || (pos >= size_)) {
                throw std::out_of_range("Out of array!");
            }
            return elem_[pos];
        }

        const_reference at(size_t pos)const {
            if ((pos < 0) || (pos >= size_)) {
                throw std::out_of_range("Out of array!");
            }
            return elem_[pos];
        }

        void assign(size_t count, const T& val) {
            assign(0, count, val);
        }

        void assign(size_t first, size_t last, const T& val) {
            size_ = last;
            for (size_t i = first; (i < last) && (i < size_); i++)
                elem_[i] = val;
        }

        T* data() noexcept{
            return elem_;
        }

        void pop_back() {
            if (!size_)
                return;
            else
                size_--;
        }

        iterator insert(iterator pos, const T & a) {
            insert(pos, 1, a);
            return pos;
        }

        iterator insert(iterator pos, size_t b, const T & a) {
            if (pos > elem_ + size_) throw std::out_of_range("Out of array!");
            for(int i = 0; i < b; i++){
                if (size_ >= cap_) {
                    pos = resize(size_ * 2,pos);
                }
                size_++;
                std::move(pos, pos + size_, pos + 1);
                *pos = a;
            }
            return pos;
        }

        iterator insert(iterator pos, std::initializer_list<T> il){
            if(size_+il.size() >= cap_){
                pos = resize(size_ + il.size() * 2,pos);
            }
            std::move(pos, pos + size_, pos + il.size());
            size_ += il.size();
            std::move(il.begin(), il.end(), pos);
            return pos;
        }

        iterator emplace(iterator it, const T & args) {
            return insert(it, std::move(args));
        }

        void emplace_back(const T &args) {
            return push_back(std::move(args));
        }
        void emplace_front(const T &args) {
            return push_front(std::move(args));
        }

        //Operatoriai---------------------------------------------------------
        reference operator[](size_t i) {
            if (i < 0 || capacity() <= i) throw std::out_of_range {"Vector::operator[]"};
            return elem_[i];
        }

        friend bool operator== <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator!= <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator< <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator> <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator<= <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator>= <T> (const vector <T>& left, const vector <T>& right);

    };

    template < typename T >
    bool operator== (const vector <T>& left, const vector <T>& right) {
        if (left.size_ != right.size_)return false;
        else
            for (int i = 0; i < left.size_; ++i)
                if (left[i] != right[i])return false;
        return true;
    }

    template < typename T >
    bool operator!= (const vector <T>& left, const vector <T>& right) {
        return !(left == right);
    }

    template < typename T >
    bool operator< (const vector <T>& left, const vector <T>& right) {

        if(left.empty() && right.empty()) return false;
        else if (left.empty()) return true;
        else if (right.empty()) return false;
        else {
            int i = 0;
            while(left[i]==right[i]){
                if((i+1 > left.size_)||(i+1 > right.size_)) break;
                i++;
            }
            if(left[i] < right[i]) return true;
            else if(left[i] == right[i]){
                if(left.size_ < right.size_) return true;
                else return false;
            }
            else return false;
        }
    }

    template < typename T >
    bool operator> (const vector <T>& left, const vector <T>& right) {
        return !(left < right);
    }

    template < typename T >
    bool operator<= (const vector <T>& left, const vector <T>& right) {

        if(left.empty() && right.empty()) return true;
        else if (left.empty()) return true;
        else if (right.empty()) return false;
        else {
            int i = 0;
            while(left[i]==right[i]){
                if((i+1 > left.size_)||(i+1 > right.size_)) break;
                i++;
            }
            if(left[i] < right[i]) return true;
            else if(left[i] == right[i]){
                if(left.size_ < right.size_) return true;
                else return true;
            }
            else return false;
        }
    }

    template < typename T >
    bool operator>= (const vector <T>& left, const vector <T>& right) {
        return !(left <= right);
    }
    template  < typename T >
    vector <T> operator+(const vector <T>& a, const vector <T>& b) {
        if (a.size() != b.size())
            throw std::runtime_error("Vector sizes not equal!");
        auto size = a.size();
        vector<T> c(size);
        for (auto i = 0; i != a.size(); ++i) c[i] = a[i] + b[i];
        return c;
    }

}

#endif //VECTOR_VECTOR_H
