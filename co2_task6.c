#include <stdio.h>
int main()
{
    double balance = 10000.0;
    double rate = 0.02;
    double repayment = 2000.0;
    double interest, payment;
    double totalInterest = 0.0;
    int month = 0;
    printf("Month\tInterest\tPayment\t\tBalance\n");
    while(balance > 0.01)
    {
        interest = balance * rate;
        if(repayment <= interest)
        {
            printf("\nLoan cannot be repaid because the repayment is too small.\n");
            break;
        }
        balance = balance + interest;
        totalInterest += interest;
        if(balance < repayment)
            payment = balance;
        else
            payment = repayment;
        balance = balance - payment;
        month++;
        printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\n",
               month, interest, payment, balance);
        if(month >= 360)
        {
            printf("\nSafety limit reached. Loan not repaid.\n");
            break;
        }
    }
    if(balance <= 0.01)
    {
        printf("\nLoan Fully Repaid\n");
        printf("Months Required = %d\n", month);
        printf("Total Interest Paid = %.2lf\n", totalInterest);
    }
    return 0;
}
