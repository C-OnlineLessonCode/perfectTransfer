#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class Vector {
public:
    Vector(int size):
        m_size(size) {
        std::cout << "Vector()" << std::endl;
        m_buf = new int[size];
        for (int i = 0; i < size; ++i) {
            m_buf[i] = i;
        }
    }
    Vector(const Vector& a) {
        std::cout << "Vector(const A& a)" << std::endl;
        m_buf = new int[a.m_size];
        m_size = a.m_size;
        std::copy(a.m_buf, a.m_buf + a.m_size, m_buf);
    }
    
    Vector& (Vector&& a) noexcept {
        std::cout << "Vector& & a)" << std::endl;
        m_size = a.m_size;
        m_buf = a.m_buf;
        a.m_buf = nullptr;
       
    }
    Vector& operator=(const Vector& a) {
        std::cout << "Vector& operator=(const Vector& a)" << std::endl;
        delete[] m_buf;
        m_size = a.m_size;
        std::copy(a.m_buf, a.m_buf + a.m_size, m_buf);
        return *this;
    }
    Vector& operator=(Vector&& a) noexcept {
        std::cout << "Vector& operator=(const Vector& a)" << std::endl;
        delete[] m_buf;
        m_size = a.m_size;
        m_buf = a.m_buf;
        a.m_buf = nullptr;
        return *this;
    }
    ~Vector() {
        std::cout << "~Vector()" << std::endl;
        if (m_buf) {
            delete[] m_buf;
        }
    }

private:
    int* m_buf = nullptr;
    size_t m_size = 0;
};

int main() { 
    Vector a1(1);
    a1 = 20;
}
