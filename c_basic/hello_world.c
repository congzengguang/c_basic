#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define PARAM 10

//�ܶ����Զ�����c����
/*
c���Ե��ص㣺
	����� 32���ؼ��֣�9��������䣬34�������

c���Եİ汾����õ���c89 �����µ���c11

c���Ա������кܶ���
	΢�� vs
	gcc
	clang


����
����


ԭ��  ��������λ
����  ����������ӷ���λ
����  ������λ���䣬����λȡ����

������ԭ��ͷ�����һ���ġ�

��������Ĵ洢��

������洢�������Բ���ķ�ʽ�洢�ġ�����Ҫ����˸����Ĵ洢��

*/

void pointorname() {
	int a;
	a = 10;
	a = 11;
	//extern ���������Ƕ��塣û�ж����û�пռ䣬û�пռ�Ͳ��ܸ�ֵ��
	/*extern int b;
	b = 12;*/
	printf("%d",a);
}


/*
	һ�����ֶ�Ӧһ���ַ���
	�ڴ���ֻ�����֣�û���ַ���
	ʹ���ַ��������ָ��ַ�������ֵ���ǵȼ۵ġ�
	�ַ������Ͼ���һ���ֽ�һ���ֽڵ����͡�
*/
void chartest() {
	char a = 'a';
	a = 97;
	printf("%c", a);
	printf("\n");
	printf("%d", a);
	//��ӡ����
	const int c = 20;//������ֻ���ģ������޸ġ�
	printf("����param %d", PARAM);
}

/*
	����Ļ�����
*/

void standioout() {
	//���һ���ٷֺ�
	printf("%%");
	printf("%%d \n");
	//���һ�������ĵ�ַ��
	int a = 10;
	printf("�����ĵ�ַ��%p",&a);
	printf("\n");
	//������ַ������Ĭ���Ҷ��롣
	printf("������пհ��ַ��������'%5d'", a);

	printf("\n������ַ������Ĭ���Ҷ��룬��0���䣬'%05d'",a);

	//������ַ���䣬-��ʾ�����
	printf("\n��'%-5d'", a);
}


void scanftest() {
	int a, b;
	printf("\n������a b");
	printf("\n");
	scanf("%d %d", &a, &b);
	printf("\n");
	printf("a = %d , b = %d", a, b);

	//��ӡ�ַ�
	//����scanf�����Ķ�ȡ����ȡһ���ַ�����ȡ֮�󣬻��и���\n���ڻ�������
	//�ڶ���scanf�����Ͷ�ȡ�����'\n'�ַ����ͻ���ֲ�������ֱ������������
	char temp;
	scanf("%c",&temp);
	char c;
	printf("\n�������ַ�:");
	scanf("%c",&c);
	printf("c = %c", c);
	
}


void getchartest() {
	char a;
	a = getchar();//��ȡ�����ַ����ڱ���a��
	printf("a = %d", a);
}

void putchartest() {
	char a = 'a';
	putchar(a);
}
/*
����++ �����ú��
ǰ��++ ���ȼӺ���
*/
void plusplustest() {
	int a = 10;
	//a++;
	printf("%d", a++);
	putchar('\n');
	int b = 20;
	//++b;
	printf("%d", ++b);
}

void main() {
	//pointorname();

	//chartest();

	//standioout();

	//scanftest();

	//getchartest();
	//putchartest();

	plusplustest();
	getchar();
	getchar();
}