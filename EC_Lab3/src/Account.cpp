#include "Account.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

Account::Account(std::string accountNumber, std::string accountHolder, double balance)
    : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance)
{
}

void Account::displayDetailsStream(std::ostream &os) const
{
  os << "Account Details for Account (ID: " << this->accountNumber << "):" << std::endl;
  os << "\tHolder: " << this->accountHolder << std::endl;
  os << "\tBalance: $" << std::fixed << std::setprecision(2) << std::showpoint << this->balance << std::endl;
}

void Account::displayDetails() const
{
  this->displayDetailsStream(std::cout);
}

int Account::deposit(double amount)
{
  if (amount > 0)
  {
    balance += amount;
    return balance;
  }
  else
  {
    throw std::invalid_argument("Invalid deposit amount.");
  }
}

int Account::withdraw(double amount)
{
  if (amount > 0 && amount <= balance)
  {
    balance -= amount;
    return balance;
  }
  else
  {
    throw std::invalid_argument("Invalid withdrawal amount or insufficient balance.");
  }
}

Account Account::operator+(Account &other)
{
  // The + operator will always attempt to withdraw 300 from the 2nd operator, and move it to the first.
  other.withdraw(300);
  // Create a new account
  return Account(this->accountNumber, this->accountHolder, this->balance + 300);
}

std::ostream &operator<<(std::ostream &os, const Account &acct)
{
  acct.displayDetailsStream(os);
  return os;
}
