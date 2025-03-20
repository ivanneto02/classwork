class Base
{
public:
virtual ~Base ( ) = default ;
virtual std :: string latex ( ) const = 0 ;
};

class Num : public Base
{
double x ;
public :
Num( double value ) ;
double get_value ( ) const { return x ; }
std :: string latex ( ) const ;
};

class Neg : public Base
{
Base *A;
public :
Neg (Base *A) ;
~Neg ( ) { delete A; }
std :: string latex ( ) const ;
};

class Add : public Base
{
Base* A, * B;
public :
Add(Base *A, Base *B) ;
~Add( ) { delete A; }
std :: string latex ( ) const ;
};

class Sub : public Base
{
Base* A, * B;
public :
Sub(Base *A, Base *B) ;
~Sub ( ) { delete A; }
std :: string latex ( ) const ;
}; 

struct pfVisitor : public Visitor {

    std::string final_exp = "";

    virtual void visit(Num* o) override {

        final_exp += o->get_value() + " ";
    }

    virtual void visit(Neg* o) override {

        final_exp += "neg ";
    }

    virtual void visit(Add* o) override {

        final_exp += "+ ";
    }

    virtual void visit(Sub* o) override {

        final_exp += "- ";
    }

};

std::string get_postfix(Base* o) {

    Visitor* myVisitor = new pfVisitor();

    o->traverse(myVisitor);

    return myVisitor->final_exp;
}