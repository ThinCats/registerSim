#include "registers.h"

EX32 EAX = {0, {0, 0}};
X16 AX = {0 , 0};
X16 AH = {0 , 0};
X16 AL = {0 , 0};

int saveData(unsigned int data, char * mod)
{
    if(!strcmp(mod, "EAX"))
    {
        EAX.H16 = data & 0xffff0000 | EAX.H16;
        EAX.L16.H8 = data & 0x0000ff00 | EAX.L16.H8;
        EAX.L16.L8 = data & 0x000000ff | EAX.L16.L8;
        return 0;
    }

    else if(!strcmp(mod, "AX"))
    {
        AX.H8 = data & 0x0000ff00 | AX.H8;
        AX.L8 = data & 0x000000ff | AX.L8;
        return 0;
    }

    else if(!strcmp(mod, "AH"))
    {
        AH.H8 = (data & 0x000000ff) | AH.H8;
        return 0;
    }
    else if(!strcmp(mod, "AL"))
    {
        AL.L8 = data & 0x000000ff | AH.L8;
        return 0;
    }

    else return -1;
}

int readData(char * mod)
{
    if(!strcmp(mod, "EAX"))
    {

        return EAX.H16 | EAX.H16 | EAX.L16.H8 | EAX.L16.L8;
    }

    if(!strcmp(mod, "AX"))
    {
        return AX.H8 | AX.L8;
    }

    if(!strcmp(mod, "AH"))
    {
        return AH.H8;
    }
    if(!strcmp(mod, "AL"))
    {
        return AL.L8;
    }

    else
    {
        printf("Wrong Reg!\n");
        return 0;
    }
}
