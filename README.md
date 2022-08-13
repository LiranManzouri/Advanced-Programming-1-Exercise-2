# Advanced Programming 1 - Exercise 1

In order to run the project, you will need to save the "classified.csv" and "Unclassified.csv" files in the directory
you are in at the time you run it. Compile command - "g++ -std=c++11 *.cpp". Run command - "./a.out k", for example: "
./a.out 7".
>

# Impletation

In the project, the flowers inputed are converted to an array of pairs, that contain the distance to the flower we try
to classify (each distance type creates a diffrent array), and a refrence to the flower itsef. then we run the Quick
select algorithm on the array (by the distance), which with the partitions prevides us with the first k elements, and
then we find which type shows up the most and thats the classifier!
