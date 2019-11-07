//
// Created by benves-7 on 11/5/19.
//

#ifndef MATHLIB_H
#define MATHLIB_H

#include <cstdio>
#include <cmath>
#include "MathLib.h"

class vector2D
{
public:
    // constructors
    vector2D();
    vector2D(float x, float y) {
        cord[0] = x;
        cord[1] = y;
    }
    ~vector2D() = default;

    // get and set func
    void Set(float x, float y) {
        cord[0] = x;
        cord[1] = y;
    }
    void SetX(float x) {
        cord[0] = x;
    }
    void SetY(float y) {
        cord[1] = y;
    }
    float GetX() {
        return cord[0];
    }
    float GetY() {
        return cord[1];
    }

    // simple print out for debug.
    void Print() const {
        printf("X: %0.1f : Y; %0.1f\n", cord[0], cord[1]);
    }

    // normal and dot func
    float Length() {
        return (sqrt(pow(cord[0], 2) + pow(cord[1], 2)));
    }
    vector2D Normalize() {
        float length = 1.0f / this->Length();
        return vector2D(GetX() * length, GetY() * length);
    }
    static const float Dot(vector2D lhs, vector2D rhs) {
        return (lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY());
    }

    // operators
    void operator*(float rhs) {
        this->cord[0] *= rhs;
        this->cord[1] *= rhs;
    }
    vector2D operator+(vector2D& rhs) {
        return vector2D(this->GetX() + rhs.GetX(), this->GetY() + rhs.GetY());
    }
    vector2D operator-(vector2D& rhs) {
        return vector2D(this->GetX() - rhs.GetX(), this->GetY() - rhs.GetY());
    }

    // compare operators
    void operator=(vector2D& rhs) {
        SetX(rhs.GetX());
        SetY(rhs.GetY());
    }
    bool operator==(vector2D& rhs) {
        if (this->GetX() == rhs.GetX() && this->GetY() == rhs.GetY())
            return true;
        return false;
    }
    bool operator!=(vector2D& rhs) {
        if (this->GetX() != rhs.GetX() || this->GetY() != rhs.GetY())
            return true;
        return false;
    }
    bool operator<(vector2D& rhs) {
        if (this->GetX() < rhs.GetX() && this->GetY() < rhs.GetY())
            return true;
        return false;
    }
    bool operator>(vector2D& rhs) {
        if (this->GetX() > rhs.GetX() && this->GetY() > rhs.GetY())
            return true;
        return false;
    }
    bool operator<=(vector2D rhs) {
        if (this->GetX() <= rhs.GetX() && this->GetY() <= rhs.GetY())
            return true;
        return false;
    }
    bool operator>=(vector2D rhs) {
        if (this->GetX() >= rhs.GetX() && this->GetY() >= rhs.GetY())
            return true;
        return false;
    }

    // get and set with brackets
    float& operator[] (const int x)
    {
        return cord[x];
    }
    float operator[] (const int x) const
    {
        return cord[x];
    }

private:

    float cord[2];
};

class vector3D {
public:
    // constructors
    vector3D();
    vector3D(float x, float y, float z) {
        cord[0] = x;
        cord[1] = y;
        cord[2] = z;
    }
    ~vector3D() = default;

    // set and get func
    void Set(float x, float y, float z) {
        cord[0] = x;
        cord[1] = y;
        cord[2] = z;
    }
    void SetX(float x) {
        cord[0] = x;
    }
    void SetY(float y) {
        cord[1] = y;
    }
    void SetZ(float z) {
        cord[2] = z;
    }

    float GetX() const {
        return cord[0];
    }
    float GetY() const {
        return cord[1];
    }
    float GetZ() const {
        return cord[2];
    }
    float* GetPointer() {
        return cord;
    }

    // easy print func for debug.
    void print() const {
        printf("X: %0.1f : Y: %0.1f : Z: %0.1f\n", GetX(), GetY(), GetZ());
    }

    // Normalize, Dot and Cross func
    float Length() {
        return sqrt((GetX() * GetX()) + (GetY() * GetY()) + (GetZ() * GetZ()));
    }
    vector3D Normalize() {
        float length = 1.0f / Length();
        return vector3D(GetX() * length, GetY() * length, GetZ() * length);
    }
    static const float Dot(vector3D lhs, vector3D rhs) {
        return (lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ());
    }
    static const vector3D Cross(vector3D lhs, vector3D rhs) {
        return vector3D(
                lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
                lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
                lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX());
    }

