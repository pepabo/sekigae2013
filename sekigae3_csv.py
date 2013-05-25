#!/usr/bin/env python
import random

items = [line[:-1].split(',') for line in open('namelist.csv', 'r')][0]
random.shuffle(items)
print(items)
