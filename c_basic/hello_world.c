#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define PARAM 10

//很多语言都基于c语言
/*
c语言的特点：
	简洁性 32个关键字，9个控制语句，34个运算符

c语言的版本，最常用的是c89 ，最新的是c11

c语言编译器有很多种
	微软 vs
	gcc
	clang


变量
常量


原码  ：二进制位
补码  ：二进制添加符号位
反码  ：符号位不变，其他位取反。

正数的原码和反码是一样的。

解决负数的存储。

计算机存储数字是以补码的方式存储的。最主要解决了负数的存储。

*/

void pointorname() {
	int a;
	a = 10;
	a = 11;
	//extern 是声明不是定义。没有定义就没有空间，没有空间就不能赋值。
	/*extern int b;
	b = 12;*/
	printf("%d",a);
}


/*
	一个数字对应一个字符。
	内存中只有数字，没有字符。
	使用字符或者数字给字符变量赋值，是等价的。
	字符本质上就是一个字节一个字节的整型。
*/
void chartest() {
	char a = 'a';
	a = 97;
	printf("%c", a);
	printf("\n");
	printf("%d", a);
	//打印常量
	const int c = 20;//常量是只读的，不可修改。
	printf("常量param %d", PARAM);
}

/*
	在屏幕上输出
*/

void standioout() {
	//输出一个百分号
	printf("%%");
	printf("%%d \n");
	//输出一个变量的地址：
	int a = 10;
	printf("变量的地址：%p",&a);
	printf("\n");
	//以五个字符输出，默认右对齐。
	printf("输出含有空白字符的输出：'%5d'", a);

	printf("\n以五个字符输出，默认右对齐，以0补充，'%05d'",a);

	//以五个字符填充，-表示左对齐
	printf("\n，'%-5d'", a);
}


void scanftest() {
	int a, b;
	printf("\n请输入a b");
	printf("\n");
	scanf("%d %d", &a, &b);
	printf("\n");
	printf("a = %d , b = %d", a, b);

	//打印字符
	//由于scanf函数的读取，读取一个字符，读取之后，还有个‘\n’在缓冲区，
	//第二个scanf函数就读取了这个'\n'字符，就会出现不让输入直接跳过的现象。
	char temp;
	scanf("%c",&temp);
	char c;
	printf("\n请输入字符:");
	scanf("%c",&c);
	printf("c = %c", c);
	
}


void getchartest() {
	char a;
	a = getchar();//读取键盘字符放在变量a中
	printf("a = %d", a);
}

void putchartest() {
	char a = 'a';
	putchar(a);
}
/*
后置++ ，先用后加
前置++ ，先加后用
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