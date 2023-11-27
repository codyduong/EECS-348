#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

void SavingsAccount::assertValid()
{
  if (this->balance < this->minimumBalance)
  {
    throw std::invalid_argument("Invalid balance, did not meet minimum balance.");;
  }
  if (this->interestRate > 1 || this->interestRate < 0)
  {
    throw std::invalid_argument("Invalid interest rate, expected between 0 and 1.");;
  }
}

SavingsAccount::SavingsAccount(std::string accountNumber, std::string accountHolder, double balance, double interestRate)
    : Account(accountNumber, accountHolder, balance), interestRate(interestRate), minimumBalance(500)
{
  this->assertValid();
}

SavingsAccount::SavingsAccount(std::string accountNumber, std::string accountHolder, double balance, double interestRate, double minimumBalance)
    : Account(accountNumber, accountHolder, balance), interestRate(interestRate), minimumBalance(minimumBalance)
{
  this->assertValid();
}

void SavingsAccount::displayDetailsStream(std::ostream &os) const
{
  Account::displayDetailsStream(os);
  os << "\tInterest Rate: " << std::fixed << std::setprecision(2) << std::showpoint << this->interestRate * 100 << "%" << std::endl;
}

int SavingsAccount::withdraw(double amount)
{
  if ((amount > 0) && (amount <= balance) && ((balance - amount) >= minimumBalance))
  {
    balance -= amount;
    return balance;
  }
  else
  {
    throw std::invalid_argument("Invalid withdrawal amount or insufficient balance.");
  }
}

SavingsAccount SavingsAccount::operator+(Account &other)
{
  // The + operator will always attempt to withdraw 300 from the 2nd operator, and move it to the first.
  other.withdraw(300);
  // Create a new account
  return SavingsAccount(this->accountNumber, this->accountHolder, this->balance + 300, this->interestRate, this->minimumBalance);
}
