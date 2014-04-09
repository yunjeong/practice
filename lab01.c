
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef struct proposition{

	int size;
	int* value;

} Prop;

int conjunctionValue(int x, int y); 
int disjunctionValue(int x, int y);
int exDisjunctionValue(int x, int y); 
int negationValue(int x); 
int implicationValue(int x, int y); 
int doubleImplicationValue(int x, int y); 

void conjunction(Prop* x, Prop* y, Prop* r); 
void disjunction(Prop* x, Prop* y, Prop* r); 
void exDisjunction(Prop* x, Prop* y, Prop* r); 
void negation(Prop* x, Prop* r); 
void implication(Prop* x, Prop* y, Prop* r); 
void doubleImplication(Prop* x, Prop* y, Prop* r); 

int logicalEquivalence(Prop* lhs, Prop* rhs); 

void main(int argc, char* argv[]) {

	int cnt=0;

	Prop* p = (Prop*)malloc(sizeof(Prop));
	Prop* q = (Prop*)malloc(sizeof(Prop));
	Prop* r = (Prop*)malloc(sizeof(Prop));
	Prop* lhs = (Prop*)malloc(sizeof(Prop));
	Prop* rhs = (Prop*)malloc(sizeof(Prop));

	p->size = 4;
	q->size = p->size;
	r->size = p->size;
	rhs->size = p->size;
	lhs->size = p->size;

	p->value = (int*)malloc(sizeof(int)*p->size);
	q->value = (int*)malloc(sizeof(int)*p->size);
	r->value = (int*)malloc(sizeof(int)*p->size);;
	rhs->value = (int*)malloc(sizeof(int)*p->size);
	lhs->value = (int*)malloc(sizeof(int)*p->size); // 구조체 마다 메모리 공간 할당

	p->value[0] = TRUE;
	p->value[1] = TRUE;
	p->value[2] = FALSE;
	p->value[3] = FALSE;

	q->value[0] = TRUE;
	q->value[1] = FALSE;
	q->value[2] = TRUE;
	q->value[3] = FALSE;

	conjunction(p, q, lhs);
	conjunction(q, p, rhs);

	printf("<<Propositional Logic Examiner>>\n");
	printf("\tLHS\t\tRHS\n");
	printf("\t-----\t\t-----\n");

	for(cnt=0; cnt<p->size; cnt++){
		printf("\t%d\t\t%d\n", lhs[cnt], rhs[cnt]);
	}

	if(logicalEquivalence(lhs,rhs)==1)
		printf("Logical equivalence between two proposition is True\n");
	else
		printf("Logical equivalence between two proposition is FALSE\n");

	free(p);
	free(q);
	free(r);
	free(lhs);
	free(rhs);

	free(p->value);
	free(q->value);
	free(r->value);
	free(rhs->value);
	free(lhs->value);

}



int conjunctionValue(int x, int y){

	return x&y;
}											// AND 연산

int disjunctionValue(int x, int y){

	return x|y;
}											// OR 연산

int exDIsjunctionValue(int x, int y){

	if(x == 1 && y == 1){
		return FALSE;
	}
	else if(x == 0 && y == 0){
		return FALSE;
	}
	else
		return TRUE;
}											

int negationValue(int x){

	if(x == 1){
		return FALSE;
	}
	else
		return TRUE;
}

int implicationValue(int x, int y){

	if(x == 1){
		if(y == 1){
			return TRUE;
		}
		else
			return FALSE;

	}
	else
		return TRUE;
}

int doubleImplicationValue(int x, int y){

	if(x == 1 && y == 1){
		return TRUE;
	}
	else if( x == 0 && y == 0){
		return TRUE;
	}
	else
		return FALSE;
}

void conjunction(Prop* x, Prop* y, Prop* r){

	int cnt = 0;

	for(cnt=0; cnt<x->size; cnt++){

		r->value[cnt] = conjunctionValue(x->value[cnt],y->value[cnt]);
	}
}													

void disjunction(Prop* x, Prop* y, Prop* r){

	int cnt = 0;

	for(cnt=0; cnt<x->size; cnt++){

		r->value[cnt] = disjunctionValue(x->value[cnt],y->value[cnt]);
	}
}

void exDisjunction(Prop* x, Prop* y, Prop* r){

	int cnt = 0;

	for(cnt=0; cnt<x->size; cnt++){

		r->value[cnt] = exDisjunctionValue(x->value[cnt],y->value[cnt]);
	}
}

void negation(Prop* x, Prop* r){

	int cnt = 0;

	for(cnt=0; cnt<x->size; cnt++){

		r->value[cnt] = negationValue(x->value[cnt]);
	}
}

void implication(Prop* x, Prop* y, Prop* r){

	int cnt = 0;

	for(cnt=0; cnt<x->size; cnt++){

		r->value[cnt] = implicationValue(x->value[cnt],y->value[cnt]);
	}
}

void doubleImplication(Prop* x, Prop* y, Prop* r){

	int cnt = 0;

	for(cnt=0; cnt<x->size; cnt++){

		r->value[cnt] = doubleImplicationValue(x->value[cnt],y->value[cnt]);
	}
}

int logicalEquivalence(Prop* lhs, Prop* rhs){

	int cnt = 0;

	for(cnt=0; cnt<lhs->size; cnt++){
		if(lhs->value[cnt] == rhs->value[cnt]){
			return 1;
		}
		else
			return 0;
	}
}


