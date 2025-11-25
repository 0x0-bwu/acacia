#pragma once
#include "Macros.hpp"

#include <type_traits>
#include <concepts>
#include <utility>
#include <cstddef>

namespace acacia::infra::traits {

namespace detail {

template <typename T>
struct same_bits_float;

template <std::floating_point T>
struct same_bits_float<T>
{
	using type = std::remove_cv_t<T>;
};

template <std::integral T>
struct same_bits_float<T>
{
	using base_t = std::remove_cv_t<T>;
	static constexpr size_t width = sizeof(base_t);

	using type = std::conditional_t<
		(width == sizeof(float)),
		float,
		std::conditional_t<
			(width == sizeof(double)),
			double,
			std::conditional_t<
				(width == sizeof(long double)),
				long double,
				void>>>;

	static_assert(!std::is_same_v<type, void>,
				  "float_type: no floating point type with matching bit-width");
};

} // namespace detail

template <typename T>
using float_t = typename detail::same_bits_float<std::remove_cv_t<T>>::type;

} // namespace acacia::infra::traits

namespace acacia {

using infra::traits::float_t;

} // namespace acacia