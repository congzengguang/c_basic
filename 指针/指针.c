#include <stdio.h>

/*
	1.内存以一个字节为单位分配内存
	2.每个字节都有地址，也就是指针。
	3.地址需要存储，32位编译器用32位（4字节）存此地址。
	64位编译器用64位（8字节）存此地址。

	编码
	寻址

	4.指针指向谁，就把谁的地址赋值给指针。
*/

int main001() {
	int a = 10;
	//两个指针指向同一块内存。
	int *p = &a;
	int *q = p;
	*p = 111;
	printf("*p = %d, a = %d, *p=%d", *p,a,*q);
	getchar();
	return 0;
}
/*
	野指针，指针变量指向一个没有意义的内存地址，也就是说非法的地址。
	只有定义后的变量的地址才是合法的地址。
*/
int main002() {
	int *p = 0x1122;
	*p = 100;
	getchar();

	return 0;
}

/*
	空指针：
	给指针变量赋值为NULL
	NULL就是数字0

*/
int main003() {
	int a = 10;
	int* p =NULL;
	if (p == NULL) {
		p = &a;
	}

	printf("%p,%d", p,a);

	getchar();
	return 0;
}
/*
	指针大小
	32位操作系统，用32位存储指针地址，也就是4字节。
	64位操作系统，用64位存储指针地址，也就是8字节。
*/
int main004() {
	
	printf("\n指针的大小：%d", sizeof(char *));
	printf("\n指针的大小：%d",sizeof(int *));

	getchar();
	return 0;
}

/*
	多级指针
	如果定义一个合适的变量存储另一个变量的地址
	在需要保存的变量地址的类型基础上加一个*
	
*/
int main005() {
	int a = 1;
	int *p = &a;
	int **pp = &p;
	printf("一级指针的地址：%p,指针变量的值 %p,指针指向的值，%d",&p,p,*p);
	printf("\n二级指针的地址：%p,指针变量的值：%p,指针指向的值，%p,变量a的值：%d",&pp,pp,*pp,*(*pp));

	getchar();
	return 0;
}
/*
	int *p;
	
	*p = *(p+0) = p[0]
	
*/
int main006() {
	

	int a = 10;
	int *p = &a;
	printf("*p =  %d", *p);
	printf("\n*p =  %d", p[0]);
	printf("\n*p =  %d", *(p+0));

	getchar();
	return 0;
}
/*
万能指针 ： void *
不可以定义普通的void类型的普通变量，因为不能分配类型，编译器不知道分配多大的内存空间。
可以定义void* 的变量，void*指针也叫万能指针。
void * 可以指向任何类型的指针变量。

*/
int main007() {

	return 0;
}
/*

	指针变量
	指针所指向的空间

*/
int main008() {
	//下面这两种方式的声明是等价的。
	const int  *p = NULL;
	int const *p2 = NULL;
	int a = 10;
	p = &a;
	//const 修饰的是* 表示指针所指向的内存是只读的。
	//*p = 100
	//下面的定义表示指针变量的值是只读。
	int * const p3 = NULL;

	//即修饰*,又修饰变量的话，表示指针所指向的空间和指针都不可更改，也就是只读的。
	const int * const p4 = NULL;
	return 0;
}
/*
	指针和数组
	一维数组，
	数组名是首元素的地址；
	数组名是常量，不允许修改。

*/
int main009() {
	
	int a[] = {1,2,3,4,5,6,7,8,9,10,12};
	int *p = a;
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("\n%d", *(p+i));
	}
	getchar();
	return 0;
}

/*
	
	指针数组，他是数组，每个元素都是指针。
	数组指针，它是指针，指向数组的指针。
*/

int main010() {
	//指针数组，就是一个数组
	int a[] = {1,2,3};
	int *p[3];
	p[0] = a;
	p[1] = a + 1;
	p[2] = a + 2;
	for (int i = 0; i < 3; i++) {
		printf("%d,\n",*(p[i]));
	}

	getchar();

	return 0;
}

