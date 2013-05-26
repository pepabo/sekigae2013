#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import unicode_literals
from __future__ import print_function
import random


def main():
    name_list = [
        'おっくん',
        'きたけー',
        'たけお',
        'ぐっさん'
    ]

    random.shuffle(name_list)

    for i, name in enumerate(name_list):
        print(i, name)

if __name__ == '__main__':
    main()
