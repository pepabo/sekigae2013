#!/usr/bin/env python
import random
import sys
import fileinput

argvs = sys.argv
argc = len(argvs)

items = []
if argc == 1:
    items = [line[:-1].split('\t') for line in fileinput.input(files='namelist.csv')][0]
else:
    items = [line[:-1].split('\t') for line in fileinput.input()][0]
random.shuffle(items)
print(items)
