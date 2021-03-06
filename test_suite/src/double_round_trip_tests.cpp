// Copyright 2013 Daniel Parker
// Distributed under Boost license

#ifdef __linux__
#define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <sstream>
#include <vector>
#include <utility>
#include <ctime>
#include "jsoncons/json.hpp"
#include "jsoncons/json_serializer.hpp"

using namespace jsoncons;

BOOST_AUTO_TEST_SUITE(double_round_trip_test_suite)

BOOST_AUTO_TEST_CASE(test_precision)
{
    json val = json::parse("42.229999999999997");
    BOOST_CHECK_EQUAL(17,val.length_or_precision());

    val = json::parse("0.42229999999999997");
    BOOST_CHECK_EQUAL(18,val.length_or_precision());

    val = json::parse("1.2345e+30");
    BOOST_CHECK_EQUAL(5,val.length_or_precision());

    val = json::parse("0.12345e+30");
    BOOST_CHECK_EQUAL(6,val.length_or_precision());

    val = json::parse("1.2345E+30");
    BOOST_CHECK_EQUAL(5,val.length_or_precision());

    val = json::parse("0.12345E+30");
    BOOST_CHECK_EQUAL(6,val.length_or_precision());

    val = json::parse("1.2345e-30");
    BOOST_CHECK_EQUAL(5,val.length_or_precision());

    val = json::parse("0.12345e-30");
    BOOST_CHECK_EQUAL(6,val.length_or_precision());

    val = json::parse("1.2345E-30");
    BOOST_CHECK_EQUAL(5,val.length_or_precision());

    val = json::parse("0.12345E-30");
    BOOST_CHECK_EQUAL(6,val.length_or_precision());

    val = json::parse("1.2345e30");
    BOOST_CHECK_EQUAL(5,val.length_or_precision());

    val = json::parse("0.12345e30");
    BOOST_CHECK_EQUAL(6,val.length_or_precision());

    val = json::parse("1.2345E30");
    BOOST_CHECK_EQUAL(5,val.length_or_precision());

    val = json::parse("0.12345E30");
    BOOST_CHECK_EQUAL(6,val.length_or_precision());
}

BOOST_AUTO_TEST_CASE(test_round_trip)
{
    std::string input = "42.229999999999997";
    BOOST_CHECK_EQUAL(input,json::parse(input).as<std::string>());

    input = "9.0099999999999998";
    BOOST_CHECK_EQUAL(input,json::parse(input).as<std::string>());

    input = "13.449999999999999";
    BOOST_CHECK_EQUAL(input,json::parse(input).as<std::string>());
}

BOOST_AUTO_TEST_SUITE_END()

