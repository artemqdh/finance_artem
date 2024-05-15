#include "finance.h"

#include <iostream>

namespace card
{
    Card::Card(std::string card_name1, int card_balance1, std::vector<std::pair<std::string, int>> ListofCards)
        : card_name(card_name1), card_balance(card_balance1)
    {
        AddCardtoList(card_name1, card_balance1, ListofCards);
    }

    void card::Card::AddCardtoList(std::string card_number1, int card_balance1, std::vector<std::pair<std::string, int>>& ListofCards) 
    {
        ListofCards.push_back({ card_number1, card_balance1 });
    }

    void Card::PrintBalance(std::vector<std::pair<std::string, int>>& ListofCards) const
    {
        std::cout << "Here are the Balances of each Card: " << std::endl;
        for (const auto& a : ListofCards)
        {
            std::cout << "'Card Number:' " << a.first << " Balance: " << a.second << std::endl;
        }
    }

    void Card::WithdrawCard(int amount1)
    {
        card_balance -= amount1;
    }

    void Card::AddBalance(int balance1)
    {
        card_balance += balance1;
    }
    
    Wallet::Wallet(std::string card_name1, int card_balance1, std::vector<std::pair<std::string, int>> ListofCards)
            : Card(card_name1, card_balance1, ListofCards), name(card_name1), balance(card_balance1)
        {
        }

    void Wallet::AddBalance(int balance1)
    {
        balance += balance1;
    }

    int Wallet::PrintBalance()
    {
        return balance;
    }


    DebitCard::DebitCard(std::string card_name1, int card_balance1, int card_number1, std::vector<std::pair<std::string, int>> ListofCards)
            : Card(card_name1, card_balance1, ListofCards), card_number(card_number1)
        {
        }

    CreditCard::CreditCard(std::string card_name1, int card_balance1, std::string expiration_date1, std::vector<std::pair<std::string, int>> ListofCards)
            : Card(card_name1, card_balance1, ListofCards), expiration_date(expiration_date1)
        {
        }
}
