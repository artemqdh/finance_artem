#include <iostream>
#include <vector>

#include "expenses.h"
#include "finance.h"
#include "data.h"

int main()
{
    std::vector <expenses::Expenses> ListofExpenses;

    std::vector<std::pair<std::string, int>> ListofCards;

    card::Wallet new_wallet("artemwallet", 5000, ListofCards);
    card::DebitCard new_debit_card("debitcard1", 10000, 1252777, ListofCards);
    card::CreditCard new_credit_card("creditcard1", 20000, "20.04.2027", ListofCards);

    expenses::Expenses a1(2000, "foodcost", "08.05.2024", "Food");
    expenses::Expenses a2(5000, "bills", "07.05.2024", "House");
    expenses::Expenses a3(2500, "dogfood", "08.05.2024", "Food");
    expenses::Expenses a4(7500, "tax", "13.06.2024", "Work");
    expenses::Expenses a5(6000, "scholarship", "13.06.2024", "School");
    expenses::Expenses a6(5500, "newfence", "13.06.2024", "House");

    ListofExpenses.push_back(a1);
    ListofExpenses.push_back(a2);
    ListofExpenses.push_back(a3);
    ListofExpenses.push_back(a4);
    ListofExpenses.push_back(a5);
    ListofExpenses.push_back(a6);

    printTop3Expenses(ListofExpenses);

    printTop3ExpensesByCategory(ListofExpenses);

    PrintAll(ListofExpenses);

    while (1 == 1) 
    {
        int num;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "----------WELCOME TO FINANCE-----------" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "What do you want to do?" << std::endl;

        std::cout << "1 - Add a new Card" << std::endl;
        std::cout << "2 - Buy something" << std::endl;
        std::cout << "3 - Add money" << std::endl;

        std::cin >> num;

        switch (num)
        {
            case 1: 
            {
                int num1;
                std::cout << "What do you want to do?" << std::endl;

                std::cout << "1 - Add Credit Card" << std::endl;
                std::cout << "2 - Add Debit Card" << std::endl;

                std::cin >> num1;

                switch (num1)
                {
                    case 1:
                    {
                        std::string name1;
                        int balance1 = 0;
                        int creditcard_number1;
                        std::cout << "Type in your name, balance and creditcard number:" << std::endl;
                        std::cin >> name1 >> balance1 >> creditcard_number1;
                        card::CreditCard creditcard_new(name1, balance1, creditcard_number1, ListofCards);
                        break;
                    }
                    case 2:
                    {
                        std::string name1;
                        int balance1 = 0;
                        std::string expirydate;
                        std::cout << "Type in your name, balance and finish data of the card:" << std::endl;
                        std::cin >> name1 >> balance1 >> expirydate;
                        card::DebitCard debitcard_new(name1, balance1, expirydate, ListofCards);
                        break;
                    }
                }
            }
            case 2:
            {
                int num;
                std::cout << "From what card or wallet are you buying?" << std::endl;

                std::cout << 
            }
        }
    }
}