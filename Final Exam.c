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






#include <stdio.h>

int validarDatos(int min,int max);
void mostrarNumerosRectilineos(int min, int max);
void verificarNumeroRectilineo(int num,int *cumple,int *paso);
int main (){
	int min,max,datosOk;
	printf("Ingrese el rango de numeros: ");
	scanf("%d %d",&min,&max);
	
	datosOk=validarDatos(min,max);
	if(datosOk){
		mostrarNumerosRectilineos(min,max);
	}
	else{
		printf("Rango incorrecto\n");
	}
	
	return 0;
}

int validarDatos(int min,int max){
	return min>99 && min<max;
}

void mostrarNumerosRectilineos(int min, int max){
	int i,cont=0,paso,cumple,pasoMenor,numMenor;
	i=min;
	while(i<=max){
		
		verificarNumeroRectilineo(i,&cumple,&paso);
		if(cumple){
			printf("numero: %d - paso: %d\n",i,paso);
			cont++;
			
			if(cont==1){
				numMenor=i;
				pasoMenor=paso;
			}
			else{
				if(paso<=pasoMenor){
					numMenor=i;
					pasoMenor=paso;
				}
			}
		}
		i++;
	}
	printf("En el rango [%d %d] hay %d numeros rectilineos\n",min,max,cont);
	if(cont>0){
		printf("El mayor numero rectilineo con la progresion aritmetica menor es %d - paso: %d\n",numMenor,pasoMenor);
	}
	
}

void verificarNumeroRectilineo(int num,int *cumple,int *paso){
	int dig,digAnt,i=0,difDig;
	
	*cumple=1;
	while(num>0){
		dig=num%10;
		num=num/10;
		
		
		if(i==1){
			difDig=digAnt - dig;
			*paso=difDig;
		}
		else{
			if(i>1){
				if(!(digAnt-dig==difDig)){
					*cumple=0;
				}
			}
		}
		
		i++;
		digAnt=dig;
	}
}
