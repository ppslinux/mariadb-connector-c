#!/bin/bash
cd ../../
make 
cd -
if [ -e cursor ]; then
	echo run
 	./cursor -h 192.168.0.8 -u root -p runwell -d runwell_test -P 3306 1>/dev/stdout
fi
