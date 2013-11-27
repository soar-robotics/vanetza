#ifndef WGS84POINT_H_GAHDJKCG
#define WGS84POINT_H_GAHDJKCG

#include <vanetza/units/angle.h>

namespace vanetza
{

struct Wgs84Point
{
    typedef AngleDegree angle_type;
    Wgs84Point(angle_type latitude, angle_type longitude) : lat(latitude), lon(longitude) {}
    angle_type lat;
    angle_type lon;
};

} // namespace vanetza 

#endif /* WGS84POINT_H_GAHDJKCG */

