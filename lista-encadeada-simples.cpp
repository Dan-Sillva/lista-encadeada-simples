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

int main () {

    // Code

};

void createEmptyList(List *list){
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
                printf("Removendo item unico...");
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
        break;
    }

}

void removeBillToList(List *list, int searchOption, int index){

}



/* \\\\\\\\\\---> insert Option :

_1 = inicio da lista
_2 = final da lista 
_3 = meio da lista          */
