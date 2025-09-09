#ifndef RUBIKSCUBESOLVER_GENERICRUBIKSCUBE_H
#define RUBIKSCUBESOLVER_GENERICRUBIKSCUBE_H

#include<bits/stdc++.h>
using namespace  std;

// it is base class like abstract class
class RubiksCube {
    public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN

    };
    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };
    enum class MOVE {
        L,LPRIME,L2,
        R,RPRIME,R2,
        F,FPRIME,F2,
        D,DPRIME,D2,
        B,BPRIME,B2,
        UP,UPRIME,U2,
    };

    // DEFINING THE VIRTUAL FUNCTIONS IN ABSTRACT CLASS WHICH WILL BE OVERRIDED

    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    Static char getColorLetter(COLOR color); //RETURNS THE FIRST COLOR LETTER OF COLOR EX: G FOR GREEN

    virtual bool isSolved() const = 0;

    // RETURNS THE MOVE IN STRING FORMAT
    static string getMove(MOVE ind);


    //PRINT THE CUBE IN PLANAR FORMAT
    void print() const;

    //Randomly shuffle the cube with 'times' moves and returns the moves performed.
    vector<MOVE> randomShuffleCube(unsigned int times);


    //Perform moves on the Rubik Cube , so that cube is actually shuffled
    RubiksCube &move(MOVE ind);

    //Invert a move
    RubiksCube &invert(MOVE ind);



    // ALL POSSIBLE ROTATIONS OR MOVES IN CUBE
    // its return type is refernce of RubiksCube and function name is f , fprime ie their move is name of function
    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;

};


#endif