#pragma once

#include "acacia/model/Point.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-but-set-variable"
#pragma clang diagnostic ignored "-Wbitwise-instead-of-logical"
#include <boost/polygon/polygon.hpp>
#pragma clang diagnostic pop

namespace boost::polygon {

using namespace acacia::model;

template <typename Coord>
struct geometry_concept<Point2D<Coord>> { using type = point_concept; };

template <typename Coord>
struct point_traits<Point2D<Coord>>
{
    using coordinate_type = Coord;
    static inline coordinate_type get(const Point2D<Coord>& point, orientation_2d orient)
    {
        return point[orient == HORIZONTAL ? 0 : 1];
    }
    static inline void set(Point2D<Coord>& point, orientation_2d orient, coordinate_type value)
    {
        point[orient == HORIZONTAL ? 0 : 1] = value;
    }
};

template <typename Coord>
struct point_mutable_traits<Point2D<Coord>>
{
    using coordinate_type = Coord;
    static inline void set(Point2D<Coord>& point, orientation_2d orient, coordinate_type value)
    {
        point[orient == HORIZONTAL ? 0 : 1] = value;
    }

    static inline Point2D<Coord> construct(coordinate_type x, coordinate_type y)
    {
        return Point2D<Coord>{x, y};
    }

    static inline Point2D<Coord> construct(const point_data<coordinate_type>& point)
    {
        return Point2D<coordinate_type>{point.x(), point.y()};
    }
};

} // namespace boost::polygon