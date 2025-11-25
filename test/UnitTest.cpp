#include "TestModel.hpp"

using namespace boost::unit_test;

extern test_suite * create_model_test_suite();

void t_additional()
{
    //add additional test here
    BOOST_CHECK(true);
}

test_suite *
init_unit_test_suite(int argc, char* argv[])
{
    framework::master_test_suite().add(create_model_test_suite());
    framework::master_test_suite().add(BOOST_TEST_CASE(&t_additional));
    return 0;
}