#!/bin/bash

# using only built-in functions, no external command

newcomers=("okkun" "keoken" "kitak" "gussan")

n_newcomers=${#newcomers[@]}

for ((i=0; i<$n_newcomers; i++)); do
  n=$(($RANDOM % $n_newcomers))

  tmp=${newcomers[$n]}
  newcomers[$n]=${newcomers[$i]}
  newcomers[$i]=$tmp
done

echo "${newcomers[@]}"
