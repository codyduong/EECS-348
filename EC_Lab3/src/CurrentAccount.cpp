#include "CurrentAccount.h"
#include <iostream>
#include <iomanip>

CurrentAccount::CurrentAccount(std::string accountNumber, std::string accountHolder, double balance, double overdraftLimit)
    : Account(accountNumber, accountHolder, balance), overdraftLimit(overdraftLimit)
{
}

void CurrentAccount::displayDetailsStream(std::ostream &os) const
{
  Account::displayDetailsStream(os);
  os << "\tOverdraft Limit: $" << std::fixed << std::setprecision(2) << std::showpoint << this->overdraftLimit << std::endl;
}

int CurrentAccount::withdraw(double amount)
{
  if ((amount > 0) && (amount <= (balance + overdraftLimit)))
  {
    balance -= amount;
    return balance;
  }
  else
  {
    throw std::invalid_argument("Invalid withdrawal amount or insufficient balance.");
  }
}

CurrentAccount CurrentAccount::operator+(Account &other)
{
  // The + operator will always attempt to withdraw 300 from the 2nd operator, and move it to the first.
  other.withdraw(300);
  // Create a new account
  return CurrentAccount(this->accountNumber, this->accountHolder, this->balance + 300, this->overdraftLimit);
}
