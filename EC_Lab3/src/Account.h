#pragma once
#include <string>

class Account
{
protected:
  virtual void displayDetailsStream(std::ostream &os) const;

public:
  std::string accountNumber;
  std::string accountHolder;
  double balance;

  Account(std::string accountNumber,
          std::string accountHolder,
          double balance);

  // Print account details
  void displayDetails() const;
  // Deposit money, return the new amount after depositing
  int deposit(double amount);
  // Withdraw ensuring sufficient balance, returning new amount after withdrawing
  virtual int withdraw(double amount);

  // + overload
  Account operator+(Account &other);

  // << overload
  friend std::ostream &operator<<(std::ostream &os, const Account &acct);
};
