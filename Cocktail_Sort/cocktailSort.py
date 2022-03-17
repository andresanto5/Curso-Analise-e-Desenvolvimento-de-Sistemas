#!/usr/bin/env python3

from barPlot import makeplot

def cocktailSort(number_list):
	counter = 1
	pos1 = len(number_list)-1
	pos2 = len(number_list)-2
	for j in range(len(number_list)):
		for i in range(len(number_list)-1):
			if number_list[pos1 - i] < number_list[pos2 - i]:
				number_list[pos1-i],number_list[pos2-i] = number_list[pos2-i],number_list[pos1-i]
				makeplot(number_list, counter)
				counter +=1
			if number_list[i] > number_list[i+1]:
				number_list[i],number_list[i+1] = number_list[i+1],number_list[i]
				makeplot(number_list, counter)
				counter +=1
	return None