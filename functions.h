#include </home/youssef/Documents/C_Files/Projects/Project2/structs.h>

//-------------------------------------------------------------
/*Employee Menu*/
__uint8_t m1(void)
{
    __uint8_t choice;
    printf("\nType 0 to exit\n");
    printf("Type 1 to add a departement\n");
    printf("Type 2 to add an employee to a departement\n");
    printf("Type 3 to remove a departement\n");
    printf("Type 4 to remove an employee\n");
    printf("Type 5 to access data details\n");
    printf("Type 6 to access Salary section\n__::");
    fgetc(stdin);
    scanf("%c", &choice);
    return choice;
}
/*Product Menu*/
__uint8_t m2(void)
{
    __uint8_t choice;
    printf("\nType 0 to exit\n");
    printf("Type 7 to add a product\n");
    printf("Type 8 to remove a product\n");
    printf("Type 9 to create a batch\n");
    printf("Type 10 to print batch content\n");
    printf("Type 11 to enter bill creation section\n__::");//add sell section and make sell bill
    fgetc(stdin);
    scanf("%c", &choice);
    return choice;
}
/*
returns value of function to access
returns 0 if Invalid choice
*/
__uint8_t Menu(void)
{
    __uint8_t choice, c;
    printf("\nType 0 to exit\n");
    printf("Type 1 to access Human resources Management section\n");
    printf("Type 2 to access Product Management section\n");
    scanf("%c", &c);
    switch (c)
    {
    case 49:
        choice = m1();
        break;
    case 50:
        choice = m2();
        break;
    default:
        printf("Invalid choice!!\n");
        choice = Menu();
        break;
    }
    return choice;
}


//---------------------------------------------------------------


//function 1
// returns 0 if no errors where detected
__uint8_t Departement_Add(Dep **Head_Dep)
{
    __uint8_t i = 0;
    Dep *Temp = (Dep*)malloc(sizeof(Dep));
    printf("Give Departement's Number: ");
    fgetc(stdin);
    scanf("%d", &(Temp->Departement_Num));
    printf("Give Departement's Name: ");
    scanf("%s", &(Temp->Departement_Name));
    Temp->Link = *Head_Dep;
    while (i < 15)
    {
        Temp->Emp_List[i].Employee_Num = 0; // setting all empty employee numbers to 0
        i++;
    }
    (*Head_Dep) = Temp;
    return 0;
}
//function 3
//returns 0 in case of no errors
__uint8_t Departement_Rem(Dep **Head_Dep)
{
    __uint8_t n, Test = 1;
    printf("Give departement number to remove: ");
    scanf("%c", &n);
    if (((*Head_Dep)->Link == NULL) && ((*Head_Dep)->Departement_Num == n))
    {
        *Head_Dep = NULL;
        return 0;
    }
    Dep *Temp = *Head_Dep;
    while (Temp != NULL)
    {
        if (Temp->Link->Departement_Num == n)
        {
            Temp->Link = Temp->Link->Link;
            Test = 0;
            break;
        }
        Temp = Temp->Link;
    }
    if (Test == 1)
    {printf("Invalid Departement number!");}
    return Test;
}

//if n = 0 prints all departements 
//if n != 0 prints that departement number
Dep *Dep_Print(Dep **Head_Dep, __uint8_t n)
{
    Dep *Temp = *Head_Dep;
    if (n == 0)
    {
        printf("------list of departements currently in memory------\n");
        while (Temp != NULL)
        {
            printf("Departement number:: %d\nDepartement Name:: %s\n\n", Temp->Departement_Num, Temp->Departement_Name);
            Temp = Temp->Link;
        }
        return NULL;
    }
    else
    {
        while (Temp != NULL)
        {
            if (Temp->Departement_Num == n)
            {return Temp;}
            Temp = Temp->Link;
        }
    }
}
//function 5
//prints all employees of that departement
void Employees_Print(Dep *D)
{
    __uint8_t i = 0;
    printf("------Showing Departement n°%c's employee list------\n", D->Departement_Num);
    printf("----------------------------------------\n");
    while (D->Emp_List[i].Employee_Num != 0)
    {
        printf("Employee number: %hu\n", D->Emp_List[i].Employee_Num);
        printf("Employee's name: %s\n", D->Emp_List[i].Name);
        printf("Employee's salary: %.3f\n", D->Emp_List[i].Salary);
        printf("Employee's Available leave days: %c\n", D->Emp_List[i].Available_Leave_Days);
        printf("----------------------------------------\n");
        i++;
    }
}

