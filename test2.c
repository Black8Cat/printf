#include <stdio.h>
#include "main.h"

int main (){

	int len, len2;
	len = _printf("HELLO\n");
	len2 = printf("HELLO\n");	
    _printf("Len:[%d]\n", len);
    printf("Len2:[%d]\n", len2);
}
