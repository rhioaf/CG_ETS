#include "stroke.h"
#include "shape.h"
//#include "util.h"
#include <graphics.h>
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;
void drawRect(dt_pilihan data, int width, int height){
    koordinat topLeft, topRight, botRight, botLeft;
    // koordinat top left
    topLeft = data.koor1;

    // koordinat top right
    topRight.x = data.koor1.x + width;
    topRight.y = data.koor1.y;

    // koordinat bot right
    botRight.x = data.koor1.x + width;
    botRight.y = data.koor1.y + height;

    // koordinat bot left
    botLeft.x = data.koor1.x;
    botLeft.y = data.koor1.y + height;

    // Check if shape should scale or not
    if(data.scalingOption){
        // Scale top left
        topLeft.x *= data.scaling;
        topLeft.y *= data.scaling;

        // Scale top right
        topRight.x *= data.scaling;
        topRight.y *= data.scaling;

        // Scale bot left
        botLeft.x *= data.scaling;
        botLeft.y *= data.scaling;

        // Scale bot right
        botRight.x *= data.scaling;
        botRight.y *= data.scaling;
    }
    // set destination ke koor 1 dan 2
    data.koor1 = topLeft;
    data.koor2 = topRight;

    // draw (topLeft to topRight)
    drawLineDDAStyle(data);

    // set new start and destination point (topRight to botRight)
    data.koor1 = topRight;
    data.koor2 = botRight;
    drawLineDDAStyle(data);

    // set new start and destination point (topLeft to botLeft)
    data.koor1 = topLeft;
    data.koor2 = botLeft;
    drawLineDDAStyle(data);

    // set new start and destination point (botLeft to botRight)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    drawLineDDAStyle(data);
}

void drawSquare(dt_pilihan data, int width){
    koordinat topLeft, topRight, botRight, botLeft;
    // koordinat top left
    topLeft = data.koor1;

    // koordinat top right
    topRight.x = data.koor1.x + width;
    topRight.y = data.koor1.y;

    // koordinat bot right
    botRight.x = data.koor1.x + width;
    botRight.y = data.koor1.y + width;

    // koordinat bot left
    botLeft.x = data.koor1.x;
    botLeft.y = data.koor1.y + width;

    // Check if shape should scale or not
    if(data.scalingOption){
        // Scale top left
        topLeft.x *= data.scaling;
        topLeft.y *= data.scaling;

        // Scale top right
        topRight.x *= data.scaling;
        topRight.y *= data.scaling;

        // Scale bot left
        botLeft.x *= data.scaling;
        botLeft.y *= data.scaling;

        // Scale bot right
        botRight.x *= data.scaling;
        botRight.y *= data.scaling;
    }
    // set destination ke koor 1 dan 2
    data.koor1 = topLeft;
    data.koor2 = topRight;

    // draw (topLeft to topRight)
    drawLineDDAStyle(data);

    // set new start and destination point (topRight to botRight)
    data.koor1 = topRight;
    data.koor2 = botRight;
    drawLineDDAStyle(data);

    // set new start and destination point (topLeft to botLeft)
    data.koor1 = topLeft;
    data.koor2 = botLeft;
    drawLineDDAStyle(data);

    // set new start and destination point (botLeft to botRight)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    drawLineDDAStyle(data);
}

void drawTriangle(dt_pilihan data, int height, int base, bool direction){
    koordinat topLeft, botLeft, botRight;
    // koordinat top center
    topLeft = data.koor1;

    // koordinat bot left
    botLeft.x = topLeft.x;
    botLeft.y = topLeft.y + height;

    // koordinat bot right
    if(direction){ // untuk menentukan arah segitiga ke kanan atau ke kiri * true ke kanan
        botRight.x = botLeft.x + base;
        botRight.y = botLeft.y;
    } else {
        botRight.x = botLeft.x + (base * -1);
        botRight.y = botLeft.y;
    }

    if(data.scalingOption){
        topLeft.x *= data.scaling;
        topLeft.y *= data.scaling;

        botLeft.x *= data.scaling;
        botLeft.y *= data.scaling;

        botRight.x *= data.scaling;
        botRight.y *= data.scaling;
    }

    // draw (top left to bot left)
    data.koor1 = topLeft;
    data.koor2 = botLeft;
    drawLineDDAStyle(data);

    // set new destination point (top center to bot right)
    data.koor2 = botRight;
    drawLineDDAStyle(data);

    // set new start and destination point (bot left to bot right)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    drawLineDDAStyle(data);
}

