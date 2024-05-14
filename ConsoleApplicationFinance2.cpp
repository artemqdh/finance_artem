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

    /*while (1 == 1) {
        int num;
        cout << "---------------------------------------" << endl;
        cout << "----------WELCOME TO FINANCE-----------" << endl;
        cout << "---------------------------------------" << endl;
        cout << "What do you want to do?" << endl;
        cout << "Add new Credit Card - 1" << endl;
        cout << "Print Balance of Wallet - 2" << endl;
        cout << "Print All Cards with their Balance - 3" << endl;
        cout << "Add Balance to Wallet - 4" << endl;
        cout << "Withdraw from Wallet - 5" << endl;

        cin >> num;

        switch (num) {
        case 1: {
            string a;
            int b;
            cout << "Type in the card name and balance:" << endl;
            cin >> a >> b;
            new_credit_card.AddCardtoList(a, b);
            break;
        }
        case 2: {
            new_wallet.PrintBalance();
            break;
        }
        case 3: {
            cout << "Here are the Balances of each Card: " << endl;
            for (const auto& a : ListofCards) {
                cout << "'Card Number:' " << a.first << " Balance: " << a.second << endl;
            }
            break;
        }
        case 4: {
            cout << "How much money do you want to add?" << endl;
            int a = 0;
            cin >> a;

            new_wallet.AddBalance(a);
            break;
        }
        case 5: {
            new_wallet.WithdrawBalance();
            break;
        }
        }
    }*/
}
