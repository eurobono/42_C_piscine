#include <stdio.h>

#define DIGITOS 10 /* binario=2, decimal=10 */
#define LENGTH 2 /* siempre menor de 64 */


int is_end(char *str, int index, int length) {


	if (((index+1) >= length) && ((str[length-1] - '0' + 1) >= DIGITOS))
		return 1;


	return 0;
}

void bp(char *str,int index,int length){
	int i;

// printf ("%s:%d:%d\n",str,index,length);


	if (index == length) {
		is_end(str,index,length) ? printf ("%s\n",str) : printf ("%s , ",str);
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

