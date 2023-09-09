#!/bin/bash
SRC_DIR=$1
BIN_DIR=$2
mkdir -p $BIN_DIR
cp ./$SRC_DIR/apache2.strace ./$BIN_DIR
# output all data into bin folder
cd ./$BIN_DIR
cat apache2.strace | grep 2071760 | grep epoll_wait | grep '= 1' | awk '{print $2}' > request_times.txt
awk '{print $3}' apache2.strace | cut -d'(' -f1 | sort | uniq -c > unique_syscalls.txt
awk '{print $3}' apache2.strace | cut -d'(' -f1 | sort > all_syscalls.txt