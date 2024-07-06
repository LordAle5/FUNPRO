#include <stdio.h>
#include <math.h>

int validarDatos(int min, int max);
int verificarSihayDufiniano(int numero);
int calcularMCD(int suma,int numero);
void encontrarMayor(int cantNumeros,int min,int max,int *mayor,int *minMayor,int *maxMayor);

int main(){
	
	int min,max,datosOk,hayDuffiniano,cantNumeros,i,mayor=0,minMayor,maxMayor;
	while(1){
		
		printf("Ingrese el rango: ");
		scanf("%d %d",&min,&max);
		
		if(min==0 && max==0){
			break;
		}
		
		datosOk=validarDatos(min,max);
		
		if(datosOk){
			cantNumeros=0;
			i=min;
			while(i<=max){
				hayDuffiniano=verificarSihayDufiniano(i);
				if(hayDuffiniano){
					cantNumeros++;
					if(cantNumeros==1){
						printf("En el rango existen los siguientes numeros duffinianos:\n");	
					}
					printf("%d ",i);
					
				}
				i++;
			}
			if(cantNumeros==0){
				printf("\nEn el rango no se encontraron numeros duffinianos:\n");
			}
			else{
				printf("\nEn el rango [%d %d] se encontraron %d numeros duffinianos \n",min,max,cantNumeros);
				encontrarMayor(cantNumeros,min,max,&mayor,&minMayor,&maxMayor);
			}
			
		}
		else{
			printf("El rango ingresado no es valido\n");
		}
	}
	if(mayor!=0){
		printf("\nEn el rango [%d %d] se encontro la mayor cantidad de numeros duffinianos. \n",minMayor,maxMayor);
	}
	return 0;
}

int validarDatos(int min, int max){
	
	return (min>0 && max>0 && min<max);
}
 
int calcularMCD(int suma,int numero){
	int resto;
	while(numero!=0){
		resto=suma%numero;
		suma=numero;
		numero=resto;
	}
	
	return suma;
}

int verificarSihayDufiniano(int numero){
	int divisor=1,cantDivisores=0,suma=0,mcd;
	
	while(divisor<=numero){
		if(numero%divisor==0){
			suma=suma + divisor;
			cantDivisores++;
		}
		divisor++;
	}
	if(cantDivisores<=2){
		return 0;
	}
	
	mcd=calcularMCD(suma,numero);
	return mcd==1;
}

void encontrarMayor(int cantNumeros,int min,int max,int *mayor,int *minMayor,int *maxMayor){
	if(cantNumeros >= (*mayor)){
		(*mayor)=cantNumeros;
		(*minMayor)=min;
		(*maxMayor)=max;
	}
	
}

