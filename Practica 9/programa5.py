# Diccionarios
dic = {
    "Hidrogeno": 1,
    "Helio": 2,
    "Carbon": 6
}

print(dic)
print(dic["Helio"])

dic["Oxigeno"] = 8
print(dic)

for elemento in dic:
    print(elemento, dic[elemento])
