#include <stdio.h>
enum
{
    LIGHT = 0,
    FAN = 1,
    AC = 2,
    HEATER = 3,
    PUMP = 4
};
unsigned char switch_on(unsigned char reg, int dev)
{
    return reg | (1U << dev);
}
unsigned char switch_off(unsigned char reg, int dev)
{
    return reg & ~(1U << dev);
}
unsigned char toggle(unsigned char reg, int dev)
{
    return reg ^ (1U << dev);
}
int is_on(unsigned char reg, int dev)
{
    return (reg & (1U << dev)) ? 1 : 0;
}
void show(unsigned char reg)
{
    for(int bit = 7; bit >= 0; bit--)
    {
        putchar(((reg >> bit) & 1U) ? '1' : '0');
    }
    printf("\n");
}
int count_on(unsigned char reg)
{
    int count = 0;
    for(int i = 0; i < 8; i++)
    {
        if(reg & (1U << i))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    unsigned char reg = 0;
    reg = switch_on(reg, LIGHT);
    reg = switch_on(reg, AC);
    show(reg);
    reg = switch_off(reg, LIGHT);
    reg = toggle(reg, FAN);
    show(reg);
    printf("AC is %s\n",
           is_on(reg, AC) ? "ON" : "OFF");
    printf("PUMP is %s\n",
           is_on(reg, PUMP) ? "ON" : "OFF");
    printf("Devices ON = %d\n",
           count_on(reg));
    return 0;
}
