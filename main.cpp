#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<cstdio>


# define PI           3.14159265358979323846

float carPosition = -0.7f;  // Initial position of the car
float cloudPosition = -1.2f; // Initial position of the cloud
float planeX = -1.2f; // Initial x-coordinate of the plane
float planeY = 0.5f; // Initial y-coordinate of the plane
float carRotation = 0;

float TrainStartX = -1.8f;
float TrainStartY = 1.2f;
float TrainSpeedX = 0.015f;
float TrainSpeedY = 0.01f;
float cloudspeed = 0.005f;

float carx = 0.73;
float cary = 1.25;
float carspeedx = 0.01;
float carspeedy = 0.02;

float planespeedX = 0.01f;
float planespeedY = 0.005f;
float carspeed = 1.0f;

bool state = false;

int sceneIndex = 0;

// Function to play the current scene's audio
void sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("Sound.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void RenderScaledText(const char* text, float x, float y, float scale, float r, float g, float b,float Width) {
    glLineWidth(Width);
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);
    while (*text) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *text);
        text++;
    }
    glPopMatrix();
}

// Function to render Scene 1
void renderScene1() {
        glColor3f(0.941,0.624,0.612);
    renderBitmapString(-0.3f,0.91f, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Urban Landscapes of Dhaka");
    renderBitmapString(0.24,0.86, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Computer Graphics [H]");
    renderBitmapString(-0.88,0.82, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Group Member :");
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.941,0.624,0.612);
    glVertex2f(-0.88, 0.8);
    glVertex2f(0.88,0.8);
    glEnd();
    renderBitmapString(-0.78,0.65, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "ID");
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.941,0.624,0.612);
    glVertex2f(-0.85, 0.64);
    glVertex2f(-0.67,0.64);
    glEnd();
    renderBitmapString(-0.05,0.65, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Name");
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.941,0.624,0.612);
    glVertex2f(-0.24, 0.64);
    glVertex2f(0.24,0.64);
    glEnd();
    renderBitmapString(0.68,0.65, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Contribution");
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.941,0.624,0.612);
    glVertex2f(0.67, 0.64);
    glVertex2f(0.86,0.64);
    glEnd();

    renderBitmapString(-0.84,0.5, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-47367-2");
    renderBitmapString(-0.22, 0.5, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Siam Sarker");
    renderBitmapString(0.74, 0.5, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20");

    renderBitmapString(-0.84, 0.4, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "23-51359-1");
    renderBitmapString(-0.22, 0.4, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Nur Farhana Akhter");
    renderBitmapString(0.74, 0.4, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20");

    renderBitmapString(-0.84, 0.3, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-45677-3");
    renderBitmapString(-0.22, 0.3, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "MD ARIFIN MONDUL BABU");
    renderBitmapString(0.74, 0.3, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20");

    renderBitmapString(-0.84, 0.2, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-45643-3");
    renderBitmapString(-0.22, 0.2, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "MD. ISTIAK ZAMAN PRAPTO");
    renderBitmapString(0.74, 0.2, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20");

    renderBitmapString(-0.84, 0.1, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-49592-3");
    renderBitmapString(-0.22, 0.1, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "RASHID ASIF CHOWDHURY");
    renderBitmapString(0.74, 0.1, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20");

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.941,0.624,0.612);
    glVertex2f(-0.88,0.05);
    glVertex2f(0.88, 0.05);
    glEnd();

    renderBitmapString(-0.1,-0.1, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Supervised by :");
    renderBitmapString(-0.13,-0.2, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Mahfujur Rahman");
    renderBitmapString(-0.19,-0.3, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "ASSISTANT PROFESSOR");
    renderBitmapString(-0.22,-0.4, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Department of Computer Science");
    renderBitmapString(-0.23,-0.5, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Faculty of Science and Technology");
    renderBitmapString(-0.34,-0.6, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University-Bangladesh(AIUB)");
  glFlush();
}

void drawCurvedRoad(float cx, float cy, float radius, float width, float startAngle, float endAngle) {


    glLineWidth(5.0);
    int numSegments = 100; // Higher value makes the curve smoother
    float angleStep = (endAngle - startAngle) / numSegments;

    // Outer edge of the road
    glBegin(GL_QUAD_STRIP);

    for (int i = 0; i <= numSegments; ++i) {
        float angle = startAngle + i * angleStep;
        float xOuter = cx + (radius + width / 2) * cos(angle);
        float yOuter = cy + (radius + width / 2) * sin(angle);
        float xInner = cx + (radius - width / 2) * cos(angle);
        float yInner = cy + (radius - width / 2) * sin(angle);

        glColor3f(0.3f, 0.3f, 0.3f); // Dark gray for the road
        glVertex2f(xOuter, yOuter); // Outer edge
        glVertex2f(xInner, yInner); // Inner edge
    }
    glEnd();



    // Add stripes in the middle
    glLineWidth(5.0); // Adjust line width as needed
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= numSegments; ++i) {
        float angle = startAngle + i * angleStep;
        float xCenter = cx + radius * cos(angle);
        float yCenter = cy + radius * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f); // White for the center line
        glVertex2f(xCenter, yCenter);
    }
    glEnd();
}

void Stripe()
{
    int numStripes = 20;  // Number of stripes
    float stripeWidth = 2.0f / numStripes;  // Normalized stripe width

    for (int i = 0; i < numStripes; i++) {
        if (i % 2 == 0) {
            glColor3f(0.0f, 0.0f, 0.0f);  // Black
        } else {
            glColor3f(1.0f, 1.0f, 1.0f);  // White
        }

        float x1 = -1.0f + i * stripeWidth;
        float x2 = x1 + stripeWidth;

        glBegin(GL_QUADS);
            /*glVertex2f(x1, -0.4f);
            glVertex2f(x2, -0.3f);
            glVertex2f(x2, -0.4f);
            glVertex2f(x1, -0.3f);*/
            glVertex2f(x1, -0.5f);
            glVertex2f(x1, -0.6f);
            glVertex2f(x2, -0.6f);
            glVertex2f(x2, -0.5f);
        glEnd();
    }
}

void Stripe2()
{
    int numStripes = 12;  // Number of stripes
    float stripeWidth = 2.0f / numStripes;  // Normalized stripe width

    for (int i = 0; i < numStripes; i++) {
        if (i % 2 == 0) {
            glColor3f(0.1f, 0.0f, 0.0f);  // Black
        } else {
            glColor3f(1.0f, 1.0f, 1.0f);  // White
        }

        float x1 = -1.0f + i * stripeWidth;
        float x2 = x1 + stripeWidth;

        glBegin(GL_QUADS);
            /*glVertex2f(x1, -0.4f);
            glVertex2f(x2, -0.3f);
            glVertex2f(x2, -0.4f);
            glVertex2f(x1, -0.3f);*/
            glVertex2f(x1, 0.4f);
            glVertex2f(x1, 0.1f);
            glVertex2f(x2, 0.1f);
            glVertex2f(x2, 0.4f);
        glEnd();
    }
}

void Stripe3()
{
    int numStripes = 20;  // Number of stripes
    float stripeWidth = 2.0f / numStripes;  // Normalized stripe width

    for (int i = 0; i < numStripes; i++) {
        if (i % 2 == 0) {
            glColor3f(0.6, 0.4, 0.2);  // Ground
        } else {
            glColor3f(1.0f, 1.0f, 1.0f);  // White
        }

        float x1 = -1.0f + i * stripeWidth;
        float x2 = x1 + stripeWidth;

        glBegin(GL_QUADS);
            /*glVertex2f(x1, -0.4f);
            glVertex2f(x2, -0.3f);
            glVertex2f(x2, -0.4f);
            glVertex2f(x1, -0.3f);*/
            glVertex2f(x1, -0.6f);
            glVertex2f(x1, -0.65f);
            glVertex2f(x2, -0.65f);
            glVertex2f(x2, -0.6f);
        glEnd();
    }
}



void drawWheel(float cx, float cy, float radius) {
    glColor3f(0.0, 0.0, 0.0); // Black
    glBegin(GL_POLYGON);
    for (int angle = 0; angle <= 360; angle += 10) {
        float theta = angle * 3.14159 / 180; // Convert degrees to radians
        glVertex2f(cx + radius * cos(theta), cy + radius * sin(theta));
    }
    glEnd();
}

void drawCar(float x, float y) {


    glPushMatrix();
    glScaled(0.7,0.7,1);
    // Car body
    glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_QUADS);
    glVertex2f(x - 0.2, y);         // Bottom left
    glVertex2f(x + 0.2, y);         // Bottom right
    glVertex2f(x + 0.2, y + 0.1);   // Top right
    glVertex2f(x - 0.2, y + 0.1);   // Top left
    glEnd();

    // Car roof
    glColor3f(0.8, 0.8, 0.8); // Gray
    glBegin(GL_QUADS);
    glVertex2f(x - 0.1, y + 0.1);   // Bottom left
    glVertex2f(x + 0.1, y + 0.1);   // Bottom right
    glVertex2f(x + 0.05, y + 0.2);  // Top right
    glVertex2f(x - 0.05, y + 0.2);  // Top left
    glEnd();

    // Wheels
    drawWheel(x - 0.12, y - 0.03, 0.05); // Front wheel
    drawWheel(x + 0.12, y - 0.03, 0.05); // Rear wheel
    glPopMatrix();
}

void drawFluffyCloud(float x, float y, float scale) {
    glColor3f(1.0, 1.0, 1.0); // White color for the cloud

    // Main circle
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle += 10) {
        float theta = angle * 3.14159 / 180;
        glVertex2f(x + scale * 0.2 * cos(theta), y + scale * 0.1 * sin(theta));
    }
    glEnd();

    // Top-left circle
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle += 10) {
        float theta = angle * 3.14159 / 180;
        glVertex2f((x - scale * 0.1) + scale * 0.15 * cos(theta), (y + scale * 0.1) + scale * 0.1 * sin(theta));
    }
    glEnd();

    // Top-right circle
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle += 10) {
        float theta = angle * 3.14159 / 180;
        glVertex2f((x + scale * 0.1) + scale * 0.15 * cos(theta), (y + scale * 0.1) + scale * 0.1 * sin(theta));
    }
    glEnd();

    // Bottom-left circle
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle += 10) {
        float theta = angle * 3.14159 / 180;
        glVertex2f((x - scale * 0.15) + scale * 0.1 * cos(theta), y + scale * 0.05 * sin(theta));
    }
    glEnd();

    // Bottom-right circle
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle += 10) {
        float theta = angle * 3.14159 / 180;
        glVertex2f((x + scale * 0.15) + scale * 0.1 * cos(theta), y + scale * 0.05 * sin(theta));
    }
    glEnd();
}


void drawRealisticPlane(float x, float y) {
    // Plane Body
    glColor3f(0.9, 0.9, 0.9); // Light gray
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.2, y);       // Body rear-bottom
    glVertex2f(x + 0.4, y);       // Body front-bottom
    glVertex2f(x + 0.4, y + 0.05); // Body front-top
    glVertex2f(x - 0.2, y + 0.05); // Body rear-top
    glEnd();

    // Nose (front of the plane)
    glColor3f(0.8, 0.8, 0.8); // Slightly darker gray
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 180; angle += 10) {
        float theta = angle * 3.14159 / 180;
        glVertex2f(x + 0.4 + 0.05 * cos(theta), y + 0.025 + 0.025 * sin(theta));
    }
    glEnd();

    // Tail
    glColor3f(0.7, 0.7, 0.7); // Darker gray
    glBegin(GL_QUADS);
    glVertex2f(x - 0.2, y + 0.05);  // Rear-top
    glVertex2f(x - 0.15, y + 0.2);  // Tail-tip top
    glVertex2f(x - 0.1, y + 0.2);   // Tail-tip bottom
    glVertex2f(x - 0.15, y + 0.05); // Rear-bottom
    glEnd();

    // Wings
    glColor3f(0.8, 0.8, 0.8); // Same as body
    glBegin(GL_QUADS);
    glVertex2f(x, y);          // Wing bottom-left
    glVertex2f(x + 0.25, y);   // Wing bottom-right
    glVertex2f(x + 0.15, y - 0.15); // Wing tip
    glVertex2f(x - 0.05, y - 0.15); // Wing bottom-tip
    glEnd();

    // Tail Wings
    glBegin(GL_QUADS);
    glVertex2f(x - 0.15, y + 0.05); // Base
    glVertex2f(x - 0.05, y + 0.05); // Base-right
    glVertex2f(x - 0.1, y + 0.15);  // Tip-right
    glVertex2f(x - 0.2, y + 0.15);  // Tip-left
    glEnd();

    // Windows
    glColor3f(0.0, 0.0, 0.0); // Black
    for (float wx = x + 0.1; wx < x + 0.35; wx += 0.05) {
        glBegin(GL_POLYGON);
        for (float angle = 0; angle <= 360; angle += 10) {
            float theta = angle * 3.14159 / 180;
            glVertex2f(wx + 0.01 * cos(theta), y + 0.035 + 0.01 * sin(theta));
        }
        glEnd();
    }

    // Wheels
    glColor3f(0.0, 0.0, 0.0); // Black
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle += 10) {
        float theta = angle * 3.14159 / 180;
        glVertex2f(x + 0.1 + 0.02 * cos(theta), y - 0.02 + 0.02 * sin(theta)); // Front wheel
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle += 10) {
        float theta = angle * 3.14159 / 180;
        glVertex2f(x - 0.1 + 0.02 * cos(theta), y - 0.02 + 0.02 * sin(theta)); // Rear wheel
    }
    glEnd();
}

void drawRoofWithStandsAndText() {
    // Roof
    glColor3f(0.6, 0.6, 0.6); // Gray for the roof
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.75); // Left bottom
    glVertex2f(1.0, 0.75);  // Right bottom
    glVertex2f(0.8, 0.85);  // Right top
    glVertex2f(-0.8, 0.85); // Left top
    glEnd();

    // Stands
    glColor3f(0.5, 0.5, 0.5); // Dark gray for stands
    for (float x = -0.8; x <= 0.8; x += 0.4) {
        glBegin(GL_QUADS);
        glVertex2f(x - 0.02, 0.75); // Bottom left
        glVertex2f(x + 0.02, 0.75); // Bottom right
        glVertex2f(x + 0.02, 0.5);  // Top right
        glVertex2f(x - 0.02, 0.5);  // Top left
        glEnd();
    }
    // Text in the middle of the roof
    glPushMatrix();
    RenderScaledText("HAZRAT SHAHJALAL INTERNATIONAL AIRPORT BANGLADESH", -0.85f, 0.78f, 0.0003f, 1.0f, 0.0f, 0.0f,1.0f);
    glPopMatrix();

}

void renderScene2() {

    // Roof with stands
    glPushMatrix();
    drawRoofWithStandsAndText();
    glPopMatrix();



    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-1.0, -0.1, 0);
    glVertex3f(-1.0, -1.0, 0);
    glVertex3f(1.0, -1.0, 0);
    glVertex3f(1.0, -0.1, 0);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef();




    glPushMatrix();
    //Stripe3();
    glPopMatrix();

    //ground
    glPushMatrix();
    glColor3ub(135,66,28);
    glBegin(GL_QUADS);
    glVertex3f(-1.0, -0.1, 0);
    glVertex3f(-1.0, -1.0, 0);
    glVertex3f(1.0, -1.0, 0);
    glVertex3f(1.0, -0.1, 0);

    glEnd();
    glPopMatrix();

    //stripe
    glPushMatrix();
    Stripe();
    glPopMatrix();

    //curved road
    glPushMatrix();
    glColor3ub(135,66,28);
    drawCurvedRoad(0.0f, -0.01f, 1.0f, 0.4f, 0, -3.14159f); // Example road curve
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1, -0.2, 0);
    glVertex3f(1, -0.2, 0);
    glVertex3f(1, -0.4, 0);
    glVertex3f(-1, -0.4, 0);

    glEnd();
    glPopMatrix();

    //cardoor
    glPushMatrix();
    glTranslated(0.7,-0.4,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(0, 0.0, 0);
    glVertex3f(0.3, 0.0, 0);
    glVertex3f(0.3,0.2 , 0);
    glVertex3f(0, 0.2, 0);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.0,-0.4,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(0, 0.0, 0);
    glVertex3f(0.3, 0.0, 0);
    glVertex3f(0.3,0.2 , 0);
    glVertex3f(0, 0.2, 0);

    glEnd();
    glPopMatrix();

    //car
    glPushMatrix();
    glRotated(carRotation,0,0,1.0);
    glPushMatrix();
    glRotated(-90,0,0,1.0);
    glTranslated(-0.3,-0.9,0);
    drawCar(0, 0);

    glPopMatrix();
    glPopMatrix();

    //Building
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1, 0.5, 0);
    glVertex3f(-1, 0.4, 0);
    glVertex3f(1, 0.4, 0);
    glVertex3f(1, 0.5, 0);

    glEnd();
    glPopMatrix();



    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1, 0.1, 0);
    glVertex3f(-1, 0.0, 0);
    glVertex3f(1, 0.0, 0);
    glVertex3f(1, 0.1, 0);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1, 0.0, 0);
    glVertex3f(-1, -0.2, 0);
    glVertex3f(1, -0.2, 0);
    glVertex3f(1, 0.0, 0);

    glEnd();
    glPopMatrix();




    //windows
    /*glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.9, 0.4, 0);
    glVertex3f(-0.9, 0.1, 0);
    glVertex3f(-0.8, 0.1, 0);
    glVertex3f(-0.8, 0.4, 0);
    glEnd();
    glPopMatrix();*/
    glPushMatrix();
    Stripe2();
    glPopMatrix();





    glPushMatrix();
    RenderScaledText("Terminal 2", -0.4f, 0.5f, 0.001f, 1.0f, 0.0f, 0.0f,1.0f);
    glPopMatrix();

    glColor3f(0.3, 0.3, 0.3);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.6,0.85);
        glVertex2f(-0.6,0.9);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.6,0.9);
        glVertex2f(-0.6,0.92);
    glEnd();

    glPushMatrix();
    glTranslated(0.6,0,0);
    glColor3f(0.3, 0.3, 0.3);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.6,0.85);
        glVertex2f(-0.6,0.9);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.6,0.9);
        glVertex2f(-0.6,0.92);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.2,0,0);
    glColor3f(0.3, 0.3, 0.3);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.6,0.85);
        glVertex2f(-0.6,0.9);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.6,0.9);
        glVertex2f(-0.6,0.92);
    glEnd();
    glPopMatrix();


    // Add moving car


    // Add moving cloud
    drawFluffyCloud(cloudPosition, 0.8, 1.0);


    // Add moving plane with wheels
    drawRealisticPlane(planeX, planeY);
}