void drawTriangleSameSide(dt_pilihan data, int side){
    int base = abs(side/2);
    int height = sqrt(pow(side, 2) - pow(base, 2));
    koordinat topCenter, botLeft, botRight;
    // koordinat top center
    topCenter = data.koor1;

    // koordinat bot left
    botLeft.x = topCenter.x - base;
    botLeft.y = topCenter.y + height;

    // koordinat bot right
    botRight.x = topCenter.x + base;
    botRight.y = botLeft.y;

    if(data.scalingOption){
        topCenter.x *= data.scaling;
        topCenter.y *= data.scaling;

        botLeft.x *= data.scaling;
        botLeft.y *= data.scaling;

        botRight.x *= data.scaling;
        botRight.y *= data.scaling;
    }

    // draw (top left to bot left)
    data.koor1 = topCenter;
    data.koor2 = botLeft;
    drawLineDDAStyle(data);

    // set new destination point (top center to bot right)
    data.koor2 = botRight;
    drawLineDDAStyle(data);

    // set new start and destination point (bot left to bot right)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    drawLineDDAStyle(data);
}

void drawParallelogram(dt_pilihan data, int base, int height){
    int diff;
    koordinat topLeft, topRight, botRight, botLeft;
    diff = abs((40 * base)/100);
    topLeft = data.koor1;

    // koordinat top right
    topRight.x = topLeft.x + base;
    topRight.y = topLeft.y;

    // koordinat bot left
    botLeft.x = topLeft.x - diff;
    botLeft.y = topLeft.y + height;

    // koordinat bot right
    botRight.x = botLeft.x + base;
    botRight.y = botLeft.y;

    if(data.scalingOption){
        topLeft.x *= data.scaling;
        topLeft.y *= data.scaling;

        topRight.x *= data.scaling;
        topRight.y *= data.scaling;

        botLeft.x *= data.scaling;
        botLeft.y *= data.scaling;

        botRight.x *= data.scaling;
        botRight.y *= data.scaling;
    }

    // draw (top left to top right)
    data.koor1 = topLeft;
    data.koor2 = topRight;
    drawLineDDAStyle(data);

    // set new destination (top left to bot left)
    data.koor2 = botLeft;
    drawLineDDAStyle(data);

    // set start and destination (bot left to bot right)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    drawLineDDAStyle(data);

    // set start and new destination (top right to bot right)
    data.koor1 = topRight;
    data.koor2 = botRight;
    drawLineDDAStyle(data);
}

void drawDiamond(dt_pilihan data, int d1 /* panjang */, int d2 /* tinggi */){
    koordinat bottom, left, right, center, top;
    int centerLength = abs(d1 / 2);
    top = data.koor1;

    // calculation center point
    center.x = top.x;
    center.y = top.y + abs(d2/2);

    // koordinat bottom
    bottom.x = top.x;
    bottom.y = top.y + d2;

    // koordinat left
    left.x = top.x - centerLength;
    left.y = center.y;

    // koordinat right
    right.x = top.x + centerLength;
    right.y = center.y;

    if(data.scalingOption){
        top.x *= data.scaling;
        top.y *= data.scaling;

        left.x *= data.scaling;
        left.y *= data.scaling;

        right.x *= data.scaling;
        right.y *= data.scaling;

        bottom.x *= data.scaling;
        bottom.y *= data.scaling;
    }

    // draw (top to left)
    data.koor1 = top;
    data.koor2 = left;
    drawLineDDAStyle(data);

    // draw top to right
    data.koor2 = right;
    drawLineDDAStyle(data);

    // set new start and destination (left to bottom)
    data.koor1 = left;
    data.koor2 = bottom;
    drawLineDDAStyle(data);

    // set new start and destination (right to bottom)
    data.koor1 = right;
    data.koor2 = bottom;
    drawLineDDAStyle(data);
}