    // operators
    vector3D operator*(float rhs) {
        return vector3D(GetX() * rhs, GetY() * rhs, GetZ() * rhs);
    }
    vector3D operator+(vector3D rhs) {
        return vector3D(GetX() + rhs.GetX(), GetY() + rhs.GetY(), GetZ() + rhs.GetZ());
    }
    vector3D operator-(vector3D rhs) {
        return vector3D(GetX() - rhs.GetX(), GetY() - rhs.GetY(), GetZ() - rhs.GetZ());
    }
    void operator+=(vector3D rhs) {
        Set(GetX() + rhs.GetX(), GetY() + rhs.GetY(), GetZ() + rhs.GetZ());
    }
    void operator-=(vector3D rhs) {
        Set(GetX() - rhs.GetX(), GetY() - rhs.GetY(), GetZ() - rhs.GetZ());
    }

    // compare operators
    void operator=(vector3D& rhs) {
        SetX(rhs.GetX());
        SetY(rhs.GetY());
        SetZ(rhs.GetZ());
    }
    bool operator==(vector3D& rhs) {
        if (GetX() == rhs.GetX() && GetY() == rhs.GetY() && GetZ() == rhs.GetZ())
            return true;
        return false;
    }
    bool operator!=(vector3D& rhs) {
        if (GetX() != rhs.GetX() || GetY() != rhs.GetY() || GetZ() != rhs.GetZ())
            return true;
        return false;
    }
    bool operator<(vector3D& rhs) {
        if (GetX() < rhs.GetX() && GetY() < rhs.GetY() && GetZ() < rhs.GetZ())
            return true;
        return false;
    }
    bool operator>(vector3D& rhs) {
        if (GetX() > rhs.GetX() && GetY() > rhs.GetY() && GetZ() > rhs.GetZ())
            return true;
        return false;
    }
    bool operator<=(vector3D rhs) {
        if (GetX() <= rhs.GetX() && GetY() <= rhs.GetY() && GetZ() <= rhs.GetZ())
            return true;
        return false;
    }
    bool operator>=(vector3D rhs) {
        if (GetX() >= rhs.GetX() && GetY() >= rhs.GetY() && GetZ() >= rhs.GetZ())
            return true;
        return false;
    }

    // get and set with brackets
    float& operator[] (const int x)
    {
        return cord[x];
    }
    float operator[] (const int x) const
    {
        return cord[x];
    }

private:
    float cord[3];
};

class vector4D
{
public:

    // constructors
    explicit vector4D(float x = 0, float y = 0, float z = 0, float w = 1) {
        cord[0] = x; cord[1] = y; cord[2] = z; cord[3] = w;
    }
    ~vector4D() = default;

    // Get and set func
    void Set(float x, float y, float z, float w) {
        cord[0] = x;
        cord[1] = y;
        cord[2] = z;
        cord[3] = w;
    }
    void SetX(float x) {
        cord[0] = x;
    }
    void SetY(float y) {
        cord[1] = y;
    }
    void SetZ(float z) {
        cord[2] = z;
    }
    void SetW(float w) {
        cord[3] = w;
    }

    float GetX() const {
        return cord[0];
    }
    float GetY() const {
        return cord[1];
    }
    float GetZ() const {
        return cord[2];
    }
    float GetW() const {
        return cord[3];
    }
    float* GetPointer() {
        return cord;
    }

    // easy print func for debug
    inline void Print() const {
        printf("X: %0.1f : Y: %0.1f : Z: %0.1f : W: %0.1f\n", GetX(), GetY(), GetZ(), GetW());
    }

    // Normalize, Cross and Dot func
    float Length() const {
        return sqrt((GetX() * GetX()) + (GetY() * GetY()) + (GetZ() * GetZ()));
    }
    vector4D Normalize() const {
        float length = 1.0f / Length();
        return vector4D((GetX() * length), (GetY() * length), (GetZ() * length), 1.0f);
    }
    static const vector4D Cross(vector4D lhs, vector4D rhs) {
        return vector4D((lhs.cord[1] * rhs.cord[2] - lhs.cord[2] * rhs.cord[1]),
                        (lhs.cord[2] * rhs.cord[0] - lhs.cord[0] * rhs.cord[2]),
                        (lhs.cord[0] * rhs.cord[1] - lhs.cord[1] * rhs.cord[0]),
                        1.0f);
    }
    static const float Dot(vector4D lhs, vector4D rhs) {
        return ((lhs.GetX() * rhs.GetX()) + (lhs.GetY() * rhs.GetY()) + (lhs.GetZ() * rhs.GetZ()));
    }

