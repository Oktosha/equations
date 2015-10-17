//
// Created by Дарья Колодзей on 17.10.15.
//

#ifndef EQUATIONS_Z_H
#define EQUATIONS_Z_H

#include <iosfwd>
#include <iostream>

template <int P> class Z;

template <int P>
std::ostream& operator << (std::ostream&, const Z<P>&);

template <int P>
std::istream& operator >> (std::istream&, Z<P>&);

template <int P>
class Z {
  public:
    Z() : _x(0) {}

    //Constructor is implicit. I know.
    Z(int x) : _x(x) {
        _x = (_x % P +  P) % P;
    }

    Z(const Z<P>&) = default;
    Z<P>& operator = (const Z<P>&) = default;

    Z<P> operator + (const Z<P>& a) const {
        return Z<P>(_x + a._x);
    }
    Z<P> operator - (const Z<P>& a) const {
        return Z<P>(_x - a._x);
    }
    Z<P> operator * (const Z<P>& a) const {
        return Z<P>(_x * a._x);
    }
    Z<P> operator - () const {
        return Z<P>(-_x);
    }
    bool operator == (const Z<P>& a) const {
        return _x == a._x;
    }

    friend std::ostream& operator << <> (std::ostream&, const Z<P>&);
    friend std::istream& operator >> <> (std::istream&, Z<P>&);
  private:
    int _x;
};

template <int P>
std::ostream& operator << (std::ostream& os, const Z<P>& x) {
    os << x._x;
    return os;
}

template <int P>
std::istream& operator >> (std::istream& is, Z<P>& x) {
    int t;
    is >> t;
    x = Z<P>(t);
    return is;
}
#endif //EQUATIONS_Z_H
