Algoritmo FormandoNumeros
	
	Escribir "Ingrese la cantidad de pares de numeros que desea procesar"
	Leer num_pares
	
	si(num_pares>0) Entonces
		i<-1
		Mientras (i<=num_pares)
			
			Escribir "Ingrese el primer numero: "
			Leer primerNum
			Escribir "Ingrese el segundo numero:"
			Leer segundoNum
			
			si(primerNum>0 y segundoNum>0) Entonces
				nuevoNumFormado<-0
				contador <-1
				Mientras (primerNum>0 o segundoNum>0)
					
					Si(segundoNum>0)Entonces
						digito2<-segundoNum mod 10
						nuevoNumFormado <- nuevoNumFormado + digito2*contador
						segundoNum<-trunc(segundoNum/10)
						contador <- contador*10
					FinSi
					
					si (primerNum>0) Entonces
						cant_Dig <- trunc((ln(primerNum))/ (ln(10))) +1
						digito1 <- trunc(primerNum/(10^(cant_Dig-1)))
						nuevoNumFormado <- nuevoNumFormado + digito1*contador
						primerNum<- primerNum mod (10^(cant_Dig-1))
						contador <- contador*10
					FinSi
					
				FinMientras
				
				Escribir "El nuevo nuemero foramdo es: ",nuevoNumFormado
			SiNo
				Escribir "Al menos uno de los numeros ingresados no es mayor que 0"
			FinSi
			si(i=1) Entonces
				mayorNum <- nuevoNumFormado
			SiNo
				si(nuevoNumFormado>mayorNum) Entonces
					mayorNum<-nuevoNumFormado
					
				FinSi
			FinSi
			i<-i+1
			
		FinMientras
		Escribir "",mayorNum
	SiNo
		Escribir "La cantidad de pares debe ser mayor que 0"
	FinSi
	
FinAlgoritmo




Algoritmo numerosCapicuasRestriccion
	Escribir "Ingrese la cantidad de pares de numeros que desea procesar"
	Leer num_par
	Si(num_par>0) Entonces
		Escribir "Ingrese el valor maximo de diferencia entre cifras consecutivas"
		Leer valor_maximo
		si(valor_maximo>0) Entonces
			i<-1
			Mientras (	i<= num_par)
				Escribir "Ingrese el primer numero: "
				Leer primerNumero
				Escribir "Ingrese el segundo numero: "
				Leer segundoNumero
				
				Si(primerNumero >0 y segundoNumero>0 y primerNumero	<100000 y segundoNumero<1000000) Entonces
					contador<-1
					nuevoNum<-0
					Mientras (primerNumero>0 o segundoNumero>0)
						si(primerNumero>0) Entonces
							digito1<-primerNumero mod 10
							nuevoNum <- nuevoNum + digito1*contador
							primerNumero<-trunc(primerNumero/10)
							contador<-contador*10
							
						FinSi
						
						si(segundoNumero>0) Entonces
							digito2<-segundoNumero mod 10
							nuevoNum <- nuevoNum + digito2*contador
							segundoNumero<-trunc(segundoNumero/10)
							contador<-contador*10
							
						FinSi
					FinMientras
					Escribir "",nuevoNum
					nuevoNumAux<-0
					contadorAux<-0
					Mientras(nuevoNum>0)
						
						digitos<-nuevoNum mod 10
						nuevoNumAux<- nuevoNumAux*10 + digitos
						nuevoNum<-trunc(nuevoNum/10)
						contadorAux<-contadorAux +1
						
					FinMientras
					contador2<-0
					n_num <-0
					Mientras (nuevoNumAux>0)
						cifra1 <- nuevoNumAux mod 10
						nuevoNumAux<- trunc(nuevoNumAux/10)
						cifra2 <- nuevoNumAux mod 10
						nuevoNumAux <- trunc(nuevoNumAux/10)
						resta <-abs(cifra1 - cifra2)
						
						Si (resta > valor_maximo) Entonces
							n_num<- n_num + cifra1*(10^(2*contador2)) + cifra2*(10^(2*contador2 +1))
							contador2<-contador2 +1
						FinSi
						
						Escribir "",n_num
					FinMientras
					
				
				SiNo
					Escribir "Debe ingresar numero positivos maximo de cinco cifras"
				FinSi
				
				
				i<- i+1
			FinMientras
		sino
			Escribir "El valor maximo de diferencia debe ser mayor de 0"
		FinSi
		
		
	sino 
		Escribir "La cantidad de pares debe ser mayor que 0"
	FinSi
	
FinAlgoritmo
