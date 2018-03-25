/*
 * Vec2.hh
 *
 *  Created on: Dec 21, 2011
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef VEC2_HH_
#define VEC2_HH_

#include <cmath>
#include "RajaAPI.hh"

#if PENNANT_OPENMP

struct double2
{
    typedef double value_type;
    double x, y;
    inline double2() : x(0.), y(0.) {}
    inline double2(const double& x_, const double& y_) : x(x_), y(y_) {}
    inline double2(const double2& v2) : x(v2.x), y(v2.y) {}
    inline ~double2() {}

    inline double2& operator=(const double2& v2)
    {
        x = v2.x;
        y = v2.y;
        return(*this);
    }

    inline double2& operator+=(const double2& v2)
    {
        x += v2.x;
        y += v2.y;
        return(*this);
    }

    inline double2& operator-=(const double2& v2)
    {
        x -= v2.x;
        y -= v2.y;
        return(*this);
    }

    inline double2& operator*=(const double& r)
    {
        x *= r;
        y *= r;
        return(*this);
    }

    inline double2& operator/=(const double& r)
    {
        x /= r;
        y /= r;
        return(*this);
    }

}; // double2

inline double2 make_double2(const double& x_, const double& y_) {
    double2 r;
    r.x = x_;
    r.y = y_;
    return r;
}

#endif

// comparison operators:

// equals
inline bool RAJA_HOST_DEVICE operator==(const double2& v1, const double2& v2)
{
    return((v1.x == v2.x) && (v1.y == v2.y));
}

// not-equals
inline bool RAJA_HOST_DEVICE operator!=(const double2& v1, const double2& v2)
{
    return(!(v1 == v2));
}


// unary operators:

// unary plus
inline double2 RAJA_HOST_DEVICE operator+(const double2& v)
{
    return(v);
}

// unary minus
inline double2 RAJA_HOST_DEVICE operator-(const double2& v)
{
  double2 r;
  r.x = -v.x;
  r.y = -v.y;
  return r;
    //return(double2(-v.x, -v.y));
}


// binary operators:

// add
inline double2 RAJA_HOST_DEVICE operator+(const double2& v1, const double2& v2)
{
  double2 r;
  r.x = v1.x + v2.x;
  r.y = v1.y + v2.y;
  return r;
    //return(double2(v1.x + v2.x, v1.y + v2.y));
}

// subtract
inline double2 RAJA_HOST_DEVICE operator-(const double2& v1, const double2& v2)
{
  double2 r;
  r.x = v1.x - v2.x;
  r.y = v1.y - v2.y;
  return r;
    //return(double2(v1.x - v2.x, v1.y - v2.y));
}

// multiply vector by scalar
inline double2 RAJA_HOST_DEVICE operator*(const double2& v, const double& r)
{
  double2 res;
  res.x = v.x * r;
  res.y = v.y * r;
  return res;
    //return(double2(v.x * r, v.y * r));
}

// multiply scalar by vector
inline double2 RAJA_HOST_DEVICE operator*(const double& r, const double2& v)
{
  double2 res;
  res.x = v.x * r;
  res.y = v.y * r;
  return res;
    //return(double2(v.x * r, v.y * r));
}

// divide vector by scalar
inline double2 RAJA_HOST_DEVICE operator/(const double2& v, const double& r)
{
    double rinv = (double) 1. / r;

    double2 res;
    res.x = v.x * rinv;
    res.y = v.y * rinv;
    return res;

    //return(double2(v.x * rinv, v.y * rinv));
}


// other vector operations:

// dot product
inline double RAJA_HOST_DEVICE dot(const double2& v1, const double2& v2)
{
    double d = v1.x * v2.x + v1.y * v2.y;
#if 0
    return(v1.x * v2.x + v1.y * v2.y);
#endif // if 0
    return d;
}

// cross product (2D)
inline double RAJA_HOST_DEVICE cross(const double2& v1, const double2& v2)
{
    return(v1.x * v2.y - v1.y * v2.x);
}

// length
inline double RAJA_HOST_DEVICE length(const double2& v)
{
    return(std::sqrt(v.x * v.x + v.y * v.y));
}

// length squared
inline double RAJA_HOST_DEVICE length2(const double2& v)
{
    return(v.x * v.x + v.y * v.y);
}

// rotate 90 degrees counterclockwise
inline double2 RAJA_HOST_DEVICE rotateCCW(const double2& v)
{
  double2 r;
  r.x = -v.y;
  r.y = v.x;
  return r;
    //return(double2(-v.y, v.x));
}

// rotate 90 degrees clockwise
inline double2 RAJA_HOST_DEVICE rotateCW(const double2& v)
{
  double2 r;
  r.x = v.y;
  r.y = -v.x;
  return r;
    //return(double2(v.y, -v.x));
}

// project v onto subspace perpendicular to u
// u must be a unit vector
inline double2 RAJA_HOST_DEVICE project(double2& v, const double2& u)
{
    // assert(length2(u) == 1.);
    return v - dot(v, u) * u;
}


#endif /* VEC2_HH_ */
