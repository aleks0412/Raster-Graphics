#pragma once

namespace utils
{
    template <typename T>
    int max(T a, T b)
    {
        return a < b ? b : a;
    }
}