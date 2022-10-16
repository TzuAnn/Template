#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
template <typename T>
class Array
{
    template <typename U>
    friend ostream &operator<<( ostream &, const Array<U> & );
    template <typename U> 
friend istream &operator>>( istream &, Array<U> & );
public:
    Array( int = 10 ); // default constructor
    Array( const Array & );// copy constructor
    ~Array();// destructor
    int getSize() const; // return size
    const Array &operator=( const Array & ); // assignment operator
    bool operator==( const Array &) const; // equality o
    //inequality operator; returns opposite of ==op
    bool operator!=( const Array &right ) const
    {
    return ! ( *this == right ); // invokes Array::operator==
    // end function operator!=
    }
    void swap(int, int);
    //subscript operator for non-const objects returns modifiabl
    T &operator[]( int ); 
    //subscript operator for const objects returns rvalue
    //int operator[]( int ) const;
private:
    int size; // pointer-based array size
    T *ptr; // pointer to first element of pointer-base
};
#endif