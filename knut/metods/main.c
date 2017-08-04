#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define rank 8

int X[55];
int Y[55];//[2]; //Y - Y[...][0]        X - Y[...][1]

void mass_set(){
    int i;
    for (i = 55; i > 0; i--){

        X[i] = i;
        Y[55-i]=X[i];
    }
}

int func(int M, int c, int a, int X0){
    int j = 24,
        k = 55;

    int     n=1,
            e   =   8;

    mass_set();

//адаптивный генератор чисел
//алгоритм А

    while (n<100){
        if (j==0){ j = 55; }

        if (k==0){ k = 55; }

        Y[k]=fmod((Y[k]+Y[j]),pow(2,e));

        //printf("%i      %i      %i\n",n, X[k] , Y[k] );
        --j;
        --k;
        ++n;
    }
}

#define TOP 16
int k = 7;
int Xn[TOP];
int Yn[TOP];
int V[TOP];//algoritm M page 45
int Xb[64];//algoritm B page 46
int Vb[64];
int Ja[TOP];

void randoms(){
    int b1 = 59,
		b2 = 57,
		c1 = 0,
		c2 = 1,
		mod_a = 256;
	int i,j;
    Xn[0]=102;
    Yn[0]=190;
    //конгруэнтный метод
    for (i=0;i<TOP;i++){
    	Xn[i+1] = fmod((Xn[i]*b1+c1),mod_a);
    	Yn[i+1] = fmod((Yn[i]*b2+c2),mod_a);
    }
    //алгоритм М
    //printf("i\tXn[i]\tj\tV[i]\tV[j]\n");
    for (i=0;i<TOP;i++){
        j=(int)((k*Yn[i])/(mod_a));
        Ja[i]=j;
        V[j]=Xn[i];
        //printf("%i\t%i\t%i\t%i\t%i\n",i,Xn[i],j,V[i],V[j] );
    }
    
    //алгоритм В
    //рандомизация перемешиванием
    for (i=0;i<63;i++){Xb[i]=Xn[i];}
    for (i=0;i<k;i++){Vb[i]=Xn[i];}
    int Yn1=Xn[k+1];
    for (i=0;i<63;i++){
        j=(int)((k*Yn1)/mod_a);
        //Vb[j]=Xb[i];
        Xb[i+1]=Vb[j];
    }
	i=0;
	int XYn[200];
	XYn[0] = 51;
	while (i<200){
		XYn[i+1] = fmod(((XYn[i]*27)+3),128);
		printf("%i\t%i\n",i,XYn[i]);
		//printf("\a");
		i++;
	}
/*
    printf("i\tXn[i]\tYn[i]\tV[i]\tJa[j]\tXYn[i]\n");
    for (i=0;i<TOP;i++){
        //printf("%i\t%i\t%i\t%i\t%i\t%i%i\t%i\t%i\n",i,Xn[i],Yn[i],V[i],Vb[j],Xb[i],X[i],Y[i] );
        printf("%i\t%i\t%i\t%i\t%i\t%i\n",i,Xn[i],Yn[i],V[i],Ja[j],XYn[i] );
    }*/
}

int main()
{
	//func(55,1,1,1);
    randoms();
    //randoms(Yn[0],5,1,8);
    
    //return 0;
}

