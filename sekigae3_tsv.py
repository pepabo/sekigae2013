#!/usr/bin/env python
import random

items = [line[:-1].split('\t') for line in open('namelist.tsv', 'r')][0]
random.shuffle(items)
print(items)
