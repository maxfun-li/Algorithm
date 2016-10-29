#include<stdio.h>
 
#define ABS(X) ((X)>0? (X):(-1)*(X))

void main()
{
	int length1, length2, destination, lengthTemp, minStep;  //指定两个长度length1，length2，指定终点destination，minStep为由length1和length2进行加减运算可得到的最小长度。 
	int length1Copy, length2Copy;                            //备份length1，length2 
	int mlength1, mlength2;                                  //分别表示length1，length2除以length1和length2的最大公约数后的数值。 
	int minuendParamLen1, minuendParamLen2, subtrahendParamLen1, subtrahendParamLen2, differenceParamLen1, differenceParamLen2; 
	//用于记录运算过程中被减数，减数，差数与length1，length2的数值关系，例如：minuend = minuendParamLen1 * length1 + minuendParamLen2 * length2。 
	printf("Please input length1: ");
	scanf("%d", &length1);
	printf("Please input length2: ");
	scanf("%d", &length2);
	printf("Please input destination: ");
	scanf("%d", &destination);
	if((length1 < 0) || (length2 < 0) || ((length1 == 0) && (length2 == 0)))
	{
		printf("\nError! length must be great than or equal to 0 and cannot be zero at the same time!\n\n");
		system("pause");
		return;
	}
	
	length1Copy = length1;
	length2Copy = length2;
	
	minuendParamLen1 = 1;         //假设length1 > length2, 则初始被减数为length2，减数为length2. 
	minuendParamLen2 = 0;
	subtrahendParamLen1 = 0;
	subtrahendParamLen2 = 1;
	
	if(length1 < length2)        //如果length1 < length2, 则交换length1，length2数值，并更新初始被减数为原length2，减数为原length1. 
	{
		lengthTemp = length1;
		length1 = length2;
		length2 = lengthTemp;
		
		minuendParamLen1 = 0;
		minuendParamLen2 = 1;
		subtrahendParamLen1 = 1;
		subtrahendParamLen2 = 0;
		
	}
	
	mlength1 = length1;
	mlength2 = length2;
	while(mlength2 != 0)       //求取length1，length2最大公约数. 
	{
		lengthTemp = mlength1 % mlength2;
		mlength1 = mlength2;
		mlength2 = lengthTemp;
	}
	mlength2 = length2Copy / mlength1;  //获取length1，length2约去最大公约数的数值. 
	mlength1 = length1Copy / mlength1;
	
	minStep = length1;                  //初始化minStep为length1（最大者），在length1=length2或者length2=0的情况下，minStep须设为length1，差数与length1，length2的关系与被减数一致。 
	differenceParamLen1 = minuendParamLen1;
	differenceParamLen2 = minuendParamLen2;
	
	while((length1 > length2) && (length2 != 0)) //在length1=length2或者length2=0的情况无需额外计算，最小长度minStep即为length1. 
	{
		lengthTemp = length1 - length2;          //求length1与length2的差。 
		
		differenceParamLen1 = minuendParamLen1 - subtrahendParamLen1; //更新差数与length1，length2的数值关系。 
		differenceParamLen2 = minuendParamLen2 - subtrahendParamLen2;
		
		if(lengthTemp > length2)  //若差数大于减数，则将差数赋值给被减数，并更新被减数与length1，length2的数值关系。
		{
			length1 = lengthTemp;
			
			minuendParamLen1 = differenceParamLen1;
			minuendParamLen2 = differenceParamLen2;
		}
		else if(length2 > lengthTemp)  //若差数小于减数，则将减数赋值给被减数，差数赋值给减数，并更新被减数，减数与length1，length2的数值关系。 
		{
			length1 = length2;
			length2 = lengthTemp; 
			
			minuendParamLen1 = subtrahendParamLen1;
			minuendParamLen2 = subtrahendParamLen2;
			subtrahendParamLen1 = differenceParamLen1;
			subtrahendParamLen2 = differenceParamLen2;
		}
		else                  //差数与减数相等，得到length1与length2加减运算后可得到的最小长度，为差数或者减数。 
		{
			minStep = lengthTemp;
			break;
		}
	}
	if((destination % minStep) == 0) //若终点数值可被最小长度，则终点可有(destination / minStep)个最小长度的运算得到。 
	{
		differenceParamLen1 *= (destination / minStep);
		differenceParamLen2 *= (destination / minStep);
		
		//化简系数differenceParamLen1，differenceParamLen2. destination = differenceParamLen1 * length1 + differenceParamLen2 * length2.
		// mlength2 * length1 = mlength1 * length2. 使该式成立最小的mlength1、mlength2为length1、length2约去最大公约数后的值. 
		//destination = (differenceParamLen1 +/- mlength2) * length1 + (differenceParamLen2 -/+ mlength1)* length2
		//由上面步骤求取的differenceParamLen1，differenceParamLen2必为一正一负（减法运算）。
		//化简将跳数（即系数）往最小数值（系数绝对值和最小）方向化简。即保证目标等式destination成立，可将正数减小，负数增大。 
		if((differenceParamLen1 > 0) && (differenceParamLen2 < 0))
 		{
			while((ABS(differenceParamLen1) + ABS(differenceParamLen2)) > 
 				  (ABS(differenceParamLen1 - mlength2) + ABS(differenceParamLen2 + mlength1)))
 			{
 				differenceParamLen1 -= mlength2;
 			    differenceParamLen2 += mlength1;
 			}
 		}
 		if((differenceParamLen1 < 0) && (differenceParamLen2 > 0))
 		{
 			while((ABS(differenceParamLen1) + ABS(differenceParamLen2)) > 
 				  (ABS(differenceParamLen1 + mlength2) + ABS(differenceParamLen2 - mlength1)))
 			{
 				differenceParamLen2 -= mlength1;
 			    differenceParamLen1 += mlength2;
 			}
 		}		
		
		
		printf("\nYes!, The destination can be reached!\nDestination: %d.   Length1: %d.   Length2: %d.\n",
		              destination, length1Copy, length2Copy);
		printf("The minimum step is: Destination = (%d) * Length1 + (%d) * Length2!\n\n", differenceParamLen1, differenceParamLen2);
	}
	else
	{
		printf("\nNo!, The destination can't be reached!\n\n");
	}
	system("pause");
 } 
