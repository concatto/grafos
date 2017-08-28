#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

struct Element {
    Element *next;
    string data;
};

struct Stack {
    int quantity;
    Element *top_of_stack;

    Stack() {
        this->top_of_stack = NULL;
        this->quantity = 0;
    }

    bool push(string data){
        Element *element = new Element;
        if(element == NULL)
            return false;

        element->data = data;

        if(this->top_of_stack == NULL){
            top_of_stack = element;
            element->next = NULL;
            return true;
        }

        element->next = top_of_stack;
        top_of_stack = element;
        return true;
    }

    bool pop(){
        if(this->quantity == 0)
            return false;
        Element *aux = top_of_stack;
        top_of_stack = top_of_stack->next;
        delete aux;
        return true;
    }

    bool isEmpty(){
        return this->quantity == 0;
    }

};

#endif // STACK_H
