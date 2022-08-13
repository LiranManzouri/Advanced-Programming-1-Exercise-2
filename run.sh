#!usr/bin/bash

function terminal1(){
    g++ Server/*.cpp Server/*.h *.cpp *.h -o bin/Server.out
    bin/Server.out
}

function terminal2(){
    g++ Client/*.cpp Client/*.h *.cpp *.h -o bin/Client.out
    bin/Client.out
}

export -f terminal1
export -f terminal2

x-terminal-emulator -e bash -c 'terminal1; bash'
x-terminal-emulator -e bash -c 'terminal2; bash'