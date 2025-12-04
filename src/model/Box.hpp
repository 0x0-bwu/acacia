#pragma once

namespace acacia::model {   

template <typename Point>
class Box
{
public:
    using Corners = std::array<Point, 2>;
    Box(const Point & ll, const Point & ur) : m_corners{ll, ur} {}
};

} // namespace acacia::model