#! /bin/sh
cmake .
make clean
make

killall fusestorage
./bin/fusestorage ../testfs

ls ../testfs/abc/defg -all