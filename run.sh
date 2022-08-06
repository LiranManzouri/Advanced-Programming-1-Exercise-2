#!usr/bin/bash

function terminal1(){
    #!usr/bin/bash
    echo "g++ Server.cpp Server.h -o bin/Server.out"
    g++ Server.cpp Server.h -o bin/Server.out
    echo "bin/Server.out"
    bin/Server.out
}

function terminal2(){
    echo "g++ Client.cpp Client.h -o bin/Client.out"
    g++ Client.cpp Client.h -o bin/Client.out
    echo " bin/Client.out"
    bin/Client.out
}

export -f terminal1
export -f terminal2

# x-terminal-emulator -e bash -c 'terminal1; bash'
# x-terminal-emulator -e bash -c 'terminal2; bash'

compileAll

