#include </usr/App/strFn.h>


/*number of employees in a departement*/
#define SIZE_DEP 15
/*Number of products in a single batch*/
#define SIZE_BATCH 20
/*Number of chars in: name*/
#define SIZE_NAME 20
/*Number of chars in: reference*/
#define SIZE_REF 10

typedef enum Bool{
    False,
    True
}Bool;

/*Employees assembled in an array in each departement*/
typedef struct Employee
{
    __uint16_t Employee_Num;
    char Name[SIZE_NAME];
    float Salary;
    __uint8_t Available_Leave_Days;
}Emp;

/*Departements organized in a linked list*/
typedef struct Departement
{
    __uint8_t Departement_Num;
    char Departement_Name[SIZE_NAME];
    Emp Emp_List[SIZE_DEP];
    struct Departement *Link;
}Dep;
/*Products assembled in an array in each Batch*/
typedef struct Product
{
    char Product_Name[SIZE_NAME];
    char Delivery_Date[10];
    /*Required only if product is expirable*/
    char Expiry_Date[10];
    float Price;
}Prod;

typedef struct Batch
{
    __uint8_t number;
    Prod Product_List[SIZE_BATCH];
    char Reference[SIZE_REF];
    struct Batch *Link;
}Batch;


