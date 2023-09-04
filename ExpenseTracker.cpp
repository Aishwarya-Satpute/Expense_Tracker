#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class ExpenseTracker {
public:
    ExpenseTracker() {}

    void addExpense(double amount, const std::string& description) {
        expenses.push_back({ amount, description });
    }

    void viewExpenses() {
        if (expenses.empty()) {
            std::cout << "No expenses recorded yet." << std::endl;
            return;
        }

        std::cout << "Expense List:" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << std::setw(15) << "Amount" << std::setw(30) << "Description" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;

        for (const auto& expense : expenses) {
            std::cout << std::fixed << std::setprecision(2) << std::setw(15) << expense.amount << std::setw(30) << expense.description << std::endl;
        }

        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Total Expenses: $" << getTotalExpenses() << std::endl;
    }

    double getTotalExpenses() {
        double total = 0.0;
        for (const auto& expense : expenses) {
            total += expense.amount;
        }
        return total;
    }

private:
    struct Expense {
        double amount;
        std::string description;
    };

    std::vector<Expense> expenses;
};

int main() {
    ExpenseTracker tracker;
    int choice;

    while (true) {
        std::cout << "Expense Tracker Menu:" << std::endl;
        std::cout << "1. Add Expense" << std::endl;
        std::cout << "2. View Expenses" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            double amount;
            std::string description;
            std::cout << "Enter expense amount: $";
            std::cin >> amount;
            std::cin.ignore();
            std::cout << "Enter expense description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            tracker.addExpense(amount, description);
            std::cout << "Expense added successfully." << std::endl;
            break;
        }

        case 2:
            tracker.viewExpenses();
            break;

        case 3:
            return 0;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

