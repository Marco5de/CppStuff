#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct element{
    int val;
    struct element* next;
}element;

struct element* head = NULL;

void addContent(int _val);
element* searchVal(int _val);
void deleteEle(int _val);
void printList();
_Bool checkSearchSucces(int _val);

int main() {

    addContent(21);
    addContent(10);
    addContent(54);
    printList();
    if(checkSearchSucces(10))
        printf("Erfolg");

    return 0;
}

void addContent(int _val){
    struct element* newEle = (struct element*)malloc(sizeof(element));
    if(newEle==NULL){
        printf("Something went wrong. Closing...");
        exit(1);
    }
    newEle->next = NULL;
    newEle->val = _val;
    if(head == NULL){
        head = newEle;
    }else{
        struct element* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
            continue;
        }
        curr->next = newEle;
    }
}

void printList(){
    struct element* curr = head;
    while (curr!=NULL){
        printf("Alter: %d\n\n",curr->val);
        curr = curr->next;
    }
    printf("Die Liste wurde erfolgreich ausgegeben\n\n");
}

element* searchVal(int _val){
    element* curr =head;
    while (curr != NULL){
        if(curr->val == _val)
            return curr;
        else{
            if(curr->next!=NULL)
                curr = curr->next;
        }
    }
    return NULL;
}
_Bool checkSearchSucces(int _val){
    if(searchVal(_val) != NULL)
        return true;
    else
        return false;
}