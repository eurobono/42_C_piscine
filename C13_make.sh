#!/bin/bash

file_name="ft_btree.txt"
count=00

while IFS= read -r linea; do
	echo $count
	mkdir ex$count
	cat ft_btree_header.c >> ex$count/ft_.c
	echo "$linea" >> ex$count/ft_.c
	cat ft_btree_footer.c >> ex$count/ft_.c
	let count++
done < "$file_name"
