Algoritmo imparesLeidos
	//Creamos unavariable llamada centinela que me indicará cuando seguir o parar
	//como por lo menos se dará una iteracion tiene valor de verdadero
	centinela<-Verdadero
	contadorImpares<-0
	
	Mientras (centinela) Hacer
		Escribir "Ingrese el numero impar: "
		Leer num
		
		si (num mod 2=0) Entonces
			centinela<-Falso
		SiNo
			contadorImpares <- contadorImpares +1
		FinSi
	FinMientras
	
	Escribir "La cantidad de numeros impares leidos es ",contadorImpares
	
FinAlgoritmo
