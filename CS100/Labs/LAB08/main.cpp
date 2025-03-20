#include <iostream>

#include "headers/imports.hpp"
#include "headers/iterator.hpp"
#include "headers/VisitorLaTeX.hpp"
#include "headers/VisitorMathML.hpp"

std::string PrintLaTeX(Base*);
std::string PrintMathML(Base*); 

int main() {

     /*  Creating expression tree  */
    Base *Expression1 = new Add(
        new Op(1.0),
        new Sub(new Op(5.0), new Op(0))
    );
   
    Base *Expression2 = new Pow(
        new Op(5.0),
        new Op(2.0)
    ); 
    
    Base *Expression3 = new Mult(
        new Op(2.0), 
        new Op(5.0)
    ); 
    
    Base *Expression4 = new Div(
        new Op(2.0), 
        new Op(3.0)
    ); 

    Base *Expression5 = new Div(
        new Mult(new Op(2.0), new Op(5.0)),
        new Pow(new Op(5.0), new Op(2.0)) 
    ); 

    std::cout << PrintLaTeX(Expression1) << std::endl; 
    std::cout << PrintMathML(Expression1) << "\n" << std::endl; 

    std::cout << PrintLaTeX(Expression2) << std::endl;
    std::cout << PrintMathML(Expression2) << "\n" << std::endl;  

    std::cout << PrintLaTeX(Expression3) << std::endl; 
    std::cout << PrintMathML(Expression3) << "\n" << std::endl; 

    std::cout << PrintLaTeX(Expression4) << std::endl; 
    std::cout << PrintMathML(Expression4) << "\n" << std::endl; 

    std::cout << PrintLaTeX(Expression5) << std::endl; 
    std::cout << PrintMathML(Expression5) << "\n" << std::endl; 

    std::cout << "End of program..." << std::endl;

    delete Expression1;
    std::cout << "Expression 1 destructor done" << std::endl;
    delete Expression2;
    delete Expression3;
    delete Expression4;
    delete Expression5;
}

std::string PrintLaTeX(Base* myExpression) {
    
    VisitorLaTeX *myVisitor = new VisitorLaTeX();

    for ( Iterator iter = Iterator(myExpression); iter.is_done() != true; iter.next() ) {

        Base* currNode = iter.current_node();

        currNode->accept(myVisitor, iter.current_index());
    }

    std::string newExpression = "$" + myVisitor->getFinal() + "$";

    delete myVisitor;

    return newExpression;    
}


std::string PrintMathML(Base* ExpressionPtr) {
    VisitorMathML *myVisitor = new VisitorMathML();

    for ( Iterator iter = Iterator(ExpressionPtr); iter.is_done() != true; iter.next() ) {

        Base* currNode = iter.current_node();

        currNode->accept(myVisitor, iter.current_index());
    }

    std::string newExpression = "<math>\n" + myVisitor->getFinal() + "</math>";

    delete myVisitor;

    return newExpression;

}