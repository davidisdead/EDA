def cambio(cantidad, denominaciones):
    resultado = []
    while (cantidad > 0):
        if (cantidad >= denominaciones[0]):

            num = cantidad // denominaciones[0]
            cantidad = cantidad - (num * denominaciones[0])
            resultado.append([denominaciones[0], num])
            denominaciones = denominaciones[1:] #Se va consumiendo la lista de denominaciones

    return resultado
print(cambio(1000, [500, 200, 100, 50, 20, 5, 1]))

print(cambio(500, [500, 200, 100, 50, 20, 5, 1]))

print(cambio(300, [50, 20, 5, 1]))

print(cambio(200, [5]))

print(cambio(98, [50, 20, 5, 1]))