    // operators
    vector4D operator*(float rhs) {
        return vector4D(GetX() * rhs, GetY() * rhs, GetZ() * rhs, 1.0f);
    }
    vector4D operator+(vector4D rhs) {
        return vector4D(GetX() + rhs.GetX(), GetY() + rhs.GetY(), GetZ() + rhs.GetZ());
    }
    vector4D operator-(vector4D rhs) {
        return vector4D(GetX() - rhs.GetX(), GetY() - rhs.GetY(), GetZ() - rhs.GetZ());
    }
    void operator+=(vector4D rhs) {
        Set(GetX() + rhs.GetX(), GetY() + rhs.GetY(), GetZ() + rhs.GetZ(), 1.0f);
    }
    void operator-=(vector4D rhs) {
        Set(GetX() - rhs.GetX(), GetY() - rhs.GetY(), GetZ() - rhs.GetZ(), 1.0f);
    }

    // get and set with brackets
    float& operator[] (const int x)
    {
        return cord[x];
    }
    float operator[] (const int x) const
    {
        return cord[x];
    }

private:
    float cord[4];
};

class matrix2D
{
public:
    // constructors
    matrix2D() {
        matrix[0][0] = 1.0f;
        matrix[0][1] = 0.0f;
        matrix[1][0] = 0.0f;
        matrix[1][1] = 1.0f;
    }
    matrix2D(float x1, float y1, float x2, float y2) {
        matrix[0][0] = x1;
        matrix[0][1] = y1;
        matrix[1][0] = x2;
        matrix[1][1] = y2;
    }
    matrix2D(vector2D lhs, vector2D rhs) {
        matrix[0][0] = lhs.GetX();
        matrix[0][1] = lhs.GetY();
        matrix[1][0] = rhs.GetX();
        matrix[1][1] = rhs.GetY();
    }
    matrix2D(float degrees)
    {
        matrix[0][0] = cos(degrees);
        matrix[0][1] = -sin(degrees);
        matrix[1][0] = sin(degrees);
        matrix[1][1] = cos(degrees);
    }
    ~matrix2D() = default;

    // Get and set func
    void Set(float x1, float y1, float x2, float y2) {
        matrix[0][0] = x1;
        matrix[0][1] = y1;
        matrix[1][0] = x2;
        matrix[1][1] = y2;
    }
    void SetX1(float x1) {
        matrix[0][0] = x1;
    }
    void SetY1(float y1) {
        matrix[0][1] = y1;
    }
    void SetX2(float x2) {
        matrix[1][0] = x2;
    }
    void SetY2(float y2) {
        matrix[1][1] = y2;
    }

    float GetX1() const {
        return matrix[0][0];
    };
    float GetY1() const {
        return matrix[0][1];
    };
    float GetX2() const {
        return matrix[1][0];
    };
    float GetY2() const {
        return matrix[1][1];
    };
    void  Print() const {
        printf("Matrix = %0.1f : %0.1f \n          %0.1f : %0.1f\n", matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
    }

    void Set(float degrees)
    {
        matrix[0][0] = cos(degrees);
        matrix[0][1] = -sin(degrees);
        matrix[1][0] = sin(degrees);
        matrix[1][1] = cos(degrees);
    }
    void Rot(float degrees)
    {
        matrix[0][0] = matrix[0][0] * cos(degrees);
        matrix[0][1] = matrix[0][1] * -sin(degrees);
        matrix[1][0] = matrix[1][0] * sin(degrees);
        matrix[1][1] = matrix[1][1] * cos(degrees);
    }
    void Transponat()
    {
        matrix2D temp;
        temp = *this;
        this->matrix[0][1] = temp.matrix[1][0];
        this->matrix[1][0] = temp.matrix[0][1];
    }

    // operators
    void operator=(matrix2D& rhs)  {
        Set(rhs.GetX1(), rhs.GetY1(), rhs.GetX2(), rhs.GetY2());
    }
    matrix2D operator*(float rhs) {
        return matrix2D(GetX1() * rhs, GetY1() * rhs, GetX2() * rhs, GetY2() * rhs);
    }
    vector2D operator*(vector2D rhs) {
        return vector2D(this->GetX1() * rhs.GetX() + this->GetY1() * rhs.GetY(),
                        this->GetX2() * rhs.GetX() + this->GetY2() * rhs.GetY());
    }
    matrix2D operator*(matrix2D rhs) {
        return (((this->matrix[0][0] * rhs.matrix[0][0]) + (this->matrix[0][1] * rhs.matrix[1][0])),
                ((this->matrix[0][0] * rhs.matrix[0][1]) + (this->matrix[0][1] * rhs.matrix[1][1])),
                ((this->matrix[1][0] * rhs.matrix[0][0]) + (this->matrix[1][1] * rhs.matrix[1][0])),
                ((this->matrix[1][0] * rhs.matrix[0][1]) + (this->matrix[1][1] * rhs.matrix[1][1])));
    }

private:
    float matrix[2][2];
};

class matrix3D
{
public:

