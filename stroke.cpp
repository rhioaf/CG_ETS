#include "stroke.h"
#include <graphics.h>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void drawLineDDAStyle(dt_pilihan data){
    int step = 0;
    float dx = (data.koor2.x - data.koor1.x);
    float dy = (data.koor2.y - data.koor1.y);
    if(abs(dx) > abs(dy)){
        step = abs(dx);
    } else {
        step = abs(dy);
    }
    dx = dx/step;
    dy = dy/step;

    float xStart;
    float yStart;
    koordinat tempKoor = data.koor1;
    int index = 1;
    bool conditionDrawing = true;
    int colorOpt = data.color;
    if(data.random){
        colorOpt = rand() % 15 + 1;
    }
    if(data.transformationType == 1){
        tempKoor = translasiPoint(data.translationAddition.x, data.translationAddition.y, tempKoor);
    }
    xStart = tempKoor.x;
    yStart = tempKoor.y;

    switch (data.style){
        case 1 : while(index <= step){
                    putpixel(xStart, yStart, colorOpt);
                    xStart += dx;
                    yStart += dy;
                    index++;
                    //delay(1);
                }
                break;
        case 2 : while(index <= step){
                    if(index % 15 > 3){
                        putpixel(xStart, yStart, colorOpt);
                    }
                    xStart += dx;
                    yStart += dy;
                    index++;
                    //delay(1);
                }
                break;
        case 3 : while(index <= step){
                    if(index % 10 == 0){
                        putpixel(xStart, yStart, colorOpt);
                    }
                    xStart += dx;
                    yStart += dy;
                    index++;
                    //delay(10);
                }
        case 4 : while(index <= step){
                    if(conditionDrawing){
                        if((index % 2) != 0){
                            putpixel(xStart, yStart, colorOpt);
                            conditionDrawing = false;
                        }
                    } else {
                        if((index % 10) != 0){
                            putpixel(xStart, yStart, colorOpt);
                            conditionDrawing = true;
                        }
                    }
                    xStart += dx;
                    yStart += dy;
                    index++;
                    //delay(10);
                }
    }
}

void drawLineDDAJC(hinomaruOogi data){
    int step = 0;
    float dx = (data.pointDestRect.x - data.pointSourceRect.x);
    float dy = (data.pointDestRect.y - data.pointSourceRect.y);
    if(abs(dx) > abs(dy)){
        step = abs(dx);
    } else {
        step = abs(dy);
    }
    dx = dx/step;
    dy = dy/step;

    float xStart;
    float yStart;
    int index = 1;
    int colorOpt = 15;
    xStart = data.pointSourceRect.x;
    yStart = data.pointSourceRect.y;

    while(index <= step){
        putpixel(xStart, yStart, colorOpt);
        xStart += dx;
        yStart += dy;
        index++;
        //delay(1);
    }
}

