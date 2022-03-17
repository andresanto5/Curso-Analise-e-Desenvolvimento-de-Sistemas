#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from frames import gera_frames


filename = []
def binary_search(array, item, comeco=0, fim=None, cont=1):
	y= len(array)//2
	limite = len(array)
	if fim == None: #Definir o tamanho final do array
		fim = len(array)-1
	if comeco <= fim: 
		m = (comeco + fim)// 2 #Define o meio do array
		contador= cont
		a = gera_frames(m, y, 'black', limite, limite, contador)
		if array[m] == item: #Quando item a ser procurado for igual a posição do vetor
			a = gera_frames(m, y, 'red', limite, limite, contador) #gera o frame final
			return a
			
		if item < array[m]:
			contador= contador +1
			return binary_search(array, item, comeco, m-1, contador)#Chama a função novamente para a esquerda
		else:
			contador= contador +1
			return  binary_search(array, item, m+1, fim, contador) #Chama a função novamente para a direita
		
	return None