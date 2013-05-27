#!/bin/ash

newcomers="okkun keoken kitak gussan"

random() {
  echo $(tr -dc 0-9 </dev/urandom | head -c5 | sed -e 's/^0//')
}

for p in $newcomers; do
  r=$(random)
  echo "$r $p"
done | sort -k1n | cut -d' ' -f2 | tr '\n' ' '
echo
