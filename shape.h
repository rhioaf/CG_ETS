/*
    File: shape.h
    Deskripsi:
    Author: Rhio Adjie Fabian / 181511064
*/

#ifndef shape_H
#define shape_H
#include "stroke.h"

void drawRect(dt_pilihan data, int width, int height);
void drawSquare(dt_pilihan data, int width);
void drawTriangle(dt_pilihan data, int height, int base, bool direction);
void drawTriangleSameSide(dt_pilihan data, int side);
void drawParallelogram(dt_pilihan data, int base, int height);
void drawDiamond(dt_pilihan data, int d1, int d2);
void drawTrapezoid(dt_pilihan data, int b1, int b2, int height);
void drawTrapezoidV2(dt_pilihan data, int b1, int b2, int height);
void drawSquareAnimate(dt_pilihan data, int width);

// Rotation section for every shape
void drawRectRotate(dt_pilihan data, int width, int height, int angle);
void drawSquareRotate(dt_pilihan data, int width, int angle);
void drawTriangleRotate(dt_pilihan data, int height, int base, bool direction, int angle);
void drawTriangleSameSideRotate(dt_pilihan data, int side, int angle);
void drawParallelogramRotate(dt_pilihan data, int base, int height, int angle);
void drawDiamondRotate(dt_pilihan data, int sideTgl, int angle);
void drawTrapezoidV2Rotate(dt_pilihan data, int b1, int b2, int height, int angle);

// Rotation Update
void drawRectRotateWithRotationPoint(hinomaruOogi data, int angle, bool rotateAct, int situation);
void drawRectHinomaru(hinomaruOogi data);
void drawHinomaru(hinomaruOogi dataCrest);



#endif // shape_H


