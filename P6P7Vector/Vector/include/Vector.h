/*
Elijah Stultz
CISP 400, MW, 3:00pm
Programming Project 7
May 13, 2020
*/

#include <iostream>
#include <fstream>
using namespace std;

#ifndef VECTOR_H_ECS_
#define VECTOR_H_ECS_

template <class T>
class Vector
{
  T* _array;
  unsigned _length;
  unsigned _size;
  int _zero;

  public:

    // Constructors and Destructor
    Vector (int Vindex = 0);
    //Vindex is the virtual index of the first element in your Vector
    Vector (const T* a, unsigned s, int Vindex = 0);
    // Vindex is the virtual index of the first element in your Vector
    // s is the number of items pointed to by T*
    Vector (const Vector<T>&);

    ~Vector ();

    //Assignment operator
    Vector<T>& operator= (const Vector<T>&);

    // Insert the Vector or a pointer to an Vector into an out stream
    template<class OT>
    friend ostream& operator<< (ostream&, const Vector<OT>&);
    template<class OT>
    friend ostream& operator<< (ostream&, const Vector<OT>*);

    // access the item at index 0<=Vindex<length (if we are using standard indexing)
    T& operator[] ( int Vindex );
    const T& operator[] (int Vindex) const;

    // Returns a new sub vector beginning at index vfirst and through index vlast-1
    Vector<T> operator() (int Vfirst, int Vlast)const;

    // Add either a new item or another Vector beginning at index length
    Vector<T>& operator+= (const T&);
    Vector<T>& operator+= (const Vector<T>&);

    // Return the number of items in the array
    unsigned Length () const;

    // Delete the item at index 0<=Vindex<length (if we are using standard indexing)
    void Remove (const int Vindex);

    // Delete the items from index vfirst through index vlast-1
    void Remove (int Vfirst, int Vlast);

    // Delete the item at index 0 (if we are using standard indexing)
    void Remove ();

    // Insert at index 0<=Vindex<length (if we are using standard indexing)
    void Insert (const T&, int Vindex);

    // Insert at index 0 (if we are using standard indexing)
    void Insert (const T&);

    //project 7 functions
    void write (ofstream &) const;
    void read (ifstream &);
};

template <class T>
Vector<T>::Vector (int Vindex)
:_length(0), _size(0), _zero(Vindex)
{
  _array = NULL;
}

template <class T>
Vector<T>::Vector (const T* a, unsigned s, int Vindex)
:_array(NULL),_length(0), _size(0), _zero(Vindex)
{
  for (unsigned i = 0; i < s; ++i) operator+=(*(a + i));
}

template <class T>
Vector<T>::Vector (const Vector<T>& v)
:_array(NULL), _length(0), _size(0), _zero(v._zero)
{
  for (unsigned i = 0; i < v._length; ++i) operator+=(v._array[i]);
}

template <class T>
Vector<T>::~Vector()
{
  delete [] _array;
}

template <class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& v)
{
  if (this != &v)
  {
    delete [] _array;
    _array = NULL;
    _size = 0;
    _length = 0;
    _zero = v._zero;

    for (unsigned i = 0; i < v._length; ++i) operator+= (v._array[i]);
  }
  return *this;
}

template<class OT>
ostream& operator<< (ostream& of, const Vector<OT>& v)
{
  if (v._length > 0)
  {
    for (unsigned i = 0; i < v._length; ++i) of << v._array[i] << ", ";
  }

  return of;
}

template<class OT>
ostream& operator<< (ostream& of, const Vector<OT>* pv)
{
  of << *pv;
}

template <class T>
T& Vector<T>::operator[] ( int Vindex )
{
  int realIndex = Vindex - _zero;

  //boundary checking
  if (realIndex >= _length || realIndex < 0) throw unsigned(17);
  return _array[realIndex];
}

template <class T>
const T& Vector<T>::operator[] (int Vindex) const
{
  int realIndex = Vindex - _zero;

  if (realIndex >= _length || realIndex < 0) throw unsigned(78);
  return _array[realIndex];
}

