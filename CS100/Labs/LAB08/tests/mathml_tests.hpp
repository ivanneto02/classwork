#include <gtest/gtest.h>

#include "../headers/VisitorMathML.hpp"
#include "../headers/imports.hpp"

TEST(MathMLTests, testAddPow) {

    std::ostringstream sout;

    Base* myExpression = new Add(
        new Add(new Op(2.0), new Op(2.0)),
        new Pow(new Op(2.0), new Op(3.0))
    );

    VisitorMathML* myVisitor = new VisitorMathML();

}

TEST(MathMLTests, testAddDivPow) {

    std::ostringstream sout;

    Base* myExpression = new Add(
        new Div(new Op(2.0), new Op(2.0)),
        new Pow(new Op(2.0), new Op(3.0))
    );

    VisitorMathML* myVisitor = new VisitorMathML();
    
   
}

TEST(MathMLTests, testAddDivSub) {

    std::ostringstream sout;

    Base* myExpression = new Add(
        new Div(new Op(2.0), new Op(2.0)),
        new Sub(new Op(2.0), new Op(3.0))
    );

    VisitorMathML* myVisitor = new VisitorMathML();
    

}

TEST(MathMLTests, testDivDivSub) {

    std::ostringstream sout;

    Base* myExpression = new Div(
        new Div(new Op(2.0), new Op(2.0)),
        new Sub(new Op(2.0), new Op(3.0))
    );

}

TEST(MathMLTests, testSubAddAdd) {

    std::ostringstream sout;

    Base* myExpression = new Sub(
        new Add(new Op(2.0), new Op(2.0)),
        new Add(new Op(2.0), new Op(3.0))
    );

    VisitorMathML* myVisitor = new VisitorMathML();
    

}

TEST(MathMLTests, testPowDivDiv) {

    std::ostringstream sout;

    Base* myExpression = new Pow(
        new Div(new Op(2.0), new Op(2.0)),
        new Div(new Op(2.0), new Op(3.0))
    );

    VisitorMathML* myVisitor = new VisitorMathML();
    

}