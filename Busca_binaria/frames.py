#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt

def gera_frames(valor_x, valor_y, cor, limite_X, limite_Y, cont):
	x = valor_x
	y = valor_y
	# Condições para o tamanho do ponto
	if valor_x <= 100:
		sizes = valor_x
	else:
		sizes = (valor_x)//10
	colors = cor
	fig, ax = plt.subplots()
	# Comando para adicionar o valor da busca em cima do ponto mostrado
	ax.annotate(valor_x, ((valor_x-(valor_x/15)), (limite_Y/1.8)))
	ax.scatter(x,y, s=sizes, c=colors, vmin=0, vmax=limite_X)
	ax.set(xlim=(0,limite_X), xticks=np.arange(0, limite_X+(limite_X*10)//100, (limite_X*10)//100),
			ylim=(0,limite_Y), yticks=np.arange(0, limite_Y+(limite_Y*10)//100, (limite_X*10)//100))
	contador = cont
	nome = '{}{}'.format(contador,'.png')
	plt.savefig(nome, dpi=200)
	return None
