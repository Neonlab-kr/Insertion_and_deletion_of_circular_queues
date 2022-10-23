#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE  7//�迭�� ũ��� 7��

typedef char Element;
Element data[MAX_QUEUE_SIZE];    // ����� �迭
int front;            // ����
int rear;            // �Ĵ�
int flag = 0;

// ���α׷� 3.1�� error()�Լ��� ����
void error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
};
// ť�� �ֿ� ����: ����
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear && flag == 0; }//���鿩��
int is_full() { return front == rear && flag == 1; }//��ȭ����
int size()//���� ����� ���� ��
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

Element AddQue(Element val)//ť�� �� ����
{
	if (is_full())
		error("  ť ��ȭ ����");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
	if (rear == front && data[front])//rear�� front�� ���� �ش� �ڸ��� ���� ������
		flag = 1;
	return val;
}
Element DelQue()//ť���� �� ����
{
	if (is_empty())
		error("  ť ���� ����");
	front = (front + 1) % MAX_QUEUE_SIZE;
	if (rear == front && !data[front])//rear�� front�� ���� �ش� �ڸ��� ���� ������
		flag = 0;
	return data[front];
}
Element peek()
{
	if (is_empty())
		error("  ť ���� ����");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

// ť �׽�Ʈ�� ���� �ڵ�: ��� �������� ����
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
	print_queue("ť ���� ���");//N���� ��� ���������� ������� Ȯ��.
}