    // constructors
    matrix3D();
    matrix3D(float x1, float y1, float x2, float y2) {
        matrix[0][0] = x1; matrix[0][1] = y1; matrix[0][2] = 0;
        matrix[1][0] = x2; matrix[1][1] = y1; matrix[1][2] = 0;
        matrix[2][0] = 0;  matrix[2][1] = 0;  matrix[2][2] = 1;
    }
    matrix3D(float degrees) {
        matrix[0][0] = cos(degrees); matrix[0][1] = -sin(degrees); matrix[0][2] = 0;
        matrix[1][0] = sin(degrees); matrix[1][1] = cos(degrees);  matrix[1][2] = 0;
        matrix[2][0] = 0;            matrix[2][1] = 0;             matrix[2][2] = degrees;
    }
    matrix3D(vector2D v) {
        for (int j = 0; j < 3; ++j)
            for (int i = 0; i < 2; ++i)
                matrix[i][j] = 0.0f;
        matrix[0][0] = 1.0f;
        matrix[1][1] = 1.0f;
        matrix[2][2] = 1.0f;
        SetPosition(v);
    }
    matrix3D(float x, float y) {
        for (int j = 0; j < 3; ++j)
            for (int i = 0; i < 2; ++i)
                matrix[i][j] = 0.0f;
        matrix[0][0] = 1.0f;
        matrix[1][1] = 1.0f;
        matrix[2][2] = 1.0f;
        SetPosition(x, y);
    }
    ~matrix3D() = default;

    // get and set func
    void Set(float x1, float y1, float x2, float y2) {
        matrix[0][0] = x1; matrix[0][1] = y1;
        matrix[1][0] = x2; matrix[1][1] = y1;
                                              matrix[2][2] = 1;
    }
    void SetX1(float x1) {
        matrix[0][0] = x1;
    }
    void SetY1(float y1) {
        matrix[0][1] = y1;
    }
    void SetX2(float x2) {
        matrix[1][0] = x2;
    }
    void SetY2(float y2) {
        matrix[1][1] = y2;
    }

    float GetX1() {
        return matrix[0][0];
    }
    float GetY1() {
        return matrix[0][1];
    }
    float GetX2() {
        return matrix[1][0];
    }
    float GetY2() {
        return matrix[1][1];
    }

    void Set(float degrees) {
        matrix[0][0] = cos(degrees); matrix[0][1] = -sin(degrees);
        matrix[1][0] = sin(degrees); matrix[1][1] = cos(degrees);
                                                                   matrix[2][2] = degrees;
    }
    void SetSize(float x, float y) {
        matrix[2][0] = x;
        matrix[2][1] = y;
    }
    void SetPosition(vector2D v) {
        matrix[0][2] = v.GetX();
        matrix[1][2] = v.GetY();
    }
    void SetPosition(float x, float y) {
        matrix[0][2] = x;
        matrix[1][2] = y;
    }
    vector2D GetSize() {
        return vector2D(matrix[2][0], matrix[2][1]);
    }
    vector2D GetPosition() {
        return vector2D(matrix[0][2], matrix[1][2]);
    }

