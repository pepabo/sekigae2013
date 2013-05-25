#!/usr/bin/env python
import random

items = [line[:-1] for line in open('namelist.txt', 'r')]
random.shuffle(items)
print(items)
