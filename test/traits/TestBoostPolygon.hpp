#pragma once
#include "acacia/traits/BoostPolygon.hpp"
#include "common/TestCommon.hpp"

using namespace boost::unit_test;
namespace tt = boost::test_tools;

void t_traits_boost_polygon()
{
    BOOST_TEST_CONTEXT("Boost.Polygon Point2D integration")
    {
        using namespace acacia::model;
        using namespace boost::polygon;

        Point2D<int> p(1, 2);

        // read via point_traits (should forward to Point2D::operator[])
        BOOST_TEST(point_traits<Point2D<int>>::get(p, HORIZONTAL) == 1);
        BOOST_TEST(point_traits<Point2D<int>>::get(p, VERTICAL) == 2);

        // modify via point_mutable_traits::set
        point_mutable_traits<Point2D<int>>::set(p, HORIZONTAL, 5);
        point_mutable_traits<Point2D<int>>::set(p, VERTICAL, 6);
        BOOST_TEST(p[0] == 5);
        BOOST_TEST(p[1] == 6);

        // construct from raw coords
        Point2D<int> p2 = point_mutable_traits<Point2D<int>>::construct(7, 8);
        BOOST_TEST(p2[0] == 7);
        BOOST_TEST(p2[1] == 8);

        // construct from boost::polygon::point_data
        point_data<int> pd(9, 10);
        Point2D<int> p3 = point_mutable_traits<Point2D<int>>::construct(pd);
        BOOST_TEST(p3[0] == 9);
        BOOST_TEST(p3[1] == 10);
    }
}

void t_traits_boost_polygon_algorithm()
{
    BOOST_TEST_CONTEXT("Boost.Polygon algorithms with Point2D")
    {
        using namespace acacia::model;
        using namespace boost::polygon;

        Point2D<int> a(0, 0);
        Point2D<int> b(3, 4);
        BOOST_TEST(manhattan_distance(a, b) == 7);
        BOOST_TEST(convolve(a, b) == b);
    }
}   