Emp *Emp_Create()
{
    Emp *Temp = (Emp*)malloc(sizeof(Emp));
    printf("Give employee number: ");
    scanf("%hu", &(Temp->Employee_Num));
    printf("Give employee Name: ");
    scanf("%s", Temp->Name);
    printf("Give employee Salary: ");
    scanf("%f", &(Temp->Salary));
    printf("Give employee Available leave days: ");
    scanf("%c", &(Temp->Available_Leave_Days));
    return Temp;
}
//function 2
void Emp_Add(Emp *New_Employee, Dep **Head_Dep)
{
    __uint8_t n, i = 0;
    Dep *Temp = *Head_Dep;
    printf("Give number of Departement to add employee into: ");
    scanf("%c", &n);
    while (Temp != NULL)
    {
        if (Temp->Departement_Num == n)
        {
            while (Temp->Emp_List[i].Employee_Num != 0)
            {i++;}
            Temp->Emp_List[i] = (*New_Employee);
        } 
    }
}
//function 4
void Emp_Rem(Dep **Head_Dep)
{
    Dep *Temp;
    __uint8_t n1, x = 0, y;
    __uint16_t n2;
    Bool Test = False;
    Temp = Dep_Print(Head_Dep, 0);
    printf("Give Departement number to remove employee from: ");
    scanf("%c", &n1);
    Temp = Dep_Print(Head_Dep, n1);
    Employees_Print(Temp);
    printf("Give employee number to remove: ");
    scanf("%hu", &n2);
    n1 = 0;
    while (n1 < 15)
    {
        if (Temp->Emp_List[n1].Employee_Num == n2)
        {
            Test = True;
            y = n1;
            n1++;
            break;
        }
        n1++;
    }
    if (Test == False)
    {return;}
    while ((Temp->Emp_List[n1].Employee_Num != 0) && (n1 < 15))
    {
        x++;
        n1++;
    }
    for (n1 = y; n1 < (y+x); n1++)
    {
        if (n1 == 16)
        {break;}
        Temp->Emp_List[n1] = Temp->Emp_List[n1 + 1];
    }
}

//if n = 0 modifies all employees
//if n != 0 modifies employees salaery from n departement 
void Salary_Modif(Dep **Head_Dep, __uint8_t n)
{
    __uint8_t c, i = 0;
    __uint16_t x;
    float Raise_Amt;
    Dep *Temp = *Head_Dep;
    if (n == 0)
    {
        
    }else
    {
        printf("Type 1 to apply raise for all departement's employees");
        printf("Type 2 to modify one salary\n__::");
        scanf("%c", &c);
        switch (c)
        {
        case 1:
            while (Temp != NULL)
            {
                printf("Enter the raise ammount to apply: ");
                scanf("%f", &Raise_Amt);
                if (Temp->Departement_Num == n)
                {
                    while (Temp->Emp_List[i].Employee_Num != 0)
                    {
                        Temp->Emp_List[i].Salary *= Raise_Amt;
                        i++;
                    }
                }
                Temp = Temp->Link;
            }
            break;
        case 2:
            while (Temp != NULL)
            {
                if (Temp->Departement_Num == n)
                {
                    Employees_Print(Temp);
                    printf("Give employee's number to modify it's salary: ");
                    scanf("%hu", &x);
                    while (Temp->Emp_List[i].Employee_Num != 0);
                    {
                        if (Temp->Emp_List[i].Employee_Num == x)
                        {
                            printf("Give employee %hu new salary: ", Temp->Emp_List[i].Employee_Num);
                            scanf("%f", &Raise_Amt);
                            Temp->Emp_List[i].Salary = Raise_Amt;
                        }
                    }
                }
                Temp = Temp->Link;
            }
            break;
        }
    }
}

