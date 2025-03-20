#include <gtest/gtest.h>

#include "../headers/VisitorLaTeX.hpp"
#include "../headers/imports.hpp"

TEST(VisitorTests, testAddPow) {

    std::ostringstream sout;

    Base* myExpression = new Add(
        new Add(new Op(2.0), new Op(2.0)),
        new Pow(new Op(2.0), new Op(3.0))
    );

    VisitorLaTeX* myVisitor = new VisitorLaTeX();
    
    sout << "$";
    for ( Iterator iter = Iterator(myExpression); iter.is_done() != true; iter.next() ) {

        Base* currNode = iter.current_node();

        currNode->accept(myVisitor, iter.current_index());

    }
    std::cout << std::endl;
    sout << myVisitor->getFinal() << "$";

    ASSERT_EQ("${({({2}+{2})}+{({2}^{3})})}$" , sout.str());
}

TEST(VisitorTests, testAddDivPow) {

    std::ostringstream sout;

    Base* myExpression = new Add(
        new Div(new Op(2.0), new Op(2.0)),
        new Pow(new Op(2.0), new Op(3.0))
    );

    VisitorLaTeX* myVisitor = new VisitorLaTeX();
    
    sout << "$";
    for ( Iterator iter = Iterator(myExpression); iter.is_done() != true; iter.next() ) {

        Base* currNode = iter.current_node();

        currNode->accept(myVisitor, iter.current_index());

    }
    std::cout << std::endl;
    sout << myVisitor->getFinal() << "$";

    ASSERT_EQ("${(\\frac{{2}}{{2}}+{({2}^{3})})}$" , sout.str());
}

TEST(VisitorTests, testAddDivSub) {

    std::ostringstream sout;

    Base* myExpression = new Add(
        new Div(new Op(2.0), new Op(2.0)),
        new Sub(new Op(2.0), new Op(3.0))
    );

    VisitorLaTeX* myVisitor = new VisitorLaTeX();
    
    sout << "$";
    for ( Iterator iter = Iterator(myExpression); iter.is_done() != true; iter.next() ) {

        Base* currNode = iter.current_node();

        currNode->accept(myVisitor, iter.current_index());

    }
    std::cout << std::endl;
    sout << myVisitor->getFinal() << "$";

    ASSERT_EQ("${(\\frac{{2}}{{2}}+{({2}-{3})})}$" , sout.str());
}

TEST(VisitorTests, testDivDivSub) {

    std::ostringstream sout;

    Base* myExpression = new Div(
        new Div(new Op(2.0), new Op(2.0)),
        new Sub(new Op(2.0), new Op(3.0))
    );

    VisitorLaTeX* myVisitor = new VisitorLaTeX();
    
    sout << "$";
    for ( Iterator iter = Iterator(myExpression); iter.is_done() != true; iter.next() ) {

        Base* currNode = iter.current_node();

        currNode->accept(myVisitor, iter.current_index());

    }
    std::cout << std::endl;
    sout << myVisitor->getFinal() << "$";

    ASSERT_EQ("$\\frac{\\frac{{2}}{{2}}}{{({2}-{3})}}$" , sout.str());
}

TEST(VisitorTests, testSubAddAdd) {

    std::ostringstream sout;

    Base* myExpression = new Sub(
        new Add(new Op(2.0), new Op(2.0)),
        new Add(new Op(2.0), new Op(3.0))
    );

    VisitorLaTeX* myVisitor = new VisitorLaTeX();
    
    sout << "$";
    for ( Iterator iter = Iterator(myExpression); iter.is_done() != true; iter.next() ) {

        Base* currNode = iter.current_node();

        currNode->accept(myVisitor, iter.current_index());

    }
    std::cout << std::endl;
    sout << myVisitor->getFinal() << "$";

    ASSERT_EQ("${({({2}+{2})}-{({2}+{3})})}$" , sout.str());
}

TEST(VisitorTests, testPowDivDiv) {

    std::ostringstream sout;

    Base* myExpression = new Pow(
        new Div(new Op(2.0), new Op(2.0)),
        new Div(new Op(2.0), new Op(3.0))
    );

    VisitorLaTeX* myVisitor = new VisitorLaTeX();
    
    sout << "$";
    for ( Iterator iter = Iterator(myExpression); iter.is_done() != true; iter.next() ) {

        Base* currNode = iter.current_node();

        currNode->accept(myVisitor, iter.current_index());

    }
    std::cout << std::endl;
    sout << myVisitor->getFinal() << "$";

    ASSERT_EQ("${(\\frac{{2}}{{2}}^\\frac{{2}}{{3}})}$" , sout.str());
}