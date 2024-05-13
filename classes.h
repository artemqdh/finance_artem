#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

#include "struct.h"

namespace expenses
{
    class Expenses
    {
    public:
        Expenses(int amount1, std::string name1, std::string date1, std::string category1)
            : amount(amount1), name(name1), category(category1)
        {
            FuncDate(date1);
        }

        void FuncDate(std::string dateStr);

        data::Data getDate() const;

        int getAmount() const;

        std::string getName() const;

        std::string getCategory() const;

    private:
        int amount;
        std::string name;
        std::string category;
        data::Data date;
    };
}

namespace card
{
    class Card
    {
    public:
        Card(std::string card_name1, int card_balance1, std::vector<std::pair<std::string, int>>& ListofCards)
            : card_name(card_name1), card_balance(card_balance1)
        {
            AddCardtoList(card_name1, card_balance1, ListofCards);
        }

        void AddCardtoList(std::string card_number1, int card_balance1, std::vector<std::pair<std::string, int>>& ListofCards);

        void PrintBalance(std::vector<std::pair<std::string, int>>& ListofCards) const;

        virtual void WithdrawCard(int amount1)
        {
            card_balance -= amount1;
        }

    protected:
        std::string card_name;
        int card_balance;
    };
}

namespace wallet
{
    class Wallet : public card::Card
    {
    public:
        Wallet(std::string card_name1, int card_balance1, std::vector<std::pair<std::string, int>>& ListofCards)
            : Card(card_name1, card_balance1, ListofCards), name(card_name1), balance(card_balance1)
        {
        }

    private:
        std::string name;
        int balance;
    };
}

namespace debitcard
{
    class DebitCard : public card::Card
    {
    public:
        DebitCard(std::string card_name1, int card_balance1, int card_number1, std::vector<std::pair<std::string, int>>& ListofCards)
            : Card(card_name1, card_balance1, ListofCards), card_number(card_number1)
        {
        }

    private:
        int card_number;
    };
}

namespace creditcard
{
    class CreditCard : public card::Card
    {
    public:
        CreditCard(std::string card_name1, int card_balance1, std::string expiration_date1, std::vector<std::pair<std::string, int>>& ListofCards)
            : Card(card_name1, card_balance1, ListofCards), expiration_date(expiration_date1)
        {
        }

    private:
        std::string expiration_date;
        int balance;
        int maximum_credit;
    };
}
