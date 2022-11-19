/*
============================================
written by Youssef Azaiez
Includes 3 header files and a C files in same dir
============================================
*/
#include </home/youssef/Documents/C_Files/Projects/Project2/functions.h>


#if !defined(SIZE_BUFF)
#define SIZE_BUFF 256

typedef unsigned char __uint8_t;
typedef enum Bool{
    False,
    True
}Bool;

#endif // SIZE_BUFF


int main(int argc, char const *argv[])
{
    Bool Test = True;
    Dep *Head_Dep = NULL;
    Batch *Head_Batch = NULL;
    while (Test == True)
    {
        Test = Choice(Menu(), &Head_Dep, &Head_Batch);
    }
    system("clear");
    printf("--------------------------------------------\n");
    printf("------------Terminating cession!------------\n");
    printf("--------------------------------------------\n");
    system("sleep 1");
    return 0;
}

//     make all available slots in arrays == 0