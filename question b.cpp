class SavingsAccount : public BankAccount {
    private:
        double interestRate;
    
    public:
        SavingsAccount(const std::string& name, int number, double initialBalance, double rate)
            : BankAccount(name, number, initialBalance), interestRate(rate) {}
    
        void applyInterest() {
            balance += balance * interestRate;
        }
    
        void display() const override {
            BankAccount::display();
            std::cout << "Interest Rate: " << interestRate * 100 << "%" << std::endl;
        }
    };
    
    class CurrentAccount : public BankAccount {
    private:
        double overdraftLimit;
    
    public:
        CurrentAccount(const std::string& name, int number, double initialBalance, double limit)
            : BankAccount(name, number, initialBalance), overdraftLimit(limit) {}
    
        void withdraw(double amount) override {
            if (amount <= balance + overdraftLimit) {
                balance -= amount;
            } else {
                std::cout << "Exceeded overdraft limit!" << std::endl;
            }
        }
    
        void display() const override {
            BankAccount::display();
            std::cout << "Overdraft Limit: $" << overdraftLimit << std::endl;
        }
    };