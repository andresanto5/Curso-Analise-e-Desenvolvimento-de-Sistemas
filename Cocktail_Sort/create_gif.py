#!/usr/bin/env python3

from PIL import Image
import glob
	
def criar_gif():
	#Criar uma lista com todas as imagens
	imgs = glob.glob("*.png")
	
	# Função para extrair apenas o número
	def extNum(elem):
		return elem[:-4]
	
	# Lista temporária para receber os números
	lista_temp = []
	
	# Laço para extrair os números e colocar na lista temporária
	for i in imgs:
		lista_temp.append(int(extNum(i)))
		
	# Ordenar a lista temporária
	lista_temp.sort()
	
	# Adicionar os valores com a extenção '.png' para a lista imgs já ordenada
	imgs = []
	for i in lista_temp:
		b = '{}{}'.format(i,'.png')
		imgs.append(b)
		
	# Criar o gif
	frames = [Image.open(image) for image in imgs]
	frame_one = frames[0]
	frame_one.save("cocktailSort.gif", format="GIF", append_images=frames,
					save_all=True, duration=300, loop=0)