#include<stdio.h>

void main()
{
	unsigned char numberIn100, numberIn10, numberIn1;
	unsigned int num = 100, arry[10] = {0, 1, 8, 27, 64, 125, 216, 343, 512, 729};
	for(numberIn100 = 1; numberIn100 <= 9; numberIn100++)
	{
		for(numberIn10 = 0; numberIn10 <= 9; numberIn10++)
		{
			for(numberIn1 = 0; numberIn1 <= 9; numberIn1++)
			{
				if(num == (arry[numberIn100] + arry[numberIn10] + arry[numberIn1]))
				{
					printf("%d  ", num);
				}
				num++;
			}
		}
	}
	printf("\n");
	system("pause");
}