void drawLineDDACustomWidth(dt_pilihan data, int width){
    int step = 0;
    float dx = (data.koor2.x - data.koor1.x);
    float dy = (data.koor2.y - data.koor1.y);
    if(abs(dx) > abs(dy)){
        step = abs(dx);
    } else {
        step = abs(dy);
    }
    dx = dx/step;
    dy = dy/step;

    float xStart = data.koor1.x;
    float yStart = data.koor1.y;
    int index = 1;
    bool conditionDrawing = true;
    int colorOpt = data.color;
    if(data.random){
        colorOpt = rand() % 15 + 1;
    }

    switch (data.style){
        case 1 : while(index <= step){
                    putpixel(xStart, yStart, colorOpt);
                    for(int i = 1; i <= width/2; i++){
                        if(dy > dx){
                            putpixel(xStart+i, yStart, colorOpt);
                            putpixel(xStart-i, yStart, colorOpt);
                        } else {
                            putpixel(xStart, yStart+i, colorOpt);
                            putpixel(xStart, yStart-i, colorOpt);
                        }
                    }
                    xStart += dx;
                    yStart += dy;
                    index++;
                    delay(10);
                }
                break;
        case 2 : while(index <= step){
                    if(index % 9 > 2){
                        putpixel(xStart, yStart, colorOpt);
                        for(int i = 1; i <= width/2; i++){
                            if(dy > dx){
                                putpixel(xStart+i, yStart, colorOpt);
                                putpixel(xStart-i, yStart, colorOpt);
                            } else {
                                putpixel(xStart, yStart+i, colorOpt);
                                putpixel(xStart, yStart-i, colorOpt);
                            }
                        }
                    }
                    xStart += dx;
                    yStart += dy;
                    index++;
                    delay(10);
                }
                break;
        case 3 : while(index <= step){
                    if(index % 2 == 0){
                        putpixel(xStart, yStart, colorOpt);
                        for(int i = 1; i <= width/2; i++){
                            if(dy > dx){
                                putpixel(xStart+i, yStart, colorOpt);
                                putpixel(xStart-i, yStart, colorOpt);
                            } else {
                                putpixel(xStart, yStart+i, colorOpt);
                                putpixel(xStart, yStart-i, colorOpt);
                            }
                        }
                    }
                    xStart += dx;
                    yStart += dy;
                    index++;
                    delay(10);
                }
        case 4 : while(index <= step){
                    if(conditionDrawing){
                        if((index % 6) != 0){
                            putpixel(xStart, yStart, colorOpt);
                            for(int i = 1; i <= width/2; i++){
                                if(dy > dx){
                                    putpixel(xStart+i, yStart, colorOpt);
                                    putpixel(xStart-i, yStart, colorOpt);
                                } else {
                                    putpixel(xStart, yStart+i, colorOpt);
                                    putpixel(xStart, yStart-i, colorOpt);
                                }
                            }
                            conditionDrawing = false;
                        }
                    } else {
                        if((index % 3) != 0){
                            putpixel(xStart, yStart, colorOpt);
                            for(int i = 1; i <= width/2; i++){
                                if(dy > dx){
                                    putpixel(xStart+i, yStart, colorOpt);
                                    putpixel(xStart-i, yStart, colorOpt);
                                } else {
                                    putpixel(xStart, yStart+i, colorOpt);
                                    putpixel(xStart, yStart-i, colorOpt);
                                }
                            }
                            conditionDrawing = true;
                        }
                    }
                    xStart += dx;
                    yStart += dy;
                    index++;
                    delay(10);
                }
    }
}

void drawCircleMP(dt_pilihan_circle data){
    int x = data.radius;
    int y = 0;
    int D = 0;

    while(x >= y){
        putpixel(data.koor1.x + x, data.koor1.y + y, 1);
        putpixel(data.koor1.x + y, data.koor1.y + x, 1);
        putpixel(data.koor1.x - y, data.koor1.y + x, 1);
        putpixel(data.koor1.x - x, data.koor1.y + y, 1);
        putpixel(data.koor1.x - x, data.koor1.y - y, 1);
        putpixel(data.koor1.x - y, data.koor1.y - x, 1);
        putpixel(data.koor1.x + y, data.koor1.y - x, 1);
        putpixel(data.koor1.x + x, data.koor1.y - y, 1);

        if(D <= 0){
            y += 1;
            D += 2*y + 1;
        } else {
            x -= 1;
            D -= 2*x + 1;
        }
    }
}

void drawHalfCircleUpMP(dt_pilihan_circle data){
    int x = data.radius;
    int y = 0;
    int D = 0;

    while(x >= y){
        //putpixel(data.koor1.x + x, data.koor1.y + y, 1);
        putpixel(data.koor1.x + y, data.koor1.y + x, 2);
        putpixel(data.koor1.x - y, data.koor1.y + x, 3);
        //putpixel(data.koor1.x - x, data.koor1.y + y, 4);
        /*putpixel(data.koor1.x - x, data.koor1.y - y, 5);
        putpixel(data.koor1.x - y, data.koor1.y - x, 6);
        putpixel(data.koor1.x + y, data.koor1.y - x, 7);
        putpixel(data.koor1.x + x, data.koor1.y - y, 8);*/

        if(D <= 0){
            y += 1;
            D += 2*y + 1;
        } else {
            x -= 1;
            D -= 2*x + 1;
        }
    }
}

