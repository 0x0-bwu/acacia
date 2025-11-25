#pragma once

#include "Traits.hpp"

#include <cmath>

namespace acacia::infra::math {

template <typename T> requires std::is_integral_v<T>
inline bool EQ(T a, T b)
{
    return a == b;
}

template <typename T> requires std::is_floating_point_v<T>
inline bool EQ(T a, T b, T tolerance = std::numeric_limits<T>::epsilon())
{
    return std::fabs(a - b) <= tolerance;
}

} // namespace acacia::infra::math