#!/usr/bin/env python
import csv
import numpy as np
import matplotlib.pyplot as plt

x_0 = []
y_0 = []
x_1 = []
y_1 = []

with open('data/25cities.csv', 'rb') as csvfile:
	spamreader = list(csv.reader(csvfile))
	spamreader = spamreader[1:]
	for row in spamreader:
		x_0.append(row[0])
		y_0.append(row[1])

with open('data/25cities_A.csv', 'rb') as csvfile:
	spamreader = list(csv.reader(csvfile))
	spamreader = spamreader[1:]
	for row in spamreader:
		x_1.append(row[0])
		y_1.append(row[1])

plt.subplot(211)
plt.scatter(x_0, y_0)
plt.title("25cities")

plt.subplot(212)
plt.scatter(x_1, y_1)
plt.title("25cities_A")

plt.show()