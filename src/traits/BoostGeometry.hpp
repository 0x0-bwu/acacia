#pragma once

#include "acacia/model/Point.hpp"

#include <boost/geometry.hpp>

namespace boost::geometry::traits {

using namespace acacia::model;

// point

template <typename Coord>
struct tag<Point2D<Coord>> { using type = point_tag;};

template <typename Coord>
struct dimension<Point2D<Coord>> : boost::mpl::int_<2> {};

template <typename Coord>
struct coordinate_type<Point2D<Coord>> { using type = Coord; };

template <typename Coord>
struct coordinate_system<Point2D<Coord>> { using type = cs::cartesian; };

template <typename Coord, std::size_t Dimension>
struct access<Point2D<Coord>, Dimension>
{
    static Coord get(const Point2D<Coord> & p) { return p[Dimension]; }
    static void set(Point2D<Coord> & p, const Coord & value) { p[Dimension] = value; }
};


} // namespace boost::geometry::traits