    void Rot(float degrees) {
        matrix[0][0] = matrix[0][0] * cos(degrees);
        matrix[0][1] = matrix[0][1] * -sin(degrees);
        matrix[1][0] = matrix[1][0] * sin(degrees);
        matrix[1][1] = matrix[1][1] * cos(degrees);
    }
    void Transpose() {
        matrix3D temp;
        temp = *this;
        this->matrix[0][1] = temp.matrix[1][0];
        this->matrix[1][0] = temp.matrix[0][1];
    }
    vector2D operator*(vector2D& rhs) {
         return vector2D(this->GetX1() * rhs.GetX() + this->GetY1() * rhs.GetY(),
                         this->GetX2() * rhs.GetX() + this->GetY2() * rhs.GetY());

    }

private:
    float matrix[3][3];
};

class matrix4D
{
public:
    matrix4D(float x1 = 1, float y1 = 0, float z1 = 0, float w1 = 0,
             float x2 = 0, float y2 = 1, float z2 = 0, float w2 = 0,
             float x3 = 0, float y3 = 0, float z3 = 1, float w3 = 0,
             float x4 = 0, float y4 = 0, float z4 = 0, float w4 = 1) {
        matrix[0][0] = x1; matrix[0][1] = y1; matrix[0][2] = z1; matrix[0][3] = w1;
        matrix[1][0] = x2; matrix[1][1] = y2; matrix[1][2] = z2; matrix[1][3] = w2;
        matrix[2][0] = x3; matrix[2][1] = y3; matrix[2][2] = z3; matrix[2][3] = w3;
        matrix[3][0] = x4; matrix[3][1] = y4; matrix[3][2] = z4; matrix[3][3] = w4;
        GetArr();
    }
    matrix4D(vector4D R, vector4D U, vector4D D) {
        matrix4D(R.GetX(), R.GetY(), R.GetZ(), 0,
                 U.GetX(), U.GetY(), U.GetZ(), 0,
                 D.GetX(), D.GetY(), D.GetZ(), 0,
                 0,0,0,1);
        GetArr();
    }
    ~matrix4D() = default;

    void Set(float x1, float y1, float z1, float w1,
             float x2, float y2, float z2, float w2,
             float x3, float y3, float z3, float w3,
             float x4, float y4, float z4, float w4)
    {
        matrix[0][0] = x1; matrix[0][1] = y1; matrix[0][2] = z1; matrix[0][3] = w1;
        matrix[1][0] = x2; matrix[1][1] = y2; matrix[1][2] = z2; matrix[1][3] = w2;
        matrix[2][0] = x3; matrix[2][1] = y3; matrix[2][2] = z3; matrix[2][3] = w3;
        matrix[3][0] = x4; matrix[3][1] = y4; matrix[3][2] = z4; matrix[3][3] = w4;
    }
    void SetI() {
        matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
        matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
        matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = 0.0f;
        matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
    }

    matrix4D RotX(float degrees) {
        float c = cos(degrees), s = sin(degrees);

        return matrix4D
                (
                        1, 0, 0, 0,
                        0, c, -s, 0,
                        0, s, c, 0,
                        0, 0, 0, 1
                );
    }
    matrix4D RotY(float degrees) {
        float c = cos(degrees), s = sin(degrees);

        return matrix4D
                (
                        c, 0, s, 0,
                        0, 1, 0, 0,
                        -s, 0, c, 0,
                        0, 0, 0, 1
                );
    }
    matrix4D RotZ(float degrees) {
        float c = cos(degrees), s = sin(degrees);

        return matrix4D
                (
                        c, -s, 0, 0,
                        s, c, 0, 0,
                        0, 0, 1, 0,
                        0, 0, 0, 1
                );
    }
    Matrix4D RotAroundVector(vector4D vec, float degrees) {
        float Cos = cos(degrees);
        float Sin = sin(degrees);
        float x = vec.GetX(), y = vec.GetY(), z = vec.GetZ();

        return Matrix4D
                (
                        x*x*(1 - Cos) + Cos, y*x*(1 - Cos) - z * Sin, z*x*(1 - Cos) + y * Sin, 0,
                        x*y*(1 - Cos) + z * Sin, y*y*(1 - Cos) + Cos, z*y*(1 - Cos) - x * Sin, 0,
                        x*z*(1 - Cos) - y * Sin, y*z*(1 - Cos) + x * Sin, z*z*(1 - Cos) + Cos, 0
                );
    }