void Railway()
{
    for (int step = 0; step <= 12; step++) {
    float i = step * 0.15f;
    float j = step * 0.105f;
    glPushMatrix();
    glTranslated(-0.1+i,0.08-j,0);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.864f, 0.179f );
        glVertex2f(-0.946f  , 0.055f  );
    glEnd();


    glBegin(GL_LINES);
        glVertex2f(-0.91f , 0.026f  );
        glVertex2f(-0.817f  ,0.146f  );
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.872f  , -0.012f  );
        glVertex2f(-0.773f , 0.109f );
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.973f , 0.066f );
        glVertex2f(-0.777f , -0.079f );
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.902f , 0.204f);
        glVertex2f(-0.73f , 0.081f );
    glEnd();
    glPopMatrix();
    }


}

void Building(float x, float y,float scalex, float scaley)
{


    glPushMatrix();
    glScaled(scalex, scaley, 0);
    glBegin(GL_QUADS);
    {
        glVertex2f(x,y);
        glVertex2f(x,y-0.903);
        glVertex2f(x-0.258,y-0.832);
        glVertex2f(x-0.265,y-0.011);
    }
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x  , y-0.903);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(x  , y-0.903);
        glVertex2f(x-0.258,y-0.832);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(x-0.258,y-0.832);
        glVertex2f(x-0.265,y-0.011);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(x-0.265,y-0.011);
        glVertex2f(x, y);
    glEnd();


    glBegin(GL_QUADS);
    {
        glVertex2f(x,y);
        glVertex2f(x,y-0.903);
        glVertex2f(x+0.116,y-0.851);
        glVertex2f(x+0.114,y+0.004);
    }
    glEnd();

    if(!state)
    glColor3f(0.0, 0.0, 0.0);
    else
    glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_QUADS);
        {
            glVertex2f(x-0.235,y-0.117);
            glVertex2f(x-0.174,y-0.109);
            glVertex2f(x-0.174,y-0.211);
            glVertex2f(x-0.235,y-0.211);
        }
        glEnd();

    if(!state)
    glColor3f(0.0, 0.0, 0.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        {
            glVertex2f(x-0.101,y-0.207);
            glVertex2f(x-0.043,y-0.209);
            glVertex2f(x-0.042,y-0.112);
            glVertex2f(x-0.101,y-0.112);
        }
    glEnd();
    if(!state)
    glColor3f(0.0, 0.0, 0.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        {
            glVertex2f(x-0.234,y-0.334);
            glVertex2f(x-0.175,y-0.332);
            glVertex2f(x-0.175,y-0.43);
            glVertex2f(x-0.234,y-0.43);
        }
    glEnd();

    if(!state)
    glColor3f(0.0, 0.0, 0.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        {
            glVertex2f(x-0.098,y-0.429);
            glVertex2f(x-0.038,y-0.432);
            glVertex2f(x-0.04,y-0.315);
            glVertex2f(x-0.098,y-0.318);
        }
    glEnd();
    glPopMatrix();


    glPopMatrix();

}

void drawCircle(float centerX, float centerY, float radius, int numSegments) {
	float aspectRatio = (float)glutGet(GLUT_WINDOW_HEIGHT) / (float)glutGet(GLUT_WINDOW_WIDTH);



       // Apply scaling to maintain aspect ratio


	int i;
	GLfloat x=centerX; GLfloat y=centerY;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();


}

void drawoutline(float x1, float y1, float x2, float y2, float width)
{
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(width);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2  , y2);
    glEnd();
}

void Trees1(float x, float y,int randomizer,float scale)
{
    glPushMatrix();
    glScaled(scale,scale,0);

    if(randomizer%2 == 0)
    {
    glColor3f(0.0, 0.608, 0.0);
    }
    else
    {
       glColor3f(0.0, 0.308, 0.0);
    }
    drawCircle(x+0.007, y+0.229, 0.05, 50);

     glColor3f(0.0, 0.608, 0.0);
    drawCircle(x+0.07, y+0.210, 0.05, 50);

    if(randomizer%2 != 0 || randomizer <= 3)
    {
        glColor3f(0.0, 0.508, 0.0);
        drawCircle(x+0.002, y+0.308, 0.05, 50);
    }

    else
    {
        glColor3f(0.0, 0.808, 0.0);
        drawCircle(x-0.002, y+0.208, 0.05, 50);
    }


    glColor3f(0.30, 0.20, 0.10);
    glBegin(GL_TRIANGLES);
    {
        glVertex2f(x,y);
        glVertex2f(x+0.037,y);
        glVertex2f(x,y+0.349);
    }
    glEnd();



    glColor3f(0.30, 0.20, 0.10);
    glBegin(GL_TRIANGLES);
    {
        glVertex2f(x,y+0.133);
        glVertex2f(x-0.079,y+0.214);
        glVertex2f(x,y+0.172);
    }
    glEnd();

    glColor3f(0.0, 0.908, 0.0);
    drawCircle(x+0.079, y+0.273, 0.05, 50);



    glColor3f(0.30, 0.20, 0.10);
    glBegin(GL_TRIANGLES);
    {
        glVertex2f(x+0.011,y+0.204);
        glVertex2f(x+0.079,y+0.271);
        glVertex2f(x+0.01,y+0.23);
    }
    glEnd();

    //Leaaves
    if(randomizer%2 == 0 || randomizer%5 == 0)
    {
        glColor3f(0.0, 0.708, 0.0);
    }
    else
    {
        glColor3f(0.0, 0.308, 0.0);
    }

    drawCircle(x-0.079, y+0.214, 0.05, 50);

    glColor3f(0.0, 0.608, 0.0);
    if(randomizer%2 != 0 || randomizer > 5)
    {
        drawCircle(x-0.042, y+0.25, 0.05, 50);
    }

    else
        {
            drawCircle(x-0.049, y+0.226, 0.05, 50);
        }


    glColor3f(0.0, 0.808, 0.0);
    drawCircle(x-0.062, y+0.246, 0.05, 50);

    glColor3f(0.0, 0.908, 0.0);
    drawCircle(x+0.015, y+0.338, 0.05, 50);

    if(randomizer%2 != 0 || randomizer%3 == 0)
    {
        glColor3f(0.0, 0.508, 0.0);
    }
    else{
    glColor3f(0.0, 0.808, 0.0);
    }
    drawCircle(x+0.099, y+0.253, 0.05, 50);
    glPopMatrix();
}

void Trees2(float x, float y,int randomizer,float scale)
{
    glPushMatrix();
    glScaled(scale,scale,0);
    glColor3f(0.30, 0.20, 0.10);
    glBegin(GL_TRIANGLES);
    {
        glVertex2f(x,y);
        glVertex2f(x+0.038,y+0.467);
        glVertex2f(x+0.085,y+0.003);
    }
    glEnd();

    glColor3f(0.0, 0.20, 0.0);
    glBegin(GL_TRIANGLES);
    {
        glVertex2f(x-0.04,y+0.242);
        glVertex2f(x+0.118,y+0.24);
        glVertex2f(x+0.038,y+0.37);
    }
    glEnd();

    glColor3f(0.0, 0.50, 0.0);
    glBegin(GL_TRIANGLES);
    {
        glVertex2f(x-0.002,y+0.33);
        glVertex2f(x+0.088,y+0.326);
        glVertex2f(x+0.04,y+0.433);
    }
    glEnd();

    glColor3f(0.0, 0.80, 0.0);
    glBegin(GL_TRIANGLES);
    {
        glVertex2f(x+0.067,y+0.401);
        glVertex2f(x+0.012,y+0.4014);
        glVertex2f(x+0.038,y+0.485);
    }
    glEnd();
    glPopMatrix();
}
// Function to render Scene 3
void renderScene3() {


    //Sky
    if(!state)
    glColor3f(0.530, 0.808, 0.922); // Light gray
    else
    glColor3f(0.0, 0.0, 0.290);
    glBegin(GL_QUADS);
    {
        glVertex2f(-1,0.434);
        glVertex2f(1.0,-0.212);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
    }
    glEnd();


    glColor3f(1.0, 0.875, 0.133); // Light gray
    drawCircle(0.851, 0.89, 0.05, 50);

    if(!state)
    drawFluffyCloud(cloudPosition, 0.8, 0.8);

      ///////////////////////////////////////////////////////////////////


    glColor3f(0.12, 0.12, 0.775);
     Building(-1.75, 1.72, 0.5,0.5);

    glColor3f(0.365, 0.12, 0.775);
     Building(-1.6, 1.65, 0.5,0.5);

    glColor3f(0.365, 0.775, 0.45);
     Building(-1.4, 1.6, 0.5,0.5);

      glColor3f(0.365, 0.775, 0.45);
     Building(-1.2, 1.5, 0.5,0.5);

    glColor3f(0.772, 0.775, 0.45);
     Building(-0.8, 1.25, 0.6,0.6);

    glColor3f(0.365, 0.2, 0.365);
     Building(-0.6, 1.2, 0.6,0.6);

    glColor3f(0.125, 0.2, 0.365);
     Building(-0.216, 1.1, 0.755,0.5);

    glColor3f(0.125, 0.45, 0.365);
     Building(-0.06, 0.87, 0.9,0.9);

    glColor3f(0.125, 0.365, 0.45);
     Building(0.18, 0.72, 0.8,0.7);

    glColor3f(0.365, 0.10, 0.45);
     Building(0.359, 0.7, 0.9,0.9);

    glColor3f(0.0, 0.8, 0.8);
     Building(0.492, 0.7,1,1);

    glColor3f(0.8, 0.8, 0.0);
    Building(0.733, 0.638,0.9,0.9);

     glColor3f(0.0, 0.8, 0.8);
     Building(1, 0.653,1,1);
//
    Trees2(-0.18, -0.2,5,1.0);

    Trees1(0.50, -0.35,3,1.5);
    Trees1(0.45, -0.3,2,2);
    Trees1(0.15, -0.25,2,2);
    Trees1(0.06, -0.15,1,1.8);
    Trees1(-0.2, -0.05,10,1.6);

    Trees2(0.35, -0.4,5,1.5);


    //Track Left Side
    glColor3f(0.8, 0.8, 0.8); // Light gray
    glBegin(GL_QUADS);
    {
        glVertex2f(0.418,-0.998);
        glVertex2f(0.048,-1.0);
        glVertex2f(-1,-0.08);
        glVertex2f(-0.811,-0.123);
    }
    glEnd();

    glColor3f(0.8, 0.8, 0.8); // Light gray
    glBegin(GL_TRIANGLES);
    {
        glVertex2f(-1.0,-0.079);
        glVertex2f(-1.0,0.024);
        glVertex2f(-0.808,-0.13);
    }
    glEnd();



    //Track Right Side
    glColor3f(0.8, 0.8, 0.8); // Light gray
    glBegin(GL_QUADS);
    {
        glVertex2f(1,-1);
        glVertex2f(1,-0.744);
        glVertex2f(-1.0,0.431);
        glVertex2f(-1.0,0.321);
    }
    glEnd();



    //Track Center
    glColor3f(0.5, 0.5, 0.5); // Light gray
    glBegin(GL_QUADS);
    {
        glVertex2f(0.417,-1);
        glVertex2f(1,-1);
        glVertex2f(-1.0,0.322);
        glVertex2f(-1.0,0.02);
    }
    glEnd();



    Railway();


    glPushMatrix();
    //Track Pillar
    glColor3f(0.5, 0.5, 0.5); // Light gray
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.655,-0.387);
        glVertex2f(-0.652,-0.996);
        glVertex2f(-0.517,-1.0);
        glVertex2f(-0.516,-0.506);
    }
    glEnd();

    glColor3f(0.5, 0.5, 0.5); // Light gray
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.96,-0.112);
        glVertex2f(-0.964,-1.0);
        glVertex2f(-0.892,-0.988);
        glVertex2f(-0.888,-0.178);
    }
    glEnd();

    drawoutline(0.257, -0.994, -1, -0.032, 8.0f);
    drawoutline(0.413, -0.998, -1, 0.015, 8.0f);
    drawoutline(0.056, -1.008, -1, -0.076, 8.0f);



