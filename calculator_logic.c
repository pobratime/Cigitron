#include <stdio.h>

#include "calculator_logic.h"

long addition (long num1, long num2){

    return num1 + num2;
}
long subtract (long num1, long num2){

    return num1 - num2;
}
long divide (long num1, long num2){

    return num1 / num2;
}
long multiply (long num1, long num2){

    return num1 * num2;
}

int logic(){

    addition(1, 3);
    subtract(1, 3);
    divide (1, 3);
    multiply (1, 3);

}