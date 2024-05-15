#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace card
{
    class Card
    {
    public:
        Card(std::string card_name1, int card_balance1, std::vector<std::pair<std::string, int>> ListofCards);

        void AddCardtoList(std::string card_number1, int card_balance1, std::vector<std::pair<std::string, int>>& ListofCards);
        void PrintBalance(std::vector<std::pair<std::string, int>>& ListofCards) const;
        void WithdrawCard(int amount1);
        void AddBalance(int balance1);

    protected:
        std::string card_name;
        int card_balance;
    };

    class Wallet : public Card
    {
    public:
        Wallet(std::string card_name1, int card_balance1, std::vector<std::pair<std::string, int>> ListofCards);
        void AddBalance(int balance1);
        int PrintBalance();

    private:
        std::string name;
        int balance;
    };

    class DebitCard : public Card
    {
    public:
        DebitCard(std::string card_name1, int card_balance1, int card_number1, std::vector<std::pair<std::string, int>> ListofCards);

    private:
        int card_number;
    };

    class CreditCard : public Card
    {
    public:
        CreditCard(std::string card_name1, int card_balance1, std::string expiration_date1, std::vector<std::pair<std::string, int>> ListofCards);

    private:
        std::string expiration_date;
        int balance;
        int maximum_credit;
    };
}
