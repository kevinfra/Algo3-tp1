import math
import numpy as np
import matplotlib.pyplot as plt
import pylab
import sys

# Antes de usar esto, tirar en consola "./tp1 2 -exp > resEj2.txt". CUIDADO CON PISAR EL ARCHIVO ANTERIOR

arr = np.genfromtxt("resEj2.txt")
x = [row[0] for row in arr]
y = [row[1] for row in arr]


def promedio(list):
   return sum(list)/len(list)

def moda(list):
  res = []
  k = 0
  while k < len(list):
    actual = list[k:k+49]
    actual.sort()
    repeticiones = 0
    for i in actual:
      apariciones = actual.count(i)
      if apariciones > repeticiones:
          repeticiones = apariciones
    modas = []
    for i in actual:
      apariciones = actual.count(i)
      if apariciones == repeticiones and i not in modas:
          modas.append(i)
    k += 50
    res.append(modas)
  return res

def mediana(list):
  k = 0
  res = []
  while k < len(list):
    subList = list[k:k+50]
    subList.sort()
    n = 50
    res.append((subList[24] + subList[25] )/2)
    k += 50
  return res


k = 0
listaPromedio = []
listaPesas = []
while k < len(x):
  subList = x[k:k+1000]
  listaPromedio.append(promedio(subList))
  listaPesas.append(y[k])
  k += 1000




promedioNP = np.array(listaPromedio)
pesasNP = np.array(listaPesas)



# medianaX  = mediana(x)
# modaX     = moda(x)

fig = plt.figure()
fig.patch.set_facecolor('white')
ax1 = fig.add_subplot(111)
pylab.plot(listaPesas, promedioNP,'ro', label= 'Resultados Ejercicio 2')


ax1.set_title("Pesas de potencias de 3")
ax1.set_xlabel('Tiempo de procesamiento en ns')
ax1.set_xscale('linear')
ax1.set_ylabel('Peso de la llave')
ax1.set_yscale('linear')

leg = ax1.legend()

leg = plt.legend( loc = 'upper right')

plt.show()
