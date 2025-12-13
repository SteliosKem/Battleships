#ifndef TE_MATH_H
#define TE_MATH_H

#include <math.h>

extern const float PI;

// 2-Dimensial Vector Object
typedef struct Vec2 {
    float x;
    float y;
} Vec2;

// 3-Dimensial Vector Object
typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

// 4x4 Square Matrix Object
typedef struct Mat4 {
    float mat[4][4];
} Mat4;

// Calculates the cross product of vectors a and b and outputs it in out.
void cross(Vec3* a, Vec3* b, Vec3* c);
// Normalizes the input vector to length 1.
void normalize(Vec3* in);

// Computes the matrix vector product and outputs it to the vector ptr "out".
void matXvec(Mat4* matrix, Vec3* in, Vec3* out);

#endif