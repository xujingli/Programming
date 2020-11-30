/*耐心细致，仔细分析
内容：浮点数比较；圆周率 、四舍五入 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//----------------------------------------------------------------------- 
//浮点数比较，一个数a落在[b-eps,b+eps]中间即判a==b，通常eps取1e-8 
const double eps = 1e-15;

#define Equ(a,b) ((fabs((a)-(b)))<(eps)) 
//浮点数等于判断，精度为1e-15

#define More(a,b) (((a)-(b))>(eps))
//浮点数大于判断，即a>b+eps 请画图理解 

#define Less(a,b) (((a)-(b))<(-eps))
//浮点数小于判断 ,即a<b-eps

#define MoreEqu(a,b) (((a)-(b))>(-eps))
//浮点数大于等于判断，即a>b-eps
//-----------------------------------------------------------------------

//圆周率
const double Pi = acos(-1.0); 

//四舍五入 
void Round(double db,int n){
	//将浮点数db保留n位，并且四舍五入
	db=db*pow(10,n);
	
	int tmp=(int)round(db); 	//四舍五入后进行取整
	db=(double)(tmp)/(pow(10,n));
	
	printf("%f\n",db); 
}

int main(){
	double db = 1.234567891234567;
	double db1= 1.234567891234567;
	
	printf("Pi = %.15f\n",Pi);//double的精度为15-16位 
	
	if(Equ(db,db1))
		printf("db == db1\n");
	else
		printf("db != db1\n");
		
	Round(-Pi,6);

	return 0;
}

