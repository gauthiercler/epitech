#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[0;37m'

if [ "$#" -ne 4 ]
then
    echo "usage: $0 path_to_key nb_team nb_players_per_team path_map"
    exit 1
fi


baseShm=$(ipcs -m | tail -n +4 | head -n -1)
baseMsgQ=$(ipcs -q | tail -n +4 | head -n -1)
baseSema=$(ipcs -s | tail -n +4 | head -n -1)
baseNammedSema=$(ls /dev/shm)

./lemipc $1 0 $4 &> /dev/null &

pids=$!


for teamNb in $(eval echo {1..$2})
do
    for playerNb in $(eval echo {1..$3})
    do
	./lemipc $1 $teamNb $4 &> /dev/null &
	pids+=" $!"
    done
done

failed=0

for p in $pids
do
    if ! wait $p
    then
	echo -e "${RED}Process with pid $p Stopped with bad exit code${WHITE}"
	failed=1
    fi
done

function kill_IPC()
{
    if [ "$1" != "" ]
    then
	echo -e "${RED}$2 are not cleared !${WHITE}"
	echo "$1"
#	toClean=$(echo "$1" | awk '{print $3}')
#	while read -r line
#	do
#	    if [ ${#line} -ne 0 ]
#	    then
#		echo "Removing $2 with id $line"
#		ipcrm "$3" $line
#	    fi
#	done <<< "$toClean"
	
#	failed=1
    fi
}

function remove_sema()
{
    if [ "$1" != "" ]
    then
	echo -e "${RED}Nammed Semaphores are not Cleared !${WHITE}"
	echo "$1"
#	toClean=$(echo "$1" | awk '{print $2}')
#	while read -r line
#	do
#	    if [[ ${#line} -ne 0 ]]
#	    then
#		echo "Removing /dev/shm/$line"
#		rm -f /dev/shm/$line
#	    fi
#	done <<< "$toClean"
    fi
}

finalShm=$(ipcs -m | tail -n +4 | head -n -1)
finalMsgQ=$(ipcs -q | tail -n +4 | head -n -1)
finalSema=$(ipcs -s | tail -n +4 | head -n -1)
finalNammedSema=$(ls /dev/shm)

diffShm=$(diff <(echo "$baseShm") <(echo "$finalShm"))
diffMsgQ=$(diff <(echo "$baseMsgQ") <(echo "$finalMsgQ"))
diffSema=$(diff <(echo "$baseSema") <(echo "$finalSema"))
diffNammedSema=$(diff <(echo "$baseNammedSema") <(echo "$finalNammedSema"))

kill_IPC "$diffShm" "Shared memory" "-m"
kill_IPC "$diffMsgQ" "Message Queue" "-q"
kill_IPC "$diffSema" "Semaphore" "-s"

remove_sema "$diffNammedSema"

if [ $failed -eq 1 ]
then
    echo -e "${RED}Tests Failed !${WHITE}"
    exit 1
else
    echo -e "${GREEN}Tests were successful !${WHITE}"
    exit 0
fi
