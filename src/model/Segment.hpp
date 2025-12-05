#pragma once

namespace acacia::model {

template <typename Point>
class Segment
{
public:
    using Points = std::array<Point, 2>;
    Segment(const Point & p1, const Point & p2) : m_points{p1, p2} {}

    ///@brief checks if this segment equals to `seg`
    bool operator== (const Segment<Point> & seg) const;
    ///@brief checks if this segment not equals to `seg`
    bool operator!= (const Segment<Point> & seg) const;

    ///@brief accesses segment point by index 0-1
    Point & operator[](size_t i);
    const Point & operator[](size_t i) const;

private:
    Points m_points;
};

template <typename Point>
inline bool Segment<Point>::operator== (const Segment<Point> & seg) const
{
    return m_points[0] == seg.m_points[0] && m_points[1] == seg.m_points[1];
}

template <typename Point>
inline bool Segment<Point>::operator!= (const Segment<Point> & seg) const
{
    return !(*this == seg);
}

template <typename Point>
inline Point & Segment<Point>::operator[](size_t i)
{
    return m_points[i];
}

template <typename Point>
inline const Point & Segment<Point>::operator[](size_t i) const
{
    return m_points[i];
}

} // namespace acacia::model