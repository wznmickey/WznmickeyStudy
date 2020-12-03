/*******************************
    Written by WANGZINING
    blog: https://wznmickey.com
*******************************/
#ifndef PAINT
#define PAINT

class Point
{
public:
    double x, y;
};

class Shape
{
public:
    virtual ~Shape() = 0;
    virtual void move(double dx, double dy);
    virtual void zoom(double x);
    virtual float area();
};

class Triangle : public Shape
{
public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3);
    ~Triangle();
    void move(double dx, double dy);
    void zoom(double x);
    float area();

private:
    Point p1, p2, p3;
};

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(Point p1, Point p2);
    ~Rectangle();
    void move(double dx, double dy);
    void zoom(double x);
    float area();

private:
    Point p1, p2;
};

class Parallelogram : public Shape
{
public:
    Parallelogram();
    Parallelogram(Point p1, Point p2, Point p3);
    ~Parallelogram();
    void move(double dx, double dy);
    void zoom(double x);
    float area();

private:
    Point p1, p2, p3;
}

class Trapezium : public Shape
{
}
#endif //PAINT