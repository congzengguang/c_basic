#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	������ȡ���ֵ��
	������Ŀ�������
*/
int compareMax(int a,int b,int c) {
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}


/*
	��ȡ����֮�е����ֵ

*/

int getMaxValue(int *a,int length) {
	
	printf("\n����ĳ��ȣ�%d", length);
	int max = *a;
	for (int x = 1; x < length; x++) {
		if (*(a+x) > max) {
			max = *(a + x);
		}
	}

	printf("\n����֮�е����ֵ��%d",max);

	return max;
	
}


int main001() {
	//��������������Ԫ�ص�ַ��ͬ
	/*
		Ҳ����˵�������������ͳ��������Ԫ�صĵ�ַ

	*/
	int a[10];
	printf("����ĵ�ַ��%p, ������Ԫ�صĵ�ַ��%p",a,&a[0]);
	//�������ǳ����������޸ġ�

	//sizeof(a) ��ȡ������ܴ�С
	printf("\n����Ĵ�С:%d", sizeof(a));
	//��������Ĵ�С������ĵ���Ԫ�صĴ�С���Ի�ȡ����ĳ���

	int n = sizeof(a) / sizeof(int);
	printf("\n����ĳ��ȣ�%d",n);
	

	printf("\n������֮�е��������%d", compareMax(1, 3, 5));

	int c[] = { 1,3,4,5,6,8,10 };
	int n2 = sizeof(c) / sizeof(int);
	getMaxValue(c,n2);

	getchar();
	return 0;
}

/*
	����ķ�ת
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
	ð������
	�����ķź��棬Ҳ����˳������
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
	��γ����
	�ж���[]���ж���ά����
	�ڴ���û�ж�ά��ֻ��һά����ά�����������һά���顣
	����a[3][4] ����������һ��һά����a[3] ,���������Ԫ����a[4]��
	int a[3][4] = {{1,2,3,4},{2,3,4,5},{3,4,5,6}};
	1. a[0] a[1] a[2]  ���� 0�� 1��2Ԫ�ص���������
	2. ��ά�����������m��n�С�

*/

int main004() {
	//��ά����ĸ�ֵ��
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
	�ַ�����
	�ַ������ַ�����Ĺ�ϵ������ַ���������0����'\0'��β�ľ����ַ���

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
	���������

*/
int main006() {
	srand((unsigned int)time(NULL));

	printf("%d",rand());
	getchar();
	return 0;
}
/*
	�ַ���������

*/
int main007() {
	char buf[100] = {0};
	printf("�������ַ�����\n");
	scanf("%s", buf); //ȡ��һ���ո�֮ǰ���ַ���
	printf("��������ַ�����%s \n",buf);
	system("pause");
	return 0;
}
/*
	gets���������Ӽ��̶�ȡ�ַ������롣�����пո�
*/
int main008() {
	char buf[100];
	gets(buf);
	printf("��������ַ����ǣ�%s",buf);
	getchar();
	return 0;
	
}

/*
	��ȫ���õĶ�ȡ�ַ�������ĺ���fgets();


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
	��Ļ�������Ļ��puts();�Զ���ӻ��з���ʾЧ����ʵ���ϱ���û����ӻ��з���
*/
int main010() {
	char buf[] = "hello";
	puts(buf);//�л���
	printf("%s",buf);//�޻���
	system("pause");
	return 0;
}

/*
	strlen��sizeof������
*/

int main011() {
	char buf1[] = "hello";
	printf("buf1�ĳ��ȣ�%lu",strlen(buf1));
	char buf2[] = "\0hello";
	printf("\nbuf2�ĳ��ȣ�%lu",strlen(buf2));
	printf("\nbuf2�ĳ��ȣ�%lu sizeof",sizeof(buf2));


	system("pause");
	return 0;
}
/*
	����Ŀ���strcpy(dst,src);
*/
int main012() {
	char src[] = "hello hello ";
	char dst[100];
	strcpy(dst,src);
	printf("%s", dst);

	//����ԭ���ǣ�����Ԫ�ؿ�ʼ��������\0����
	char src2[] = "hello  \0 hello ";
	char dst2[100];
	strcpy(dst2, src2);
	printf("\n%s", dst2);  //ʵ�ʿ���ֻ������'\0'
	system("pause");
	return 0;
}

/*
	strncpy(dst,src,len);����������Կ���'\0' ����'\0'��������ݾ�����Ϊ���ˣ�Ҳ���ǲ��ɿ�����
*/
int main013() {
	char src[100] = "hello c language";
	char dst[100]="aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	strncpy(dst,src,strlen(src));
	printf("%s", dst);
	strncpy(dst, src, strlen(src) + 1);//�������������ݿ���˵���������Կ���'\0'
	printf("\n%s",dst);

	getchar();
	return 0;
}
/*
	�Ƚ��ַ����Ĵ�С��
*/
int main014() {

	char str1[] = "abc";
	char str2[] = "abcd";
	int flag = strcmp(str1, str2);
	if (flag > 0) {
		printf("str1 ����str2");
	}
	if (flag < 0) {
		printf("str1 С��str2");
	}
	//�������Ƚ�ǰ�����ַ��Ļ����� strncmp();

	getchar();
	return 0;
}

int main() {
	
}