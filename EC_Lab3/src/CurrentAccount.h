#include "Account.h"

class CurrentAccount : public Account
{
protected:
  void displayDetailsStream(std::ostream &os) const override;

public:
  double overdraftLimit;

  CurrentAccount(std::string accountNumber,
                 std::string accountHolder,
                 double balance, double overdraftLimit);

  // Withdraw ensuring sufficient balance, allowing an overdraft, returning new amount after withdrawing
  int withdraw(double amount) override;

  // + overload
  CurrentAccount operator+(Account &other);
};
