#include <stdio.h>

/*
	1.�ڴ���һ���ֽ�Ϊ��λ�����ڴ�
	2.ÿ���ֽڶ��е�ַ��Ҳ����ָ�롣
	3.��ַ��Ҫ�洢��32λ��������32λ��4�ֽڣ���˵�ַ��
	64λ��������64λ��8�ֽڣ���˵�ַ��

	����
	Ѱַ

	4.ָ��ָ��˭���Ͱ�˭�ĵ�ַ��ֵ��ָ�롣
*/

int main001() {
	int a = 10;
	//����ָ��ָ��ͬһ���ڴ档
	int *p = &a;
	int *q = p;
	*p = 111;
	printf("*p = %d, a = %d, *p=%d", *p,a,*q);
	getchar();
	return 0;
}
/*
	Ұָ�룬ָ�����ָ��һ��û��������ڴ��ַ��Ҳ����˵�Ƿ��ĵ�ַ��
	ֻ�ж����ı����ĵ�ַ���ǺϷ��ĵ�ַ��
*/
int main002() {
	int *p = 0x1122;
	*p = 100;
	getchar();

	return 0;
}

/*
	��ָ�룺
	��ָ�������ֵΪNULL
	NULL��������0

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
	ָ���С
	32λ����ϵͳ����32λ�洢ָ���ַ��Ҳ����4�ֽڡ�
	64λ����ϵͳ����64λ�洢ָ���ַ��Ҳ����8�ֽڡ�
*/
int main004() {
	
	printf("\nָ��Ĵ�С��%d", sizeof(char *));
	printf("\nָ��Ĵ�С��%d",sizeof(int *));

	getchar();
	return 0;
}

/*
	�༶ָ��
	�������һ�����ʵı����洢��һ�������ĵ�ַ
	����Ҫ����ı�����ַ�����ͻ����ϼ�һ��*
	
*/
int main005() {
	int a = 1;
	int *p = &a;
	int **pp = &p;
	printf("һ��ָ��ĵ�ַ��%p,ָ�������ֵ %p,ָ��ָ���ֵ��%d",&p,p,*p);
	printf("\n����ָ��ĵ�ַ��%p,ָ�������ֵ��%p,ָ��ָ���ֵ��%p,����a��ֵ��%d",&pp,pp,*pp,*(*pp));

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
����ָ�� �� void *
�����Զ�����ͨ��void���͵���ͨ��������Ϊ���ܷ������ͣ���������֪����������ڴ�ռ䡣
���Զ���void* �ı�����void*ָ��Ҳ������ָ�롣
void * ����ָ���κ����͵�ָ�������

*/
int main007() {

	return 0;
}
/*

	ָ�����
	ָ����ָ��Ŀռ�

*/
int main008() {
	//���������ַ�ʽ�������ǵȼ۵ġ�
	const int  *p = NULL;
	int const *p2 = NULL;
	int a = 10;
	p = &a;
	//const ���ε���* ��ʾָ����ָ����ڴ���ֻ���ġ�
	//*p = 100
	//����Ķ����ʾָ�������ֵ��ֻ����
	int * const p3 = NULL;

	//������*,�����α����Ļ�����ʾָ����ָ��Ŀռ��ָ�붼���ɸ��ģ�Ҳ����ֻ���ġ�
	const int * const p4 = NULL;
	return 0;
}
/*
	ָ�������
	һά���飬
	����������Ԫ�صĵ�ַ��
	�������ǳ������������޸ġ�

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
	
	ָ�����飬�������飬ÿ��Ԫ�ض���ָ�롣
	����ָ�룬����ָ�룬ָ�������ָ�롣
*/

int main010() {
	//ָ�����飬����һ������
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
	ֵ���ݣ��������޸Ĳ���Ӱ�쵽ʵ�ʲ�����

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
	printf("���鳤�ȣ�%d\n",n);
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
	printf("���鳤�ȣ�%d\n", len);
	for (int x = 0; x < len; x++) {
		printf("%d\n",a[x]);
	}
}

/*
	�β��е����鲻�����飬��һ��ָ�롣
	����������ʽ��ȫ�ȼۡ�
	void print_array(int *a);
	void print_array(int a[]);
	void print_array(int a[100]);
*/
int main012() {
	int a[] = {1,2,-1,-5,3,4,7,8,10};
	//ʵ���ϲ�û�д�ӡ�����е�Ԫ�أ���ʱ�������βε�ʱ����ָ����������������Ԫ�ظ�������
	//���Խ���������ǣ���������Ԫ�صĸ�����
	print_array(a);
	sort_array(a);
	print_array(a);

	getchar();
	return 0;
}

/*
	�ַ�������
	ÿ���ַ�������һ����ַ,�����ַ���ַ�������Ԫ�صĵ�ַ��

*/
int main013() {

	printf("�ַ�����%s\n","hello");
	printf("�ַ�����%p\n","hello");
	printf("�ַ�����%s\n", "hello"+1); //������֤�ַ���������Ԫ�ص�ַ��
	getchar();

	return 0;
}
/*
	�ڣ����ڲ�����ı������Ǿֲ�����
	static�ֲ�����ʵ�ڱ���׶ξ��Ѿ������ڴ�ռ䣬����û�е���֮ǰ�����Ѿ����ڡ�
	���뿪������static�ֲ����������ͷţ�ֻ���ڳ��������static�����Ż��Զ��ͷš�
	�ֲ��������������ڵ�ǰ��{},�뿪�����޷�ʹ�ô˱�����
	��ͬ�ģ����У�����������һ�������԰ѣ����������ӣ���ͬ�ķ��ӿ�����ͬ����С��顣
	static�ֲ������ĳ�ʼ�����ֻ��ִ��һ�Σ����ǿ��Ը�ֵ��Ρ�

	��ͨ�ֲ�������static�ֲ�����������
		
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
	
	ȫ�ֱ���
	�ڣ������涨��ı���Ϊȫ�ֱ�����
	ֻҪ������ȫ�ֱ������κεط�����ʹ�ô˱�����
	���ʹ�ô˱���ʱ����ǰ���Ҳ����˱����Ķ��壬��Ҫ��������ʹ�á�
	ȫ�ֱ�������ʼ����Ĭ�ϸ�ֵΪ0
	ȫ�ֱ���ֻ�ܶ���һ�Σ�����������Ρ�
	ȫ�ֱ����ڱ���׶��Ѿ�����ռ䣨����û��ִ��ǰ����ֻ��������������������Զ��ͷš�
*/

extern int a;
void method2() {
	printf("a��ֵ��%d\n",a);
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
	staticȫ�ֱ�����
	staticȫ�ֱ�������ͨ��ȫ�ֱ�������������������ļ�����
	extern�ؼ���ֻ��������ͨȫ�ֱ�����������
	һ���ļ�ֻ����һ��staticȫ�ֱ����Ķ��壬 һ���ļ����ܳ��ֶ��������ļ���ʱstatic��������ͬҲû�й�ϵ��
	staticȫ�ֱ���ֻ���ڵ�ǰ�ļ�ʹ�á�
*/

int main016() {

}

/*
	��ͨ������static����
	�����ļ�ֻ����һ����ͨ�������塣
	һ���ļ�������һ��static�������塣
	��ͨ�����������ļ������ã�static����ֻ�б��ļ����á�
*/

int main() {

	getchar();
	return 0;
}