void drawTrapezoid(dt_pilihan data, int b1 /* panjang atas */, int b2 /* panjang bawah */, int height){
    koordinat topLeft, topRight, botLeft, botRight;
    topLeft = data.koor1;
    int tepian = abs((b2 - b1)/2);

    // koordinat top right
    topRight.x = topLeft.x + b1;
    topRight.y = topLeft.y;

    // koordinat bot left
    botLeft.x = topLeft.x - tepian;
    botLeft.y = topLeft.y + height;

    // koordinat bot right
    botRight.x = topRight.x + tepian;
    botRight.y = botLeft.y;

    // draw (top left to top right)
    data.koor2 = topRight;
    drawLineDDAStyle(data);

    // draw (top left to bot left)
    data.koor2 = botLeft;
    drawLineDDAStyle(data);

    // set new start and destination (bot left to bot right)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    drawLineDDAStyle(data);

    // set new start and destination (top right to bot right)
    data.koor1 = topRight;
    data.koor2 = botRight;
    drawLineDDAStyle(data);
}

void drawTrapezoidV2(dt_pilihan data, int b1 /* panjang atas */, int b2 /* panjang bawah */, int height){
    // Koordinat untuk segitiga
    // tinggi dan panjang alas
    int tepian = abs((b2-b1)/2); // untuk panjang alas segitiga di kedua sisi persegi panjang
    koordinat topRight, topLeft;
    topRight.x = data.koor1.x + b1;
    topRight.y = data.koor1.y;
    topLeft = data.koor1;

    // Draw rectangle first
    drawRect(data, b1, height);
    // Draw first triangle (right side)
    data.koor1 = topRight;
    drawTriangle(data, height, tepian, true);
    // Draw second triangle (left side)
    data.koor1 = topLeft;
    drawTriangle(data, height, tepian, false);
}

void drawSquareAnimate(dt_pilihan data, int width){
    while(width > 0){
        drawSquare(data, width);
        width -= 40;
        data.koor1.x += 20;
        data.koor1.y += 20;
    }
}

void drawRectRotate(dt_pilihan data, int width, int height, int angle){
    koordinat topLeft, topRight, botRight, botLeft, rotationPoint;
    // koordinat top left
    topLeft = data.koor1;

    // Manual assign for rotation koordinat
    rotationPoint.x = topLeft.x + width;
    rotationPoint.y = topLeft.y + height;

    // koordinat top right
    topRight.x = data.koor1.x + width;
    topRight.y = data.koor1.y;

    // set destination ke koor 2
    data.koor2 = topRight;

    // koordinat bot right
    botRight.x = data.koor1.x + width;
    botRight.y = data.koor1.y + height;

    // koordinat bot left
    botLeft.x = data.koor1.x;
    botLeft.y = data.koor1.y + height;

    // draw (topLeft to topRight)
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new start and destination point (topRight to botRight)
    data.koor1 = topRight;
    data.koor2 = botRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new start and destination point (topLeft to botLeft)
    data.koor1 = topLeft;
    data.koor2 = botLeft;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new start and destination point (botLeft to botRight)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);
}

void drawSquareRotate(dt_pilihan data, int width, int angle){
    koordinat topLeft, topRight, botRight, botLeft, rotationPoint;
    // koordinat top left
    topLeft = data.koor1;

    // Manual assign for rotation koordinat
    rotationPoint.x = topLeft.x + width;
    rotationPoint.y = topLeft.y + width;

    // koordinat top right
    topRight.x = data.koor1.x + width;
    topRight.y = data.koor1.y;

    // set destination ke koor 2
    data.koor2 = topRight;

    // koordinat bot right
    botRight.x = data.koor1.x + width;
    botRight.y = data.koor1.y + width;

    // koordinat bot left
    botLeft.x = data.koor1.x;
    botLeft.y = data.koor1.y + width;

    // draw (topLeft to topRight)
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new start and destination point (topRight to botRight)
    data.koor1 = topRight;
    data.koor2 = botRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new start and destination point (topLeft to botLeft)
    data.koor1 = topLeft;
    data.koor2 = botLeft;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new start and destination point (botLeft to botRight)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);
}

void drawTriangleRotate(dt_pilihan data, int height, int base, bool direction, int angle){
    koordinat topLeft, botLeft, botRight, rotationPoint;
    // koordinat top center
    topLeft = data.koor1;

    // Manual assign for rotation koordinat
    rotationPoint = topLeft;

    // koordinat bot left
    botLeft.x = topLeft.x;
    botLeft.y = topLeft.y + height;

    // koordinat bot right
    if(direction){ // untuk menentukan arah segitiga ke kanan atau ke kiri * true ke kanan
        botRight.x = botLeft.x + base;
        botRight.y = botLeft.y;
    } else {
        botRight.x = botLeft.x + (base * -1);
        botRight.y = botLeft.y;
    }

    // draw (top left to bot left)
    data.koor2 = botLeft;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new destination point (top center to bot right)
    data.koor2 = botRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new start and destination point (bot left to bot right)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);
}

