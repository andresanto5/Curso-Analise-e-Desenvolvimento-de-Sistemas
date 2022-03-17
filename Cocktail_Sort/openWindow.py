#!/usr/bin/env python3

import PySimpleGUI as sg 
from cocktailSort import cocktailSort
from create_gif import *
import random

class windowPython:
	def __init__(self):
		sg.change_look_and_feel('DarkAmber')
		#Layout
		layout = [
			[sg.Text('*** Bem-Vindo ao Cocktail Sort ***', font='Courier 18')],
			[sg.Image('cocktail.jpeg', size=(300,300), pad=(50,0))],
			[sg.Text('Qual o tamanho da lista? ', font='Courier 18'), sg.Input(size=(5,0), key='number', font='Courier 18')],
			[sg.Text('Deseja continuar? ', font='Courier 18')],
			[sg.Radio('Sim', 'continued', key='no', font='Courier 18'), sg.Radio('Não', 'continued', key='yes', font='Courier 18')],
			[sg.Button('Submit')],
			
		]
		#window
		self.readWindow = sg.Window('Data Cocktail Sort').layout(layout)
	
	def Start(self):
			#Extract screen data
			self.button, self.values = self.readWindow.Read()
			numbers = self.values['number']
			
			return numbers
	def turnOff(self):
		self.button, self.values = self.readWindow.Read()
		on = self.values['no']
		off = self.values['yes']
		if on == True:
			dec = 'no'
		else:
			dec = 'yes'
		return dec

