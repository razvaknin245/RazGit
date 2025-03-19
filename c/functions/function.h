#ifndef FUNCTION_H
#define FUNCTION_H /*infndef and define and end if is for make sure that i load library only once*/

#include<stdlib.h>
#include<stdio.h> /*for getchar() and printf() functions*/

#define ESC 27

typedef void (*foo_ptr)();/*create a function pointer*/
extern foo_ptr fp_arr[256];/* create array to functions pointers*/

void if_key_Check(char c); /*first function , use if/else*/

void sc_key_Check(char c); /*second function us switc/case*/

void initLut(int size); /*function to initialize the lookup table to NULL and selected keys*/

void lut_key_check(char c);/*third function , use lookuptable*/

void empty_func();/*empty func for initialize the lookup table*/

void a_key();/* function to save in lookup table incase of choose A*/

void t_key();/* function to save in lookup table incase of choose T*/

void esc_key();/* function to save in lookup table incase of choose esc*/

#endif