template <class T>
Vector<T> Vector<T>::operator() (int Vfirst, int Vlast)const
{
  int RealFIndex = Vfirst - _zero;
  int RealLIndex = Vlast - _zero;

  if (RealFIndex < 0 || RealLIndex >= _length || RealFIndex >= RealLIndex) throw unsigned(12);
  Vector<T> v(_zero);

  for (unsigned i = RealFIndex; i <= RealLIndex; ++i) v += _array[i];

  return v;
}

template<class T>
Vector<T>& Vector<T>::operator+= (const T& newt)
{
  if (_size > _length) _array[_length++] = newt;
  else
  {
    if (_size == 0) _size++;

    //double the size if its equal to or less than length
    _size *= 2;

    //dynamically allocate a new T array
    T *temp = new T [_size];

    //copy all contents from _array to temp array
    for (unsigned i = 0; i < _length; ++i) *(temp + i) = *(_array + i);

    delete [] _array;

    _array = temp;

    _array[_length++] = newt;
  }

  return *this;
}

template<class T>
Vector<T>& Vector<T>::operator+= (const Vector<T>& newv)
{
  for (unsigned i = 0, len = newv.Length(); i < len; ++i) operator+=(newv[i]);

  return *this;
}

template<class T>
unsigned Vector<T>::Length () const
{
  return _length;
}

//delete item at vindex assuming it is valid, then return a new vector
template<class T>
void Vector<T>::Remove (const int Vindex)
{
  int realIndex = Vindex - _zero;

  if (realIndex < 0 || realIndex >= _length) throw unsigned(25);

  Vector<T> temp(_zero);

  for (unsigned i = 0; i < _length; ++i)
  {
    if (i != realIndex) temp += _array[i];
  }
  //re-assign
  operator=(temp);
}

// Delete the items from index vfirst through index vlast-1
template<class T>
void Vector<T>::Remove (int Vfirst, int Vlast)
{

  int RealFIndex = Vfirst - _zero;
  int RealLIndex = Vlast - _zero;

  if (RealFIndex < 0 || RealLIndex >= _length || RealFIndex >= RealLIndex) throw unsigned(29);
  for (int i = Vlast - 1; i >= Vfirst; i--) Remove(i);
}

//removes first index
template <class T>
void Vector<T>::Remove ()
{
  Remove(_zero);
}

template<class T>
void Vector<T>::Insert (const T& newt, int Vindex)
{
  int realIndex = Vindex - _zero;

  Vector<T> temp(_zero);

  if (realIndex < 0 || realIndex >= _length) throw unsigned(22);

  for (unsigned i = 0; i < _length; ++i)
  {
    if (i == realIndex) temp += newt;
    temp += *(_array + i);
  }

  operator=(temp);
}

template <class T>
void Vector<T>::Insert (const T& newt)
{
  Insert(newt, _zero);
}

template<class T>
void Vector<T>::write(ofstream &of) const
{
  if(!of.is_open()) throw 34;

  //write _length, _zero, then _array
  of.write(reinterpret_cast<const char *>(&_length), sizeof(_length));
  of.write(reinterpret_cast<const char *>(&_zero), sizeof(_zero));
  of.write(reinterpret_cast<const char *>(_array), sizeof(T) * _length);
}

template<class T>
void Vector<T>::read(ifstream &inf)
{
  if(!inf.is_open()) throw 35;

  unsigned alength;
  int zero;

  //read in length of the array and the virtual index
  inf.read(reinterpret_cast<char *>(&alength), sizeof(unsigned));
  inf.read(reinterpret_cast<char *>(&zero), sizeof(int));

  T *arr = new T[alength];

  //read all the contents of the original array into a new one
  inf.read(reinterpret_cast<char *>(arr), sizeof(T) * alength);

  Vector<T> newVect(arr, alength, zero);

  operator=(newVect);

  delete [] arr;
}

#endif //VECTOR_H_ECS_
