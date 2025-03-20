#include "../header/rectangle.hpp"

Rectangle::Rectangle(int w, int h) {

    if (w < 0) {
        this->width = 0;
    }
    else {
        this->width = w;
    }

    if (h < 0) {
        this->height = 0;
    }
    else {
        this->height = h;
    }
}

void Rectangle::set_width(int w) {
    this->width = w;
}

void Rectangle::set_height(int h) {
    this->height = h;
}

int Rectangle::area() {
    return this->width * this->height;
}

int Rectangle::perimeter() {

    if (this->width == 0 || this->height == 0) {
        return 0;
    }

    return (2 * this->width + 2 * this->height);
}

int Rectangle::get_width() const {
    return this->width;
}

int Rectangle::get_height() const {
    return this->height;
}