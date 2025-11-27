# Calculadora
print("---Calculadora---")
print("1- Sumar")
print("2- Restar")
print("3- Multiplicar")
print("4- Dividir")
print("5- Salir")

op = int(input("Opción: "))

if op == 1:
    a = int(input("a: "))
    b = int(input("b: "))
    print("Resultado:", a + b)

elif op == 2:
    a = int(input("a: "))
    b = int(input("b: "))
    print("Resultado:", a - b)

elif op == 3:
    a = int(input("a: "))
    b = int(input("b: "))
    print("Resultado:", a * b)

elif op == 4:
    a = int(input("a: "))
    b = int(input("b: "))
    print("Resultado:", a / b)

elif op == 5:
    print("Saliendo...")
else:
    print("Opción inválida")
