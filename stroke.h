/*
    File : stroke.h
    Deskripsi :
    Author: Rhio Adjie Fabian / 181511064

*/

#ifndef stroke_H
#define stroke_H

typedef struct {
    float x;
    float y;
}koordinat;

typedef struct {
    koordinat koor1;
    koordinat koor2;
    int color = 15; // White
    bool random = false;
    int style = 1;
    int transformationType = 0; // Make sure if using translation or not
    koordinat translationAddition;
    int scaling = 1;
    bool scalingOption = false;
}dt_pilihan;

struct dt_pilihan_circle{
    koordinat koor1;
    int radius;
    int startOctant = 1;
    int endOctant = 8;
};

typedef struct{
    float matriks3[1][3];
}matriks3Col;

struct dt_ellipse{
    int rx = 0;
    int ry = 0;
    koordinat centerKoor;
    int color = 0;
};

struct hinomaruOogi{
    koordinat pointSourceRect;
    koordinat pointDestRect;
    int radius;
    int heightRect;
    koordinat rotationPoint;
    dt_pilihan_circle hinomaruFan;
    dt_pilihan_circle littleCircle;
    int angleRotationRect;
    bool firstRectRotateAct = false;
    int angleRotationFirstRect = 0;
    int angleRotationHinomaruFan = -23;
    bool doRotationHinomaruXC = false;
    int angleRotationLittleCircle = 0;
};

struct edgePoints{
    koordinat firstKoor;
    koordinat secondKoor;
};

void drawLineDDAStyle(dt_pilihan data);
void drawLineDDAJC(hinomaruOogi data);
void drawLineDDACustomWidth(dt_pilihan data, int width);
void drawCircleMP(dt_pilihan_circle data);
void drawHalfCircleUpMP(dt_pilihan_circle data);
void drawHalfCircleDownMP(dt_pilihan_circle data);
void drawTopHinomaru(dt_pilihan_circle data, int color);
void drawRotatedTopHinomaru(dt_pilihan_circle data, int angle, hinomaruOogi dataCrest);
hinomaruOogi rotateHinomaru(hinomaruOogi data, int angle);
koordinat translasiPoint(int translasiX, int translasiY, koordinat translasiKoor);
int scalingRadius(int currentRadius, float valueScale);
void drawPoint(koordinat data, int color);
koordinat rotatePoint(koordinat currKoor, koordinat rotateKoor, int angle);
matriks3Col multiply3ColMatriks(float firstMatriks[][3], float secondMatriks[][3]);
void drawEllipseMP(dt_ellipse);
void drawEllipseMPRotate(dt_ellipse data, int angle);
koordinat getNewRotationPoint(koordinat rectPoint, int x, int y);

#endif // stroke_H

