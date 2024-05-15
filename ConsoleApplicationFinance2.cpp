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

        std::cout << "1 - Buy something" << std::endl;
        std::cout << "2 - Add money" << std::endl;

        std::cin >> num;

        switch (num)
        {
            case 1:
            {
                int num1;
                std::cout << "From what card or wallet are you buying?" << std::endl;

                std::cout << "1 - Credit Card" << std::endl;
                std::cout << "2 - Debit Card" << std::endl;
                std::cout << "3 - Wallet" << std::endl;

                std::cin >> num1;

                switch (num1)
                {
                    case 1:
                    {
                        std::cout << "What are you buying? (1) Type in the name, (2) how much it costs, (3) the category and (4) the date when you bought it:" << std::endl;
                        std::string name1;
                        int amount1 = 0;
                        std::string date1;
                        std::string category1;
                        expenses::Expenses new_expense(amount1, name1, date1, category1);

                        ListofExpenses.push_back(new_expense);

                        new_credit_card.WithdrawCard(amount1);
                        break;
                    }
                    case 2:
                    {
                        std::cout << "What are you buying? (1) Type in the name, (2) how much it costs, (3) the category and (4) the date when you bought it:" << std::endl;
                        std::string name1;
                        int amount1 = 0;
                        std::string date1;
                        std::string category1;
                        expenses::Expenses new_expense(amount1, name1, date1, category1);

                        ListofExpenses.push_back(new_expense);

                        new_debit_card.WithdrawCard(amount1);
                        break;
                    }
                    case 3:
                    {
                        std::cout << "What are you buying? (1) Type in the name, (2) how much it costs, (3) the category and (4) the date when you bought it:" << std::endl;
                        std::string name1;
                        int amount1 = 0;
                        std::string date1;
                        std::string category1;
                        expenses::Expenses new_expense(amount1, name1, date1, category1);

                        ListofExpenses.push_back(new_expense);

                        new_wallet.WithdrawCard(amount1);
                        break;
                    }
                }break;
            }
            case 2:
            {
                int num2;
                std::cout << "Where do you want to add money?" << std::endl;

                std::cout << "1 - Credit Card" << std::endl;
                std::cout << "2 - Debit Card" << std::endl;
                std::cout << "3 - Wallet" << std::endl;

                std::cin >> num2;
                
                switch (num2)
                {
                    case 1:
                    {
                        std::cout << "How much money do you want to add?" << std::endl;
                        int amount1;
                        std::cin >> amount1;
                    
                        new_credit_card.AddBalance(amount1);

                        break;
                    }
                    case 2:
                    {
                        std::cout << "How much money do you want to add?" << std::endl;
                        int amount1;
                        std::cin >> amount1;

                        new_debit_card.AddBalance(amount1);

                        break;
                    }
                    case 3:
                    {
                        std::cout << "How much money do you want to add?" << std::endl;
                        int amount1;
                        std::cin >> amount1;

                        new_wallet.AddBalance(amount1);

                        break;
                    }
                }break;
            }
        }
    }
}