# -----------------------------------------
# Memoria inicial
# -----------------------------------------
memoria = {1: 0, 2: 1, 3: 1}


# -----------------------------------------
# Función auxiliar iterativa usada por top-down
# (corresponde a fibonacci_iterativo_v2 del cuaderno)
# -----------------------------------------
def fibonacci_iterativo_v2(n):
    if n <= 1:
        return n
    f_parciales = [0, 1]
    for i in range(2, n + 1):
        f_parciales.append(f_parciales[-1] + f_parciales[-2])
    return f_parciales[n]


# -----------------------------------------
# Función Top-Down con memorización
# -----------------------------------------
def fibonacci_top_down(numero):
    # Si el número ya está calculado, solo lo regresamos
    if numero in memoria:
        return memoria[numero]

    # Si no está calculado, se obtiene con la función auxiliar
    f = fibonacci_iterativo_v2(numero - 1) + fibonacci_iterativo_v2(numero - 2)

    # Lo guardamos en memoria
    memoria[numero] = f
    return memoria[numero]


# -----------------------------------------
# PRUEBAS DEL ALGORITMO
# -----------------------------------------

print("fibonacci_top_down(12) =", fibonacci_top_down(12))
print("Memoria después de consultar 12:", memoria)

print("fibonacci_top_down(8) =", fibonacci_top_down(8))
print("Memoria después de consultar 8:", memoria)


# -----------------------------------------
# Guardar memoria usando pickle
# -----------------------------------------
import pickle

archivo = open('memoria.p', 'wb')       # Abrir archivo en modo binario para escribir
pickle.dump(memoria, archivo)           # Guardar el diccionario memoria
archivo.close()                         # Cerrar archivo


# -----------------------------------------
# Leer memoria desde archivo
# -----------------------------------------
archivo = open('memoria.p', 'rb')       # Abrir archivo en modo binario para leer
memoria_de_archivo = pickle.load(archivo)
archivo.close()

print("Memoria leída desde archivo:", memoria_de_archivo)