void swap(int *a,int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap2(int a, int b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}
/*
	值传递，函数的修改不会影响到实际参数。

*/
int main011() {
	
	int a = 10, b = 20;
	swap(&a,&b);
	printf("a = %d ,b = %d",a,b); //a = 20 ,b =10
	swap2(a,b);
	printf("\na = %d ,b = %d", a, b);//a = 20 ,b =10
	getchar();
	return 0;
}
void sort_array(int a[]) {
	int n = sizeof(a) / sizeof(a[0]);
	printf("数组长度：%d\n",n);
	int i = 0, j = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - j; j++) {
			if (a[j] > a[j + 1]) {
				int temp;
				temp = a[j];
				a[j] = a[j+1];
				a[j + 1] = temp;
			}
		}
	}
}

void print_array(int a[]) {
	int len = sizeof(a) / sizeof(a[0]);
	printf("数组长度：%d\n", len);
	for (int x = 0; x < len; x++) {
		printf("%d\n",a[x]);
	}
}

/*
	形参中的数组不是数组，是一个指针。
	以下三种形式完全等价。
	void print_array(int *a);
	void print_array(int a[]);
	void print_array(int a[100]);
*/
int main012() {
	int a[] = {1,2,-1,-5,3,4,7,8,10};
	//实际上并没有打印出所有的元素，这时数组在形参的时候，是指针变量，导致求出的元素个数错误。
	//所以解决方案就是，传递数组元素的个数。
	print_array(a);
	sort_array(a);
	print_array(a);

	getchar();
	return 0;
}

/*
	字符串常量
	每个字符串都是一个地址,这个地址是字符串的首元素的地址。

*/
int main013() {

	printf("字符串：%s\n","hello");
	printf("字符串：%p\n","hello");
	printf("字符串：%s\n", "hello"+1); //可以验证字符串就是首元素地址。
	getchar();

	return 0;
}
/*
	在｛｝内部定义的变量就是局部变量
	static局部变量实在编译阶段就已经分配内存空间，函数没有调用之前，就已经存在。
	当离开｛｝，static局部变量不会释放，只有在程序结束，static变量才会自动释放。
	局部变量的作用域在当前的{},离开｛｝无法使用此变量。
	不同的｛｝中，变量名可以一样，可以把｛｝比作房子，不同的房子可以有同名的小伙伴。
	static局部变量的初始化语句只会执行一次，但是可以赋值多次。

	普通局部变量和static局部变量的区别：
		
*/

void fun() {
	int i = 0;
	printf("i=%d\n",i);
	i++;
}

void static_fun() {
	static int i = 0;
	printf("i=%d\n", i);
	i++;
}
int main014() {
	fun();
	fun();
	fun();
	static_fun();
	static_fun();
	static_fun();
	getchar();
	return 0;
}

/*
	
	全局变量
	在｛｝外面定义的变量为全局变量。
	只要定义了全局变量，任何地方都能使用此变量。
	如果使用此变量时，在前面找不到此变量的定义，需要声明才能使用。
	全局变量不初始化，默认赋值为0
	全局变量只能定义一次，可以声明多次。
	全局变量在编译阶段已经分配空间（函数没有执行前），只有在整个程序结束，才自动释放。
*/

extern int a;
void method2() {
	printf("a的值：%d\n",a);
}

int a = 10;
void method() {
	a = 11;
}


int main015() {
	
	method();
	method2();

	system("pause");
	return 0;
}

/*
	static全局变量：
	static全局变量和普通的全局变量的区别就是作用域（文件）。
	extern关键字只适用于普通全局变量的声明。
	一个文件只能有一个static全局变量的定义， 一个文件不能出现多个。多个文件及时static变量名相同也没有关系。
	static全局变量只能在当前文件使用。
*/

int main016() {

}

/*
	普通函数和static函数
	所有文件只能有一次普通函数定义。
	一个文件可以有一个static函数定义。
	普通函数，所有文件都能用，static函数只有本文件能用。
*/

int main() {

	getchar();
	return 0;
}