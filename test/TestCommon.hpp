#pragma once
#define BOOST_TEST_INCLUDED
// #define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/mpl/list.hpp>
#include <filesystem>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <list>

inline std::string GetTestOutDataPath()
{

    return std::filesystem::path(__FILE__).parent_path().string() + "/data/out";
}

inline std::string GetTestInDataPath()
{
    return std::filesystem::path(__FILE__).parent_path().string() + "/data/in";
}