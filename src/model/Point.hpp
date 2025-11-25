#pragma once
#include "acacia/infra/Math.hpp"
#include <array>

namespace acacia::model {

template <typename Coord, size_t Dim>
class Point
{
    using FCoord = float_t<Coord>;
    using Coords = std::array<Coord, Dim>;
public:

    ///@brief constructs a point with all zero coordinates
    Point();
    ///@brief constructs a point with given coordinates
    
    template <std::same_as<Coord>... Args> requires (sizeof...(Args) == Dim)
    Point(Args... args);

    ///@brief check if this point equals to p
    bool operator== (const Point<Coord, Dim> & p) const;
    
    ///@brief check if this point not equals to p
    bool operator!= (const Point<Coord, Dim> & p) const;

    ///@brief access the x, y coordinate by index 0-1
    Coord & operator[] (size_t dim);
    const Coord & operator[] (size_t dim) const;

    Point<Coord, Dim> operator+ (const Point<Coord, Dim> & coor) const;
    Point<Coord, Dim> operator- () const;
    Point<Coord, Dim> operator- (const Point<Coord, Dim> & coor) const;
    Point<Coord, Dim> operator* (FCoord scale) const;
    Point<Coord, Dim> operator/ (FCoord scale) const;
    void operator+= (const Point<Coord, Dim> & coor);
    void operator-= (const Point<Coord, Dim> & coor);
    void operator*= (FCoord scale);
    void operator/= (FCoord scale);
    Point<Coord, Dim> operator* (const Point<Coord, Dim> & a) const;

    // start std style apis
    using iterator = typename Coords::iterator;
    using const_iterator = typename Coords::const_iterator;
    iterator begin() { return m_coords.begin(); }
    iterator end() { return m_coords.end(); }
    const_iterator begin() const { return m_coords.begin(); }
    const_iterator end() const { return m_coords.end(); }
    const_iterator cbegin() const { return m_coords.cbegin(); }
    const_iterator cend() const { return m_coords.cend(); }   
    // end std style apis

private:
    Coords m_coords;
};

template <typename Coord, size_t Dim>
inline Point<Coord, Dim>::Point()
{
    m_coords.fill(0);
}

template <typename Coord, size_t Dim>
template <std::same_as<Coord>... Args> requires (sizeof...(Args) == Dim)
inline Point<Coord, Dim>::Point(Args... args) : m_coords{args...} {}

template <typename Coord, size_t Dim>
inline bool Point<Coord, Dim>::operator== (const Point<Coord, Dim> & p) const
{
    for (size_t i = 0; i < Dim; ++i) {
        if (not infra::math::EQ(m_coords[i], p[i])) return false;
    }
    return true;
}
template <typename Coord, size_t Dim>
inline bool Point<Coord, Dim>::operator!= (const Point<Coord, Dim> & p) const
{
    return not (*this == p);
}

template <typename Coord, size_t Dim>
inline Coord & Point<Coord, Dim>::operator[] (size_t dim)
{
    return m_coords[dim];
}

template <typename Coord, size_t Dim>
inline const Coord & Point<Coord, Dim>::operator[] (size_t dim) const
{
    return m_coords[dim];
}

template <typename Coord, size_t Dim>
inline Point<Coord, Dim> Point<Coord, Dim>::operator+ (const Point<Coord, Dim> & coor) const
{
    Point<Coord, Dim> res;
    for (size_t i = 0; i < Dim; ++i) {
        res[i] = m_coords[i] + coor[i];
    }
    return res;
}

template <typename Coord, size_t Dim>
inline Point<Coord, Dim> Point<Coord, Dim>::operator- () const
{
    Point<Coord, Dim> res;
    for (size_t i = 0; i < Dim; ++i) {
        res[i] = -m_coords[i];
    }
    return res;
}

template <typename Coord, size_t Dim>
inline Point<Coord, Dim> Point<Coord, Dim>::operator- (const Point<Coord, Dim> & coor) const
{
    Point<Coord, Dim> res;
    for (size_t i = 0; i < Dim; ++i) {
        res[i] = m_coords[i] - coor[i];
    }
    return res;
}

template <typename Coord, size_t Dim>
inline Point<Coord, Dim> Point<Coord, Dim>::operator* (FCoord scale) const
{
    Point<Coord, Dim> res(*this);
    std::for_each(res.begin(), res.end(), [scale](Coord & c) { c *= scale; });
    return res;
}

template <typename Coord, size_t Dim>
inline Point<Coord, Dim> Point<Coord, Dim>::operator/ (FCoord scale) const
{
    scale = 1 / scale;
    Point<Coord, Dim> res(*this);
    std::for_each(res.begin(), res.end(), [scale](Coord & c) { c *= scale; });
    return res;
}

template <typename Coord, size_t Dim>
inline void Point<Coord, Dim>::operator+= (const Point<Coord, Dim> & coor)
{
    for (size_t i = 0; i < Dim; ++i) {
        m_coords[i] += coor[i];
    }
}

template <typename Coord, size_t Dim>
inline void Point<Coord, Dim>::operator-= (const Point<Coord, Dim> & coor)
{
    for (size_t i = 0; i < Dim; ++i) {
        m_coords[i] -= coor[i];
    }
}

template <typename Coord, size_t Dim>
inline void Point<Coord, Dim>::operator*= (FCoord scale)
{
    std::for_each(m_coords.begin(), m_coords.end(), [scale](Coord & c) { c *= scale; });
}

template <typename Coord, size_t Dim>
inline void Point<Coord, Dim>::operator/= (FCoord scale)
{
    scale = 1 / scale;
    std::for_each(m_coords.begin(), m_coords.end(), [scale](Coord & c) { c *= scale; });
} 

template <typename Coord, size_t Dim>
inline Point<Coord, Dim> Point<Coord, Dim>::operator* (const Point<Coord, Dim> & a) const
{
    Point<Coord, Dim> res;
    for (size_t i = 0; i < Dim; ++i) {
        res[i] = m_coords[i] * a[i];
    }
    return res;
}

template <typename Coord>
using Point2D = Point<Coord, 2>;

template <typename Coord>
using Point3D = Point<Coord, 3>;

} // namespace acacia::model
    
