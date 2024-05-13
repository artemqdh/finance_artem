#include "classes.h"

namespace expenses
{
    void FuncDate(std::string dateStr)
    {
        data::Data date(dateStr);
        date.day = date.day;
        date.month = date_.month;
        date.year = date.year;
    }

    data::Data getDate() const
    {
        return date;
    }

    int getAmount() const
    {
        return amount;
    }

    std::string getName() const
    {
        return name;
    }

    std::string getCategory() const
    {
        return category;
    }
}

void AddCardtoList(std::string card_number1, int card_balance1, std::vector<std::pair<std::string, int>>& ListofCards)
{
    ListofCards.push_back({ card_number1, card_balance1 });
}

void PrintBalance(std::vector<std::pair<std::string, int>>& ListofCards) const {
    std::cout << "Here are the Balances of each Card: " << std::endl;
    for (const auto& a : ListofCards)
    {
        std::cout << "'Card Number:' " << a.first << " Balance: " << a.second << std::endl;
    }
}
