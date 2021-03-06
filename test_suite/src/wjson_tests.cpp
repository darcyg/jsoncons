// Copyright 2013 Daniel Parker
// Distributed under Boost license

#include <boost/test/unit_test.hpp>
#include "jsoncons/json.hpp"
#include "jsoncons/json_serializer.hpp"
#include "jsoncons/json_filter.hpp"
#include <sstream>
#include <vector>
#include <utility>
#include <ctime>

using namespace jsoncons;

BOOST_AUTO_TEST_SUITE(wjson_test_suite)

BOOST_AUTO_TEST_CASE(test_wjson )
{
    wjson root;
    root[L"field1"] = L"test";
    root[L"field2"] = 3.9;
    root[L"field3"] = true;

    std::wcout << "Wide character test" << std::endl;
    std::wcout << root << std::endl;

    std::wstring s1 = root[L"field1"].as<std::wstring>();
    BOOST_CHECK_EQUAL( s1.c_str(),  L"test");

}

BOOST_AUTO_TEST_CASE(test_wjson_escape_u)
{
    std::wstring input = L"[\"\\uABCD\"]";
    std::wistringstream is(input);

    wjson root = wjson::parse_stream(is);

    std::wstring s = root[0].as<std::wstring>();
    BOOST_CHECK_EQUAL( s.length(), 1 );
    BOOST_CHECK_EQUAL( s[0], 0xABCD );
}

BOOST_AUTO_TEST_SUITE_END()

