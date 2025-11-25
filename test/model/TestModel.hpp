
#pragma once

#include "TestPoint.hpp"

test_suite * create_model_test_suite()
{
    auto * test_suite = BOOST_TEST_SUITE("Model Test Suite");

    test_suite->add(BOOST_TEST_CASE(&t_model_point));

    return test_suite;
}