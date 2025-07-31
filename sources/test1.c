#include <stdio.h>

#define DIGITOS 2 /* binario=2, decimal=10 */
#define LENGTH 3  /* siempre menor de 64 */


void bp(char *str,int index,int length){
	int i;

// printf ("%s:%d:%d\n",str,index,length);


	if (index == length) {
		printf ("%s\n",str);
		return;
	}


	str[index]='0';

	for (i=0; i < DIGITOS; i++) {
		bp (str, index+1, length);
		str[index]++;
	}

	return;
}



void main() {

	char cadena[66]={0};

	if ((LENGTH <1) || (LENGTH > 64)) {
		printf ("ERROR: LENGTH must be in between 1 and 64\n");
		return;
	}


	bp (cadena,0,LENGTH);

	return;
}

