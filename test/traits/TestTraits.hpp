#pragma once

#include "TestBoostGeometry.hpp"
#include "TestBoostPolygon.hpp"

test_suite * create_traits_test_suite()
{
    auto * test_suite = BOOST_TEST_SUITE("Traits Test Suite");

    test_suite->add(BOOST_TEST_CASE(&t_traits_boost_geometry));
    test_suite->add(BOOST_TEST_CASE(&t_traits_boost_geometry_algorithm));

    test_suite->add(BOOST_TEST_CASE(&t_traits_boost_polygon));
    test_suite->add(BOOST_TEST_CASE(&t_traits_boost_polygon_algorithm));

    return test_suite;
}