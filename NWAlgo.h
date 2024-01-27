//
// Created by marij on 23-1-2024.
//

#ifndef DNA_SEQUENCING_NWALGO_H
#define DNA_SEQUENCING_NWALGO_H

#include <iostream>
#include "SubstitutionMatrix.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept> // Required for std::runtime_error
#include <functional>


using namespace std;
class NWAlgo {

    string xString;
    string yString;
    int yLength = 0;
    int xLength = 0;
    int gap_penalty;
    int mismatch_penalty;
    SubstitutionMatrix SM;
    vector<vector<int>> _matrix;
    vector<vector<int>> _scoringMatrix;

    void init(); // initialises the vector is called from the constructor
    int FindSubstitutionScore(int i, int j);

public:
    NWAlgo(const string &seq1, const string &seq2, int gap_penalty, int mismatch_penalty, SubstitutionMatrix SM); //constructor
    NWAlgo(const string &seq1, const string &seq2, int gap_penalty, int mismatch_penalty); //constructor
    void run(); // Function to perform Needleman-Wunsch alignment and traceback
    void printMatrix();
    static void help();
};
#endif //DNA_SEQUENCING_NWALGO_H