/////


    glPopMatrix();

    drawoutline(-1.0,0.43,1.0,-0.75, 8.0f);
    drawoutline(-1.0,0.325,1.0,-0.99, 8.0f);

    drawoutline(-0.964,-0.11,-0.964,-1.0, 8.0f);
    drawoutline(-0.89,-0.177,-0.89,-1.0, 8.0f);
    drawoutline(-0.65,-0.39,-0.65,-1.0, 8.0f);
    drawoutline(-0.516,-0.507,-0.516,-1.0, 8.0f);


//////////////////////////////////////////////////////////////////

//Train Start
glPushMatrix();
glTranslated(TrainStartX,TrainStartY,0);
glRotated(-1.0,0,0,1.0);
  glPushMatrix();
    glRotated(-5,0.0,0.0,1.0);
    glTranslated(-0.96,0.26,0.0);
    glScaled(0.55,0.55,0.0);



    glColor3f(0.0, 0.1, 0.0); //Train Front
    glBegin(GL_QUADS);
    {
        glVertex2f(0.5,-0.81);
        glVertex2f(0.782,-0.823);
        glVertex2f(0.788,-0.406);
        glVertex2f(0.515,-0.39);
    }
    glEnd();

    glColor3f(0.0, 0.2, 0.0); // Train Side
    glBegin(GL_QUADS);
    {
        glVertex2f(0.517,-0.39);
        glVertex2f(-0.157,-0.16);
        glVertex2f(-0.172,-0.427);
        glVertex2f(0.505,-0.814);
    }
    glEnd();

    glColor3f(0.5, 0.0, 0.0); // Train Stripe
    glBegin(GL_QUADS);
    {
        glVertex2f(0.511,-0.525);
        glVertex2f(-0.166,-0.263);
        glVertex2f(-0.16,-0.21);
        glVertex2f(0.513,-0.464);
    }
    glEnd();

    glColor3f(0.5, 0.0, 0.0); // Train Stripe
    glBegin(GL_QUADS);
    {
        glVertex2f(0.511,-0.525);
        glVertex2f(0.786,-0.54);
        glVertex2f(0.788,-0.476);
        glVertex2f(0.514,-0.46);
    }
    glEnd();

    drawoutline(0.788,-0.478,0.5147,-0.462, 8.0f);
    drawoutline(0.513,-0.522,0.787,-0.538, 8.0f);
    drawoutline(0.508,-0.523,-0.162,-0.2634, 8.0f);
    drawoutline(-0.161,-0.212,0.516,-0.4616, 8.0f);

    glColor3f(0.4, 0.0, 0.0); //Train Top
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.16,-0.16);
        glVertex2f(-0.004,-0.114);
        glVertex2f(0.79,-0.406);
        glVertex2f(0.517,-0.392);
    }
    glEnd();

    drawoutline(0.513, -0.391, -0.153, -0.16, 8.0f);
    drawoutline(-0.171, -0.427, 0.505, -0.81, 8.0f);
    drawoutline(-0.169, -0.425, -0.153, -0.16, 8.0f);
    drawoutline(0.513, -0.394, 0.505, -0.8, 8.0f);
    drawoutline(0.513, -0.394, 0.789, -0.404, 8.0f);
    drawoutline(0.783, -0.82, 0.79, -0.409, 8.0f);
    drawoutline(0.784, -0.816, 0.504, -0.808, 8.0f);
    drawoutline(0.79, -0.408, -0.003, -0.116, 8.0f);
    drawoutline(-0.003,-0.116, -0.154, -0.158, 8.0f);


    //Train Door1
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.35,-0.382);
        glVertex2f(0.419,-0.408);
        glVertex2f(0.412,-0.722);
        glVertex2f(0.334,-0.685);
    }
    glEnd();

    //Train Door2
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.129,-0.298);
        glVertex2f(0.178,-0.31);
        glVertex2f(0.17,-0.587);
        glVertex2f(0.12,-0.56);
    }
    glEnd();

    //Train Door3
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.006,-0.25);
        glVertex2f(-0.013,-0.485);
        glVertex2f(-0.059,-0.466);
        glVertex2f(-0.053,-0.226);
    }
    glEnd();


    drawoutline(0.35,-0.382,0.4184,-0.408, 8.0f);
    drawoutline(0.4184,-0.408,0.4118,-0.721, 8.0f);
    drawoutline(0.4118,-0.721,0.3347,-0.6846, 8.0f);
    drawoutline(0.3347,-0.6846,0.35,-0.382, 8.0f);

    drawoutline(0.217,-0.3513,0.3075,-0.385, 8.0f);
    drawoutline(0.3075,-0.385,0.298,-0.528, 8.0f);
    drawoutline(0.298,-0.528,0.2133,-0.4846, 8.0f);
    drawoutline(0.2133,-0.4846,0.217,-0.3513, 8.0f);

    drawoutline(0.128,-0.299,0.178,-0.3116, 8.0f);
    drawoutline(0.178,-0.3116,0.169,-0.587, 8.0f);
    drawoutline(0.169,-0.587,0.118,-0.56, 8.0f);
    drawoutline(0.118,-0.56,0.128,-0.299, 8.0f);

    drawoutline(0.022,-0.3954,0.09,-0.424, 8.0f);
    drawoutline(0.09,-0.424,0.096,-0.3055, 8.0f);
    drawoutline(0.096,-0.3055,0.029,-0.28, 8.0f);
    drawoutline(0.029,-0.28,0.022,-0.3954, 8.0f);

    drawoutline(-0.053,-0.2266,-0.006,-0.244, 8.0f);
    drawoutline(-0.006,-0.244,-0.0133,-0.4835, 8.0f);
    drawoutline(-0.0133,-0.4835,-0.0587,-0.4647, 8.0f);
    drawoutline(-0.0587,-0.4647,-0.053,-0.2266, 8.0f);

    drawoutline(-0.136,-0.318,-0.086,-0.334, 8.0f);
    drawoutline(-0.086,-0.334,-0.081,-0.226, 8.0f);
    drawoutline(-0.081,-0.226,-0.132,-0.2015, 8.0f);
    drawoutline(-0.132,-0.2015,-0.136,-0.318, 8.0f);

    if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.308,-0.384);
        glVertex2f(0.301,-0.53);
        glVertex2f(0.213,-0.485);
        glVertex2f(0.219,-0.347);
    }
    glEnd();

    if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.086,-0.335);
        glVertex2f(-0.08,-0.226);
        glVertex2f(-0.13,-0.2);
        glVertex2f(-0.137,-0.317);
    }
    glEnd();

     if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.029,-0.28);
        glVertex2f(0.094,-0.305);
        glVertex2f(0.089,-0.424);
        glVertex2f(0.022,-0.395);
    }
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(0.45, -0.83, 0.03, 100);


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(0.349, -0.777, 0.03, 100);


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-0.076, -0.521, 0.03, 100);


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-0.14, -0.487, 0.03, 100);

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.172,-0.427);
        glVertex2f(0.504,-0.812);
        glVertex2f(0.498,-0.864);
        glVertex2f(-0.177,-0.466);
    }
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.503,-0.810);
        glVertex2f(0.783,-0.82);
        glVertex2f(0.781,-0.875);
        glVertex2f(0.4976,-0.864);
    }
    glEnd();
    drawoutline(-0.172,-0.427, -0.177, -0.466, 8.0f);
    drawoutline(0.498,-0.862, 0.503, -0.81, 8.0f);
    drawoutline(-0.175,-0.463, 0.499, -0.86, 8.0f);
    drawoutline(0.782,-0.817, 0.781, -0.873, 8.0f);
    drawoutline(0.781,-0.873,0.498,-0.86, 8.0f);


    drawoutline(0.781,-0.873,0.498,-0.86, 8.0f);
    glPopMatrix();




