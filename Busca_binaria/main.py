#!/usr/bin/env python3

from frames import gera_frames
from search import binary_search
from create_gif import criar_gif
import glob

if __name__=='__main__':
	
	desliga = False
	while desliga is False:
		lista = []
		item = eval(input('Qual o valor que você quer buscar? '))
		limite = eval(input('Qual o limite máximo de números nessa busca? '))
		for i in range(0,limite):
			lista.append(i)
		b_binaria = binary_search(lista, item)
		criar_gif()
		
		continua = eval(input("Resultado pronto!\nDeseja fazer uma nova busca? (digite: 1 para continuar ou 2 para desligar): "))
		if continua == 1:
			desliga = False
		else:
			print("Programa Desligado!")
			desliga = True