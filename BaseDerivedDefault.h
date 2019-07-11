//
// Created by Henry Tsang on 2019-07-02.
//

#ifndef TESTINGEXE_BASEDERIVEDDEFAULT_H
#define TESTINGEXE_BASEDERIVEDDEFAULT_H

#include <algorithm>

class Base
{
    int i_;

public:

    // Constructor
    Base(int i = 0) noexcept :
        i_(i)
    {}

    // Destructor
    virtual ~Base() = default;

    // Copy constructor
    Base(const Base&) = default;

    // Copy assignment operator
    Base& operator=(const Base&) = default;

    // Move constructor
    Base(Base&&) = default;

    // Move assignment operator
    Base& operator=(Base&&) = default;

    // note: these are manually defined as destructor need manual definition to have virtual

    friend void swap(Base& a, Base& b) noexcept
    {
        using std::swap;

        swap(a.i_, b.i_);
    }

};

class Derived :
    public Base
{
    int j_;

public:
    Derived(int j = 0, int i = 0) noexcept :
        Base(i),
        j_(j)
    {}

    friend void swap(Derived& a, Derived& b) noexcept
    {
        using std::swap;

        swap(static_cast<Base&>(a), static_cast<Base&>(b));
        std::swap(a.j_, b.j_);
    }
};

#endif //TESTINGEXE_BASEDERIVEDDEFAULT_H
