//
// Created by liran on 30/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_CREATECLASSIFIEDFILES_H
#define ADVANCED_PROGRAMMING_1_CREATECLASSIFIEDFILES_H

#include <string>

class CreateClassifiedFiles {

    const int k;
    const std::string unclassifiedPath;
    const std::string outputClassifiedPath;

public:

    CreateClassifiedFiles(int k, std::string unclassifiedPath, std::string outputClassifiedPath) :
            k(k), outputClassifiedPath(std::move(outputClassifiedPath)), unclassifiedPath(std::move(unclassifiedPath)) {}

    // creates the output files for the classifier to write in
    // and write the classified info to the files
    void createClassified() const;
};


#endif //ADVANCED_PROGRAMMING_1_CREATECLASSIFIEDFILES_H