//////////

    glPushMatrix();
    glTranslated(-0.55,0.17,0.0);
    glScaled(0.7,0.7,0.0);
    glColor3f(0.0, 0.1, 0.0); //Train Front
    glBegin(GL_QUADS);
    {
        glVertex2f(0.5,-0.81);
        glVertex2f(0.782,-0.823);
        glVertex2f(0.788,-0.406);
        glVertex2f(0.515,-0.39);
    }
    glEnd();

    glColor3f(0.0, 0.2, 0.0); // Train Side
    glBegin(GL_QUADS);
    {
        glVertex2f(0.517,-0.39);
        glVertex2f(-0.157,-0.16);
        glVertex2f(-0.172,-0.427);
        glVertex2f(0.505,-0.814);
    }
    glEnd();

    glColor3f(0.5, 0.0, 0.0); // Train Stripe
    glBegin(GL_QUADS);
    {
        glVertex2f(0.511,-0.525);
        glVertex2f(-0.166,-0.263);
        glVertex2f(-0.16,-0.21);
        glVertex2f(0.513,-0.464);
    }
    glEnd();

    glColor3f(0.5, 0.0, 0.0); // Train Stripe
    glBegin(GL_QUADS);
    {
        glVertex2f(0.511,-0.525);
        glVertex2f(0.786,-0.54);
        glVertex2f(0.788,-0.476);
        glVertex2f(0.514,-0.46);
    }
    glEnd();

    drawoutline(0.788,-0.478,0.5147,-0.462, 8.0f);
    drawoutline(0.513,-0.522,0.787,-0.538, 8.0f);
    drawoutline(0.508,-0.523,-0.162,-0.2634, 8.0f);
    drawoutline(-0.161,-0.212,0.516,-0.4616, 8.0f);

    glColor3f(0.4, 0.0, 0.0); //Train Top
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.16,-0.16);
        glVertex2f(-0.004,-0.114);
        glVertex2f(0.79,-0.406);
        glVertex2f(0.517,-0.392);
    }
    glEnd();

    drawoutline(0.513, -0.391, -0.153, -0.16, 8.0f);
    drawoutline(-0.171, -0.427, 0.505, -0.81, 8.0f);
    drawoutline(-0.169, -0.425, -0.153, -0.16, 8.0f);
    drawoutline(0.513, -0.394, 0.505, -0.8, 8.0f);
    drawoutline(0.513, -0.394, 0.789, -0.404, 8.0f);
    drawoutline(0.783, -0.82, 0.79, -0.409, 8.0f);
    drawoutline(0.784, -0.816, 0.504, -0.808, 8.0f);
    drawoutline(0.79, -0.408, -0.003, -0.116, 8.0f);
    drawoutline(-0.003,-0.116, -0.154, -0.158, 8.0f);


    //Train Door1
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.35,-0.382);
        glVertex2f(0.419,-0.408);
        glVertex2f(0.412,-0.722);
        glVertex2f(0.334,-0.685);
    }
    glEnd();

    //Train Door2
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.129,-0.298);
        glVertex2f(0.178,-0.31);
        glVertex2f(0.17,-0.587);
        glVertex2f(0.12,-0.56);
    }
    glEnd();

    //Train Door3
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.006,-0.25);
        glVertex2f(-0.013,-0.485);
        glVertex2f(-0.059,-0.466);
        glVertex2f(-0.053,-0.226);
    }
    glEnd();


    drawoutline(0.35,-0.382,0.4184,-0.408, 8.0f);
    drawoutline(0.4184,-0.408,0.4118,-0.721, 8.0f);
    drawoutline(0.4118,-0.721,0.3347,-0.6846, 8.0f);
    drawoutline(0.3347,-0.6846,0.35,-0.382, 8.0f);

    drawoutline(0.217,-0.3513,0.3075,-0.385, 8.0f);
    drawoutline(0.3075,-0.385,0.298,-0.528, 8.0f);
    drawoutline(0.298,-0.528,0.2133,-0.4846, 8.0f);
    drawoutline(0.2133,-0.4846,0.217,-0.3513, 8.0f);

    drawoutline(0.128,-0.299,0.178,-0.3116, 8.0f);
    drawoutline(0.178,-0.3116,0.169,-0.587, 8.0f);
    drawoutline(0.169,-0.587,0.118,-0.56, 8.0f);
    drawoutline(0.118,-0.56,0.128,-0.299, 8.0f);

    drawoutline(0.022,-0.3954,0.09,-0.424, 8.0f);
    drawoutline(0.09,-0.424,0.096,-0.3055, 8.0f);
    drawoutline(0.096,-0.3055,0.029,-0.28, 8.0f);
    drawoutline(0.029,-0.28,0.022,-0.3954, 8.0f);

    drawoutline(-0.053,-0.2266,-0.006,-0.244, 8.0f);
    drawoutline(-0.006,-0.244,-0.0133,-0.4835, 8.0f);
    drawoutline(-0.0133,-0.4835,-0.0587,-0.4647, 8.0f);
    drawoutline(-0.0587,-0.4647,-0.053,-0.2266, 8.0f);

    drawoutline(-0.136,-0.318,-0.086,-0.334, 8.0f);
    drawoutline(-0.086,-0.334,-0.081,-0.226, 8.0f);
    drawoutline(-0.081,-0.226,-0.132,-0.2015, 8.0f);
    drawoutline(-0.132,-0.2015,-0.136,-0.318, 8.0f);

    if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.308,-0.384);
        glVertex2f(0.301,-0.53);
        glVertex2f(0.213,-0.485);
        glVertex2f(0.219,-0.347);
    }
    glEnd();

    if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.086,-0.335);
        glVertex2f(-0.08,-0.226);
        glVertex2f(-0.13,-0.2);
        glVertex2f(-0.137,-0.317);
    }
    glEnd();

     if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.029,-0.28);
        glVertex2f(0.094,-0.305);
        glVertex2f(0.089,-0.424);
        glVertex2f(0.022,-0.395);
    }
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(0.45, -0.83, 0.03, 100);


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(0.349, -0.777, 0.03, 100);


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-0.076, -0.521, 0.03, 100);


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-0.14, -0.487, 0.03, 100);

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.172,-0.427);
        glVertex2f(0.504,-0.812);
        glVertex2f(0.498,-0.864);
        glVertex2f(-0.177,-0.466);
    }
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.503,-0.810);
        glVertex2f(0.783,-0.82);
        glVertex2f(0.781,-0.875);
        glVertex2f(0.4976,-0.864);
    }
    glEnd();
    drawoutline(-0.172,-0.427, -0.177, -0.466, 8.0f);
    drawoutline(0.498,-0.862, 0.503, -0.81, 8.0f);
    drawoutline(-0.175,-0.463, 0.499, -0.86, 8.0f);
    drawoutline(0.782,-0.817, 0.781, -0.873, 8.0f);
    drawoutline(0.781,-0.873,0.498,-0.86, 8.0f);


    drawoutline(0.781,-0.873,0.498,-0.86, 8.0f);
    glPopMatrix();



