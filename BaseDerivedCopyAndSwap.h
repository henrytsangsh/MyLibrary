//
// Created by Henry Tsang on 2019-07-02.
//

#ifndef TESTINGEXE_BASEDERIVEDTEMPLATE_H
#define TESTINGEXE_BASEDERIVEDTEMPLATE_H

#include <algorithm>

class BaseClass
{

protected:
    int i_;

public:

    // Default constructor (with optional parameters)
    BaseClass(int i = 0) :
        i_(i)
    { }

    // Default destructor
    virtual ~BaseClass() = default;

    // Copy constructor
    BaseClass(const BaseClass& ref) = default;

    // Assignment operator (using copy-swap idiom)
    BaseClass& operator=(BaseClass ref) noexcept
    {
        swap(*this, ref);
        return *this;
    }

    // Move constructor (using the copy-swap idiom)
    BaseClass(BaseClass&& ref) noexcept :
        BaseClass{} // using c++11 cascading constructors, init object to default state
    {
        swap(*this, ref);
    }

    // Swap
    friend void swap(BaseClass& a, BaseClass& b) noexcept {
        using std::swap;

        // Swap all member variables
        swap(a.i_, b.i_);
    }

    // Move assignment operator = no longer necessary
};


class DerivedClass :
    public BaseClass
{
private:
    int j_;

public:

    // Default constructor
    DerivedClass(int j = 0, int i = 0) noexcept :
        BaseClass(i),
        j_(j)
    {}

    // Default destructor
    virtual ~DerivedClass() = default;

    // Copy constructor
    DerivedClass(const DerivedClass& ref) = default;

    // Assignment operator
    DerivedClass& operator=(DerivedClass& ref) noexcept
    {
        swap(*this, ref);
        return *this;
    }

    // Move constructor
    DerivedClass(DerivedClass&& ref) noexcept :
        DerivedClass{}
    {
        swap(*this, ref);
    }

    friend void swap(DerivedClass& a, DerivedClass& b) noexcept {

        using std::swap;

        swap(static_cast<BaseClass&>(a), static_cast<BaseClass&>(b));
        swap(a.j_, b.j_);
    }

};

#endif //TESTINGEXE_BASEDERIVEDTEMPLATE_H
