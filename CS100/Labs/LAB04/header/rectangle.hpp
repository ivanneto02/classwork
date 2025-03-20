#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
    private:
        int width;
        int height;
    public:
		Rectangle() : width(0), height(0) {};
		Rectangle(int, int);

        void set_width(int w);
        void set_height(int h);
        int area();
		int perimeter(); 

        int get_width() const;
        int get_height() const;
};

#endif // RECTANGLE_HPP 
