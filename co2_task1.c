#include <stdio.h>
int main()
{
    float price, gross, discount, gst, total, net;
    int qty, senior;
    printf("Enter price: ");
    scanf("%f", &price);
    printf("Enter quantity: ");
    scanf("%d", &qty);
    printf("Senior citizen? (1=Yes, 0=No): ");
    scanf("%d", &senior);
    gross = price * qty;
    discount = senior ? gross * 0.15f : 0.0f;
    gst = gross * 0.05f;
    total = gross - discount + gst;
    net = (total > 1000) ? total - 50 : total;
    printf("\nGross Amount = %.2f", gross);
    printf("\nDiscount = %.2f", discount);
    printf("\nGST = %.2f", gst);
    printf("\nTotal = %.2f", total);
    printf("\nNet Amount = %.2f", net);
    return 0;
}