/////////////

     //Train Carriage
    glColor3f(0.0, 0.2, 0.0); //Train Front
    glBegin(GL_QUADS);
    {
        glVertex2f(0.5,-0.81);
        glVertex2f(0.782,-0.823);
        glVertex2f(0.788,-0.406);
        glVertex2f(0.515,-0.39);
    }
    glEnd();

    glColor3f(0.0, 0.2, 0.0); // Train Side
    glBegin(GL_QUADS);
    {
        glVertex2f(0.517,-0.39);
        glVertex2f(-0.157,-0.16);
        glVertex2f(-0.172,-0.427);
        glVertex2f(0.505,-0.814);
    }
    glEnd();

    glColor3f(0.5, 0.0, 0.0); // Train Stripe
    glBegin(GL_QUADS);
    {
        glVertex2f(0.511,-0.525);
        glVertex2f(-0.166,-0.263);
        glVertex2f(-0.16,-0.21);
        glVertex2f(0.513,-0.464);
    }
    glEnd();

    glColor3f(0.5, 0.0, 0.0); // Train Stripe
    glBegin(GL_QUADS);
    {
        glVertex2f(0.511,-0.525);
        glVertex2f(0.786,-0.54);
        glVertex2f(0.788,-0.476);
        glVertex2f(0.514,-0.46);
    }
    glEnd();

    drawoutline(0.788,-0.478,0.5147,-0.462, 8.0f);
    drawoutline(0.513,-0.522,0.787,-0.538, 8.0f);
    drawoutline(0.508,-0.523,-0.162,-0.2634, 8.0f);
    drawoutline(-0.161,-0.212,0.516,-0.4616, 8.0f);

    glColor3f(0.4, 0.0, 0.0); //Train Top
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.16,-0.16);
        glVertex2f(-0.004,-0.114);
        glVertex2f(0.79,-0.406);
        glVertex2f(0.517,-0.392);
    }
    glEnd();

    drawoutline(0.513, -0.391, -0.153, -0.16, 8.0f);
    drawoutline(-0.171, -0.427, 0.505, -0.81, 8.0f);
    drawoutline(-0.169, -0.425, -0.153, -0.16, 8.0f);
    drawoutline(0.513, -0.394, 0.505, -0.8, 8.0f);
    drawoutline(0.513, -0.394, 0.789, -0.404, 8.0f);
    drawoutline(0.783, -0.82, 0.79, -0.409, 8.0f);
    drawoutline(0.784, -0.816, 0.504, -0.808, 8.0f);
    drawoutline(0.79, -0.408, -0.003, -0.116, 8.0f);
    drawoutline(-0.003,-0.116, -0.154, -0.158, 8.0f);

    //Train Front Window
    if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.559,-0.456);
        glVertex2f(0.767,-0.46);
        glVertex2f(0.765,-0.627);
        glVertex2f(0.563,-0.63);
    }
    glEnd();

    //Train Door1
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.35,-0.382);
        glVertex2f(0.419,-0.408);
        glVertex2f(0.412,-0.722);
        glVertex2f(0.334,-0.685);
    }
    glEnd();

    //Train Door2
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.129,-0.298);
        glVertex2f(0.178,-0.31);
        glVertex2f(0.17,-0.587);
        glVertex2f(0.12,-0.56);
    }
    glEnd();

    //Train Door3
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.006,-0.25);
        glVertex2f(-0.013,-0.485);
        glVertex2f(-0.059,-0.466);
        glVertex2f(-0.053,-0.226);
    }
    glEnd();



    if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.308,-0.384);
        glVertex2f(0.301,-0.53);
        glVertex2f(0.213,-0.485);
        glVertex2f(0.219,-0.347);
    }
    glEnd();

    if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.086,-0.335);
        glVertex2f(-0.08,-0.226);
        glVertex2f(-0.13,-0.2);
        glVertex2f(-0.137,-0.317);
    }
    glEnd();

     if(!state)
    glColor3f(0.0, 1.0, 1.0);
    else
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.029,-0.28);
        glVertex2f(0.094,-0.305);
        glVertex2f(0.089,-0.424);
        glVertex2f(0.022,-0.395);
    }
    glEnd();

     //windows outline
    drawoutline(0.56,-0.455,0.767,-0.459, 8.0f);
    drawoutline(0.767,-0.459,0.763,-0.626, 8.0f);
    drawoutline(0.763,-0.626,0.563,-0.6296, 8.0f);
    drawoutline(0.563,-0.6296,0.56,-0.455, 8.0f);

    drawoutline(0.35,-0.382,0.4184,-0.408, 8.0f);
    drawoutline(0.4184,-0.408,0.4118,-0.721, 8.0f);
    drawoutline(0.4118,-0.721,0.3347,-0.6846, 8.0f);
    drawoutline(0.3347,-0.6846,0.35,-0.382, 8.0f);

    drawoutline(0.217,-0.3513,0.3075,-0.385, 8.0f);
    drawoutline(0.3075,-0.385,0.298,-0.528, 8.0f);
    drawoutline(0.298,-0.528,0.2133,-0.4846, 8.0f);
    drawoutline(0.2133,-0.4846,0.217,-0.3513, 8.0f);

    drawoutline(0.128,-0.299,0.178,-0.3116, 8.0f);
    drawoutline(0.178,-0.3116,0.169,-0.587, 8.0f);
    drawoutline(0.169,-0.587,0.118,-0.56, 8.0f);
    drawoutline(0.118,-0.56,0.128,-0.299, 8.0f);

    drawoutline(0.022,-0.3954,0.09,-0.424, 8.0f);
    drawoutline(0.09,-0.424,0.096,-0.3055, 8.0f);
    drawoutline(0.096,-0.3055,0.029,-0.28, 8.0f);
    drawoutline(0.029,-0.28,0.022,-0.3954, 8.0f);

    drawoutline(-0.053,-0.2266,-0.006,-0.244, 8.0f);
    drawoutline(-0.006,-0.244,-0.0133,-0.4835, 8.0f);
    drawoutline(-0.0133,-0.4835,-0.0587,-0.4647, 8.0f);
    drawoutline(-0.0587,-0.4647,-0.053,-0.2266, 8.0f);

    drawoutline(-0.136,-0.318,-0.086,-0.334, 8.0f);
    drawoutline(-0.086,-0.334,-0.081,-0.226, 8.0f);
    drawoutline(-0.081,-0.226,-0.132,-0.2015, 8.0f);
    drawoutline(-0.132,-0.2015,-0.136,-0.318, 8.0f);

    glColor3f(0.0, 0.0, 0.0);
    drawCircle(0.45, -0.83, 0.03, 100);


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(0.349, -0.777, 0.03, 100);


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-0.076, -0.521, 0.03, 100);


    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-0.14, -0.487, 0.03, 100);

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.172,-0.427);
        glVertex2f(0.504,-0.812);
        glVertex2f(0.498,-0.864);
        glVertex2f(-0.177,-0.466);
    }
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.503,-0.810);
        glVertex2f(0.783,-0.82);
        glVertex2f(0.781,-0.875);
        glVertex2f(0.4976,-0.864);
    }
    glEnd();

    drawoutline(-0.172,-0.427, -0.177, -0.466, 8.0f);
    drawoutline(0.498,-0.862, 0.503, -0.81, 8.0f);
    drawoutline(-0.175,-0.463, 0.499, -0.86, 8.0f);
    drawoutline(0.782,-0.817, 0.781, -0.873, 8.0f);
    drawoutline(0.781,-0.873,0.498,-0.86, 8.0f);


    drawoutline(0.781,-0.873,0.498,-0.86, 8.0f);
    glPopMatrix();



    if(state){
     glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

     glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // Semi-transparent black
        glBegin(GL_QUADS);
            glVertex2f(1.0f, 1.0f);
            glVertex2f(1.0f, -1.0f);
            glVertex2f(-1.0f, -1.0f);
            glVertex2f(-1.0f, 1.0f);
        glEnd();
    }

    if(state){
    glColor3f(1.0, 1.0, 1.0); // Light gray
    drawCircle(0.851, 0.89, 0.05, 50);}




}



