#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE  7//배열의 크기는 7로

typedef char Element;
Element data[MAX_QUEUE_SIZE];    // 요소의 배열
int front;            // 전단
int rear;            // 후단
int flag = 0;

// 프로그램 3.1의 error()함수와 동일
void error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
};
// 큐의 주요 연산: 공통
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear && flag == 0; }//공백여부
int is_full() { return front == rear && flag == 1; }//포화여부
int size()//현재 저장된 값의 수
{
	if(flag = 0)
	{
		return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	}
	else
	{
		return MAX_QUEUE_SIZE;
	}
}

Element AddQue(Element val)//큐에 값 삽입
{
	if (is_full())
		error("  큐 포화 에러");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
	if (rear == front && data[front])//rear와 front가 같고 해당 자리에 값이 있을때
		flag = 1;
	return val;
}
Element DelQue()//큐에서 값 삭제
{
	if (is_empty())
		error("  큐 공백 에러");
	front = (front + 1) % MAX_QUEUE_SIZE;
	if (rear == front && !data[front])//rear와 front가 같고 해당 자리에 값이 없을때
		flag = 0;
	return data[front];
}
Element peek()
{
	if (is_empty())
		error("  큐 공백 에러");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

// 큐 테스트를 위한 코드: 요소 종류마다 수정
void print_queue(char msg[]) {
	int i, maxi = rear;
	if (front >= rear) maxi += MAX_QUEUE_SIZE;
	printf("%s[%2c]= ", msg, size());
	for (i = front + 1; i <= maxi; i++)
		printf("%2c ", data[i%MAX_QUEUE_SIZE]);
	printf("\n");
}

void main()
{
	init_queue();
	printf("\tAddQue() --> %c\n", AddQue('A'));
	printf("\tAddQue() --> %c\n", AddQue('B'));
	printf("\tDelQue() --> %c\n", DelQue());
	printf("\tAddQue() --> %c\n", AddQue('C'));
	printf("\tAddQue() --> %c\n", AddQue('D'));
	printf("\tAddQue() --> %c\n", AddQue('E'));
	printf("\tAddQue() --> %c\n", AddQue('F'));
	printf("\tAddQue() --> %c\n", AddQue('G'));
	printf("\tDelQue() --> %c\n", DelQue());
	printf("\tDelQue() --> %c\n", DelQue());
	printf("\tAddQue() --> %c\n", AddQue('H'));
	printf("\tAddQue() --> %c\n", AddQue('I'));
	printf("\tDelQue() --> %c\n", DelQue());
	printf("\tAddQue() --> %c\n", AddQue('J'));
	printf("\tDelQue() --> %c\n", DelQue());
	printf("\tDelQue() --> %c\n", DelQue());
	printf("\tAddQue() --> %c\n", AddQue('K'));
	printf("\tAddQue() --> %c\n", AddQue('L'));
	printf("\tDelQue() --> %c\n", DelQue());
	printf("\tAddQue() --> %c\n", AddQue('M'));
	printf("\tAddQue() --> %c\n", AddQue('N'));
	print_queue("큐 내부 출력");//N까지 모두 정상적으로 저장됨을 확인.
}