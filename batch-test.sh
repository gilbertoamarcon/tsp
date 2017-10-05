#!/bin/bash
problems=$(ls "data")
tools="0 1 2"

for i in {1..100}; do 
	echo $i
	for t in $tools; do 
		for p in $problems; do
			com="./bin/main data/$p $t"
			# echo $com
			$com >> "res/res_${t}_${p}"
		done
	done
done