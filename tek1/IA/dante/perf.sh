#!/bin/bash

make

make -C generateur

generateur/generateur $1 $2 $3 > perf

make fclean -C generateur

echo "Profondeur :" > perf_time
{ time profondeur/solver perf ; } 1>/dev/null 2>> perf_time
echo -e "\nLargeur :" >> perf_time
{ time largeur/solver perf ; } 1>/dev/null 2>> perf_time
echo -e "\nA star :" >> perf_time
{ time astar/solver perf ; } 1>/dev/null 2>> perf_time
echo -e "\nTournoi :" >> perf_time
{ time tournoi/solver perf ; } 1>/dev/null 2>> perf_time

make fclean

rm -f perf

cat perf_time

rm -f perf_time

exit 0
