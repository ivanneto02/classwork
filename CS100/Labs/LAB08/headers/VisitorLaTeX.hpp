#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include "visitor.hpp"
#include <string>

class VisitorLaTeX : public Visitor {
    private:
        std::string finalExp;

    public:

        virtual ~VisitorLaTeX() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) override;
        virtual void visit_rand(Rand* node) override;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node) override;
        virtual void visit_add_middle(Add* node) override;
        virtual void visit_add_end(Add* node) override;
        virtual void visit_sub_begin(Sub* node) override;
        virtual void visit_sub_middle(Sub* node) override;
        virtual void visit_sub_end(Sub* node) override;
        virtual void visit_mult_begin(Mult* node) override;
        virtual void visit_mult_middle(Mult* node) override;
        virtual void visit_mult_end(Mult* node) override;
        virtual void visit_div_begin(Div* node) override;
        virtual void visit_div_middle(Div* node) override;
        virtual void visit_div_end(Div* node) override;
        virtual void visit_pow_begin(Pow* node) override;
        virtual void visit_pow_middle(Pow* node) override;
        virtual void visit_pow_end(Pow* node) override;

        std::string getFinal() const { return this->finalExp; };
};

#endif