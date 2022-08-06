//
// Created by liran on 30/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_CREATECLASSIFIEDFILES_H
#define ADVANCED_PROGRAMMING_1_CREATECLASSIFIEDFILES_H

#include <string>

class CreateClassifiedFiles {

    const int k;
    const std::string classifiedPath;
    const std::string unclassifiedPath;

public:

    CreateClassifiedFiles(int k, std::string classifiedPath, std::string unclassifiedPath) :
            k(k), classifiedPath(std::move(classifiedPath)), unclassifiedPath(std::move(unclassifiedPath)) {}

    // creates the output files for the classifier to write in
    // and write the classified info to the files
    void createClassified() const;

};


#endif //ADVANCED_PROGRAMMING_1_CREATECLASSIFIEDFILES_H
