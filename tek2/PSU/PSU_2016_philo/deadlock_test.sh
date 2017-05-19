#!/bin/zsh

philo=$1 #nbPhilo
eat=$2 #eatValue
iterations=$3 #nbIterations to perform
for i in {1..$iterations}
do timeout 2 ./philo -p $philo -e $eat && echo $i/$iterations || break
done
if [ $i != $iterations ]
then
    echo "DeadLock "$i/$iterations
else
    echo "Success"
fi
