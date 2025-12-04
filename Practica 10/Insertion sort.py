def insertionSort(n_lista):
    for index in range(1,len(n_lista)):
        actual = n_lista[index]
        posicion = index
        print("valor a ordenar = {}".format(actual))
        while posicion>0 and n_lista[posicion-1]>actual:
            n_lista[posicion]=n_lista[posicion-1]
            posicion = posicion-1
        n_lista[posicion]=actual
        print(n_lista)
    return n_lista

lista = [21, 10, 0, 11, 9, 24, 20, 14, 1]
print("Lista desordenada {}".format(lista))
insertionSort(lista)
print("Lista ordenada {}".format(lista))