 #include<stdio.h>
 
 #define ABS(X) ((X)>0? (X):(-1)*(X))

 void main()
 {
 	int paramA, paramB, paramC;  //输入参数A、B、C, 可正可负可零. 运算过程中参数A、B以绝对值|A|、|B|参与运算，最后再调整系数X、Y符号. 
 	int mParamA, mParamB;        //分别表示参数|A|、|B|除以|A|和|B|的最大公约数的数值.
 	int paramACopy, paramBCopy, paramTemp, paramMin; //paramACopy, paramBCopy备份参数A、B，paramTemp为计算使用到的中间变量，paramMin为参数|A|、|B|辗转相减后可获得的最小正数.
 	int minuendCoefficientWithParamA, minuendCoefficientWithParamB;        //记录被减数与参数|A|和|B|的数值计算关系. 
 	int subtrahendCoefficientWithParamA, subtrahendCoefficientWithParamB;  //记录减数与参数|A|和|B|的数值计算关系. 
 	int differenceCoefficientWithParamA, differenceCoefficientWithParamB;  //记录差数与参数|A|和|B|的数值计算关系. 
 	
 	printf("*******************************************************************");
 	printf("\nThis program is used to calculate X and Y with C = A * X + B * Y.\n");
 	printf("Where A, B, C are both input parameters and are integers,\nAnd the solution will make |X| + |Y| is minimal!\n");
 	printf("*******************************************************************");
 	
 	printf("\n\nPlease input parameter A(integer): ");
 	scanf("%d", &paramA);
 	printf("Please input parameter B(integer): ");
 	scanf("%d", &paramB);
 	printf("Please input parameter C(integer): ");
 	scanf("%d", &paramC);
 	if((paramA == 0) && (paramB == 0))         //参数A、B都为0，单独判断处理。 
 	{
 		if(paramC == 0)
 		{
 			printf("\nYes!, the answer is exist!");
 			printf("\nInput parameters:   A: 0,  B: 0,  C: 0.");
 			printf("\nOutput parameters:  X: 0,  Y: 0.");
 			printf("\nThe solution is:  (0) = (0) * (0) + (0) * (0)!\n\n");
 		}
 		else
 		{
 			printf("\nNo! The answer is not exist!\n\n");
 		}
 		system("pause");
 		return;
 	}
 	paramACopy = paramA;                      //备份参数A、B 
 	paramBCopy = paramB;

 	if(paramA < 0)  paramA *= -1;             //舍去参数A、B符号，取其绝对值。 
 	if(paramB < 0)  paramB *= -1;
 	if(paramA == 0)                           //假设参数|A|>|B|, 则被减数取为|A|，减数取为|B|，更新被减数、减数与参数|A|和|B|的数值计算关系. 
 	{
 		minuendCoefficientWithParamA = 0;
 		minuendCoefficientWithParamB = 0;
 	}
 	else
 	{
 		minuendCoefficientWithParamA = 1;
 		minuendCoefficientWithParamB = 0;
	}
 	
 	if(paramB == 0)
 	{
 		subtrahendCoefficientWithParamA = 0;
 		subtrahendCoefficientWithParamB = 0;
 	}
 	else
 	{
 		subtrahendCoefficientWithParamA = 0;
 		subtrahendCoefficientWithParamB = 1;
	}

 	if(paramA < paramB)                    //若参数|A|<|B|，则交换|A|、|B|，并同步更新被减数、减数与原参数|A|和|B|的数值计算关系 
 	{
 		paramTemp = paramA;
 		paramA = paramB;
 		paramB = paramTemp;

 		paramTemp = minuendCoefficientWithParamA;
 		minuendCoefficientWithParamA = subtrahendCoefficientWithParamA;
 		subtrahendCoefficientWithParamA = paramTemp;
 		paramTemp = minuendCoefficientWithParamB;
 		minuendCoefficientWithParamB = subtrahendCoefficientWithParamB;
 		subtrahendCoefficientWithParamB = paramTemp;
 	}

 	mParamA = paramA;
 	mParamB = paramB;

 	while(mParamB != 0)                   //求取参数|A|和|B|的最大公约数. 
 	{
 		paramTemp = mParamA % mParamB;
 		mParamA = mParamB;
 		mParamB = paramTemp; 
 	}

 	mParamB = ABS(paramBCopy) / mParamA;  //求取原参数|A|、|B|除以它们最小公约数后的数值.
 	mParamA = ABS(paramACopy) / mParamA;

 	paramMin = paramA;     //初始化最小正数为|A|，并更新差数与|A|、|B|的数值运算关系. 当|A|=|B|或者|B|=0时，最小正数即为|A|，对应数值运算关系即为被减数的数值运算关系. 
 	differenceCoefficientWithParamA = minuendCoefficientWithParamA;
 	differenceCoefficientWithParamB = minuendCoefficientWithParamB;
 	
 	while((paramA > paramB) && (paramB != 0)) //当|A|=|B|或者|B|=0时，最小长度即为|A|，对应数值运算关系即为被减数的数值运算关系, 无需计算求解. 
 	{
 		paramTemp = paramA - paramB;          //求差数|A|-|B|，并更新差数与|A|、|B|计算关系.

 		differenceCoefficientWithParamA = minuendCoefficientWithParamA - subtrahendCoefficientWithParamA;
 		differenceCoefficientWithParamB = minuendCoefficientWithParamB - subtrahendCoefficientWithParamB;
 		if(paramTemp > paramB)                //若差数大于减数，则将差数赋值给被减数，并更新被减数与|A|、|B|的运算关系. 
 		{
 			paramA = paramTemp;

 			minuendCoefficientWithParamA = differenceCoefficientWithParamA;
 			minuendCoefficientWithParamB = differenceCoefficientWithParamB;
 		}
 		else if(paramTemp < paramB)           //若差数小于减数，则将减数赋值给被减数，差数赋值给减数，并更新被减数、减数与|A|、|B|的运算关系.
 		{
 			paramA = paramB;
 			paramB = paramTemp;

 			minuendCoefficientWithParamA = subtrahendCoefficientWithParamA;
 			minuendCoefficientWithParamB = subtrahendCoefficientWithParamB;
 			subtrahendCoefficientWithParamA = differenceCoefficientWithParamA;
 			subtrahendCoefficientWithParamB = differenceCoefficientWithParamB;
 		}
 		else                                //若差数等于减数，则获取到最小数值(|A|、|B|辗转相减运算可得到的最小正数).即为差数(或者减数).最小正数与|A|、|B|的运算关系即为差数的运算关系. 
 		{
 			paramMin = paramTemp;
 			break;
 		}
 	}
 	if((paramC % paramMin) == 0)              //若目标数可被最小正数整除，则目标数可由(paramC / paramMin)次最小正数与|A|、|B|的运算关系求得。 
 	{
 		differenceCoefficientWithParamA *= (paramC / paramMin);
 		differenceCoefficientWithParamB *= (paramC / paramMin);

        //化简系数differenceCoefficientWithParamA，differenceCoefficientWithParamB. C = differenceCoefficientWithParamA * |A| + differenceCoefficientWithParamB * |B|.
		// mParamB * |A| = mParamA * |B|. 使该式成立最小的mParamA、mParamB为|A|、|B|约去最大公约数后的值. 
		//C = (differenceCoefficientWithParamA +/- mParamB) * |A| + (differenceCoefficientWithParamB -/+ mParamA)* |B|
		//由上面步骤求取的differenceCoefficientWithParamA，differenceCoefficientWithParamB必为一正一负（减法运算）。
		//将系数往系数绝对值和最小的方向化简。即保证目标等式C成立，可将正数减小，负数增大。
 		if((differenceCoefficientWithParamA > 0) && (differenceCoefficientWithParamB < 0))
 		{
			while((ABS(differenceCoefficientWithParamA) + ABS(differenceCoefficientWithParamB)) > 
 				  (ABS(differenceCoefficientWithParamA - mParamB) + ABS(differenceCoefficientWithParamB + mParamA)))
 			{
 				differenceCoefficientWithParamA -= mParamB;
 			    differenceCoefficientWithParamB += mParamA;
 			}
 		}
 		if((differenceCoefficientWithParamA < 0) && (differenceCoefficientWithParamB > 0))
 		{
 			while((ABS(differenceCoefficientWithParamA) + ABS(differenceCoefficientWithParamB)) > 
 				  (ABS(differenceCoefficientWithParamA + mParamB) + ABS(differenceCoefficientWithParamB - mParamA)))
 			{
 				differenceCoefficientWithParamB -= mParamA;
 			    differenceCoefficientWithParamA += mParamB;
 			}
 		}

        //根据A、B的符号调整differenceCoefficientWithParamA、differenceCoefficientWithParamB的符号，使C等式仍成立.
		//且仍有|differenceCoefficientWithParamA| + |differenceCoefficientWithParamB|最小. 
 		if(paramACopy < 0) differenceCoefficientWithParamA *= -1;
 		if(paramBCopy < 0) differenceCoefficientWithParamB *= -1;
 		printf("\nYes!, The answer is exist!");
 		printf("\nInput parameters:   A: %d,  B: %d,  C: %d.", paramACopy, paramBCopy, paramC);
 		printf("\nOutput parameters:  X: %d,  Y: %d.", differenceCoefficientWithParamA, differenceCoefficientWithParamB);
 		printf("\nThe solution is:  (%d) = (%d) * (%d) + (%d) * (%d)!\n\n", paramC, differenceCoefficientWithParamA, paramACopy, differenceCoefficientWithParamB, paramBCopy);
 	}
 	else
 	{
 		printf("\nNo! The answer is not exist!\n\n");
 	}
 	system("pause");
  } 
