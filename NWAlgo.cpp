//
// Created by marij on 23-1-2024.
//

#include "NWAlgo.h"

NWAlgo::NWAlgo(const std::string &seq1, const std::string &seq2, int gap_penalty, int mismatch_penalty, SubstitutionMatrix SM):
        xLength(seq1.length()+1),
        yLength(seq2.length()+1),
        xString(seq1),
        yString(seq2),
        gap_penalty(gap_penalty),
        mismatch_penalty(mismatch_penalty),
        SM(SM)
{
    // Create a 2D matrix to store the scores
    _matrix = vector<vector<int>>(yLength, vector<int>(xLength, 0));
    init();
}
NWAlgo::NWAlgo(const std::string &seq1, const std::string &seq2, int gap_penalty, int mismatch_penalty):
        NWAlgo(seq1,seq2,gap_penalty,mismatch_penalty,SubstitutionMatrix::DEFAULT)
{}


void NWAlgo::init()
{

    _scoringMatrix =
    {
    { 0, 'C', 'S', 'T', 'P','A','G','N','D','E','Q','H','R','K','M','I','L','V','F','Y','W' },
    { 'C',  9, },
    { 'S', -1, 4, },
    { 'T', -1, 1, 5 },
    { 'P', -3, -1, -1, 7 },
    {'A', 0, 1, 0 ,-1,4},
    {'G',-3,0,-2,-2,0,6},
    {'N',-3,1,0,-2,-2,0,6},
    {'D', -3,0,-1,-1,-2,-1,1,6},
    {'E',-4,0,-1,-1,-1,-2,0,2,5},
    {'Q',-3,0,-1,-1,-1,-2,0,0,2,5},
    {'H',-3  ,-1,-2,-2,-2,-2,1,-1,0,0,8},
    {'R', -3 ,-1,-1,-2,-1,-2,0,-2,0,1,0,5},
    {'K', -3 ,0,-1,-1,-1,-2,0,-1,1,1,-1,2,5},
    {'M', -1 ,-1,-1,-2,-1,-3,-2,-3,-2,0,-2,-1,-1,5},
    {'I', -1 ,-2,-1,-3,-1,-4,-3,-3,-3,-3,-3,-3,-3,1,4},
    {'L', -1  ,-2,-1,-3,-1,-4,-3,-4,-3,-2,-3,-2,-2,2,2,4},
    {'V', -1,-2,0,-2,0,-3,-3,-3,-2,-2,-3,3,2,1,3,1,4},
    {'F', -2 ,-2,-2,-4,-2,-3,-3,-3,-3,-3,-1,-3,-3,0,0,0,-1,6},
    {'Y', -2 ,-2,-2,-3,-2,-3,-2,-3,-2,-1,2,-2,-2,-1,-1,-1,-1,3,7},
    {'W', -2 ,-3,-2,-4,-3,-2,-4,-4,-3,-2,-2,-3,-3,-1,-3,-2,-3,1,2,11},
    };

    // Initialize the first row and column with gap penalties
    for (int i = 1; i < yLength; ++i) {
        _matrix[i][0] = i * gap_penalty;
    }
    for (int j = 1; j < xLength; ++j) {
        _matrix[0][j] = j * gap_penalty;
    }
    // Fill in the matrix using the recurrence relation
    // Fill in the matrix using the recurrence relation
    for (int i = 1; i < yLength; ++i) {
        for (int j = 1; j < xLength; ++j) {
            int match = _matrix[i - 1][j - 1] + FindSubstitutionScore(i,j);
            int delete_gap = _matrix[i - 1][j] + gap_penalty;
            int insert_gap = _matrix[i][j - 1] + gap_penalty;
            // Choose the maximum of the three possibilities
            _matrix[i][j] = max({match, delete_gap, insert_gap});
        }
    }
}

int NWAlgo::FindSubstitutionScore(int i, int j)
{

    switch (SM)
    {
        case DEFAULT:
            if (xString[j - 1] == yString[i - 1]) return 0;
            else return mismatch_penalty;
        case PAM500:
            throw runtime_error("not implemented sorry");
        case PAM1:
            throw runtime_error("not implemented sorry");
        case PAM120:
            char x = xString[j-1];
            char y = yString[i-1];

            auto xIndex = std::find(_scoringMatrix[0].begin(), _scoringMatrix[0].end(), x);
            auto yIndex = std::find(_scoringMatrix[0].begin(), _scoringMatrix[0].end(), y);

            // Check if the characters are in the row
            if (xIndex== _scoringMatrix[0].end() && yIndex == _scoringMatrix[0].end()) {
                throw std::runtime_error("X or y not found");
            }
            int xPosition = std::distance(_scoringMatrix[0].begin(), xIndex);
            int yPosition = std::distance(_scoringMatrix[0].begin(), yIndex);

            if (yPosition < xPosition) swap(xPosition, yPosition);

            auto result =_scoringMatrix[yPosition][xPosition];
            return result;
    }
}



void NWAlgo::run()  {
    // Traceback to find the aligned sequences
    int i = yLength - 1;
    int j = xLength - 1;
    string alignedSeq1, alignedSeq2;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && _matrix[i][j] == _matrix[i - 1][j - 1] + FindSubstitutionScore(i,j)) {
            alignedSeq1 = xString[j - 1] + alignedSeq1;
            alignedSeq2 = yString[i - 1] + alignedSeq2;
            --i;
            --j;
        } else if (i > 0 && _matrix[i][j] == _matrix[i - 1][j] + gap_penalty) {
            alignedSeq1 = '-' + alignedSeq1;
            alignedSeq2 = yString[i - 1] + alignedSeq2;
            --i;
        } else {
            alignedSeq1 = xString[j - 1] + alignedSeq1;
            alignedSeq2 = '-' + alignedSeq2;
            --j;
        }
    }

    // Print the aligned sequences
    cout << "Aligned Sequence 1: " << alignedSeq1 << endl;
    cout << "Aligned Sequence 2: " << alignedSeq2 << endl;
}

void NWAlgo::printMatrix() {


    if (SM == PAM120){
        cout << "Scoring Matrix:" << endl;
    for (int i = 0; i < _scoringMatrix.size(); ++i)
    {
        for (int j = 0; j < _scoringMatrix[i].size(); ++j) {
            if (j == 0 || i == 0) cout << setw(4) << (char) _scoringMatrix[i][j];
            else
                cout << setw(4) << _scoringMatrix[i][j];
        }
        cout << '\n';
    }
    cout<< "\n\n";
    }
    cout << "final Matrix:" << endl;

    // Print column indices
    cout << "   ";
    for (int j = 0; j < xLength; ++j) {
        cout << setw(4) << (j == 0 ? '-' : xString[j - 1]);
    }
    cout << endl;

    for (int i = 0; i < yLength; ++i) {
        // Print row index
        cout << setw(4) << (i == 0 ? '-' : yString[i - 1]);

        for (int j = 0; j < xLength; ++j) {
            // Print matrix element
            cout << setw(4) << _matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;


}

void NWAlgo::help()
{
    cout <<"by changing the strings in main you can perform protein sequence alignment \n"
           "the default implementation works with match and mismatch penalties \nbut if you want to do biologically significant calculations you should use the PAM120 Substitution matrix by adding that argument to the constructor \n\n";
}