void RoadStripe()
{   for (int step = 0; step <= 20; step++) {
    float i = step * 0.046f;
    float j = step * 0.1f;
    glPushMatrix();
    glTranslated(-i,-j,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_QUADS);
    {
        glVertex2f(0.902,0.978);
        glVertex2f(0.9115,0.971);
        glVertex2f(0.895,0.932);
        glVertex2f(0.8865,0.939);
    }
    glEnd();
        glPopMatrix();
    }
}

void RoadStripe2()
{   for (int step = 0; step <= 20; step++) {
    float i = step * 0.085f;
    float j = step * 0.1f;
    glPushMatrix();
    glTranslated(-i,-j,0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_QUADS);
    {
        glVertex2f(0.709,0.983);
        glVertex2f(0.722,0.977);
        glVertex2f(0.702,0.941);
        glVertex2f(0.689,0.947);
    }
        glEnd();
        glPopMatrix();
    }
}



void LightPole()
{   for (int step = 0; step <= 5; step++) {
    float i = step * 0.3f;
    float j = step * 0.46f;
    glPushMatrix();
    glTranslated(i,j,0);
        glColor3f(0.75, 0.75, 0.75);
        glLineWidth(14.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.416,-0.844);
            glVertex2f(-0.432,0.52);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(-0.43,0.376);
            glVertex2f(-0.273,0.53);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(-0.43,0.375);
            glVertex2f(-0.588,0.53);
        glEnd();

        glLineWidth(14.0f);
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2f(-0.588,0.53);
            glVertex2f(-0.610,0.53);
        glEnd();

        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2f(-0.279,0.53);
            glVertex2f(-0.257,0.53);
        glEnd();
        glPopMatrix();
    }
}

