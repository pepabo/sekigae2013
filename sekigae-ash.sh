#!/bin/ash

newcomers="okkun keoken kitak gussan"

n_newcomers=$(echo $newcomers | wc -w)

random() {
  echo $(tr -dc 0-9 </dev/urandom | head -c5 | sed -e 's/^0//')
}

i=0
newcomers=$(
for p in $newcomers; do
  echo -n " $i:$p"
  i=$(($i+1))
done
)

i=0
while [ $i -lt $n_newcomers ]; do
  n=$(($(random) % $n_newcomers))

  tmp_n=$(echo "$newcomers" | egrep -o " $n:[^ ]+")
  tmp_i=$(echo "$newcomers" | egrep -o " $i:[^ ]+")
  newcomers=$(echo "$newcomers"    | \
    sed -e "s/$tmp_n/ __SWAPME__/" | \
    sed -e "s/$tmp_i/$tmp_n/"      | \
    sed -e "s/ __SWAPME__/$tmp_i/" )

  i=$(($i+1))
done

echo $(echo "$newcomers" | sed -e "s/ [0-9]:/ /g")
