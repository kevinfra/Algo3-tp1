import math
import numpy as np
import matplotlib.pyplot as plt
import pylab
import sys

# Antes de usar esto, tirar en consola "./tp1 2 > resEj2.txt". CUIDADO CON PISAR EL ARCHIVO ANTERIOR

arr = np.genfromtxt("resEj2.txt")
x = [row[0] for row in arr]
y = [row[1] for row in arr]



fig = plt.figure()
fig.patch.set_facecolor('white')
ax1 = fig.add_subplot(111)
pylab.plot(x,y,'ro', label= 'Resultados Ejercicio 2')


ax1.set_title("Pesas de potencias de 3")
ax1.set_xlabel('Tiempo de procesamiento en ns')
ax1.set_xscale('log', basex=2)
ax1.set_ylabel('Peso de la llave')
ax1.set_yscale('linear')

leg = ax1.legend()

leg = plt.legend( loc = 'upper right')

plt.show()
