#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>


int main() 
{
	char sim = 0;
	while (sim != '\r')
	{
		sim = fgetc(stdin);
		if ((sim >= '0') && (sim <= '9'))
		{
			int x = (int)(sim - '0');
			printf_s("%d ", x = pow(x, 2));
		}
	}
	system("pause");
	return 0;

}