#include <unistd.h>
#include <stdio.h>
#include "ft_abs.h"

int	main(void)
{
	int	i;
	char	c;
	long	l;
	unsigned long		ul;

i = ABS(-1);
c = ABS(-1);
l = ABS(-1);
ul = ABS(-1);
	printf ("ABS (-1) = %d\n",ABS(-1));
	printf ("ABS (0) = %d\n",ABS(0));
	printf ("ABS (+1) = %d\n",ABS(+1));
	return (0);
}
