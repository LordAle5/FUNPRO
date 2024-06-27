#include <stdio.h>
void evaluarNumeros(int primerNum, int segundoNum,int *datosOk, int *esCapicua);
int validarDatos(int primerNum,int segundoNum);

int main(){
	
	int centinela=1,primerNum,segundoNum,datosOk,esCapicua;
	
	while(centinela){
		
		printf("Ingrese el par de numeros : ");
		scanf("%d %d", &primerNum,&segundoNum);
		if(primerNum==0 && segundoNum==0){
			break;
		}
	
		evaluarNumeros(primerNum,segundoNum,&datosOk,&esCapicua);
		if(datosOk){
			if(esCapicua){
				printf("Los numeros %d y %d en conjunto forman un numero capicua\n",primerNum,segundoNum);

			}
			else{
				printf("Los numeros %d y %d en conjunto no forman un numero capicua\n",primerNum,segundoNum);
			}
	
		}
		else{
			printf("Alguno de los datos ingresados no son correctos\n");
		}
	}
	return 0;
}

void evaluarNumeros(int primerNum, int segundoNum,int *datosOk, int *esCapicua){
	
	*datosOk=validarDatos(primerNum,segundoNum);
	*esCapicua=evaluarCapicua(primerNum,segundoNum);
	
}

int validarDatos(int primerNum,int segundoNum){
	return (primerNum>0 && segundoNum>0);
}

int evaluarCapicua(int primerNum, int segundoNum){
	
	
	
}