void drawTriangleSameSideRotate(dt_pilihan data, int side, int angle){
    int base = abs(side/2);
    int height = sqrt(pow(side, 2) - pow(base, 2));
    koordinat topCenter, botLeft, botRight, rotationPoint;
    // koordinat top center
    topCenter = data.koor1;

    // koordinat bot left
    botLeft.x = topCenter.x - base;
    botLeft.y = topCenter.y + height;

    // koordinat bot right
    botRight.x = topCenter.x + base;
    botRight.y = botLeft.y;

    // Manual assign for rotation koordinat
    rotationPoint.x = topCenter.x;
    rotationPoint.y = botRight.y;

    // draw (top left to bot left)
    data.koor2 = botLeft;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new destination point (top center to bot right)
    data.koor2 = botRight;
    //data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new start and destination point (bot left to bot right)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);
}

void drawParallelogramRotate(dt_pilihan data, int base, int height, int angle) {
    int diff;
    koordinat topLeft, topRight, botRight, botLeft, rotationPoint;
    diff = abs((40 * base)/100);
    topLeft = data.koor1;

    // koordinat top right
    topRight.x = topLeft.x + base;
    topRight.y = topLeft.y;

    // koordinat bot left
    botLeft.x = topLeft.x - diff;
    botLeft.y = topLeft.y + height;

    // koordinat bot right
    botRight.x = botLeft.x + base;
    botRight.y = botLeft.y;

    // Manual assign for rotation koordinat
    rotationPoint = topLeft;

    // draw (top left to top right)
    data.koor2 = topRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set new destination (top left to bot left)
    data.koor2 = botLeft;
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set start and destination (bot left to bot right)
    data.koor1 = botLeft;
    data.koor2 = botRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);

    // set start and new destination (top right to bot right)
    data.koor1 = topRight;
    data.koor2 = botRight;
    data.koor1 = rotatePoint(data.koor1, rotationPoint, angle);
    data.koor2 = rotatePoint(data.koor2, rotationPoint, angle);
    drawLineDDAStyle(data);
}

void drawDiamondRotate(dt_pilihan data, int sideTgl, int angle){
    drawTriangleSameSide(data, sideTgl);
    drawTriangleSameSideRotate(data, sideTgl, angle);
}

void drawTrapezoidV2Rotate(dt_pilihan data, int b1, int b2, int height, int angle){
    // Koordinat untuk segitiga
    // tinggi dan panjang alas
    int tepian = abs((b2-b1)/2); // untuk panjang alas segitiga di kedua sisi persegi panjang
    koordinat topRight, topLeft;
    topRight.x = data.koor1.x + b1;
    topRight.y = data.koor1.y;
    topLeft = data.koor1;

    // Draw rectangle first
    drawRectRotate(data, b1, height, angle);
    // Draw first triangle (right side)
    data.koor1 = topRight;
    drawTriangleRotate(data, height, tepian, true, angle);
    // Draw second triangle (left side)
    data.koor1 = topLeft;
    drawTriangleRotate(data, height, tepian, false, angle);
}

