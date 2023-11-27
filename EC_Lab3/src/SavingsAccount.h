#include "Account.h"

class SavingsAccount : public Account
{
private:
  void assertValid();

protected:
  void displayDetailsStream(std::ostream &os) const override;

public:
  double minimumBalance;
  double interestRate;

  SavingsAccount(std::string accountNumber,
                 std::string accountHolder,
                 double balance, double interestRate);
  SavingsAccount(std::string accountNumber,
                 std::string accountHolder,
                 double balance, double interestRate, double minimumBalance);

  // Withdraw ensuring sufficient balance, enforcing a minimum (other than zero), returning new amount after withdrawing
  int withdraw(double amount) override;

  // + overload
  SavingsAccount operator+(Account &other);
};
