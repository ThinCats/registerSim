#include <stdio.h>
#include <stdlib.h>
#include "registers.h"

int main()
{
    printf("You can choose to save in or read data from those registers:\nEAX, AX, AH, AL\n");

    int n = 0;
    char po[10];
    unsigned int num;

    while(n != 2)
    {
        printf("\nNow you can choose to save or read\n(0-save, 1-read, 2-quit):");
        scanf("%d", &n);

        switch(n)
        {
        case 0:

            printf("\nNow please input your data and chosen register:\n(The format is like this:\n32 EAX\n");
            scanf("%u %s", &num, po);

            if(saveData(num, po) == -1)
                printf("\nPlease input the correct format\n");

            else
                printf("\nNow it is saved in %s, with data %u\n", po, num);
                break;


        case 1:

            printf("\nWhich register you want to read(EAX, AX, AH, AL)\n");
            scanf("%s", po);

            printf("\nThe data in %s is %x\n", po, readData(po));
            break;

        case 2:
            printf("Quiting\n");
            break;

        }

    }

    return 0;
}
