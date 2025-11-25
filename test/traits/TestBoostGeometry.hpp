#pragma once

#include "acacia/traits/BoostGeometry.hpp"
#include "common/TestCommon.hpp"

using namespace acacia::model;
using namespace boost::unit_test;
namespace tt = boost::test_tools;

void t_traits_boost_geometry()
{
    BOOST_TEST_CONTEXT("Boost.Geometry Point2D integration")
    {
        using BGPoint = boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>;
        Point2D<double> acacia_point(1.5, -2.5);
        BGPoint bg_point;

        boost::geometry::convert(acacia_point, bg_point);
        BOOST_TEST(boost::geometry::get<0>(bg_point) == 1.5, tt::tolerance(1e-9));
        BOOST_TEST(boost::geometry::get<1>(bg_point) == -2.5, tt::tolerance(1e-9));

        BGPoint bg_point2(3.0, 4.0);
        Point2D<double> acacia_point2;
        boost::geometry::convert(bg_point2, acacia_point2);
        BOOST_TEST(acacia_point2[0] == 3.0, tt::tolerance(1e-9));
        BOOST_TEST(acacia_point2[1] == 4.0, tt::tolerance(1e-9));
    }
}

void t_traits_boost_geometry_algorithm()
{
    BOOST_TEST_CONTEXT("Boost.Geometry algorithms with Point2D")
    {
        using namespace boost::geometry;
        Point2D<double> p1(0.0, 0.0);
        Point2D<double> p2(3.0, 4.0);

        double dist = distance(p1, p2);
        BOOST_TEST(dist == 5.0, tt::tolerance(1e-9));

        Point2D<double> midpoint;
        midpoint[0] = (p1[0] + p2[0]) / 2.0;
        midpoint[1] = (p1[1] + p2[1]) / 2.0;

        BOOST_TEST(midpoint[0] == 1.5, tt::tolerance(1e-9));
        BOOST_TEST(midpoint[1] == 2.0, tt::tolerance(1e-9));            
    }
}