#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	三个数取最大值。
	利用三目运算符。
*/
int compareMax(int a,int b,int c) {
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}


/*
	获取数组之中的最大值

*/

int getMaxValue(int *a,int length) {
	
	printf("\n数组的长度：%d", length);
	int max = *a;
	for (int x = 1; x < length; x++) {
		if (*(a+x) > max) {
			max = *(a + x);
		}
	}

	printf("\n数组之中的最大值：%d",max);

	return max;
	
}


int main001() {
	//数组名和数组首元素地址相同
	/*
		也就是说，数组名被解释成数组的首元素的地址

	*/
	int a[10];
	printf("数组的地址：%p, 数组首元素的地址：%p",a,&a[0]);
	//数组名是常量，不能修改。

	//sizeof(a) 获取数组的总大小
	printf("\n数组的大小:%d", sizeof(a));
	//根据数组的大小和数组的单个元素的大小可以获取数组的长度

	int n = sizeof(a) / sizeof(int);
	printf("\n数组的长度：%d",n);
	

	printf("\n三个数之中的最大数：%d", compareMax(1, 3, 5));

	int c[] = { 1,3,4,5,6,8,10 };
	int n2 = sizeof(c) / sizeof(int);
	getMaxValue(c,n2);

	getchar();
	return 0;
}

/*
	数组的反转
*/

int main002() {
	int a[] = {1,3,5,6,7,8,9,0};
	for (int x = 0; x < sizeof(a) / sizeof(int); x++) {
		printf("\n%d", a[x]);
	}
	printf("\n--------------------------------------");
	int i = 0;
	int j = sizeof(a) / sizeof(int) -1;

	while (i < j) {
		int temp = 0;
		temp = *(a + i);
		*(a + i) = *(a + j);
		*(a + j) = temp;
		i++;
		j--;
	}

	for (int x = 0; x < sizeof(a) / sizeof(int); x++) {
		printf("\n%d",a[x]);
	}
	getchar();
	return 0;
}
/*
	冒泡排序
	将最大的放后面，也就是顺序排序。
*/
int main003() {
	int a[] = {10,30,6,1,-1,2,-2,4,5};
	int i = 0;
	int j = 0;
	int n = sizeof(a) / sizeof(int);
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp;
				temp = a[j];
				a[j] = a[j+1];
				a[j + 1] = temp;
			}
		}
	}

	for (int x = 0; x < n; x++) {
		printf("%d\n",a[x]);
	}

	system("pause");
	return 0;
}


/*
	二纬数组
	有多少[]就有多少维数组
	内存中没有多维，只有一维，多维数组是特殊的一维数组。
	例如a[3][4] 可以理解成有一个一维数组a[3] ,里面的三个元素是a[4]。
	int a[3][4] = {{1,2,3,4},{2,3,4,5},{3,4,5,6}};
	1. a[0] a[1] a[2]  就是 0， 1，2元素的数组名。
	2. 二维数组可以理解成m行n列。

*/

int main004() {
	//二维数组的赋值。
	int a[3][4];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = i + j;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d\n",a[i][j]);
		}
	}


	system("pause");
}

/*
	字符数组
	字符串和字符数组的关系：如果字符数组是以0或者'\0'结尾的就是字符串

*/

int main005() {
	
	printf("\n%d",'0');
	printf("\n%c",0);
	printf("\n%c",'\0');
	
	char c[] = {'a','b','c','\0'};
	printf("\n%s",c);

	getchar();

	return 0;
}
/*
	产生随机数

*/
int main006() {
	srand((unsigned int)time(NULL));

	printf("%d",rand());
	getchar();
	return 0;
}
/*
	字符串的输入

*/
int main007() {
	char buf[100] = {0};
	printf("请输入字符串：\n");
	scanf("%s", buf); //取第一个空格之前的字符串
	printf("你输入的字符串：%s \n",buf);
	system("pause");
	return 0;
}
/*
	gets（）函数从键盘读取字符串输入。可以有空格
*/
int main008() {
	char buf[100];
	gets(buf);
	printf("您输入的字符串是：%s",buf);
	getchar();
	return 0;
	
}

/*
	安全可用的读取字符串输入的函数fgets();


*/

int  main009() {
	char buf[10];
	fgets(buf,sizeof(buf),stdin);
	printf("\n");
	printf("%s",buf);

	getchar();
	system("pause");
	return 0;
}
/*
	屏幕输出到屏幕，puts();自动添加换行符显示效果。实际上变量没有添加换行符。
*/
int main010() {
	char buf[] = "hello";
	puts(buf);//有换行
	printf("%s",buf);//无换行
	system("pause");
	return 0;
}

/*
	strlen和sizeof的区别
*/

int main011() {
	char buf1[] = "hello";
	printf("buf1的长度：%lu",strlen(buf1));
	char buf2[] = "\0hello";
	printf("\nbuf2的长度：%lu",strlen(buf2));
	printf("\nbuf2的长度：%lu sizeof",sizeof(buf2));


	system("pause");
	return 0;
}
/*
	数组的拷贝strcpy(dst,src);
*/
int main012() {
	char src[] = "hello hello ";
	char dst[100];
	strcpy(dst,src);
	printf("%s", dst);

	//拷贝原理是，从首元素开始，拷贝到\0结束
	char src2[] = "hello  \0 hello ";
	char dst2[100];
	strcpy(dst2, src2);
	printf("\n%s", dst2);  //实际拷贝只拷贝到'\0'
	system("pause");
	return 0;
}

/*
	strncpy(dst,src,len);这个函数可以拷贝'\0' 但是'\0'后面的数据就无能为力了，也就是不可拷贝。
*/
int main013() {
	char src[100] = "hello c language";
	char dst[100]="aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	strncpy(dst,src,strlen(src));
	printf("%s", dst);
	strncpy(dst, src, strlen(src) + 1);//从这个输出的内容看，说明函数可以拷贝'\0'
	printf("\n%s",dst);

	getchar();
	return 0;
}
/*
	比较字符串的大小，
*/
int main014() {

	char str1[] = "abc";
	char str2[] = "abcd";
	int flag = strcmp(str1, str2);
	if (flag > 0) {
		printf("str1 大于str2");
	}
	if (flag < 0) {
		printf("str1 小于str2");
	}
	//如果打算比较前几个字符的话，用 strncmp();

	getchar();
	return 0;
}

int main() {
	
}