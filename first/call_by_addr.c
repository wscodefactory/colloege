#include <stdio.h>

// 인자로 주어진 주소에 들어있는 값을 증가
void increment(int *a)
{
    (*a)++;
    
}

int main(void)
{
    int     num;
    scanf("%d", &num);
    
    // num의 주소를 인자로 increment()함수 호출
    increment(&num);     // 이부분 수정
    
	printf("%d\n", num);
}