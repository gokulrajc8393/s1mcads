// myfile.c
#include <stdio.h>
//#define SAMPLE 10
void main()
{
#ifdef SAMPLE
	printf("With preprocessor directive=%d\n",SAMPLE);
#else
	printf("With out #ifdef\n");
#endif
}
