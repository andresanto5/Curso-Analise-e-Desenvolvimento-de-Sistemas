#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
plt.style.use('_mpl-gallery')

def makeplot(number_list, counter):
	color_list=[]
	for i in number_list:
		y = i
		if number_list[i]==i:
			color_list.append('red')
		else:
			color_list.append('black')
	# make data:
	#np.random.seed(3)
	x = 0.5 + np.arange(len(number_list))
	y = number_list
	
	# plot
	fig, ax = plt.subplots()
	
	ax.bar(x, y, width=1, edgecolor="white", color=color_list, linewidth=0.7)
	
	ax.set(xlim=(0, len(y)), xticks=np.arange(0, len(y)),
			ylim=(0, len(y)), yticks=np.arange(0, len(y)))
	
	nome = '{}{}'.format(counter,'.png')
	plt.savefig(nome, dpi=200)