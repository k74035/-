#include <stdio.h>

//포인터 변수

int main() {

	char* px;
	int* py;
	double* pz;

	px = (char*)1000;
	py = (int*)100;
	pz = (double*)10;

	printf("%d %d %d\n", px, py, pz);
	px++;
	py++;
	pz++;
	printf("%d %d %d\n", px, py, pz);

	printf("px+1 =%d, py + 1 =%d, pz + 1= %d", px + 1, py + 1, pz + 1);
	return 0;
}


#include <stdio.h>

//참조에 의한 호출 1) Char형 변수 x, y의 값을 교환할 수 있는 함수를 call by value로 구현하기

void swap(int x, int y);

int main()
{
	char x = 2;
	char y = 4;

	printf("%d %d\n", x, y);
	printf("스왑 이후\n");
	swap(x, y);
	printf("%d %d", x, y);

	return 0;

}

void swap(int x, int y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;

}
#include <stdio.h>

#include <stdio.h>

//참조에 의한 호출 1) Char형 변수 x, y의 값을 교환할 수 있는 함수를 call by reference로 구현하기

void swap(int* px, int* py);

int main()
{
	char x = 2;
	char y = 4;

	printf("%d %d\n", x, y);
	printf("스왑 이후\n");
	swap(&x, &y);
	printf("%d %d", x, y);



	return 0;

}

void swap(int* px, int* py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;

}

#include <stdio.h>

//참조에 의한 호출 2)Double형 배열 개수가 15인 변수 a, b를 교환할 수 있는 함수를 call by reference로 구현하기

void swap(double* px, double* py);


void swap(double* px, double* py)
{
	int i;
	double tmp[15];

	for (i = 0; i < 15; i++)
	{
		tmp[i] = px[i];
		px[i] = py[i];
		py[i] = tmp[i];
	}
}

int main(void)
{
	double a[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	double b[15] = { 14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };

	double* pa;
	double* pb;

	pa = a;
	pb = b;

	swap(pa, pb);

	int x;
	for (x = 0; x <= 14; x++)
	{
		printf("%f\n", a[x]);
	}

	int y;
	for (y = 0; y <= 14; y++)
	{
		printf("%f\n ", b[y]);
	}
}


#include <stdio.h>

//참조에 의한 호출 3) Int형 배열 개수가 10인 변수 a의 합을 구하여 결과를 리턴하는 함수를 call by reference로 구현하기

int sum(int* p);

int main()
{
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p;
	p = array;
	printf("%d", sum(array));
}
int sum(int* p)
{
	int i = 0;
	int result = 0;

	for (i = 0; i < 10; i++)
		result += p[i];


	return result;
}

#include <stdio.h>

//재귀호출 함수 1) 1~n까지의 합 계산 • Sum(3)은 3 + sum(2)


int sum(int x);

int main()
{
	int n = 0;
	printf("정수를 입력하시오");
	scanf("%d", &n);
	printf("%d", sum(n));

}
int sum(int x)
{
	if (x >= 0)
		return x + sum(x - 1);
	else return 0;
}

#include <stdio.h>

//재귀호출 함수 2) 1/1 + ½ + 1/3 + … 1/n 을 계산 • Return 1.0 / n + sum(n - 1)


double sum(int x);

int main()
{
	int n = 0;
	printf("정수를 입력하시오");
	scanf("%d", &n);
	printf("%lf", sum(n));

}
double sum(int x)
{
	if (x != 0)
		return 1.0 / x + sum(x - 1);
	else return 0;
}

#include <stdio.h>

//재귀호출 함수 3) 팩토리얼 계산


int factorial(int x);

int main()
{
	int n = 0;
	printf("정수를 입력하시오");
	scanf("%d", &n);
	printf("%d", factorial(n));

}
int factorial(int x)
{
	if (x != 0)
		return x * factorial(x - 1);

}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{int factorial(int x)
{
	if (x >= 1)
		return x * factorial(x - 1);
	else return 1;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


 /* 구조체
• 구조체배열을 선언하여 여러 학생의 정보를 입력받고 평균 점수, 최고점수,
최저점수를 각각 구하는 함수를 작성
• 구조체 멤버는 int id, char name[20], double grade 로 구성
• 구조체 배열 크기 3으로 선언
• Scanf로 값을 받는 방법과 초기화를 하는 방법 두가지 모두 해보기
• 구조체 배열을 함수 인자로 전달
• 평균점수 반환하는 함수 구현
• 최고와 최저점수를 구하여 함수의 인자를 통해 결과를 돌려주는 함수 구현
• 결과를 받아서 평균, 최고, 최저점수 출력
*/

#include <stdio.h>
#define SIZE 3

struct student()
{
	int id;
	char name[20];
	double grade;
};

int high_score();
int low_score();
int average;

int main()
{
	struct student list[SIZE];
	int i = 0;

	for (i = 0; i < SIZE; i++)
	{
		printf("학번을 입력하시오: ");
		scanf("%d", &list[i].number);
		printf("이름을 입력하시오: ");
		scanf("%s", list[i].name);
		printf("학점을 입력하시오(실수): ");
		scanf("%lf", &list[i].grade);
	}
	for (i = 0; i < SIZE; i++)
		printf("학번: %d, 이름: %s, 학점: %f\n", list[i].number, list[i].name, list[i].grade);

	printf("최고 성적 = %d", high_score(&list[0], &list[1], &list[2]));
	printf("최저 성적 = %d", low_score(&list[0], &list[1], &list[2]));
	printf("평균 성적 = %d", average(&list[0], &list[1], &list[2]));

	return 0;


}

int high_score(struct student list[0], struct student list[1], struct student list[2])
{
	int i = 0;
	int max = list[0].grade;

	for (i = 0; i < 3; i++)
		if (list[i].grade > max)
			max = list[i].grade;
	return max;

}

int low_score(struct student list[0], struct student list[1], struct student list[2])
{
	int i = 0;
	int mim = list[0].grade;

	for (i = 0; i < 3; i++)
		if (list[i].grade < mim)
			mim = list[i].grade;
	return mim;

}
int average(struct student list[0], struct student list[1], struct student list[2])
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < 3; i++)
		sum *= list[i].grade;
	return sum / 3;



	/* 2차원배열
• 학생들의 성적 기록표를 2차원 배열에 저장하고 각 학생의 최종 성적을
계산하기
• 최종성적 : 중간고사 30 % +기말고사 40 % +기말과제 20 % +퀴즈점수 10 % +결석횟수
감점
	*/

#include<stdio.h>
#define ROWS 3
#define COLS 5

	int main()
	{
		int a[ROWS][COLS] = { { 87, 98, 80, 76, 3 },
	{ 99, 89, 90, 90, 0 },
	{ 65, 68, 50, 49, 0 }
		};

		int i;
		double final_scores = 0;
		for (i = 0; i < ROWS; i++)
		{
			final_scores = a[i][0] * 0.3 + a[i][1] * 0.4 +
				a[i][2] * 0.2 + a[i][3] * 0.1 - a[i][4];
			printf("학생 % d 의 최종성적 = % 10.2f \n", i + 1, final_scores);
		}
		return 0;
	}


