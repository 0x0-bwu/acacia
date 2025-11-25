#pragma once

#include "acacia/model/Point.hpp"
#include "common/TestCommon.hpp"

using namespace acacia::model;
using namespace boost::unit_test;
namespace tt = boost::test_tools;

void t_model_point()
{
    BOOST_TEST_CONTEXT("Point construction and comparison")
    {
        Point<int, 3> origin;
        for (auto coord : origin) {
            BOOST_TEST(coord == 0);
        }

        Point<int, 3> coordinates(1, 2, 3);
        Point<int, 3> same(1, 2, 3);
        Point<int, 3> different(3, 2, 1);

        BOOST_TEST(coordinates == same);
        BOOST_TEST(!(coordinates != same));
        BOOST_TEST(coordinates != different);
    }

    BOOST_TEST_CONTEXT("Point arithmetic and scaling")
    {
        Point<float, 3> a(1.5f, -2.0f, 0.25f);
        Point<float, 3> b(0.5f, 2.0f, -0.25f);

        auto sum = a + b;
        BOOST_TEST(sum[0] == 2.0f, tt::tolerance(1e-6f));
        BOOST_TEST(sum[1] == 0.0f, tt::tolerance(1e-6f));
        BOOST_TEST(sum[2] == 0.0f, tt::tolerance(1e-6f));

        auto diff = a - b;
        BOOST_TEST(diff[0] == 1.0f, tt::tolerance(1e-6f));
        BOOST_TEST(diff[1] == -4.0f, tt::tolerance(1e-6f));
        BOOST_TEST(diff[2] == 0.5f, tt::tolerance(1e-6f));

        auto hadamard = a * b;
        BOOST_TEST(hadamard[0] == 0.75f, tt::tolerance(1e-6f));
        BOOST_TEST(hadamard[1] == -4.0f, tt::tolerance(1e-6f));
        BOOST_TEST(hadamard[2] == -0.0625f, tt::tolerance(1e-6f));

        auto scaled = a * 2.0f;
        BOOST_TEST(scaled[0] == 3.0f, tt::tolerance(1e-6f));
        BOOST_TEST(scaled[1] == -4.0f, tt::tolerance(1e-6f));
        BOOST_TEST(scaled[2] == 0.5f, tt::tolerance(1e-6f));

        auto divided = a / 2.0f;
        BOOST_TEST(divided[0] == 0.75f, tt::tolerance(1e-6f));
        BOOST_TEST(divided[1] == -1.0f, tt::tolerance(1e-6f));
        BOOST_TEST(divided[2] == 0.125f, tt::tolerance(1e-6f));

        Point<int, 3> ints(1, 2, 3);
        ints += Point<int, 3>(3, 2, 1);
        BOOST_TEST(ints[0] == 4);
        BOOST_TEST(ints[1] == 4);
        BOOST_TEST(ints[2] == 4);

        ints -= Point<int, 3>(1, 1, 1);
        BOOST_TEST(ints[0] == 3);
        BOOST_TEST(ints[1] == 3);
        BOOST_TEST(ints[2] == 3);

        ints *= 2.0f;
        BOOST_TEST(ints[0] == 6);
        BOOST_TEST(ints[1] == 6);
        BOOST_TEST(ints[2] == 6);

        ints /= 2.0f;
        BOOST_TEST(ints[0] == 3);
        BOOST_TEST(ints[1] == 3);
        BOOST_TEST(ints[2] == 3);
    }

    BOOST_TEST_CONTEXT("Point2D helpers")
    {
        Point2D<double> p(3.0, -1.0);
        Point2D<double> q(-1.0, 4.0);

        auto sum = p + q;
        BOOST_TEST(sum[0] == 2.0, tt::tolerance(1e-9));
        BOOST_TEST(sum[1] == 3.0, tt::tolerance(1e-9));

        auto neg = -p;
        BOOST_TEST(neg[0] == -3.0, tt::tolerance(1e-9));
        BOOST_TEST(neg[1] == 1.0, tt::tolerance(1e-9));

        auto hadamard = p * q;
        BOOST_TEST(hadamard[0] == -3.0, tt::tolerance(1e-9));
        BOOST_TEST(hadamard[1] == -4.0, tt::tolerance(1e-9));

        auto scaled = q * 0.5;
        BOOST_TEST(scaled[0] == -0.5, tt::tolerance(1e-9));
        BOOST_TEST(scaled[1] == 2.0, tt::tolerance(1e-9));

        double accumulation = 0.0;
        for (double v : q) {
            accumulation += v;
        }
        BOOST_TEST(accumulation == 3.0, tt::tolerance(1e-9));
    }

    BOOST_TEST_CONTEXT("Point3D helpers")
    {
        Point3D<float> p(1.0f, 2.0f, 3.0f);
        Point3D<float> q(3.0f, 2.0f, 1.0f);

        auto neg = -p;
        BOOST_TEST(neg[0] == -1.0f, tt::tolerance(1e-6f));
        BOOST_TEST(neg[1] == -2.0f, tt::tolerance(1e-6f));
        BOOST_TEST(neg[2] == -3.0f, tt::tolerance(1e-6f));

        auto diff = p - q;
        BOOST_TEST(diff[0] == -2.0f, tt::tolerance(1e-6f));
        BOOST_TEST(diff[1] == 0.0f, tt::tolerance(1e-6f));
        BOOST_TEST(diff[2] == 2.0f, tt::tolerance(1e-6f));

        auto scaled = p * 3.0f;
        BOOST_TEST(scaled[0] == 3.0f, tt::tolerance(1e-6f));
        BOOST_TEST(scaled[1] == 6.0f, tt::tolerance(1e-6f));
        BOOST_TEST(scaled[2] == 9.0f, tt::tolerance(1e-6f));

        auto divided = p / 2.0f;
        BOOST_TEST(divided[0] == 0.5f, tt::tolerance(1e-6f));
        BOOST_TEST(divided[1] == 1.0f, tt::tolerance(1e-6f));
        BOOST_TEST(divided[2] == 1.5f, tt::tolerance(1e-6f));

        p += q;
        BOOST_TEST(p[0] == 4.0f, tt::tolerance(1e-6f));
        BOOST_TEST(p[1] == 4.0f, tt::tolerance(1e-6f));
        BOOST_TEST(p[2] == 4.0f, tt::tolerance(1e-6f));

        p *= 0.5f;
        BOOST_TEST(p[0] == 2.0f, tt::tolerance(1e-6f));
        BOOST_TEST(p[1] == 2.0f, tt::tolerance(1e-6f));
        BOOST_TEST(p[2] == 2.0f, tt::tolerance(1e-6f));
    }
}