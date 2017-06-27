#pragma once

namespace util
{
    template <typename T> class Iterator
    {
    protected:
        // variables
        T m_value;
        Iterator * m_next;
        Iterator * m_prev;
    public:
        // public defaults
        inline Iterator() : Iterator(nullptr, nullptr) {};
        inline Iterator(Iterator * next) : Iterator(nullptr, next) {};
        inline Iterator(const T & value) : Iterator(value, nullptr, nullptr) {};
        inline Iterator(Iterator & other) : Iterator(other.m_value, other.m_prev, other.m_next) {};
        inline Iterator(const T & value, Iterator * next) : Iterator(value, nullptr, next) {};
        inline Iterator(Iterator * prev, Iterator * next) { this->m_next = next; this->m_prev = prev; };
        inline Iterator(const T & value, Iterator * prev, Iterator * next) { this->m_next = next; this->m_prev = prev; this->m_value = value; };
        // public functions
        inline Iterator * & prev()  { return this->m_prev; };
        inline Iterator * & next()  { return this->m_next; };
        inline Iterator * & left()  { return this->prev(); };
        inline Iterator * & right() { return this->next(); };
        // public operator overloading
        inline operator T() { return (T) this->m_value; };
        inline operator T&() { return (T&) this->m_value; };
        inline void operator =(const T & other) { this->m_value = other; }
        inline void operator =(const Iterator & other) { this->m_next = other.m_next; this->m_prev = other.m_prev; this->m_value = other.m_value; }
    };
}