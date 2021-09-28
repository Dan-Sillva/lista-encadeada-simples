    /*
Implementar uma lista encadeada simples, com operações de inserção e remoção no início, meio e fim da fila, 
além de busca de elementos.

A lista deve armazenar valores referentes ao pagamento de uma conta, com dia, mês e ano do vencimento, valor 
(double) e situação do pagamento (true para pago,  false para não pago).

Forma de entrega: Link para o repositório do Github
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bill Bill;

//---> types
typedef struct List {
    int index;
    Bill *startingPointList;
};

struct bill {
    /* data */
    char date[11]; // --> dd/mm/aaaa
    double value;
    bool paymentStatus;

    Bill *next;
};

//---> functions
void createEmptyList(List *list);
Bill *createBill(char date[11], double value, bool status);

void addBillToList(Bill *bill, List *list, int insertOption);
void addBillToList(Bill *bill, List *list, int insertOption, int index);
void removeBillToList(List *list, int removeOption);
void removeBillToList(List *list, int removeOption, int index);

Bill *searchList (char search[11], List *list, int searchOption);

void printBill(Bill *bill);
void printList(List *list);

bool ArrayToBool(char str[]);


int main () {
    // Code

    
    List *list = (List *)malloc(sizeof(List));
    createEmptyList(list);

    Bill *bill1 = createBill("22/04/2002", 34.99, true);
    Bill *bill2 = createBill("22/04/2003", 76.71, false);
    Bill *bill3 = createBill("22/04/2004", 32.69, true);
    Bill *bill4 = createBill("22/04/2005", 74.73, false);
    Bill *bill5 = createBill("22/04/2006", 79.77, true);
    Bill *bill6 = createBill("22/04/2007", 34.94, false);
    Bill *bill7 = createBill("22/04/2008", 74.74, true);

    addBillToList(bill1, list, 2);
    addBillToList(bill2, list, 2);
    addBillToList(bill3, list, 2);
    addBillToList(bill4, list, 2);
    addBillToList(bill5, list, 2);
    addBillToList(bill6, list, 2);
    addBillToList(bill7, list, 2); 
    

    //functions area  

    printf("----------\n\n");
    searchList("22/04/2006", list, 1);
    printf("----------\n\n");

    printList(list);

};

void createEmptyList(List *list){
    list->index = 0;
    list->startingPointList = NULL;  
};

Bill *createBill(char date[11], double value, bool status){
    Bill *newBill = (Bill *) malloc(sizeof(Bill));

    strcpy(newBill->date, date);
    newBill->value = value;
    newBill->paymentStatus = status;
    newBill->next = NULL;

    return newBill;

};

void addBillToList(Bill *bill, List *list, int insertOption) {

    switch (insertOption)
    {
    case 1:
        // ---> add inicio
        if(list->startingPointList == NULL){
            list->startingPointList = bill;
        } else { 
            bill->next = list->startingPointList;
            list->startingPointList = bill;

        }
        list->index++;
        break;
    
    case 2:
        // ---> add final
        if(list->startingPointList == NULL){
            list->startingPointList = bill;
        } else { 
            Bill *auxBill = list->startingPointList;
            while(auxBill->next != NULL){
                auxBill = auxBill->next;
            }
            auxBill->next = bill;

        }
        list->index++;
        break;
    
    default:
        printf("The selected option do not exist !");
        break;
    }

};

void addBillToList(Bill *bill, List *list, int insertOption, int index){

    // ---> add meio
    if(insertOption == 3){
        if(list->startingPointList == NULL || index == 0){
            bill->next = list->startingPointList;
            list->startingPointList = bill;
        } else {
            Bill *auxBill = list->startingPointList;
            int cont = 1;

            while(cont < index && auxBill->next != NULL){
                auxBill = auxBill->next;
                cont++;
            }

            bill->next = auxBill->next;
            auxBill->next = bill;
        }
        list->index++;

    } else {
        printf("The selected option do not exist !");
    }   

};

void removeBillToList(List *list, int removeOption) {

    switch (removeOption)
    {

    case 1:
        // remove inicio
        {
            Bill *auxBill = list->startingPointList;
            list->startingPointList = auxBill->next;

            free(auxBill);
        }
        
        break;
    
    case 2:
        // remove final
        {
            Bill *auxBill = list->startingPointList;

            if(auxBill->next == NULL){
                printf("Removing..");
                list->startingPointList = NULL;

            } else {
                Bill *prevBill = list->startingPointList;
                while(auxBill->next != NULL){
                    prevBill = auxBill;
                    auxBill = auxBill->next;
                }

                prevBill->next = NULL;
                free(auxBill);
            }
        }

        break;
    
    default:
        printf("The selected option do not exist !\n\n");
    
        break;
    }

}

void removeBillToList(List *list, int removeOption, int index){
    if (removeOption == 3) {
        Bill *prevBill = list->startingPointList;

        if(prevBill->next == NULL){
            printf("removing...");
            prevBill = NULL;
        } else {
            Bill *auxBill = list->startingPointList;
            for(int n=1; n<index; n++){
                prevBill = auxBill;
                auxBill = auxBill->next;
            }
            prevBill->next = auxBill->next;
            free(auxBill);
        }
    } else {
        printf("The selected option do not exist !\n\n");
    }
    
}

Bill *searchList (char search[11], List *list, int searchOption){
    /* searchoption:
        1-date
        2-value
        3-status  */
    Bill *auxBill = list->startingPointList;
    
    switch (searchOption)
    {
    case 1:
        {
            for(int n=1; n<=list->index; n++){
                if(auxBill->date == search){
                    printBill(auxBill);
                };
                auxBill = auxBill->next;
            };
        }

        break;

    case 2:
        {
            for(int n=1; n<=list->index; n++){
                if(auxBill->value == atof(search)){     //atof = ArrayToFloat
                    printBill(auxBill);
                };
                auxBill = auxBill->next;
            };
        }

        break;

    case 3:
        {   
            for(int n=1; n<=list->index; n++){
                if(auxBill->paymentStatus == ArrayToBool(search)){     // convert char array to boolean
                    printBill(auxBill);
                };
                auxBill = auxBill->next;
            };
        }  

        break;
    
    default:
        break;
    }

    return NULL;
};

void printBill(Bill *bill){
    printf("[Date : %s ]-[Value : R$%.2f ]-[Status : %6s ]\n", bill->date, bill->value, bill->paymentStatus?"true":"false");
}

void printList(List *list){
    Bill *auxBill = list->startingPointList;

    // system("cls");
    printf("---------------------------////\n\n");
    for(int n=1; n<=list->index; n++){
        printBill(auxBill);
        
        auxBill = auxBill->next;
    };
    printf("\n\n");

};

bool ArrayToBool(char str[]){
    if (str == "true") {return true;} else if (str == "false") {return false;};
};


/* \\\\\\\\\\---> insert Option :

_1 = inicio da lista
_2 = final da lista 
_3 = meio da lista          */
