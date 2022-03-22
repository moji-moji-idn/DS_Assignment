#pragma warning (disable : 4996)
#include <stdio.h>
#define MAX(a,b) ((a>b)?(a):(b))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

void printPoly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		if (!p.coef[p.degree - i]) continue;
		printf("%3.1lfx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1lf\n", p.coef[p.degree]);
}
polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

int main() {
	polynomial A = { 3, {0, 5, 3, 4} };
	polynomial B = { 4, {1, 2, 0, 1, 3} };
	polynomial C;
	C = addPoly(A, B);
	printf("\n A(x)="); 
	printPoly(A);
	printf("\n B(x)=");
	printPoly(B);
	printf("\n C(x)=");
	printPoly(C);
	getchar();
}
