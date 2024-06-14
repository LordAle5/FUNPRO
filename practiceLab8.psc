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
