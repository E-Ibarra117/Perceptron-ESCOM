#include<stdio.h>

int x1[4]={0,0,1,1}, x2[4]={0,1,0,1}, output[4]={0,0,0,1};     //patrones de entrada y salida AND
float w1=1, w2=0, theta=0.5;                               //definicion de pesos y sesgo

//suma ponderada de las entradas y el sesgo
float WeightedSum(int x1, int x2, float w1, float w2, float theta){
    return x1*w1 + x2*w2 + theta;
}

//función de activación heavyside
int activationFun(float x){
    if(x>=0)
        return 1;
    else
        return 0;
}

//calculo de error
int Error(int res,int real){
    return real - res;
}


int main(){
    int e=0, obt=0, i=0;
    int errors=0;
    
    while(i<4){ //iteracion sobre las salidas
    obt = activationFun(WeightedSum(x1[i],x2[i],w1,w2,theta)); //resultado perceptron
    e = Error(obt,output[i]);
        if(e!=0){ //contar errores y reportar
            errors++;
            printf("error[%d] in pos [%d %d] expected: %d got: %d err: %d\n",errors,x1[i],x2[i],output[i],obt,e);
        }

    i++;
    }
    printf("Num errors: %d",errors); //total errores

}