void Pillar()
{
    for (int step = 0; step <= 5; step++) {
    float i = step * 0.155f;
    float j = step * 0.5f;
    glPushMatrix();
    glTranslated(i,j,0);
    glColor3f(0.8,0.8,0.8);
        glBegin(GL_QUADS);
    {
        glVertex2f(0.473,-0.664);
        glVertex2f(0.674,-0.666);
        glVertex2f(0.674,-1.0);
        glVertex2f(0.381,-1.0);
    }
    glEnd();
    glColor3f(0.9,0.9,0.9);
     glBegin(GL_QUADS);
    {
        glVertex2f(0.473,-0.664);
        glVertex2f(0.674,-0.666);
        glVertex2f(0.6666,-0.642);
        glVertex2f(0.4806,-0.643);
    }
    glEnd();
        glPopMatrix();
    }
}
void renderScene4() {
//ground
     glColor3f(0.361,0.263,0.153);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.355,-1);
        glVertex2f(0.988,1.0);
        glVertex2f(1,1);
        glVertex2f(1,-1);
    }
    glEnd();

    //GGreen

    glColor3f(0.0,0.4,0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(-1.0,-0.443);
        glVertex2f(0.65,1.0);
        glVertex2f(-1,1);
        glVertex2f(-1.0,-0.443);
    }
    glEnd();

    //sky
    glColor3f(0.53,0.808,0.923);
    glBegin(GL_QUADS);
    {
        glVertex2f(-1.0,0.31);
        glVertex2f(-0.148,1.0);
        glVertex2f(-1,1);
        glVertex2f(-1.0,0.31);
    }
    glEnd();

    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.595,-0.099);
        glVertex2f(-0.601,0.495);
        glVertex2f(-0.44,0.542);
        glVertex2f(-0.307,0.121);
    }
    glEnd();



    glLineWidth(10.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.78,0.68);
        glVertex2f(-0.443,0.666);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.78,0.572);
        glVertex2f(-0.717,0.572);
    glEnd();


    Pillar();

    RoadStripe();
    RoadStripe2();

    //buildings

    glColor3f(0.0, 0.0, 0.5);

    glBegin(GL_QUADS);
    {
        glVertex2f(-0.153,0.864);
        glVertex2f(-0.155,0.336);
        glVertex2f(-0.321,0.193);
        glVertex2f(-0.33,0.729);
    }

        glEnd();

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
    {
        glVertex2f(-0.217,1.003);
        glVertex2f(0.0506,1.001);
        glVertex2f(-0.152,0.864);
        glVertex2f(-0.215,1.002);
    }

        glEnd();

    glColor3f(1.0, 0.65, 0.0);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.052,1.002);
        glVertex2f(0.054,0.836);
        glVertex2f(-0.154,0.687);
        glVertex2f(-0.154,0.865);
    }

        glEnd();

    glColor3f(1.0, 0.75, 0.8);

    glBegin(GL_QUADS);
    {
        glVertex2f(-1.001,0.17);
        glVertex2f(-0.676,0.43);
        glVertex2f(-0.681,-0.145);
        glVertex2f(-1.002,-0.412);
    }

        glEnd();

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_QUADS);
    {
        glVertex2f(-0.675,0.429);
        glVertex2f(-0.672,0.538);
        glVertex2f(-1.001,0.535);
        glVertex2f(-1.001,0.172);
    }

        glEnd();

    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(-1.001,0.094);
        glVertex2f(-0.676,0.357);
        glVertex2f(-0.677,0.245);
        glVertex2f(-0.999,-0.021);
    }

        glEnd();

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    {
        glVertex2f(-1,-0.113);
        glVertex2f(-0.679,0.148);
        glVertex2f(-0.679,0.1175);
        glVertex2f(-1,-0.145);
    }

        glEnd();

    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(-1.001,-0.22);
        glVertex2f(-0.68,0.029);
        glVertex2f(-0.681,-0.077);
        glVertex2f(-1.0012,-0.33);
    }

        glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.212,0.573);
        glVertex2f(0,0.749);
        glVertex2f(0,0.427);
        glVertex2f(-0.214,0.236);
    }
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.21,0.573);
        glVertex2f(-0.267,0.711);
        glVertex2f(-0.07,0.87);
        glVertex2f(0,0.75);
    }

        glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.268,0.708);
        glVertex2f(-0.276,0.18);
        glVertex2f(-0.214,0.236);
        glVertex2f(-0.21,0.573);
    }

        glEnd();

    //Board Pole
    glColor3f(0.95, 0.95, 0.95);
    glLineWidth(15.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.78,-0.22);
        glVertex2f(-0.78,0.685);
    glEnd();

     //2nd Building
     //front
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0,0.748);
        glVertex2f(0.185,0.898);
        glVertex2f(0.186,0.597);
        glVertex2f(-0.002,0.426);
    }

        glEnd();

    //roof
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
    {
        glVertex2f(-0.069,0.87);
        glVertex2f(0.093,1);
        glVertex2f(0.185,0.897);
        glVertex2f(-0.001,0.748);
    }

        glEnd();

        //windows
    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.024,0.7186);
        glVertex2f(0.0596,0.748);
        glVertex2f(0.059,0.6867);
        glVertex2f(0.0236,0.6574);
    }

        glEnd();

    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.1155,0.789);
        glVertex2f(0.1504,0.818);
        glVertex2f(0.1504,0.763);
        glVertex2f(0.1156,0.733);
    }

        glEnd();

     //middle border
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    {
        glVertex2f(0,0.58);
        glVertex2f(0.185,0.738);
        glVertex2f(0.1866,0.715);
        glVertex2f(0.001,0.557);
    }

        glEnd();
        //windows
    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.053,0.57);
        glVertex2f(0.0534,0.5108);
        glVertex2f(0.0215,0.4822);
        glVertex2f(0.0212,0.5406);
    }

        glEnd();

    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.1502,0.651);
        glVertex2f(0.15,0.597);
        glVertex2f(0.12,0.571);
        glVertex2f(0.1206,0.622);
    }

        glEnd();
    //3rd building
    glColor3f(1.0, 0.75, 0.8);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.185,0.897);
        glVertex2f(0.326,1.003);
        glVertex2f(0.328,0.729);
        glVertex2f(0.187,0.604);
    }

        glEnd();

        //roof
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.092,1);
        glVertex2f(0.3253,1.001);
        glVertex2f(0.185,0.897);
        glVertex2f(0.0937,1);
    }

        glEnd();
     //window
    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.239,0.8853);
        glVertex2f(0.2392,0.834);
        glVertex2f(0.2113,0.811);
        glVertex2f(0.211,0.8603);
    }

        glEnd();

    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.3006,0.9324);
        glVertex2f(0.3007,0.8774);
        glVertex2f(0.2732,0.8545);
        glVertex2f(0.273,0.907);
    }

        glEnd();
     //middle border
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.1857,0.739);
        glVertex2f(0.327,0.852);
        glVertex2f(0.328,0.833);
        glVertex2f(0.187,0.7144);
    }

        glEnd();
    //window
    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.234,0.719);
        glVertex2f(0.2343,0.6805);
        glVertex2f(0.211,0.66);
        glVertex2f(0.2106,0.6977);
    }

        glEnd();

    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.2979,0.7687);
        glVertex2f(0.2976,0.7305);
        glVertex2f(0.274,0.7107);
        glVertex2f(0.274,0.748);
    }

        glEnd();
    //4th building
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.326,1.001);
        glVertex2f(0.49,1.001);
        glVertex2f(0.489,0.871);
        glVertex2f(0.328,0.728);
    }

        glEnd();
    //window
    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.376,0.9878);
        glVertex2f(0.3762,0.942);
        glVertex2f(0.3507,0.916);
        glVertex2f(0.3504,0.9637);
    }

        glEnd();
    //middle border
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.3274,0.852);
        glVertex2f(0.489,0.9725);
        glVertex2f(0.4897,0.961);
        glVertex2f(0.3283,0.8336);
    }

        glEnd();
    //window
    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.3813,0.844);
        glVertex2f(0.3808,0.8014);
        glVertex2f(0.35,0.7754);
        glVertex2f(0.3503,0.8165);
    }

        glEnd();
    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.4586,0.914);
        glVertex2f(0.4587,0.878);
        glVertex2f(0.4297,0.853);
        glVertex2f(0.4303,0.8897);
    }

        glEnd();
    //5th building
    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.4902,1.0013);
        glVertex2f(0.6313,0.9995);
        glVertex2f(0.49,0.87);
        glVertex2f(0.49,1.001);
    }

        glEnd();
    //middle border
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.4896,0.9725);
        glVertex2f(0.5321,1.0016);
        glVertex2f(0.5412,1.0008);
        glVertex2f(0.4898,0.9608);
    }

        glEnd();
    //window
    glColor3f(0.5, 0.8, 0.9);

    glBegin(GL_QUADS);
    {
        glVertex2f(0.5403,0.9763);
        glVertex2f(0.5404,0.9417);
        glVertex2f(0.5196,0.924);
        glVertex2f(0.52,0.959);
    }

        glEnd();

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_QUADS);
    {
        glVertex2f(-0.394,0.858);
        glVertex2f(-0.217,1.004);
        glVertex2f(-0.154,0.865);
        glVertex2f(-0.33,0.73);
    }

        glEnd();

    glColor3f(0.0, 0.0, 0.5);

    glBegin(GL_QUADS);
    {
        glVertex2f(-0.3945,0.86);
        glVertex2f(-0.396,0.429);
        glVertex2f(-0.324,0.195);
        glVertex2f(-0.33,0.73);
    }

        glEnd();


    //Road

    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.308,0.178);
        glVertex2f(0.63,1);
        glVertex2f(0.675,1);
        glVertex2f(-0.323,0.114);
    }
    glEnd();


    glBegin(GL_QUADS);
    {
        glVertex2f(-0.308,0.178);
        glVertex2f(-0.433,0.576);
        glVertex2f(-0.453,0.52);
        glVertex2f(-0.323,0.114);
    }
    glEnd();

    glBegin(GL_QUADS);
    {
        glVertex2f(-1.0,-0.396);
        glVertex2f(-0.617,-0.074);
        glVertex2f(-0.583,-0.09);
        glVertex2f(-1.0,-0.493);
    }
    glEnd();


    glBegin(GL_QUADS);
    {
        glVertex2f(-0.617,-0.074);
        glVertex2f(-0.613,0.483);
        glVertex2f(-0.588,0.48);
        glVertex2f(-0.583,-0.09);
    }
    glEnd();


    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.319,0.115);
        glVertex2f(0.675,1);
        glVertex2f(0.699,1);
        glVertex2f(-0.314,0.074);
    }
    glEnd();

    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.577,-1.0);
        glVertex2f(0.767,1.0);
        glVertex2f(0.797,1.0);
        glVertex2f(-0.467,-1.0);
    }
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.328,-0.988);
        glVertex2f(0.977,1.0);
        glVertex2f(1.0,1.0);
        glVertex2f(0.39,-1.0);
    }
    glEnd();

    glColor3f(0.7,0.7,0.7);
     glBegin(GL_QUADS);
    {
        glVertex2f(-0.467,-0.994);
        glVertex2f(0.797,1.0);
        glVertex2f(0.843,1.0);
        glVertex2f(-0.385,-1.0);
    }
    glEnd();


    //Board
    glColor3f(0,0.8,0.5);
    glBegin(GL_QUADS);
    {
        glVertex2f(-0.71,0.65);
        glVertex2f(-0.471,0.64);
        glVertex2f(-0.471,0.36);
        glVertex2f(-0.722,0.37);
    }
    glEnd();

    glBegin(GL_QUADS);
    {
        glVertex2f(-0.443,0.7);
        glVertex2f(-0.01,0.685);
        glVertex2f(-0.01,0.275);
        glVertex2f(-0.448,0.29);
    }
    glEnd();

    glColor3f(1,1,1);
    renderBitmapString(-0.65, 0.5, 0.0, GLUT_BITMAP_HELVETICA_18, "Banani");
    renderBitmapString(-0.25, 0.5, 0.0, GLUT_BITMAP_HELVETICA_18, "Kuril");

    LightPole();




    //car
    glPushMatrix();
    glTranslated(carx,cary,0);

    glScaled(0.7,0.7,0);
    glColor3f(0.5,0,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.213,-0.24);
        glVertex2f(0.41,-0.32);
        glVertex2f(0.454,-0.21);
        glVertex2f(0.25,-0.13);
    }
    glEnd();


    glColor3f(0.53,0.808,0.923);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.25,-0.13);
        glVertex2f(0.454,-0.21);
        glVertex2f(0.464,-0.077);
        glVertex2f(0.336,-0.03);
    }
    glEnd();

    glColor3f(0.5,0,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.464,-0.077);
        glVertex2f(0.336,-0.033);
        glVertex2f(0.436,0.133);
        glVertex2f(0.508,0.093);
    }
    glEnd();

    glColor3f(0.5,0,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.436,0.133);
        glVertex2f(0.508,0.093);
        glVertex2f(0.6,0.195);
        glVertex2f(0.479,0.286);
    }
    glEnd();

    glColor3f(0.4,0,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.6,0.195);
        glVertex2f(0.455,-0.21);
        glVertex2f(0.465,-0.077);
        glVertex2f(0.507,0.097);
    }
    glEnd();

    glBegin(GL_QUADS);
    {
        glVertex2f(0.479,0.286);
        glVertex2f(0.25,-0.13);
        glVertex2f(0.336,-0.03);
        glVertex2f(0.436,0.133);
    }
    glEnd();

    glColor3f(0.8,0.8,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.255,-0.177);
        glVertex2f(0.314,-0.2);
        glVertex2f(0.31,-0.238);
        glVertex2f(0.232,-0.207);
    }
    glEnd();





    glPushMatrix();
    glTranslated(0.097,-0.04,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(0.255,-0.177);
        glVertex2f(0.314,-0.2);
        glVertex2f(0.31,-0.238);
        glVertex2f(0.232,-0.207);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();


}