void drawHalfCircleDownMP(dt_pilihan_circle data){
    int x = data.radius;
    int y = 0;
    int D = 0;

    while(x >= y){
        /*putpixel(data.koor1.x + x, data.koor1.y + y, 1);
        putpixel(data.koor1.x + y, data.koor1.y + x, 2);
        putpixel(data.koor1.x - y, data.koor1.y + x, 3);
        putpixel(data.koor1.x - x, data.koor1.y + y, 4);*/
        putpixel(data.koor1.x - x, data.koor1.y - y, 5);
        putpixel(data.koor1.x - y, data.koor1.y - x, 6);
        putpixel(data.koor1.x + y, data.koor1.y - x, 7);
        putpixel(data.koor1.x + x, data.koor1.y - y, 8);

        if(D <= 0){
            y += 1;
            D += 2*y + 1;
        } else {
            x -= 1;
            D -= 2*x + 1;
        }
    }
}

void drawTopHinomaru(dt_pilihan_circle data, int color){
    int x = data.radius;
    int y = 0;
    int D = 0;

    while(x >= y){
        if(data.startOctant <= 1 && data.endOctant >= 1){
            putpixel(data.koor1.x + x, data.koor1.y - y, color);
        }
        if(data.startOctant <= 2 && data.endOctant >= 2){
            putpixel(data.koor1.x + y, data.koor1.y - x, color);
        }
        if(data.startOctant <= 3 && data.endOctant >= 3){
            putpixel(data.koor1.x - y, data.koor1.y - x, color);
        }
        if(data.startOctant <= 4 && data.endOctant >= 4){
            putpixel(data.koor1.x - x, data.koor1.y - y, color);
        }
        if(data.startOctant <= 5 && data.endOctant >= 5){
            putpixel(data.koor1.x - x, data.koor1.y + y, color);
        }
        if(data.startOctant <= 6 && data.endOctant >= 6){
            putpixel(data.koor1.x - y, data.koor1.y + x, color);
        }
        if(data.startOctant <= 7 && data.endOctant >= 7){
            putpixel(data.koor1.x + y, data.koor1.y + x, color);
        }
        if(data.startOctant <= 8 && data.endOctant >= 8){
            putpixel(data.koor1.x + x, data.koor1.y + y, color);
        }
        if(D <= 0){
            y += 1;
            D += 2*y + 1;
        } else {
            x -= 1;
            D -= 2*x + 1;
        }
    }
}
void drawRotatedTopHinomaru(dt_pilihan_circle data, int angle, hinomaruOogi dataCrest){
    int x = data.radius;
    int y = 0;
    int D = 0;
    koordinat helperKoor, tempKoor, rotationPoint;
    rotationPoint.x = 0;
    rotationPoint.y = 0;

    while(x >= y){
        helperKoor.x = x;
        helperKoor.y = y;

        if(data.startOctant <= 1 && data.endOctant >= 1){
            tempKoor = rotatePoint(helperKoor, rotationPoint, -dataCrest.angleRotationFirstRect-angle);
            putpixel(data.koor1.x + tempKoor.x, data.koor1.y - tempKoor.y, 15);
        }
        if(data.startOctant <= 2 && data.endOctant >= 2){
            tempKoor = rotatePoint(helperKoor, rotationPoint, dataCrest.angleRotationFirstRect+angle);
            putpixel(data.koor1.x + tempKoor.y, data.koor1.y - tempKoor.x, 15);
        }
        if(data.startOctant <= 3 && data.endOctant >= 3){
            tempKoor = rotatePoint(helperKoor, rotationPoint, -dataCrest.angleRotationFirstRect-angle);
            putpixel(data.koor1.x - tempKoor.y, data.koor1.y - tempKoor.x, 15);
        }
        if(data.startOctant <= 4 && data.endOctant >= 4){
            tempKoor = rotatePoint(helperKoor, rotationPoint, dataCrest.angleRotationFirstRect+angle);
            putpixel(data.koor1.x - tempKoor.x, data.koor1.y - tempKoor.y, 15);
        }
        if(data.startOctant <= 5 && data.endOctant >= 5){
            tempKoor = rotatePoint(helperKoor, rotationPoint, -dataCrest.angleRotationFirstRect-angle);
            putpixel(data.koor1.x - tempKoor.x, data.koor1.y + tempKoor.y, 15);
        }
        if(data.startOctant <= 6 && data.endOctant >= 6){
            tempKoor = rotatePoint(helperKoor, rotationPoint, dataCrest.angleRotationFirstRect+angle);
            putpixel(data.koor1.x - tempKoor.y, data.koor1.y + tempKoor.x, 15);
        }
        if(data.startOctant <= 7 && data.endOctant >= 7){
            tempKoor = rotatePoint(helperKoor, rotationPoint, -dataCrest.angleRotationFirstRect-angle);
            putpixel(data.koor1.x + tempKoor.y, data.koor1.y + tempKoor.x, 15);
        }
        if(data.startOctant <= 8 && data.endOctant >= 8){
            tempKoor = rotatePoint(helperKoor, rotationPoint, dataCrest.angleRotationFirstRect+angle);
            putpixel(data.koor1.x + tempKoor.x, data.koor1.y + tempKoor.y, 15);
        }
        if(D <= 0){
            y += 1;
            D += 2*y + 1;
        } else {
            x -= 1;
            D -= 2*x + 1;
        }
    }
}

