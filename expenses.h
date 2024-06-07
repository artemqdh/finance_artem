#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "data.h"

namespace expenses
{
    class Expenses
    {
    public:
        Expenses(int amount1, std::string name1, std::string date1, std::string category1);

        data::Data getDate() const;
        int getAmount() const;
        std::string getName() const;
        std::string getCategory() const;

    private:
        int amount;
        std::string name;
        data::Data date;
        std::string category;

        void FuncDate(std::string dateStr);
    };

    std::vector<Expenses*> Report_Expenses_Week(std::vector<Expenses>& ListofExpenses);
    void printTop3ExpensesByCategory(const std::vector<Expenses>& ListofExpenses);
    void printTop3Expenses(std::vector<Expenses>& ListofExpenses);
    void PrintAll(std::vector<Expenses>& ListofExpenses);
    void PrintWeek(std::vector<Expenses>& ListofExpenses);
}