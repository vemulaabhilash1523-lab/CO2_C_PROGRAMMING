#include <stdio.h>
int callCount = 0;
int verifyCard()
{
    callCount++;
    printf("verifyCard() called\n");
    return 1;
}
int main()
{
    int isSenior, eligibleClass, hasDisabilityCard;
    printf("Enter Senior Citizen Status (1/0): ");
    scanf("%d", &isSenior);
    printf("Enter Eligible Class Status (1/0): ");
    scanf("%d", &eligibleClass);
    printf("Enter Disability Card Status (1/0): ");
    scanf("%d", &hasDisabilityCard);
    callCount = 0;
    if ((isSenior && eligibleClass) || verifyCard())
    {
        printf("Concession Granted\n");
    }
    else
    {
        printf("Concession Not Granted\n");
    }
    printf("Calls using && and || = %d\n", callCount);
    callCount = 0;
    if ((isSenior & eligibleClass) | verifyCard())
    {
        printf("Concession Granted\n");
    }
    else
    {
        printf("Concession Not Granted\n");
    }
    printf("Calls using & and | = %d\n", callCount);
    return 0;
}