//function 6
void Salary(Dep **Head_Dep)
{
    __uint8_t x;
    printf("Type 1 to modify departement's salary\n");
    printf("Type 2 to modify all salaries\n__::");
    scanf("%c", &x);
    Dep_Print(Head_Dep, 0);
    switch (x)
    {
    case 1:
        printf("Give departement's number: ");
        scanf("%c", &x);
        Salary_Modif(Head_Dep, x);
        break;
    case 2:
        Salary_Modif(Head_Dep, 0);
        break;
    default:
        printf("Invalid value!");
        break;
    }
}

//-------------------------------------------------------------
//function 9
void Batch_Add(Batch **Head_Batch)
{
    Batch *Temp = (Batch*)malloc(sizeof(Batch));
    printf("Type Batch number: ");
    scanf("%c", &(Temp->number));
    printf("Give batch reference: ");
    scanf("%s", &(Temp->Reference));
    for (__uint8_t i = 0; i < SIZE_BATCH; i++)
    {
        Temp->Product_List[i].Price = 0;
    }
    Temp->Link = *Head_Batch;
    *Head_Batch = Temp;
}
//function 7
void Prod_Add(Batch **Head_Batch)
{
    __uint8_t n, i = 0;
    Batch *Temp = *Head_Batch;
    Prod P;
    printf("Give number of batch to add product into: ");
    scanf("%c", &n);
    while (Temp != NULL)
    {
        if (Temp->number == n)
        {
            while (Temp->Product_List[i].Price != 0)
            {i++;}
            printf("Give Product's name: ");
            scanf("%s", &(P.Product_Name));
            printf("Give Product's Price: ");
            scanf("%f", &(P.Price));
            printf("Enter Delivery date and expiration date: ");
            scanf("%s", &(P.Delivery_Date));
            scanf("%s", &(P.Expiry_Date));
            Temp->Product_List[i] = P;
            break;
        }
        Temp = Temp->Link;
    }
}
//function 8

//function 10
void Batch_Print(Batch **Head_Batch)
{
    __uint8_t n, i = 0;
    Batch *Temp = *Head_Batch;
    printf("Give batch number to show: ");
    scanf("%c", &n);
    while (Temp != NULL)
    {
        if (Temp->number == n)
        {
            printf("--------Printing Batch number: %c--------", n);
            while (Temp->Product_List[i].Price != 0)
            {
                printf("--------------------");
                printf("Product Name: %s");
                printf("Product Delivery Date: %s");
                printf("Product Expiration Date: %s");
                printf("Product Price: %.3f");
                printf("--------------------");
                i++;
            }
        }
        Temp = Temp->Link;
    }
}


//-------------------------------------------------------------


Bool Choice (__uint8_t choice, Dep **Head_Dep, Batch **Head_Batch)
{
    __uint8_t x;
    Dep *Temp;
    switch (choice)
    {
    case 48:
        return False;
    case 49:
        Departement_Add(Head_Dep);
        break;
    case 50:
        Emp_Add(Emp_Create(), Head_Dep);
        break;
    case 51:
        Departement_Rem(Head_Dep);
        break;
    case 52:
        Emp_Rem(Head_Dep);
        break;
    case 53:
        Temp = Dep_Print(Head_Dep, 0);
        printf("Type Departement number to print it's details\nElse type 0\n__::");
        scanf("%c", &x);
        Temp = Dep_Print(Head_Dep, x);
        Employees_Print(Temp);
        break;
    case 54:
        Salary(Head_Dep);
        break;
    case 55:
        Prod_Add(Head_Batch);
        break;
    case 56:
        
        break;
    case 57:
        Batch_Add(Head_Batch);
        break;
    case 10:
        Batch_Print(Head_Batch);
        break;
    case 11:

        break;
    }
    return True;
}