void drawRectRotateWithRotationPoint(hinomaruOogi data, int angle, bool rotateAct, int situation){
    // This rectangle is vertical
    koordinat topLeft, topRight, botRight, botLeft;
    // bot left
    botLeft = data.pointSourceRect;

    // top left
    topLeft.x = botLeft.x;
    topLeft.y = botLeft.y - data.radius;

    // bot right
    botRight.x = botLeft.x + data.heightRect;
    botRight.y = botLeft.y;

    // top right
    topRight.x = botRight.x;
    topRight.y = topLeft.y;

    if(rotateAct){
        // Rotate all the points based on rotationPoint
        topLeft = rotatePoint(topLeft, data.rotationPoint, angle);
        topRight = rotatePoint(topRight, data.rotationPoint, angle);
        botLeft = rotatePoint(botLeft, data.rotationPoint, angle);
        botRight = rotatePoint(botRight, data.rotationPoint, angle);
    }
    if(rotateAct && situation == 1){
        // Rotate all the points based on rotationPoint
        topLeft = rotatePoint(topLeft, data.rotationPoint, data.angleRotationFirstRect);
        topRight = rotatePoint(topRight, data.rotationPoint, data.angleRotationFirstRect);
        botLeft = rotatePoint(botLeft, data.rotationPoint, data.angleRotationFirstRect);
        botRight = rotatePoint(botRight, data.rotationPoint, data.angleRotationFirstRect);
    }

    // Set new initiate line
    // Draw from topLeft to botLeft
    data.pointSourceRect = topLeft;
    data.pointDestRect = botLeft;
    drawLineDDAJC(data);

    // Draw from topLeft to topRight
    data.pointDestRect = topRight;
    drawLineDDAJC(data);

    // Draw from topRight to botRight
    data.pointSourceRect = data.pointDestRect;
    data.pointDestRect = botRight;
    drawLineDDAJC(data);

    // Draw from botRight to botLeft
    data.pointSourceRect = data.pointDestRect;
    data.pointDestRect = botLeft;
    drawLineDDAJC(data);
}
void drawRectHinomaru(hinomaruOogi data){
    koordinat topLeft, topRight, botRight, botLeft;
    // koordinat top left
    topLeft = data.pointSourceRect;

    // koordinat top right
    topRight.x = data.pointSourceRect.x + data.radius;
    topRight.y = data.pointSourceRect.y;

    // koordinat bot right
    botRight.x = data.pointSourceRect.x + data.radius;
    botRight.y = data.pointSourceRect.y + data.heightRect;

    // koordinat bot left
    botLeft.x = data.pointSourceRect.x;
    botLeft.y = data.pointSourceRect.y + data.heightRect;

    // Set new initiate line
    // Draw from topLeft to botLeft
    data.pointSourceRect = topLeft;
    data.pointDestRect = botLeft;
    drawLineDDAJC(data);

    // Draw from topLeft to topRight
    data.pointDestRect = topRight;
    drawLineDDAJC(data);

    // Draw from topRight to botRight
    data.pointSourceRect = data.pointDestRect;
    data.pointDestRect = botRight;
    drawLineDDAJC(data);

    // Draw from botRight to botLeft
    data.pointSourceRect = data.pointDestRect;
    data.pointDestRect = botLeft;
    drawLineDDAJC(data);
}

void drawHinomaru(hinomaruOogi dataCrest){
    koordinat littleCirclePoint;
    int limitCircle, radius3Octant;
    // Draw first rectangle as a middle rectangle
    drawRectRotateWithRotationPoint(dataCrest, dataCrest.angleRotationFirstRect, dataCrest.firstRectRotateAct, 0);

    // Draw 4 left rectangle (2 for each side)
    // Right side (value of angle is positive)
    for(int i = 1; i <= 2; i++){
        drawRectRotateWithRotationPoint(dataCrest, dataCrest.angleRotationRect*i, true, 1);
    }

    // Left side (value of angle is negative)
    for(int i = 1; i <= 2; i++){
        drawRectRotateWithRotationPoint(dataCrest, -dataCrest.angleRotationRect*i, true, 1);
    }

    // Set up for the fan
    dataCrest.hinomaruFan.radius = abs(dataCrest.radius*9.5/10);
    dataCrest.hinomaruFan.koor1 = dataCrest.rotationPoint;
    limitCircle = abs(dataCrest.hinomaruFan.radius*5/10);
    radius3Octant = abs((dataCrest.hinomaruFan.radius-limitCircle)*4/10);
    while(dataCrest.hinomaruFan.radius >= limitCircle){
        drawRotatedTopHinomaru(dataCrest.hinomaruFan, dataCrest.angleRotationHinomaruFan, dataCrest);
        dataCrest.hinomaruFan.radius -= 1;
    }

    // Set up for the little circle
    littleCirclePoint.x = dataCrest.rotationPoint.x;
    littleCirclePoint.y = dataCrest.rotationPoint.y - abs(dataCrest.radius*2.8/4);
    dataCrest.littleCircle.koor1 = littleCirclePoint;
    dataCrest.littleCircle.radius = abs(radius3Octant);
    if(dataCrest.doRotationHinomaruXC){
        dataCrest.littleCircle.koor1 = rotatePoint(dataCrest.littleCircle.koor1, dataCrest.rotationPoint, dataCrest.angleRotationLittleCircle);
    }
    while(dataCrest.littleCircle.radius >= 0){
        drawTopHinomaru(dataCrest.littleCircle, 0);
        dataCrest.littleCircle.radius -= 1;
    }
}
