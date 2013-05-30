#!/usr/bin/env python
import random
import sys
import fileinput

argvs = sys.argv
argc = len(argvs)

items = []
if argc == 1:
    items = [line[:-1] for line in open('namelist.csv', 'r')]
else:
    items = [line[:-1] for line in fileinput.input()]

random.shuffle(items)
print(items)