hinomaruOogi rotateHinomaru(hinomaruOogi data, int angle){
    hinomaruOogi rotatedHinomaru;
    rotatedHinomaru = data;

    // Set first rectangle to rotate
    rotatedHinomaru.firstRectRotateAct = true;
    rotatedHinomaru.angleRotationFirstRect = angle;

    return rotatedHinomaru;
}

koordinat translasiPoint(int translasiX, int translasiY, koordinat translasiKoor){
    koordinat temp;
    // Calculate translasi x axis and y axis
    temp.x = translasiKoor.x + translasiX;
    temp.y = translasiKoor.y + translasiY;
    return temp;
}

int scalingRadius(int currentRadius, float valueScale){
    return currentRadius * valueScale;
}

void drawPoint(koordinat data, int color){
    putpixel(data.x, data.y, color);
}

koordinat rotatePoint(koordinat currKoor, koordinat rotateKoor, int angle){
    koordinat temp;
    float newAngle = angle * (M_PI/180); // Konversi nilai ke dalam bentuk radian
    float rotationMatriks[3][3] = {
        {
            cos(newAngle), sin(newAngle), 0
        },
        {
            -sin(newAngle), cos(newAngle), 0
        },
        {
            0, 0, 1
        }
    };
    // Translasi point ke titik 0,0
    currKoor = translasiPoint(-rotateKoor.x, -rotateKoor.y, currKoor);
    float matriksPoint[1][3] = {currKoor.x, currKoor.y, 1};
    matriks3Col matriksResult = multiply3ColMatriks(matriksPoint, rotationMatriks);

    temp.x = matriksResult.matriks3[0][0]; // Assign result of matriks
    temp.y = matriksResult.matriks3[0][1];
    // Return back the new koordinat after rotation
    temp = translasiPoint(rotateKoor.x, rotateKoor.y, temp);
    return temp;
}

matriks3Col multiply3ColMatriks(float firstMatriks[][3], float secondMatriks[][3]){
    matriks3Col matriksResult;
    int i, j, k, n = 3;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            matriksResult.matriks3[i][j] = 0;
            for(k = 0; k < n; k++){
                matriksResult.matriks3[i][j] += firstMatriks[i][k] * secondMatriks[k][j];
            }
        }
    }
    return matriksResult;
}

void drawEllipseMP(dt_ellipse data){
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = data.ry;

    d1 = (data.ry * data.ry) - (data.rx * data.rx * data.ry) + (0.25 * data.rx * data.rx);
    dx = 2 * data.ry * data.ry * x;
    dy = 2 * data.rx * data.rx * y;

    /* Region 1 */
    while(dx < dy){
        putpixel(x + data.centerKoor.x, y + data.centerKoor.y, data.color);
        putpixel(-x + data.centerKoor.x, y + data.centerKoor.y, data.color);
        putpixel(x + data.centerKoor.x, -y + data.centerKoor.y, data.color);
        putpixel(-x + data.centerKoor.x, -y + data.centerKoor.y, data.color);

        if(d1 < 0){
            x++;
            dx += 2 * data.ry * data.ry;
            d1 += dx + (data.ry * data.ry);
        } else {
            x++;
            y--;
            dx += 2 * data.ry * data.ry;
            dy -= 2 * data.rx * data.rx;
            d1 += dx - dy + (data.ry * data.ry);
        }
    }

    d2 = ((data.ry * data.ry) * ((x + 0.5) * (x + 0.5))) + ((data.rx * data.rx) * ((y-1) * (y-1))) - (data.rx * data.rx * data.ry * data.ry);
    /* Region 2 */
    while(y >= 0){
        putpixel(x + data.centerKoor.x, y + data.centerKoor.y, data.color);
        putpixel(-x + data.centerKoor.x, y + data.centerKoor.y, data.color);
        putpixel(x + data.centerKoor.x, -y + data.centerKoor.y, data.color);
        putpixel(-x + data.centerKoor.x, -y + data.centerKoor.y, data.color);

        if(d2 > 0){
            y--;
            dy -= 2 * data.rx * data.rx;
            d2 += (data.rx * data.rx) - dy;
        } else {
            y--;
            x++;
            dx += 2 * data.ry * data.ry;
            dy -= 2 * data.rx * data.rx;
            d2 += dx - dy + (data.rx * data.rx);
        }
    }
}

