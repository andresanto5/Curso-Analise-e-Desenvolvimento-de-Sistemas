#!/usr/bin/env python3

from cocktailSort import cocktailSort
from create_gif import *
from openWindow import *
import random




if __name__=='__main__':
	turns_off = False
	while turns_off == False:
		w = windowPython()
		newList = []
		n = int(w.Start())
		for i in range(n):
			newList.append(int(i))
		a =list(newList)
		random.shuffle(a)
		cocktailSort(a)
		criar_gif()
		if w.turnOff() =='yes':
			turns_off = True