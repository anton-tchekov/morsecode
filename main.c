#include <stdio.h>
#include "morsecode.h"

int main(void)
{
	char buf[256];
	printf("encode(\"HELLOWORLD\") = %s\n", morse_encode("HELLOWORLD", buf));
	printf("decode(\"...././.-../.-../---/.--/---/.-./.-../-..\") = %s\n",
			morse_decode("...././.-../.-../---/.--/---/.-./.-../-..", buf));
	return 0;
}