void drawEllipseMPRotate(dt_ellipse data, int angle){
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = data.ry;
    koordinat region1, region2, region3, region4, rotationKoor, currKoor;
    rotationKoor.x = 0;
    rotationKoor.y = 0;

    d1 = (data.ry * data.ry) - (data.rx * data.rx * data.ry) + (0.25 * data.rx * data.rx);
    dx = 2 * data.ry * data.ry * x;
    dy = 2 * data.rx * data.rx * y;

    /* Region 1 */
    while(dx < dy){
        // Assign koordinat and rotate
        currKoor.x = x;
        currKoor.y = y;

        region1 = currKoor;
        region1 = rotatePoint(currKoor, rotationKoor, angle);
        region2 = rotatePoint(currKoor, rotationKoor, -angle);
        region3 = rotatePoint(currKoor, rotationKoor, angle);
        region4 = rotatePoint(currKoor, rotationKoor, -angle);

        region1.y = -region1.y;

        region2.x = -region2.x;
        region2.y = -region2.y;

        region3.x = -region3.x;
        region3.y = region3.y;

        // Draw new koordinat
        putpixel(region1.x + data.centerKoor.x, region1.y + data.centerKoor.y, data.color);
        putpixel(region2.x + data.centerKoor.x, region2.y + data.centerKoor.y, data.color);
        putpixel(region3.x + data.centerKoor.x, region3.y + data.centerKoor.y, data.color);
        putpixel(region4.x + data.centerKoor.x, region4.y + data.centerKoor.y, data.color);

        if(d1 < 0){
            x++;
            dx += 2 * data.ry * data.ry;
            d1 += dx + (data.ry * data.ry);
        } else {
            x++;
            y--;
            dx += 2 * data.ry * data.ry;
            dy -= 2 * data.rx * data.rx;
            d1 += dx - dy + (data.ry * data.ry);
        }
    }

    d2 = ((data.ry * data.ry) * ((x + 0.5) * (x + 0.5))) + ((data.rx * data.rx) * ((y-1) * (y-1))) - (data.rx * data.rx * data.ry * data.ry);
    /* Region 2 */
    while(y >= 0){
        // Assign koordinat and rotate
        currKoor.x = x;
        currKoor.y = y;

        region1 = currKoor;
        region1 = rotatePoint(currKoor, rotationKoor, angle);
        region2 = rotatePoint(currKoor, rotationKoor, -angle);
        region3 = rotatePoint(currKoor, rotationKoor, angle);
        region4 = rotatePoint(currKoor, rotationKoor, -angle);

        region1.y = -region1.y;

        region2.x = -region2.x;
        region2.y = -region2.y;

        region3.x = -region3.x;
        region3.y = region3.y;

        // Draw new koordinat
        putpixel(region1.x + data.centerKoor.x, region1.y + data.centerKoor.y, data.color);
        putpixel(region2.x + data.centerKoor.x, region2.y + data.centerKoor.y, data.color);
        putpixel(region3.x + data.centerKoor.x, region3.y + data.centerKoor.y, data.color);
        putpixel(region4.x + data.centerKoor.x, region4.y + data.centerKoor.y, data.color);

        if(d2 > 0){
            y--;
            dy -= 2 * data.rx * data.rx;
            d2 += (data.rx * data.rx) - dy;
        } else {
            y--;
            x++;
            dx += 2 * data.ry * data.ry;
            dy -= 2 * data.rx * data.rx;
            d2 += dx - dy + (data.rx * data.rx);
        }
    }
}

koordinat getNewRotationPoint(koordinat rectPoint, int x, int y){
    koordinat temp;
    temp.x = rectPoint.x + y;
    temp.y = rectPoint.y - x;
    return temp;
}