    void Transpose() {
        matrix4D temp;
        temp = *this;

        this->matrix[0][1] = temp.matrix[1][0]; // 1
        this->matrix[1][0] = temp.matrix[0][1]; // 2

        this->matrix[0][2] = temp.matrix[2][0]; // 3
        this->matrix[2][0] = temp.matrix[0][2]; // 4

        this->matrix[1][2] = temp.matrix[2][1]; // 5
        this->matrix[2][1] = temp.matrix[1][2]; // 6

        this->matrix[0][3] = temp.matrix[3][0]; // 7
        this->matrix[3][0] = temp.matrix[0][3]; // 8

        this->matrix[1][3] = temp.matrix[3][1]; // 9
        this->matrix[3][1] = temp.matrix[1][3]; // 10

        this->matrix[2][3] = temp.matrix[3][2]; // 11
        this->matrix[3][2] = temp.matrix[2][3]; // 12

        GetArr();

        temp.~matrix4D();
    }
    void InversThis()
    {
        GetArr();
        float inv[16], det;
        int i;

        inv[0] = arr[5] * arr[10] * arr[15] -
                 arr[5] * arr[11] * arr[14] -
                 arr[9] * arr[6] * arr[15] +
                 arr[9] * arr[7] * arr[14] +
                 arr[13] * arr[6] * arr[11] -
                 arr[13] * arr[7] * arr[10];

        inv[4] = -arr[4] * arr[10] * arr[15] +
                 arr[4] * arr[11] * arr[14] +
                 arr[8] * arr[6] * arr[15] -
                 arr[8] * arr[7] * arr[14] -
                 arr[12] * arr[6] * arr[11] +
                 arr[12] * arr[7] * arr[10];

        inv[8] = arr[4] * arr[9] * arr[15] -
                 arr[4] * arr[11] * arr[13] -
                 arr[8] * arr[5] * arr[15] +
                 arr[8] * arr[7] * arr[13] +
                 arr[12] * arr[5] * arr[11] -
                 arr[12] * arr[7] * arr[9];

        inv[12] = -arr[4] * arr[9] * arr[14] +
                  arr[4] * arr[10] * arr[13] +
                  arr[8] * arr[5] * arr[14] -
                  arr[8] * arr[6] * arr[13] -
                  arr[12] * arr[5] * arr[10] +
                  arr[12] * arr[6] * arr[9];

        inv[1] = -arr[1] * arr[10] * arr[15] +
                 arr[1] * arr[11] * arr[14] +
                 arr[9] * arr[2] * arr[15] -
                 arr[9] * arr[3] * arr[14] -
                 arr[13] * arr[2] * arr[11] +
                 arr[13] * arr[3] * arr[10];

        inv[5] = arr[0] * arr[10] * arr[15] -
                 arr[0] * arr[11] * arr[14] -
                 arr[8] * arr[2] * arr[15] +
                 arr[8] * arr[3] * arr[14] +
                 arr[12] * arr[2] * arr[11] -
                 arr[12] * arr[3] * arr[10];

        inv[9] = -arr[0] * arr[9] * arr[15] +
                 arr[0] * arr[11] * arr[13] +
                 arr[8] * arr[1] * arr[15] -
                 arr[8] * arr[3] * arr[13] -
                 arr[12] * arr[1] * arr[11] +
                 arr[12] * arr[3] * arr[9];

        inv[13] = arr[0] * arr[9] * arr[14] -
                  arr[0] * arr[10] * arr[13] -
                  arr[8] * arr[1] * arr[14] +
                  arr[8] * arr[2] * arr[13] +
                  arr[12] * arr[1] * arr[10] -
                  arr[12] * arr[2] * arr[9];

        inv[2] = arr[1] * arr[6] * arr[15] -
                 arr[1] * arr[7] * arr[14] -
                 arr[5] * arr[2] * arr[15] +
                 arr[5] * arr[3] * arr[14] +
                 arr[13] * arr[2] * arr[7] -
                 arr[13] * arr[3] * arr[6];

        inv[6] = -arr[0] * arr[6] * arr[15] +
                 arr[0] * arr[7] * arr[14] +
                 arr[4] * arr[2] * arr[15] -
                 arr[4] * arr[3] * arr[14] -
                 arr[12] * arr[2] * arr[7] +
                 arr[12] * arr[3] * arr[6];

        inv[10] = arr[0] * arr[5] * arr[15] -
                  arr[0] * arr[7] * arr[13] -
                  arr[4] * arr[1] * arr[15] +
                  arr[4] * arr[3] * arr[13] +
                  arr[12] * arr[1] * arr[7] -
                  arr[12] * arr[3] * arr[5];

        inv[14] = -arr[0] * arr[5] * arr[14] +
                  arr[0] * arr[6] * arr[13] +
                  arr[4] * arr[1] * arr[14] -
                  arr[4] * arr[2] * arr[13] -
                  arr[12] * arr[1] * arr[6] +
                  arr[12] * arr[2] * arr[5];

        inv[3] = -arr[1] * arr[6] * arr[11] +
                 arr[1] * arr[7] * arr[10] +
                 arr[5] * arr[2] * arr[11] -
                 arr[5] * arr[3] * arr[10] -
                 arr[9] * arr[2] * arr[7] +
                 arr[9] * arr[3] * arr[6];

        inv[7] = arr[0] * arr[6] * arr[11] -
                 arr[0] * arr[7] * arr[10] -
                 arr[4] * arr[2] * arr[11] +
                 arr[4] * arr[3] * arr[10] +
                 arr[8] * arr[2] * arr[7] -
                 arr[8] * arr[3] * arr[6];

        inv[11] = -arr[0] * arr[5] * arr[11] +
                  arr[0] * arr[7] * arr[9] +
                  arr[4] * arr[1] * arr[11] -
                  arr[4] * arr[3] * arr[9] -
                  arr[8] * arr[1] * arr[7] +
                  arr[8] * arr[3] * arr[5];

        inv[15] = arr[0] * arr[5] * arr[10] -
                  arr[0] * arr[6] * arr[9] -
                  arr[4] * arr[1] * arr[10] +
                  arr[4] * arr[2] * arr[9] +
                  arr[8] * arr[1] * arr[6] -
                  arr[8] * arr[2] * arr[5];

        det = arr[0] * inv[0] + arr[1] * inv[4] + arr[2] * inv[8] + arr[3] * inv[12];

        if (det == 0)
        {
            printf("Invalid invers: identity returned\n");
            SetI();
            return;
        }

        det = 1.0 / det;

        for (i = 0; i < 16; i++)
            arr[i] = inv[i] * det;
        MakeToMatrix();
    }

