#ifndef _REG_
#define _REG_

#include <stdio.h>
#include <string.h>

//16-bit register
struct X16
{
    //8-bit register
    char H8;
    char L8;
};

//32-bit register
struct EX32
{
    short H16;
    struct X16 L16;
};

typedef struct X16 X16;
typedef struct EX32 EX32;

extern EX32 EAX;
extern X16 AX;
extern X16 AH;
extern X16 AL;

int saveData(unsigned int data, char * mod);

int readData(char * mod);

#endif // _REG_
