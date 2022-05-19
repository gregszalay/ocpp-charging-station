
#pragma once

#include <Arduino.h>
#include <map>

template <typename T>
struct map_init_helper
{
    T &data;
    map_init_helper(T &d) : data(d) {}
    map_init_helper &operator()(typename T::key_type const &key, typename T::mapped_type const &value)
    {
        data[key] = value;
        return *this;
    }
};

template <typename T>
map_init_helper<T> map_init(T &item)
{
    return map_init_helper<T>(item);
};