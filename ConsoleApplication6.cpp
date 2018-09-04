#include<stdio.h>
#include <stdlib.h>
/**打印99乘法表*/
int main()
{
	int i, j;

	for (i = 1; i<10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d  ", j, i, j*i);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

//打印出所有的“水仙花”数。所谓“水仙花”数是指一个3位数，其各个位数字立方和等于该数本身。

#include<stdio.h>

int main()
{
	int n = 100, a, b, c, d;

	do
	{
		c = n / 100;
		a = n % 10;
		b = (n - c * 100 - a) / 10;
		d = a*a*a + b*b*b + c*c*c;
		if (n == d)
		{
			printf("%d\n", n);
		}
		n++;
	} while (n<1000);

	return 0;
}


//c语言实现简单选择排序。

#include<stdio.h>

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int b, c, i, j, n;

	n = sizeof(a) / sizeof(int);
	for (i = 0; i < n - 1; i++)
	{
		c = a[i];
		for (j = i + 1; j<n; j++)
		{
			if (c < a[j])
			{
				b = c;
				c = a[j];
				a[j] = b;
			}
		}
		a[i] = c;
	}
	for (i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}


//C语言冒泡法排序

#include<stdio.h>

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int b, c, i, j, n;

	n = sizeof(a) / sizeof(int);
	for (i = 0; i < n - 1; i++)
	{
		c = a[i];
		for (j = i + 1; j<n; j++)
		{
			if (c < a[j])
			{
				b = c;
				c = a[j];
				a[j] = b;
			}
		}
		a[i] = c;
	}
	for (i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}


//C语言利用指针实现strcmp功能

#include<stdio.h>
#include<string.h>

int my_strcmp(char *a, char *b);

int main()
{
	char a[] = "abcde";
	char b[] = "abcde";

	printf("use    strcmp = %d\n", strcmp(a, b));
	printf("use my_strcmp = %d\n", my_strcmp(a, b));

	return 0;
}

int my_strcmp(char *a, char *b)
{
	int r = 0;
	while (*a != '\0' || *b != '\0')
	{
		r = *a - *b;
		if (r != 0)
		{
			return r;
		}
		a++;
		b++;
	}
	return r;
}


//C语言用函数实现strlen功能

#include<stdio.h>
#include<string.h>

int my_strlen(char * p);

int main()
{
	char s[] = "hello!";
	int l;

	l = my_strlen(s);

	printf("   use strlen=%lu\n", strlen(s));
	printf("no use strlen=%d\n", l);

	return 0;
}

int my_strlen(char * p)
{
	int n = 0;

	while (*p != '\0')
	{
		n++;
		p++;
	}

	return n;
}

//
//编写strcat函数(不调用C的字符串库函数，编写函数 strcat).
//
//已知strcat函数的原型是 char *strcat(char *strDest, const char *strSrc);
//strDest是目的字符串，strSrc是源串。

#include<stdio.h>
#include<string.h>

char *my_strcat(char *p, char *q);

int main()
{
	char s1[100] = "so  ";
	char c1[100] = "so  ";
	char s2[] = "many!";
	char c2[] = "many!";

	puts(my_strcat(s1, s2));
	strcat(c1, c2);
	puts(c1);

	return 0;
}

char *my_strcat(char *p, char *q)
{
	char *a, *b;

	a = p;
	b = q;

	while (*a != '\0')
	{
		a++;
	}
	while (*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	*a = *b;

	return p;
}



//2. 已知两个升序数组a、b及空数组c:
//
//Int a[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
//Int b[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
//Int c[20];
//编写程序将两个数组完成归并，并存入数组c中；

#include<stdio.h>

int *paixua(int *a, int *b, int a1, int b1, int *c);

int main()
{
	int a[] = { 1, 2, 4, 7 }, a1 = sizeof(a) / sizeof(int);
	int b[] = { 2, 3, 5, 8, 10, 12 }, b1 = sizeof(b) / sizeof(int);
	int c[a1 + b1], c1 = a1 + b1, i, *p;

	p = paixua(a, b, a1, b1, c);
	for (i = 0; i<c1; i++)
	{
		printf("%d\n", c[i]);
	}
	puts("");
	return 0;
}


int *paixua(int *a, int *b, int a1, int b1, int *c)
{
	int *r = c, *p = c;
	int i, j = a1 + b1, aa = 0, bb = 0;

	for (i = 0; i<j; i++)                //最大比较次数
	{
		if (*a <= *b && aa<a1)          //取a数组靠前较小的数给c
		{
			*p = *a;
			a++;
			p++;
			aa++;
		}
		if (aa == a1)                    //如果a数组先取完跳出循环
		{
			break;
		}
		if (*a>*b && bb<b1)             //取b数组靠前较小的数给c
		{
			*p = *b;
			b++;
			p++;
			bb++;
		}
		if (bb == b1)                //如果b数组先取完跳出循环
		{
			break;
		}
	}
	while (aa != a1)                 //如果a数组没有取完,剩下的元素给c数组
	{
		*p = *a;
		p++;
		aa++;
		a++;
	}
	while (bb != b1)             //如果b数组没有取完,剩下的元素给c数组
	{
		*p = *b;
		p++;
		bb++;
		b++;
	}

	return r;               //返回c数组起始地址
}