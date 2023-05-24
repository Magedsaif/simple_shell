#include"shell.h"
/**
 *
 *
 *
 *
 *
*/
void int_to_str(int n, char *str)
{
	int tmp;
	int i = 0;
	if (n == 0)
	{
		str[i++] = '0';
	}
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++; /* calc str length needed*/
	}
	tmp = n;
	while (i > 0)
	{
		str[--i] = tmp % 10 + '0'; /*store rightmost and move backward*/
		tmp /= 10; /*remove rightmost*/

	}
	str[i] = '\0'; /*null term*/

}
