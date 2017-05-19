#!/bin/bash

filename="$1"
test_index=1
nb_success=0
nb_tests=0

error="  KO\t"
success="  OK\t"

#define language in english
export LANG=C

#check if terminal isi color compatible
check_colors()
{
  if [ -t 1 ]
  then
    ncolors=$(tput colors)
    if [[ -n "$ncolors" && "$ncolors" -ge 8 ]]
    then
      bold="$(tput bold)"
      underline="$(tput smul)"
      standout="$(tput smso)"
      normal="$(tput sgr0)"
      black="$(tput setaf 0)"
      red="$(tput setaf 1)"
      green="$(tput setaf 2)"
      yellow="$(tput setaf 3)"
      blue="$(tput setaf 4)"
      magenta="$(tput setaf 5)"
      cyan="$(tput setaf 6)"
      white="$(tput setaf 7)"
    fi
  fi
}

#check number of args
arg_checker()
{
  if [ $1 -ne 1 ]
  then
    echo "Please provide a file with commands (1 per line)"
    exit 1
  fi
}

#build shell if needed
build_shell()
{
  which ./42sh
  if [ $? -eq 1 ]
  then
    echo "Building 42sh"
    make &> /dev/null
  fi
}

#clean files
clean()
{
  rm -rf $1 $2
}

purge_dir()
{
  cd .. ; rm -rf /tmp/tests ; mkdir /tmp/tests ; cd /tmp/tests
}

#launch command, redirect and get ret value
launch_command_42()
{

  echo "=== TEST $test_index : $line ===" >> /tmp/42shlog
  echo -e "$line" | /tmp/42sh &> /tmp/42shtest
  sh_ret=$?
  cat /tmp/42shtest >> /tmp/42shlog
  purge_dir
}

#launch command, redirect and get ret value
launch_command_tcsh()
{
  echo "=== TEST $test_index : $line ===" >> /tmp/tcshlog
  echo -e "$line" | tcsh &> /tmp/tcshtest
  tcsh_ret=$?
  cat /tmp/tcshtest >> /tmp/tcshlog
  purge_dir
}

#display number of successfull tests
disp_result()
{
  echo -e "\n   $cyan$bold$nb_success success / $nb_tests tests$normal"
  if [ $nb_success -eq $nb_tests ]
  then
    echo -e "\n $blue$bold Congratulation 100% tests !"
  fi
}

#display status of current test
disp_status()
{
  result=$(diff /tmp/42shtest /tmp/tcshtest)

  #check is results are identics
  if [[ $? -eq 0 && $tcsh_ret -eq $sh_ret ]]
  then
    echo -en "$bold$green$success$white$normal"
    ((nb_success++))
  else
    echo -en "$bold$red$error$white$normal"
  fi
}

#display ret value of the 2 shells
disp_ret()
{
  echo -en $white "$sh_ret\t"
  echo -e $whhite " $tcsh_ret"
}

#get instruction and process test
process_loop()
{
  while read -r line
  do
    if [[ ${line:0:1} != "#" ]]
    then
      echo -en "$white  $test_index\t"
      launch_command_42
      launch_command_tcsh
      disp_status
      disp_ret
      ((nb_tests++))
    fi
    ((test_index++))
  done < "$test_file"
}

disp_credits()
{
  echo -e "\n$bold$yellow  Go check the logs in /tmp"
  echo -e "\n$green Mouli by cler_g, dusaut_v, foret_a, buyuma_a Epitech Lille Promo 2020 42sh 2015-2016 Reserved$normal$white"
}

arg_checker $#
check_colors
build_shell
clean /tmp/42sh /tmp/tests
mkdir /tmp/tests
cp 42sh /tmp; cp $1 /tmp/test_file; cd /tmp/tests
test_file=/tmp/test_file
clean /tmp/42shlog /tmp/tcshlog

echo -e "$white$bold TEST\tRESULT\t42SH\tTCSH$normal"

process_loop
disp_result
clean /tmp/42shtest /tmp/tcshtest
disp_credits
cd -

exit 0
