int main() {
    SavingsAccount sa("Alice", 12345, 1000.0, 0.03);
    CurrentAccount ca("Bob", 67890, 500.0, 200.0);

    sa.deposit(200);
    sa.applyInterest();
    sa.display();

    ca.withdraw(600);
    ca.display();

    return 0;
}