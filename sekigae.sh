#!/bin/bash

### use 'GNU coreutils 8.4' at CentOS release 6.2

shuf -e "たけお" "きたけー" "ぐっさん" "おっくん" | tr '\n' '|' | sed -e 's/|$/\n/'