    void GetArr()
    {
        int index = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                arr[index] = this->matrix[i][j];
                index++;
            }
    }
    void MakeToMatrix()
    {
        Set(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9], arr[10], arr[11], arr[12], arr[13], arr[14], arr[15]);
    }

    float* GetPointer() {
        return arr;
    }

    matrix4D lookAt(vector4D cameraPosition, vector4D cameraTarget, vector4D cameraUp) {
        vector4D f = (cameraTarget - cameraPosition).Normalize();
        vector4D u = cameraUp.Normalize();
        vector4D s = vector4D::Cross(f, u).Normalize();
        u = vector4D::Cross(s, f);

        matrix4D Result;
        Result.matrix[0][0] = s.GetX();
        Result.matrix[1][0] = s.GetY();
        Result.matrix[2][0] = s.GetZ();
        Result.matrix[0][1] = u.GetX();
        Result.matrix[1][1] = u.GetY();
        Result.matrix[2][1] = u.GetZ();
        Result.matrix[0][2] = -f.GetX();
        Result.matrix[1][2] = -f.GetY();
        Result.matrix[2][2] = -f.GetZ();
        Result.matrix[3][0] = -(vector4D::Dot(s, cameraPosition));
        Result.matrix[3][1] = -(vector4D::Dot(u, cameraPosition));
        Result.matrix[3][2] =  (vector4D::Dot(f, cameraPosition));
        Result.Transpose();
        return Result;
    }


    matrix4D operator/(float rhs)
    {
        return matrix4D(
                matrix[0][0] / rhs, matrix[0][1] / rhs, matrix[0][2] / rhs, matrix[0][3] / rhs,
                matrix[1][0] / rhs, matrix[1][1] / rhs, matrix[1][2] / rhs, matrix[1][3] / rhs,
                matrix[2][0] / rhs, matrix[2][1] / rhs, matrix[2][2] / rhs, matrix[2][3] / rhs,
                matrix[3][0] / rhs, matrix[3][1] / rhs, matrix[3][2] / rhs, matrix[3][3] / rhs);
    }
    matrix4D operator*(float rhs)
    {
        return matrix4D(
                matrix[0][0] * rhs, matrix[0][1] * rhs, matrix[0][2] * rhs, matrix[0][3] * rhs,
                matrix[1][0] * rhs, matrix[1][1] * rhs, matrix[1][2] * rhs, matrix[1][3] * rhs,
                matrix[2][0] * rhs, matrix[2][1] * rhs, matrix[2][2] * rhs, matrix[2][3] * rhs,
                matrix[3][0] * rhs, matrix[3][1] * rhs, matrix[3][2] * rhs, matrix[3][3] * rhs);
    }
    vector4D operator*(vector4D rhs)
    {
        return vector4D
                (matrix[0][0] * rhs.GetX() + matrix[0][1] * rhs.GetY() + matrix[0][2] * rhs.GetZ(),
                        matrix[1][0] * rhs.GetX() + matrix[1][1] * rhs.GetY() + matrix[1][2] * rhs.GetZ(),
                        matrix[2][0] * rhs.GetX() + matrix[2][1] * rhs.GetY() + matrix[2][2] * rhs.GetZ(),
                        matrix[3][0] * rhs.GetX() + matrix[3][1] * rhs.GetY() + matrix[3][2] * rhs.GetZ()
                );
    }
    matrix4D operator*(matrix4D rhs)
    {
        return matrix4D
                (
                        matrix[0][0] * rhs.matrix[0][0] + matrix[0][1] * rhs.matrix[1][0] + matrix[0][2] * rhs.matrix[2][0] + matrix[0][3] * rhs.matrix[3][0],
                        matrix[0][0] * rhs.matrix[0][1] + matrix[0][1] * rhs.matrix[1][1] + matrix[0][2] * rhs.matrix[2][1] + matrix[0][3] * rhs.matrix[3][1],
                        matrix[0][0] * rhs.matrix[0][2] + matrix[0][1] * rhs.matrix[1][2] + matrix[0][2] * rhs.matrix[2][2] + matrix[0][3] * rhs.matrix[3][2],
                        matrix[0][0] * rhs.matrix[0][3] + matrix[0][1] * rhs.matrix[1][3] + matrix[0][2] * rhs.matrix[2][3] + matrix[0][3] * rhs.matrix[3][3],
                        matrix[1][0] * rhs.matrix[0][0] + matrix[1][1] * rhs.matrix[1][0] + matrix[1][2] * rhs.matrix[2][0] + matrix[1][3] * rhs.matrix[3][0],
                        matrix[1][0] * rhs.matrix[0][1] + matrix[1][1] * rhs.matrix[1][1] + matrix[1][2] * rhs.matrix[2][1] + matrix[1][3] * rhs.matrix[3][1],
                        matrix[1][0] * rhs.matrix[0][2] + matrix[1][1] * rhs.matrix[1][2] + matrix[1][2] * rhs.matrix[2][2] + matrix[1][3] * rhs.matrix[3][2],
                        matrix[1][0] * rhs.matrix[0][3] + matrix[1][1] * rhs.matrix[1][3] + matrix[1][2] * rhs.matrix[2][3] + matrix[1][3] * rhs.matrix[3][3],
                        matrix[2][0] * rhs.matrix[0][0] + matrix[2][1] * rhs.matrix[1][0] + matrix[2][2] * rhs.matrix[2][0] + matrix[2][3] * rhs.matrix[3][0],
                        matrix[2][0] * rhs.matrix[0][1] + matrix[2][1] * rhs.matrix[1][1] + matrix[2][2] * rhs.matrix[2][1] + matrix[2][3] * rhs.matrix[3][1],
                        matrix[2][0] * rhs.matrix[0][2] + matrix[2][1] * rhs.matrix[1][2] + matrix[2][2] * rhs.matrix[2][2] + matrix[2][3] * rhs.matrix[3][2],
                        matrix[2][0] * rhs.matrix[0][3] + matrix[2][1] * rhs.matrix[1][3] + matrix[2][2] * rhs.matrix[2][3] + matrix[2][3] * rhs.matrix[3][3],
                        matrix[3][0] * rhs.matrix[0][0] + matrix[3][1] * rhs.matrix[1][0] + matrix[3][2] * rhs.matrix[2][0] + matrix[3][3] * rhs.matrix[3][0],
                        matrix[3][0] * rhs.matrix[0][1] + matrix[3][1] * rhs.matrix[1][1] + matrix[3][2] * rhs.matrix[2][1] + matrix[3][3] * rhs.matrix[3][1],
                        matrix[3][0] * rhs.matrix[0][2] + matrix[3][1] * rhs.matrix[1][2] + matrix[3][2] * rhs.matrix[2][2] + matrix[3][3] * rhs.matrix[3][2],
                        matrix[3][0] * rhs.matrix[0][3] + matrix[3][1] * rhs.matrix[1][3] + matrix[3][2] * rhs.matrix[2][3] + matrix[3][3] * rhs.matrix[3][3]
                );
    }
    void operator+=(matrix4D rhs)
    {
                matrix[0][0] += rhs.matrix[0][0], matrix[0][1] += rhs.matrix[0][1], matrix[0][2] += rhs.matrix[0][2], matrix[0][3] += rhs.matrix[0][3],
                matrix[1][0] += rhs.matrix[1][0], matrix[1][1] += rhs.matrix[1][1], matrix[1][2] += rhs.matrix[1][2], matrix[1][3] += rhs.matrix[1][3],
                matrix[2][0] += rhs.matrix[2][0], matrix[2][1] += rhs.matrix[2][1], matrix[2][2] += rhs.matrix[2][2], matrix[2][3] += rhs.matrix[2][3],
                matrix[3][0] += rhs.matrix[3][0], matrix[3][1] += rhs.matrix[3][1], matrix[3][2] += rhs.matrix[3][2];
    }

private:
    float matrix[4][4];
    float arr[16];
};

#endif //MATHLIB_H
