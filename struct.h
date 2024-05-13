#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

#include "print.h"
#include "classes.h"

namespace data
{
    struct Data
    {
        Data() = default;
        Data(std::string a)
        {
            int day = atoi(a.substr(0, 2).c_str());
            int month = atoi((a.substr(3, 2)).c_str());
            int year = atoi((a.substr(6, 4)).c_str());
        }
        int day;
        int month;
        int year;
    };
}