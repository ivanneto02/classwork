#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle {

    private:
        double radius;
    public:
        Circle(double radius) : radius(radius) {}
        double area() const;
        double perimeter() const;
};

#endif /*CIRCLE_HPP*/