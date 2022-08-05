//
// Created by liran on 30/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_CREATECLASSIFIEDFILES_H
#define ADVANCED_PROGRAMMING_1_CREATECLASSIFIEDFILES_H

class CreateClassifiedFiles {

    const int k;

public:

    explicit CreateClassifiedFiles(int k) : k(k) {}

    // creates the output files for the classifier to write in
    // and write the classified info to the files
    void createClassified() const;

};


#endif //ADVANCED_PROGRAMMING_1_CREATECLASSIFIEDFILES_H
