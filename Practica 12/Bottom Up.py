def fibonacci_bottom_up(numero):
    f_parciales = [0, 1, 1]   # Esta es la lista que mantiene las soluciones previamente calculadas
    while len(f_parciales) < numero:
        f_parciales.append(f_parciales[-1] + f_parciales[-2])
        print(f_parciales)
    return f_parciales[numero - 1]

fibonacci_bottom_up(5)