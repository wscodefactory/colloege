#include <stdio.h>
#define SIZE 7

// 배열 list에서 n개 요소의 합을 구함
int cal_sum(int  list[ ], int  n)
{
	int  sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += list[i];
	}
	return sum;
}
int main(void)
{
	int  num[ ] = { 2, 3, 5, 7, 9, 11, 13 };
	int  sum, i, k;
	
	scanf("%d %d", &i, &k);
/*sum = cal_sum(num+i,k);   // 이부분 수정
또는*/ sum = cal_sum(&num[i],k);  
	printf("%d\n", sum);
	return 0;
}
