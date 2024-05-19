#pragma once
#include <stdexcept>

namespace data
{
    struct Data
    {
        Data() = default;
        Data(std::string datacopy)
        {
            std::string DD = datacopy.substr(0, 2);
            std::string MM = datacopy.substr(3, 2);
            std::string YY = datacopy.substr(6, 4);
            this->day = atoi(DD.c_str());
            this->month = atoi(MM.c_str());
            this->year = atoi(YY.c_str());
            //Place for your decision
            //...
            if (day > 31 || month > 12 || year < 2024)
            {
                throw std::domain_error("Error. Date is not normal.");
            }
        }

        Data operator = (const Data& rhs)
        {
            day = rhs.day;
            month = rhs.month;
            year = rhs.year;

            return *this;
        }

        int day;
        int month;
        int year;
    };
}