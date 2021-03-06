// Copyright 2013 Daniel Parker
// Distributed under the Boost license, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// See https://github.com/danielaparker/jsoncons for latest version

#ifndef MY_ANY_SPECIALIZATIONS_HPP
#define MY_ANY_SPECIALIZATIONS_HPP

#include "jsoncons/json.hpp"
#include <vector>

namespace jsoncons {

template<>
inline void serialize(json_output_handler& os, const std::vector<double>& v)
{
    os.begin_array();
    for (size_t i = 0; i < v.size(); ++i)
    {
        os.value(v[i], 0);
    }
    os.end_array();
}

}

#endif
