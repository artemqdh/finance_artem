#include "print.h"

void printTop3Expenses(std::vector <expenses::Expenses>& ListofExpenses)
{
    std::sort(ListofExpenses.begin(), ListofExpenses.end(), [](const expenses::Expenses& exp1, const expenses::Expenses& exp2)
        {
            return exp1.getAmount() > exp2.getAmount();
        });

    std::cout << "Top 3 Expenses:" << std::endl;
    for (int i = 0; i < std::min(3, (int)ListofExpenses.size()); ++i)
    {
        std::cout << "Name: " << ListofExpenses[i].getName() << " Amount: " << ListofExpenses[i].getAmount() << std::endl;
    }
}

void printTop3ExpensesByCategory(std::vector <expenses::Expenses>& ListofExpenses)
{
    std::vector<std::pair<std::string, int>> categoryExpenses;

    for (const auto& exp : ListofExpenses)
    {
        std::string category = exp.getCategory();
        int amount = exp.getAmount();

        auto i = find_if(categoryExpenses.begin(), categoryExpenses.end(), [&category](const std::pair<std::string, int>& p)
            {
                return p.first == category;
            });

        if (i != categoryExpenses.end())
        {
            i->second += amount;
        }
        else
        {
            categoryExpenses.push_back({ category, amount });
        }
    }

    sort(categoryExpenses.begin(), categoryExpenses.end(), [](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2)
        {
            return p1.second > p2.second;
        });

    std::cout << "Top 3 Expenses by Category:" << std::endl;
    for (int i = 0; i < std::min(3, (int)categoryExpenses.size()); ++i)
    {
        std::cout << "Category: " << categoryExpenses[i].first << " Total Amount: " << categoryExpenses[i].second << std::endl;
    }
}

void PrintAll(std::vector <expenses::Expenses>& ListofExpenses)
{
    std::cout << "Type in the date of today: " << std::endl;
    std::string datacopy;
    std::cin >> datacopy;

    data::Data date_ex(datacopy);

    date_ex = { D, M, Y };

    tm current_date = {};

    current_date.tm_year = Y - 1900;
    current_date.tm_mon = M - 1;
    current_date.tm_mday = D;

    int num = 0;
    std::cout << "Type in 1 to print all of the Day." << std::endl;
    std::cout << "Type in 2 to print all of this Week." << std::endl;
    std::cout << "Type in 3 to print all of this Month." << std::endl;
    std::cin >> num;

    switch (num)
    {
    case 1:
    {
        for (int i = 0; i < ListofExpenses.size(); ++i)
        {
            if (date_ex.day == ListofExpenses[i].getDate().day && date_ex.month == ListofExpenses[i].getDate().month && date_ex.year == ListofExpenses[i].getDate().year)
            {
                std::cout << "Name: " << ListofExpenses[i].getName() << " Amount: " << ListofExpenses[i].getAmount() << std::endl;
            }
        }
        break;
    }
    case 2:
    {
        std::cout << "Categories for " << std::endl;
        for (int i = 0; i < 7; ++i)
        {
            std::time_t next_day = std::mktime(&current_date) + i * 24 * 60 * 60;
            std::tm* next_date = std::localtime(&next_day);

            // Здесь можно добавить логику для вывода категорий для каждой даты
            std::cout << next_date->tm_mday << "." << next_date->tm_mon + 1 << "." << next_date->tm_year + 1900 << std::endl;

            date_ex.day = next_date->tm_mday;
            date_ex.month = next_date->tm_mon + 1;
            date_ex.year = next_date->tm_year + 1900;

            for (int a = 0; a < ListofExpenses.size(); ++a)
            {
                if (date_ex.day == ListofExpenses[a].getDate().day && date_ex.month == ListofExpenses[a].getDate().month && date_ex.year == ListofExpenses[a].getDate().year)
                {
                    std::cout << "Name: " << ListofExpenses[a].getName() << " Amount: " << ListofExpenses[a].getAmount() << std::endl;
                }
            }
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < ListofExpenses.size(); ++i)
        {
            if (date_ex.month == ListofExpenses[i].getDate().month && date_ex.year == ListofExpenses[i].getDate().year)
            {
                std::cout << "Name: " << ListofExpenses[i].getName() << " Amount: " << ListofExpenses[i].getAmount() << std::endl;
            }
        }
        break;
    }
    }
}