// Display function
void display() {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glLoadIdentity(); // Reset transformations

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    switch (sceneIndex) {
        case 0:
            glClearColor(0.388f, 0.169f, 0.424f, 1.0f);
            renderScene1();
            break;
        case 1:
            glClearColor(0.529, 0.808, 0.922, 1.0);
            renderScene2();
            //glutTimerFunc(1000, update, 0);
            break;
        case 2:
            glClearColor(0.361, 0.263, 0.153, 1.0);
            renderScene3();
            //glutTimerFunc(1000, TrainUpdate, 0);
            break;
        case 3:
            glClearColor(0.8,0.8,0.8, 1.0);
            renderScene4();
            //glutTimerFunc(1000, CarUpdate, 0);
            break;
    }
    glutSwapBuffers();
}

void unifiedUpdate(int value) {

    if(sceneIndex == 1)
    {
    carPosition += 0.01f; // Move car to the right
    if (carPosition > 0.7f) carPosition = -0.7f; // Reset car

    cloudPosition += cloudspeed; // Move cloud to the right
    if (cloudPosition > 1.2f) cloudPosition = -1.2f; // Reset cloud

    planeX += planespeedX; // Plane moves diagonally
    planeY += planespeedY;
    if (planeX > 1.2f) {
        planeX = -1.2f; // Reset plane position
        planeY = 0.5f;
    }
    carRotation += carspeed;  // Increment rotation angle (degrees)
    if (carRotation >= 210.0f) {
        carRotation -= 200.0f;  // Keep angle within 0-360 range
    }
    }

    if(sceneIndex == 2)
    {

        TrainStartX += TrainSpeedX;
    TrainStartY -= TrainSpeedY;


    if (TrainStartX > 2.0f || TrainStartY<-2.0f) {
        TrainStartX = -1.8f;
        TrainStartY = 1.2f;
    }

    cloudPosition += cloudspeed; // Move cloud to the right
    if (cloudPosition > 1.2f) cloudPosition = -1.2f; // Reset cloud

    }

    if(sceneIndex == 3)
    {


            carx -= carspeedx;
            cary -= carspeedy;


        if (carx > 1.5f || cary<-1.5f) {
        carx = 0.73f;
        cary = 1.25f;
    }
    }

    glutPostRedisplay();
    glutTimerFunc(16, unifiedUpdate, 0); // Maintain a consistent 60 FPS.
}

// Timer function to switch scenes
void timer(int value) {
    sceneIndex = (sceneIndex + 1) % 4; // Cycle through scenes
    glutPostRedisplay();              // Request a redraw
    glutTimerFunc(5000, timer, 0);    // Set timer for 5 seconds
}

// Initialization function
void init() {
    glClearColor(0.388f, 0.169f, 0.424f, 1.0f);
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            if(sceneIndex == 1)
            {
            planespeedX = planespeedX + 0.01f;
            planespeedY = planespeedY + 0.005f;
            }

            if(sceneIndex == 2)
            {
            state = false;
            }

            if(sceneIndex == 3)
            {
                carspeedx = carspeedx + 0.01;
                carspeedy =carspeedy + 0.02;
            }
            break;

        case GLUT_KEY_DOWN:
            if(sceneIndex == 1)
            {
            planespeedX =planespeedX - 0.01f;
            planespeedY = planespeedY - 0.005f;
            }

            if(sceneIndex == 2)
            {
            state = true;
            }

            if(sceneIndex == 3)
            {
                carspeedx = carspeedx - 0.01;
                carspeedy =carspeedy - 0.02;
            }
            break;

        case GLUT_KEY_LEFT:
            if(sceneIndex == 1)
            {
            cloudspeed = cloudspeed - 0.005;
            }

            if(sceneIndex == 2)
            {
            cloudspeed = cloudspeed-0.005;
            }
            break;


        case GLUT_KEY_RIGHT:

            if(sceneIndex == 1)
            {
            cloudspeed = cloudspeed + 0.005;
            }

            if(sceneIndex == 2)
            {
            cloudspeed = cloudspeed+0.005;
            }
            break;
    }
    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
	    if(sceneIndex == 1)
            {
		carspeed = carspeed+1.0f;
            }

        if(sceneIndex == 2)
        {
        TrainSpeedX = TrainSpeedX + 0.015f;
         TrainSpeedY = TrainSpeedY + 0.01f;
        }

        if(sceneIndex == 3)
        {
            carspeedx = carspeedx + 0.01;
        carspeedy =carspeedy + 0.02;
        }
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
        if(sceneIndex == 1)
            {
		carspeed = carspeed-1.0f;
            }

        if(sceneIndex == 2)
        {
            TrainSpeedX = TrainSpeedX - 0.015f;
            TrainSpeedY = TrainSpeedY - 0.01f;
        }

        if(sceneIndex == 3)
        {
            carspeedx = carspeedx - 0.01;
        carspeedy =carspeedy - 0.02;
        }
	}
	glutPostRedisplay();
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("urban Landscapes of Dhaka");

    init();

    glutDisplayFunc(display);
    sound();

    glutTimerFunc(5000, timer, 0); // Start timer
    glutTimerFunc(5000, unifiedUpdate, 0); // Start timer
    glutSpecialFunc(SpecialInput);
    glutMouseFunc(handleMouse);
    glutMainLoop();

    return 0;
}
