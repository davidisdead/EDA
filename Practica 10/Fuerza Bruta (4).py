from string import ascii_letters , digits
from itertools import product

#concatenar letras y dígitos en una sola cadena
caracteres = ascii_letters+digits

def buscador(con):

    #archivo con todas las combinaciones generadas
    archivo = open("combinacionescar4.txt", "w")

    if 3<= len(con) <= 4:
        for r in range(4,5):
            for comb in product(caracteres, repeat = 4):
                #Se utiliza join() para concatenar los caracteres regresados por la función product().
                #Como join necesita una cadena inicial para hacer la concatenación, se pone una cadena vacía
                #al principio
                prueba = "".join(comb)
                #Escribiendo al archivo cada combinación generada
                archivo.write(prueba + "\n")
                if prueba == con:
                    print("Tu contraseña es {}".format(prueba))
                    #Cerrando el archivo
                    archivo.close()
                    return
    else:
        print("Ingresa una contraseña que contenga de 3 a 4 caracteres")      
from time import time
t0 = time()
con = "h0l4"
buscador(con)
print("Tiempo de ejecución {}".format(round(time()-t0, 6)))