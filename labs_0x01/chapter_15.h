#ifndef CHAPTER_15_H
#define CHAPTER_15_H

#include <iostream>

class Shape_1 {
public:
    Shape_1();
    virtual void draw();
};

class Circle_1 : public Shape_1 {
public:
    void draw();
};

class Square_1 : public Shape_1 {
public:
    void draw();
};

class Triangle_1 : public Shape_1 {
public:
    void draw();
};

void function_15_1 (Shape_1& shp);

class Class_15_A {
public:
    Class_15_A(int ii) : i(ii) {}
    ~Class_15_A() {}
    void f() const {}
private:
    int i;
};

class Class_15_B {
public:
    Class_15_B(int ii) : i(ii) {}
    ~Class_15_B() {}
    virtual void f() const;
private:
    int i;
};

class Class_15_C : public Class_15_B {
public:
    Class_15_C(int ii) : Class_15_B(ii), a(ii) {}
    ~Class_15_C() {}
    void f() const;
private:
    Class_15_A a;
};

class Instrument_5 {
public:
    virtual void play(int note) const;
    virtual void prepare() const;
};

class Wind_5 : public Instrument_5 {
public:
    void play(int note) const;
};

void function_15_5(Instrument_5& i);

#endif
