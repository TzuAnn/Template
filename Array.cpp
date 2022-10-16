#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include"Array.h"
using namespace std;
template<typename T>
Array<T>::Array( int Asize )
{
    size = ( Asize > 0 ? Asize : 10 );
    ptr = new T[size];
    /* for ( int i = 0; i < size; i++ )
    {
        ptr[i] = '0';
    } */
}
template<typename T>
Array<T>::Array(const Array<T> &copy)
:size(copy.size)
{
    cout << "copy constructor" << endl;
    ptr = new T[size];
    for ( int i = 0; i < size; i++ )
    {
        ptr[i] = copy.ptr[i];
    }
}
template<typename T>
Array<T>::~Array()
{
    delete[]ptr;
}
template<typename T>
int Array<T>::getSize() const
{
    return size;
}
template<typename T>
const Array<T> &Array<T>::operator=(const Array &right)
{
    if ( &right != this )
    {
        if ( size != right.size )
        {
            delete[] ptr;
            size = right.size;
            ptr = new T[size];
        }
        for ( int i = 0 ; i < size; i++ )
        {
            ptr[i] = right.ptr[i];
        }
    }
    return *this;
}
template<typename T>
bool Array<T>::operator==(const Array &right) const
{
    if ( size != right.size )
        return false;
    for ( int i = 0; i < size; i++ )
        if ( ptr[i] != right.ptr[i] )
            return false;
        return true;
}
template<typename T>
T &Array<T>::operator[](int subscript)
{
    if ( subscript < 0 || subscript >= size )
    {
        cerr << "\nError: Subscript " << subscript << " out of range " << endl;
        exit(1);
    }
    return ptr[subscript];
}

/* template<typename T>
int Array<T>::operator[](int subscript) const
{
    if ( subscript < 0 || subscript >= size )
    {
        cerr << "\nError: Subscript " << subscript << " out of range " << endl;
        exit(1);
    }
    return ptr[subscript];
} */
template<typename T>
ostream &operator<<( ostream &output, const Array<T> &a )
{
    int i;
    // output private ptr-based array
    for ( i = 0; i < a.size; i++ )
    {
        output << setw( 12 ) << a.ptr[ i ];
        if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
            output << endl;
    } // end for
    if ( i % 4 != 0 )  // end last line of output
        output << endl;
    return output;   // enables cout << x << y;
}
template<typename T>
istream &operator>>( istream &input, Array<T> &a )
{
    for ( int i = 0; i < a.size; i++ )
        input >> a.ptr[i];
    return input;   // enables cin >> x >> y;
}
template<typename T>
void Array<T>::swap(int a, int b)
{
    if ( a >= size || a < 0 )
    {
        cerr << "\nswapping fails " << a << " out of range " << endl;
    }
    if ( b < 0 || b >= size )
    {
        cerr << "\nswapping fails " << b << " out of range " << endl;
    }
    if ( a < size && b < 0 && b >= size && a < 0 )
    {
        T abc;
        abc = ptr[a];
        ptr[a] = ptr[b];
        ptr[b] = abc;
    }
}