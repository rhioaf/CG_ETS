#include "util.h"
#include "stroke.h"
#include "shape.h"
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <cstdlib>

using namespace std;

koordinat getFirstRectPoint(hinomaruOogi data){
    koordinat result;
    result.x = data.rotationPoint.x - abs(data.heightRect/2);
    result.y = data.rotationPoint.y + data.heightRect;
    return result;
}

void generateMenu(){
     // Initialize some variable
    int widthW = 1400, heightW = 700, menuOption;
    hinomaruOogi dataCrest, dataCrestLittle1, dataCrestLittle2;
    koordinat rotationPoint, firstPointCHinomaru, firstPointLittleH1, firstPointLittleH2;
    bool finish = false;
    int angleRectRotateArr[11] = {-30, -60, -90, -120, -180, -210, -240, -270, -300, -330, -360};
    int angleRotate45[9] = {-45, -90, -135, -180, -225, -270, -315, -360};
    hinomaruOogi crestBorderArr[9];

    // Code challenge variable
    hinomaruOogi borderHinomaru, centerHinomaru;

    // Setup the menu
    while(!finish){
        cout << "********** PROGRAM ETS CG **********" << endl;
        cout << "0. Keluar" << endl;
        cout << "1. Object Japanese Crest (Hinomaru Oogi)" << endl;
        cout << "2. Animasi Object Japanese Crest" << endl;
        cout << "3. Code challenge" << endl;
        cout << "Pilihan anda : ";
        cin >> menuOption;

        switch(menuOption){
            case 0      : {
                            finish = true;
                            break;
                        }
            case 1      : {
                            // Setup the window
                            initwindow(widthW, heightW, "UTS CG Praktikum", 0, 0, false, false);

                            // Data of hinomaru center
                            dataCrest.pointSourceRect.x = abs(widthW/2);
                            dataCrest.pointSourceRect.y = 450;
                            dataCrest.heightRect = 40;
                            dataCrest.radius = 250;
                            dataCrest.angleRotationRect = 34;
                            rotationPoint.x = dataCrest.pointSourceRect.x + abs(dataCrest.heightRect/2);
                            rotationPoint.y = dataCrest.pointSourceRect.y - dataCrest.heightRect;
                            dataCrest.rotationPoint = rotationPoint;
                            dataCrest.hinomaruFan.startOctant = 1;
                            dataCrest.hinomaruFan.endOctant = 3;
                            dataCrest.littleCircle.startOctant = 1;
                            dataCrest.littleCircle.endOctant = 8;

                            // Draw hinomaru
                            drawHinomaru(dataCrest);
                            cout << "Press any key in command window to close the window BGI" << endl;
                            _getch();
                            closegraph();
                            break;
                        }
            case 2      : {
                            cout << "Press any key in window BGI to close the window" << endl;
                            // Setup the window
                            initwindow(widthW, heightW, "UTS CG Praktikum", 0, 0, true, true);

                            // Data of hinomaru center
                            dataCrest.pointSourceRect.x = abs(widthW/2);
                            dataCrest.pointSourceRect.y = 450;
                            dataCrest.heightRect = 40;
                            dataCrest.radius = 250;
                            dataCrest.angleRotationRect = 34;
                            rotationPoint.x = dataCrest.pointSourceRect.x + abs(dataCrest.heightRect/2);
                            rotationPoint.y = dataCrest.pointSourceRect.y - dataCrest.heightRect;
                            dataCrest.rotationPoint = rotationPoint;
                            dataCrest.hinomaruFan.startOctant = 1;
                            dataCrest.hinomaruFan.endOctant = 3;
                            dataCrest.littleCircle.startOctant = 1;
                            dataCrest.littleCircle.endOctant = 8;

                            // Data of hinomaru little top (1)
                            dataCrestLittle1.pointSourceRect.x = 150;
                            dataCrestLittle1.pointSourceRect.y = 150;
                            dataCrestLittle1.heightRect = 15;
                            dataCrestLittle1.radius = 120;
                            dataCrestLittle1.angleRotationRect = 34;
                            rotationPoint.x = dataCrestLittle1.pointSourceRect.x + abs(dataCrestLittle1.heightRect/2);
                            rotationPoint.y = dataCrestLittle1.pointSourceRect.y - dataCrestLittle1.heightRect;
                            dataCrestLittle1.rotationPoint = rotationPoint;
                            dataCrestLittle1.hinomaruFan.startOctant = 1;
                            dataCrestLittle1.hinomaruFan.endOctant = 3;

                            // Data of hinomaru little bottom (2)
                            dataCrestLittle2.pointSourceRect.x = 1400;
                            dataCrestLittle2.pointSourceRect.y = 700;
                            dataCrestLittle2.heightRect = 15;
                            dataCrestLittle2.radius = 120;
                            dataCrestLittle2.angleRotationRect = 34;
                            rotationPoint.x = dataCrestLittle2.pointSourceRect.x + abs(dataCrestLittle2.heightRect/2);
                            rotationPoint.y = dataCrestLittle2.pointSourceRect.y - dataCrestLittle2.heightRect;
                            dataCrestLittle2.rotationPoint = rotationPoint;
                            dataCrestLittle2.hinomaruFan.startOctant = 1;
                            dataCrestLittle2.hinomaruFan.endOctant = 3;

                            // Keep first coordinate of every hinomaru
                            firstPointCHinomaru = dataCrest.pointSourceRect;
                            firstPointLittleH1 = dataCrestLittle1.pointSourceRect;
                            firstPointLittleH2 = dataCrestLittle2.pointSourceRect;

                            // Start the looping
                            int countLoop = 0, indexArrayAngleRectRotate = 0, valueTranslateTop = 20, valueTranslateBot = -20;
                            //while(finish)
                            //for(countLoop = 0; countLoop <= 11; countLoop++)

                            while(!kbhit()){
                                cleardevice();

                                // Draw section

                                // Hinomaru Center
                                drawHinomaru(dataCrest);
                                if(indexArrayAngleRectRotate == 11) indexArrayAngleRectRotate = 0;
                                dataCrest = rotateHinomaru(dataCrest, angleRectRotateArr[indexArrayAngleRectRotate]);
                                dataCrest.doRotationHinomaruXC = true;
                                dataCrest.angleRotationLittleCircle = angleRectRotateArr[indexArrayAngleRectRotate];

                                // Little hinomaru top
                                if(dataCrestLittle1.pointSourceRect.x >= widthW - 250){
                                    valueTranslateTop *= -1;
                                }
                                if(dataCrestLittle1.pointSourceRect.x <= 150 && valueTranslateTop < 0){
                                    valueTranslateTop *= -1;
                                }
                                drawHinomaru(dataCrestLittle1);

                                // Little hinomaru bot
                                if(dataCrestLittle2.pointSourceRect.x <= 150 && valueTranslateBot < 0){
                                    valueTranslateBot *= -1;
                                }
                                if(dataCrestLittle2.pointSourceRect.x >= widthW - 250 && valueTranslateBot > 0){
                                    valueTranslateBot *= -1;
                                }
                                drawHinomaru(dataCrestLittle2);
                                swapbuffers();

                                // Translation and scaling section

                                // Little hinomaru top
                                dataCrestLittle1.pointSourceRect = translasiPoint(valueTranslateTop, 0, dataCrestLittle1.pointSourceRect);
                                dataCrestLittle1.rotationPoint = getNewRotationPoint(dataCrestLittle1.pointSourceRect, dataCrestLittle1.heightRect, abs(dataCrestLittle1.heightRect/2));

                                // Rotation section hinomaru top
                                dataCrestLittle1 = rotateHinomaru(dataCrestLittle1, -angleRectRotateArr[indexArrayAngleRectRotate]);
                                dataCrestLittle1.doRotationHinomaruXC = true;
                                dataCrestLittle1.angleRotationLittleCircle = -angleRectRotateArr[indexArrayAngleRectRotate];

                                // Little hinomaru bot
                                dataCrestLittle2.pointSourceRect = translasiPoint(valueTranslateBot, 0, dataCrestLittle2.pointSourceRect);
                                dataCrestLittle2.rotationPoint = getNewRotationPoint(dataCrestLittle2.pointSourceRect, dataCrestLittle2.heightRect, abs(dataCrestLittle2.heightRect/2));

                                // Rotation section hinomaru bot
                                dataCrestLittle2 = rotateHinomaru(dataCrestLittle2, -angleRectRotateArr[indexArrayAngleRectRotate]);
                                dataCrestLittle2.doRotationHinomaruXC = true;
                                dataCrestLittle2.angleRotationLittleCircle = -angleRectRotateArr[indexArrayAngleRectRotate];

                                // Scale hinomaru center
                                if(dataCrest.radius > 180){
                                    dataCrest.radius = scalingRadius(dataCrest.radius, 0.8);
                                } else {
                                    dataCrest.radius = scalingRadius(dataCrest.radius, 1.2);
                                }
                                indexArrayAngleRectRotate++;
                                countLoop++;
                                delay(50);
                            }
                            closegraph();
                            break;
                        }
            case 3      :{
                            cout << "Press any key in window BGI to close the window" << endl;
                            // Setup the window
                            initwindow(widthW, heightW, "UTS CG Praktikum", 0, 0, true, true);

                            // Data of center hinomaru
                            centerHinomaru.pointSourceRect.x = abs(widthW/2);
                            centerHinomaru.pointSourceRect.y = 450;
                            centerHinomaru.heightRect = 40;
                            centerHinomaru.radius = 200;
                            centerHinomaru.angleRotationRect = 34;
                            rotationPoint.x = centerHinomaru.pointSourceRect.x + abs(centerHinomaru.heightRect/2);
                            rotationPoint.y = centerHinomaru.pointSourceRect.y - centerHinomaru.heightRect;
                            centerHinomaru.rotationPoint = rotationPoint;
                            centerHinomaru.hinomaruFan.startOctant = 1;
                            centerHinomaru.hinomaruFan.endOctant = 3;
                            centerHinomaru.littleCircle.startOctant = 1;
                            centerHinomaru.littleCircle.endOctant = 8;

                            // Data of border hinomaru
                            borderHinomaru.pointSourceRect.x = abs(widthW/2);
                            borderHinomaru.pointSourceRect.y = 150;
                            borderHinomaru.heightRect = 20;
                            borderHinomaru.radius = 100;
                            borderHinomaru.angleRotationRect = 34;
                            rotationPoint.x = borderHinomaru.pointSourceRect.x + abs(borderHinomaru.heightRect/2);
                            rotationPoint.y = borderHinomaru.pointSourceRect.y - borderHinomaru.heightRect;
                            borderHinomaru.rotationPoint = rotationPoint;
                            borderHinomaru.hinomaruFan.startOctant = 1;
                            borderHinomaru.hinomaruFan.endOctant = 3;
                            borderHinomaru.littleCircle.startOctant = 1;
                            borderHinomaru.littleCircle.endOctant = 8;

                            for(int i=0; i < 9; i++){
                                // Rotate border to determine location
                                crestBorderArr[i] = borderHinomaru;
                                borderHinomaru.pointSourceRect = rotatePoint(borderHinomaru.pointSourceRect, centerHinomaru.rotationPoint, -angleRotate45[i]);
                                borderHinomaru.rotationPoint = getNewRotationPoint(borderHinomaru.pointSourceRect, borderHinomaru.heightRect, abs(borderHinomaru.heightRect/2));
                            }

                            int countBorder = sizeof(crestBorderArr)/sizeof(crestBorderArr[0]);
                            // Looping
                            while(!kbhit()){
                                cleardevice();
                                // Draw center hinomaru
                                drawHinomaru(centerHinomaru);

                                // Draw border hinomaru
                                for(int i=0; i < countBorder; i++){
                                    borderHinomaru = crestBorderArr[i];
                                    borderHinomaru.pointSourceRect = rotatePoint(borderHinomaru.pointSourceRect, centerHinomaru.rotationPoint, -15);
                                    borderHinomaru.rotationPoint = getNewRotationPoint(borderHinomaru.pointSourceRect, borderHinomaru.heightRect, abs(borderHinomaru.heightRect/2));

                                    // Draw hinomaru
                                    drawHinomaru(borderHinomaru);
                                    crestBorderArr[i] = borderHinomaru;
                                }

                                // Scale hinomaru center
                                if(centerHinomaru.radius > 180){
                                    centerHinomaru.radius = scalingRadius(centerHinomaru.radius, 0.8);
                                } else {
                                    centerHinomaru.radius = scalingRadius(centerHinomaru.radius, 1.2);
                                }
                                swapbuffers();
                            }
                            closegraph();
                            break;
                        }
        }
        system("CLS");
    }
    return;

}
