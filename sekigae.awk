# Usage
#  echo おっくん きたけー たけお ぐっさん | awk -f sekigae.awk
#  echo おっくん きたけー たけお ぐっさん | gawk --compat -f sekigae.awk

BEGIN {
  srand()
}

{
  split($0, names)

  shuffle(names, NF)

  print join(names, " | ")
}

# shuffles and overwrites the given array
function shuffle(array, size) {
  for (i = size; 1 < i; i--) {
    swap(array, i, random(i)+1)
  }
}

# picks up a random integer from 0 to n-1
function random(n) {
  return int(n * rand())
}

# swaps array[i] and array[j]
function swap(array, i, j) {
  if (i != j) {
    temporary = array[i]
    array[i]  = array[j]
    array[j]  = temporary
  }
}

# joins given array into string
function join(array, glue) {
  head = 1
  for (i in array) {  # notice that keys may not be sorted
    if (head) {
      joined = array[i]
      head = 0
    } else {
      joined = joined glue array[i]
    }
  }

  return joined
}
