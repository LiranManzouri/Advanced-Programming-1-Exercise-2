# Advanced Programming 1 - Exercise 2

In order to run the project, you will need to save an empty "bin" directory and a "classified.csv" file (in that names),
like we've seen in exercise 1 in the directory you are in at the time you run the project. We already have this
classified.csv file in GitHub, but if you would like to use new file, just do what mentioned above. Next, you'll need to
open 2 terminals, in each you'll need to move into the directory where the code files + the classified.csv file are in.
One terminal for the server, which the compile command and the run command in it are:
Compile command - "g++ -std=c++11 Server/\*.cpp Server/\*.h \*.cpp \*.h -o bin/Server.out". Run command - "
./bin/Server.out"
. The second terminal is for the client, which the compile command and the run command in it are:
Compile command - "g++ -std=c++11 Client/\*.cpp Client/\*.h *.cpp \*.h -o bin/Client.out". Run command - "
./bin/Client.out".

# Shortcut for compilation and running commands

SHORTCUT: you can open one terminal, move into the directory where the code files + the classifieds.csv file are in, and
write there "bash run.sh" in the command line after being at the directory, and 2 terminals for server and client will
automatically open.

Of course, if it's not working on mobaXterm, the commands that we mentioned above are working.

# Notes and actions while running

After running, you'll be asked in the terminals for the unclassified path and the output path, write them seperated with
space. For example: "Unclassified.csv output.csv" (without the ""). You can close the client socket and stop the
communication anytime, by writing "close" (without the "") instead of the paths. For closing the server socket, you'll
have to close the client socket first, and then press "2" in the little menu you will see, for waiting and accept
another client, press "1" in that menu, and then run only the Client again (same as mentioned up).

# Implantation

In this project, there are server and client. The client sends a path to unclassified flowers to the server, which
classify them by the knn algorithm we've implemented in exercise 1, with k = 7. After classifying, the server sends the
classifiers to the client, which writes them to an output file he has got.