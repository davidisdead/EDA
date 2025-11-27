# Variables globales y locales
vg = 10  # variable global

def funcion():
    vl = 5   # variable local
    print("Variable local:", vl)
    print("Variable global:", vg)

funcion()
print("Global fuera de función:", vg)
