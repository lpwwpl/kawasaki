#ifndef UTILS_H
#define UTILS_H

#include <algorithm>


//-------------------------------------------------------------------------------------------------
class Utils
{
public:

    template<typename T>
    static T clamp(T min, T max, T val)
    {
        return std::min(max, std::max(min, val));
    }
};

#endif // UTILS_H
