#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <iostream>
#include <ctime>
#include <cmath>

GLfloat positiontree = 2.0f;
GLfloat speedtree = 0.029f;
/// Score
int score = 0,s;
///Distance
float distancee = 0.0f,d;
float moveAmount = 0.001f; // Initial amount of movement in each step
bool moveLeft = false; //   indicate whether the car is moving left
bool moveRight = false; //   indicate whether the car is moving right
//mid point of the car=(-0.00014, -0.28558).
float main_car_x = -0.00014f; // Initial x position
float main_car_y = -0.8; // Initial y position
float position1_x =0.2f;
float position1 = 0.0f;
float position2 = 1.20f;
float position3 = 1.50f;
float position4 = 1.90f;
float position1_x_1 =-0.425f;
float position1_x_2 =0.425f;

float H1=0.2f;

int lives = 3;
float B1=0.2f;
float B2=1.2f;
bool collisionOccurred = false;
time_t collisionStartTime;

float distance(float x1, float y1, float x2, float y2)
{

    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

}

void increaseLife()
{
    lives+=1; // Increase life
}

bool checkCollision()
{

    float collisionThreshold = 0.14f;

    // Check for collision with other car

    if (distance(position1_x, position1, main_car_x, main_car_y) < collisionThreshold ||
            distance(position1_x_1, position2, main_car_x, main_car_y) < collisionThreshold ||
            distance(position1_x_2, position3, main_car_x, main_car_y) < collisionThreshold ||
            distance(B1, B2, main_car_x, main_car_y) < collisionThreshold

       )

    {

        if (!collisionOccurred)
        {

            collisionOccurred = true;
            collisionStartTime = time(NULL);
        }

        return true; // Collision detected with other objects
    }

    // Check for collision with Live object

    if (distance(H1, position4, main_car_x, main_car_y) < collisionThreshold)

    {
        increaseLife(); // Increase life if collision with Live object

        return true; // Collision detected with Live object
    }

/// to make the car invisible

    if (distance(position1_x, position1, main_car_x, main_car_y) < collisionThreshold ||

            distance(position1_x_1, position2, main_car_x, main_car_y) < collisionThreshold ||
            distance(position1_x_2, position3, main_car_x, main_car_y) < collisionThreshold ||
            distance(B1, B2, main_car_x, main_car_y) < collisionThreshold)

    {

        if (!collisionOccurred)
        {
            collisionOccurred = false;
            collisionStartTime = time(NULL);
        }

        return true; // Collision detected with other objects

    }

    // Handle collision duration and life deduction

    if (collisionOccurred)

    {
        lives--;

        collisionOccurred = false;
    }

    return false; // No collision detected

}


///reduce heart

void drawHearts()
{

    int maxHearts = 5; // Maximum number of hearts to display

    // Ensure lives doesn't exceed the maximum hearts
    if (lives > maxHearts) {
        lives = maxHearts;
    }
    for (int i = 0; i < lives ; i++) {
    glPushMatrix();
    glTranslatef(-0.94f + i * 0.05f, 0.71f, 0.0f); // Adjust heart positions
        glColor3f(1.0f, 0.0f, 0.0f); // Red color for filling
        glScalef(0.07,0.07,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0.5);   //1
        glVertex2f(0.1248, 0.5541);   //2
        glVertex2f(0.2434, 0.5333); //3
        glVertex2f(0.3162, 0.4397);     //4
        glVertex2f(0.3162, 0.3273);    //5
        glVertex2f(0.2704, 0.2296);   //6
        glVertex2f(0.1914, 0.1318);//o
        glVertex2f(0.1144, 0.0444);//o
        glVertex2f(0, -0.0388);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0,0.5);   //1
        glVertex2f(-0.1248, 0.5541);   //2
        glVertex2f(-0.2434, 0.5333); //3
        glVertex2f(-0.3162, 0.4397);     //4
        glVertex2f(-0.3162, 0.3273);    //5
        glVertex2f(-0.2704, 0.2296);   //6
        glVertex2f(-0.1914, 0.1318);//o
        glVertex2f(-0.1144, 0.0444);//o
        glVertex2f(0, -0.0388);
        glEnd();
        glPopMatrix();

    }

}

///main car movement
void Main_car()
{

    glPushMatrix(); // Save current matrix

    glTranslatef(main_car_x, main_car_y, 0.0f); // Apply translation to the car

    //down body
    glScalef(.6,1.3,0);
    glBegin(GL_POLYGON);
    glColor3f(0.130f, 0.170f, 0.620f);

    glVertex2f(0.08f,0.10f);
    glVertex2f(0.09f,0.09f);
    glVertex2f(0.25f,0.09f);
    glVertex2f(0.26f,0.10f);
    glVertex2f(0.25f,0.08f);
    glVertex2f(0.09f,0.08f);
    glEnd();
    //mid body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f,0.10f);
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.25f,0.45f);
    glVertex2f(0.09f,0.45f);
    glVertex2f(0.08f,0.44f);
    glVertex2f(0.08f,0.10f);
    glVertex2f(0.09f,0.09f);
    glVertex2f(0.25f,0.09f);
    glEnd();
    //uper body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.25f,0.45f);
    glVertex2f(0.09f,0.45f);
    glVertex2f(0.08f,0.44f);
    glVertex2f(0.09f,0.46f);
    glVertex2f(0.25f,0.46f);
    glEnd();
    //windows
    glBegin(GL_POLYGON);
    //1 back
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.11f,0.14f);
    glVertex2f(0.23f,0.14f);
    glVertex2f(0.24f,0.12f);
    glVertex2f(0.22f,0.11f);
    glVertex2f(0.123f,0.11f);
    glVertex2f(0.10f,0.12f);
    glEnd();

    glBegin(GL_POLYGON);
    //2 back right small
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.25f,0.14f);
    glVertex2f(0.25f,0.19f);
    glVertex2f(0.23f,0.19f);
    glVertex2f(0.23f,0.16f);

    glEnd();
    glBegin(GL_POLYGON);
//3 back left small
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.09f,0.14f);
    glVertex2f(0.09f,0.19f);
    glVertex2f(0.11f,0.19f);
    glVertex2f(0.11f,0.16f);

    glEnd();

    glEnd();
    glBegin(GL_POLYGON);
//4 back left big
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.09f,0.21f);
    glVertex2f(0.09f,0.33f);
    glVertex2f(0.11f,0.29f);
    glVertex2f(0.11f,0.21f);

    glEnd();

    glBegin(GL_POLYGON);
//4 back Right big
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.25f,0.21f);
    glVertex2f(0.25f,0.33f);
    glVertex2f(0.23f,0.29f);
    glVertex2f(0.23f,0.21f);
    glEnd();

    glBegin(GL_POLYGON);
//5 Fornt
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.23f,0.33f);
    glVertex2f(0.11f,0.33f);
    glVertex2f(0.10f,0.34f);
    glVertex2f(0.09f,0.38f);
    glVertex2f(0.25f,0.38f);
    glVertex2f(0.24f,0.34f);
    glEnd();

    glBegin(GL_POLYGON);
//6  Right light
    glColor3f (1.0f, 1.0f,1.0f);
    glVertex2f(0.23f,0.43f);
    glVertex2f(0.25f,0.43f);
    glVertex2f(0.23f,0.45f);

    glEnd();

    glBegin(GL_POLYGON);
//7 left light
    glColor3f (1.0f, 1.0f,1.0f);
    glVertex2f(0.12f,0.43f);
    glVertex2f(0.10f,0.43f);
    glVertex2f(0.12f,0.45f);
    glEnd();
    glPopMatrix();
    glLoadIdentity();

}


///control function

GLfloat position = 0.0f;

GLfloat speed = 0.1f;

GLfloat speed1 = 0.05f;

GLfloat speed2 = 0.05f;

GLfloat speed3 = 0.05f;

GLfloat speed4 = 0.05f;
///My car movement
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            speedtree += 0.005f; // increase car speed
            break;
        case GLUT_KEY_DOWN:
            speedtree -= 0.005f; // decrease car speed
            break;
        case GLUT_KEY_LEFT:
            if (main_car_x > -0.4f) // limit car movement left to -0.4
                main_car_x -= 0.1f; // move the car left
            break;
        case GLUT_KEY_RIGHT:
            if (main_car_x < 0.1f) // limit car movement right to +0.2
                main_car_x += 0.1f; // move the car right
            break;
                }

    glutPostRedisplay(); // redraw the scene
}


///

void update(int value)
{
    if(positiontree <-1.0)
        positiontree = 1.0f;
    positiontree -= speedtree;

    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
}

///enviroment

void env()

{

    glClearColor(0.2f, 0.8f, 0.2f, 1.0f); // Set background color to a shade of green

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    //glLoadIdentity(); // Reset the transformation matrix

     glPushMatrix();
    //road side color
    glBegin(GL_POLYGON);
    glColor3f(0.82f, 0.98f, 0.82f);
    glVertex2f(1.0f,1.0f);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glEnd();
    glPopMatrix();

   //road
   //Red part road boarder
    glScalef(.8,1,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.55f,1.0f);
    glVertex2f(-0.55f,1.0f);
    glVertex2f(-0.55f,-1.0f);
    glVertex2f(0.55f,-1.0f);
    glEnd();
    glLoadIdentity();

    //white part road boarder
    glScalef(.8,1,0);
    glTranslatef(+0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();
    glLoadIdentity();


    ///Translation black
    //glTranslatef(0.0f,position, 0.0f);
    //black part
    glScalef(.8,1,0);
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.5f,1.0f);
    glVertex2f(-0.5f,1.0f);
    glVertex2f(-0.5f,-1.0f);
    glVertex2f(0.5f,-1.0f);
    glEnd();
    glLoadIdentity();

    //inside left side traffic border
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.19f,1.0f);
    glVertex2f(-0.195f,1.0f);
    glVertex2f(-0.195f,-1.0f);
    glVertex2f(-0.19f,-1.0f);
    glEnd();

    //inside right side traffic border
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.19f,1.0f);
    glVertex2f(0.195f,1.0f);
    glVertex2f(0.195f,-1.0f);
    glVertex2f(0.19f,-1.0f);
    glEnd();

    //inside middle traffic border
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.005f,1.0f);
    glVertex2f(0.0f,1.0f);
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.005f,-1.0f);
    glEnd();



    glLoadIdentity();

    glFlush();

}


void Tree(float x, float y,float z)

{

    glTranslatef(x, y,z);

    //1.TREE(1st crishmas tree 1)
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0.18f,0.85f,0.15f);
    glVertex2f(-.7f,-0.02f);
    glVertex2f(-.74f,-0.06f);
    glVertex2f(-.66f,-0.06f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.18f,0.85f,0.15f);
    glVertex2f(-.7f,-0.04f);
    glVertex2f(-.76f,-0.10f);
    glVertex2f(-.64f,-0.10f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.18f,0.85f,0.15f);
    glVertex2f(-.7f,-0.07f);
    glVertex2f(-.78f,-0.14f);
    glVertex2f(-.62f,-0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.04f,.62f,.23f);
    glVertex2f(-.71f,-0.12f);
    glVertex2f(-.71f,-0.20f);
    glVertex2f(-.69f,-0.20f);
    glVertex2f(-.69f,-0.12f);
    glEnd();
    glPopMatrix();
    //tree 1 end

    //1st tree(Crishmas tree 2)
    glPushMatrix();
    glTranslatef(-0.0f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.18f,0.85f,0.15f);
    glVertex2f(-.7f,-0.02f);
    glVertex2f(-.74f,-0.06f);
    glVertex2f(-.66f,-0.06f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.18f,0.85f,0.15f);
    glVertex2f(-.7f,-0.04f);
    glVertex2f(-.76f,-0.10f);
    glVertex2f(-.64f,-0.10f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.18f,0.85f,0.15f);
    glVertex2f(-.7f,-0.07f);
    glVertex2f(-.78f,-0.14f);
    glVertex2f(-.62f,-0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.04f,.62f,.23f);
    glVertex2f(-.71f,-0.12f);
    glVertex2f(-.71f,-0.20f);
    glVertex2f(-.69f,-0.20f);
    glVertex2f(-.69f,-0.12f);
    glEnd();
    glLoadIdentity();
    glPopMatrix();
    //1.tree 2 end

}

void Tree1(float x, float y,float z)

{

    glTranslatef(x, y,z);

    //2nd tree(Botgas type1)
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.18f,0.85f,0.15f);
    glVertex2f(-.74f,-0.70f);//1
    glVertex2f(-.72f,-0.72f);//2
    glVertex2f(-0.68f,-.68f);//3
    glVertex2f(-0.70f,-.66f);//4
    glVertex2f(-0.68f,-.64f);//5
    glVertex2f(-0.74f,-.58f);//6
    glVertex2f(-0.82f,-.60f);//7
    glVertex2f(-0.84f,-.64f);//8
    glVertex2f(-0.82f,-.66f);//9
    glVertex2f(-0.84f,-.68f);//10
    glVertex2f(-0.80f,-.72f);//11
    glVertex2f(-0.78f,-.70f);//12
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.04f,.62f,.23f);
    glVertex2f(-.74f,-0.80f);//1
    glVertex2f(-.78f,-0.72f);//2
    glVertex2f(-0.74f,-.68f);//3
    glVertex2f(-0.76f,-.70f);//4
    glVertex2f(-0.80f,-.68f);//5
    glVertex2f(-0.78f,-.72f);//6
    glVertex2f(-0.78f,-.80f);//7
    glEnd();
    glPopMatrix();
    //tree 1 end
    //tree end(botgas 2)

    ///2nd tee
    glPushMatrix();
    glTranslatef(-0.0f,0.9f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.18f,0.85f,0.15f);
    glVertex2f(-.74f,-0.70f);//1
    glVertex2f(-.72f,-0.72f);//2
    glVertex2f(-0.68f,-.68f);//3
    glVertex2f(-0.70f,-.66f);//4
    glVertex2f(-0.68f,-.64f);//5
    glVertex2f(-0.74f,-.58f);//6
    glVertex2f(-0.82f,-.60f);//7
    glVertex2f(-0.84f,-.64f);//8
    glVertex2f(-0.82f,-.66f);//9
    glVertex2f(-0.84f,-.68f);//10
    glVertex2f(-0.80f,-.72f);//11
    glVertex2f(-0.78f,-.70f);//12
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.04f,.62f,.23f);
    glVertex2f(-.74f,-0.80f);//1
    glVertex2f(-.78f,-0.72f);//2
    glVertex2f(-0.74f,-.68f);//3
    glVertex2f(-0.76f,-.70f);//4
    glVertex2f(-0.80f,-.68f);//5
    glVertex2f(-0.78f,-.72f);//6
    glVertex2f(-0.78f,-.80f);//7
    glEnd();
    glLoadIdentity();
    glPopMatrix();
    //tree end

}

void Home(float x, float y,float z)

{

    glTranslatef(x, y,z);

    //// Building

    //1ST HOUSE
    //1st
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.501f,0.0f,.0f);
    glVertex2f(-.9f,-0.32f);
    glVertex2f(-.88f,-0.38f);
    glVertex2f(-.78f,-.38f);
    glVertex2f(-.82f,-.32f);
    glEnd();


    glBegin(GL_QUADS);//2nd with door
    glColor3f(0.556f,0.737f,.556f);
    glVertex2f(-.8f,-.46f);
    glVertex2f(-.88f,-0.46f);
    glVertex2f(-.88f,-.38f);
    glVertex2f(-.8f,-.38f);
    glEnd();


    glBegin(GL_POLYGON);//3rd with window
    glColor3f(0.180f,0.542f,.341f);
    glVertex2f(-.88f,-0.38f);
    glVertex2f(-.94f,-.38f);
    glVertex2f(-.94f,-.46f);
    glVertex2f(-.88f,-.48f);
    glEnd();


    glBegin(GL_QUADS);//4 th
    glColor3f(0.501f,0.0f,.0f);
    glVertex2f(-.92f,-0.32f);
    glVertex2f(-.96f,-.38f);
    glVertex2f(-.94f,-.38f);
    glVertex2f(-.9f,-.32f);
    glEnd();


    glBegin(GL_QUADS);//5 th
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-.88f,-0.48f);
    glVertex2f(-.8f,-.48f);
    glVertex2f(-.8f,-.46f);
    glVertex2f(-.88f,-.46f);
    glEnd();


    glBegin(GL_QUADS); //6th
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-.94f,-0.44f);
    glVertex2f(-.94f,-.46f);
    glVertex2f(-.88f,-.48f);
    glVertex2f(-.88f,-.46f);
    glEnd();

    glBegin(GL_QUADS);//DOOR
    glColor3f(1.f,1.f,1.f);
    glVertex2f(-.845f,-0.41f);
    glVertex2f(-.845f,-.46f);
    glVertex2f(-.825f,-.46f);
    glVertex2f(-.825f,-.41f);
    glEnd();


    glBegin(GL_QUADS);//window
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-.9f,-0.4f);
    glVertex2f(-.92f,-.4f);
    glVertex2f(-.92f,-.42f);
    glVertex2f(-.9f,-.42f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.180f,0.542f,.341f);
    glVertex2f(-.88f,-0.38f);
    glVertex2f(-.94f,-.38f);
    glVertex2f(-.9f,-.32f);

    glEnd();
	glPopMatrix();
    //1ST HOUSE END


}

void Home1(float x, float y,float z)

{
    glTranslatef(x, y,z);
	//2ST HOUSE
    //1st
    glBegin(GL_QUADS);
    glColor3f(0.09f,0.09f,.443f);
    glVertex2f(-.6f,-0.3f);
    glVertex2f(-.7f,-0.31f);
    glVertex2f(-.74f,-.36f);
    glVertex2f(-.64f,-.36f);
    glEnd();


    glBegin(GL_QUADS);//2Nd with DOOR
    glColor3f(0.274f,0.509f,.705f);
    glVertex2f(-.72f,-0.36f);
    glVertex2f(-.72f,-.44f);
    glVertex2f(-.64f,-.44f);
    glVertex2f(-.64f,-.36f);
    glEnd();


    glBegin(GL_QUADS);//3RD WITH DOOR
    glColor3f(0.368f,0.619f,0.627f);
    glVertex2f(-.64f,-0.36f);
    glVertex2f(-.56f,-.36f);
    glVertex2f(-.56f,-.44f);
    glVertex2f(-.64f,-.44f);
    glEnd();


    glBegin(GL_QUADS);//4 th
    glColor3f(.0f,0.0f,.0f);
    glVertex2f(-.64f,-0.44f);
    glVertex2f(-.64f,-.46f);
    glVertex2f(-.735f,-.46f);
    glVertex2f(-.735f,-.44f);
    glEnd();


    glBegin(GL_QUADS); //5th
    glColor3f(.0f,0.0f,.0f);
    glVertex2f(-.64f,-0.44f);
    glVertex2f(-.64f,-0.46f);
    glVertex2f(-.56f,-.46f);
    glVertex2f(-.56f,-.44f);
    glEnd();

    glBegin(GL_QUADS);//DOOR
    glColor3f(0.156f,0.145f,.04f);
    glVertex2f(-.59f,-0.39f);
    glVertex2f(-.59f,-.44f);
    glVertex2f(-.61f,-.44f);
    glVertex2f(-.61f,-.39f);
    glEnd();


    glBegin(GL_QUADS);//DOOR
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-.67f,-0.39f);
    glVertex2f(-.69f,-.39f);
    glVertex2f(-.69f,-.44f);
    glVertex2f(-.67f,-.44f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-.56f,-0.36f);
    glVertex2f(-.6f,-.3f);
    glVertex2f(-.64f,-.36f);

    glEnd();
    glLoadIdentity();

    //2nd HOUSE END
}


/// car 1

void car1(int a)

{

    //down body
    glPushMatrix();
    glScalef(.6,1.3,0);
    glTranslatef(position1_x,position1, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.9f,0.42f);
    glVertex2f(0.08f,0.10f);
    glVertex2f(0.09f,0.09f);
    glVertex2f(0.25f,0.09f);
    glVertex2f(0.26f,0.10f);
    glVertex2f(0.25f,0.08f);
    glVertex2f(0.09f,0.08f);
    glEnd();
//mid body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f,0.10f);
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.25f,0.45f);
    glVertex2f(0.09f,0.45f);
    glVertex2f(0.08f,0.44f);
    glVertex2f(0.08f,0.10f);
    glVertex2f(0.09f,0.09f);
    glVertex2f(0.25f,0.09f);
    glEnd();
//uper body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.25f,0.45f);
    glVertex2f(0.09f,0.45f);
    glVertex2f(0.08f,0.44f);
    glVertex2f(0.09f,0.46f);
    glVertex2f(0.25f,0.46f);
    glEnd();
//windows
    glBegin(GL_POLYGON);
//1 back
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.11f,0.14f);
    glVertex2f(0.23f,0.14f);
    glVertex2f(0.24f,0.12f);
    glVertex2f(0.22f,0.11f);
    glVertex2f(0.123f,0.11f);
    glVertex2f(0.10f,0.12f);
    glEnd();

    glBegin(GL_POLYGON);
//2 back right small
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.25f,0.14f);
    glVertex2f(0.25f,0.19f);
    glVertex2f(0.23f,0.19f);
    glVertex2f(0.23f,0.16f);

    glEnd();
    glBegin(GL_POLYGON);
//3 back left small
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.09f,0.14f);
    glVertex2f(0.09f,0.19f);
    glVertex2f(0.11f,0.19f);
    glVertex2f(0.11f,0.16f);

    glEnd();

    glEnd();
    glBegin(GL_POLYGON);
//4 back left big
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.09f,0.21f);
    glVertex2f(0.09f,0.33f);
    glVertex2f(0.11f,0.29f);
    glVertex2f(0.11f,0.21f);

    glEnd();

    glBegin(GL_POLYGON);
//4 back Right big
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.25f,0.21f);
    glVertex2f(0.25f,0.33f);
    glVertex2f(0.23f,0.29f);
    glVertex2f(0.23f,0.21f);
    glEnd();

    glBegin(GL_POLYGON);
//5 Fornt
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.23f,0.33f);
    glVertex2f(0.11f,0.33f);
    glVertex2f(0.10f,0.34f);
    glVertex2f(0.09f,0.38f);
    glVertex2f(0.25f,0.38f);
    glVertex2f(0.24f,0.34f);
    glEnd();

    glBegin(GL_POLYGON);
//6  Right light
    glColor3f (1.0f, 1.0f,1.0f);
    glVertex2f(0.23f,0.43f);
    glVertex2f(0.25f,0.43f);
    glVertex2f(0.23f,0.45f);

    glEnd();

    glBegin(GL_POLYGON);
//7 left light
    glColor3f (1.0f, 1.0f,1.0f);
    glVertex2f(0.12f,0.43f);
    glVertex2f(0.10f,0.43f);
    glVertex2f(0.12f,0.45f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers(); // Swap front and back buffers

}

/// car 2

void car2(int c)

{

    //down body
    glPushMatrix();
    glScalef(0.6,1.3,0);
    glTranslatef(position1_x_1,position2, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.92f,0.14f,0.260f);

    glVertex2f(0.08f,0.10f);
    glVertex2f(0.09f,0.09f);
    glVertex2f(0.25f,0.09f);
    glVertex2f(0.26f,0.10f);
    glVertex2f(0.25f,0.08f);
    glVertex2f(0.09f,0.08f);
    glEnd();
//mid body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f,0.10f);
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.25f,0.45f);
    glVertex2f(0.09f,0.45f);
    glVertex2f(0.08f,0.44f);
    glVertex2f(0.08f,0.10f);
    glVertex2f(0.09f,0.09f);
    glVertex2f(0.25f,0.09f);
    glEnd();
//uper body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.25f,0.45f);
    glVertex2f(0.09f,0.45f);
    glVertex2f(0.08f,0.44f);
    glVertex2f(0.09f,0.46f);
    glVertex2f(0.25f,0.46f);
    glEnd();
//windows
    glBegin(GL_POLYGON);
//1 back
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.11f,0.14f);
    glVertex2f(0.23f,0.14f);
    glVertex2f(0.24f,0.12f);
    glVertex2f(0.22f,0.11f);
    glVertex2f(0.123f,0.11f);
    glVertex2f(0.10f,0.12f);
    glEnd();

    glBegin(GL_POLYGON);
//2 back right small
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.25f,0.14f);
    glVertex2f(0.25f,0.19f);
    glVertex2f(0.23f,0.19f);
    glVertex2f(0.23f,0.16f);

    glEnd();
    glBegin(GL_POLYGON);
//3 back left small
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.09f,0.14f);
    glVertex2f(0.09f,0.19f);
    glVertex2f(0.11f,0.19f);
    glVertex2f(0.11f,0.16f);

    glEnd();

    glEnd();
    glBegin(GL_POLYGON);
//4 back left big
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.09f,0.21f);
    glVertex2f(0.09f,0.33f);
    glVertex2f(0.11f,0.29f);
    glVertex2f(0.11f,0.21f);

    glEnd();

    glBegin(GL_POLYGON);
//4 back Right big
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.25f,0.21f);
    glVertex2f(0.25f,0.33f);
    glVertex2f(0.23f,0.29f);
    glVertex2f(0.23f,0.21f);
    glEnd();

    glBegin(GL_POLYGON);
//5 Fornt
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.23f,0.33f);
    glVertex2f(0.11f,0.33f);
    glVertex2f(0.10f,0.34f);
    glVertex2f(0.09f,0.38f);
    glVertex2f(0.25f,0.38f);
    glVertex2f(0.24f,0.34f);
    glEnd();

    glBegin(GL_POLYGON);
//6  Right light
    glColor3f (1.0f, 1.0f,1.0f);
    glVertex2f(0.23f,0.43f);
    glVertex2f(0.25f,0.43f);
    glVertex2f(0.23f,0.45f);

    glEnd();

    glBegin(GL_POLYGON);
//7 left light
    glColor3f (1.0f, 1.0f,1.0f);
    glVertex2f(0.12f,0.43f);
    glVertex2f(0.10f,0.43f);
    glVertex2f(0.12f,0.45f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers(); // Swap front and back buffers

}

/// car 3

void car3(int d)

{
    glLoadIdentity();
    //down body
    glPushMatrix();
    glScalef(.6,1.3,0);
    glTranslatef(position1_x_2, position3, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.58f,0.42f,0.27f);
    glVertex2f(0.08f,0.10f);
    glVertex2f(0.09f,0.09f);
    glVertex2f(0.25f,0.09f);
    glVertex2f(0.26f,0.10f);
    glVertex2f(0.25f,0.08f);
    glVertex2f(0.09f,0.08f);
    glEnd();
    //mid body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f,0.10f);
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.25f,0.45f);
    glVertex2f(0.09f,0.45f);
    glVertex2f(0.08f,0.44f);
    glVertex2f(0.08f,0.10f);
    glVertex2f(0.09f,0.09f);
    glVertex2f(0.25f,0.09f);
    glEnd();
//uper body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.25f,0.45f);
    glVertex2f(0.09f,0.45f);
    glVertex2f(0.08f,0.44f);
    glVertex2f(0.09f,0.46f);
    glVertex2f(0.25f,0.46f);
    glEnd();
//windows
    glBegin(GL_POLYGON);
//1 back
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.11f,0.14f);
    glVertex2f(0.23f,0.14f);
    glVertex2f(0.24f,0.12f);
    glVertex2f(0.22f,0.11f);
    glVertex2f(0.123f,0.11f);
    glVertex2f(0.10f,0.12f);
    glEnd();

    glBegin(GL_POLYGON);
//2 back right small
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.25f,0.14f);
    glVertex2f(0.25f,0.19f);
    glVertex2f(0.23f,0.19f);
    glVertex2f(0.23f,0.16f);

    glEnd();
    glBegin(GL_POLYGON);
//3 back left small
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.09f,0.14f);
    glVertex2f(0.09f,0.19f);
    glVertex2f(0.11f,0.19f);
    glVertex2f(0.11f,0.16f);

    glEnd();

    glEnd();
    glBegin(GL_POLYGON);
//4 back left big
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.09f,0.21f);
    glVertex2f(0.09f,0.33f);
    glVertex2f(0.11f,0.29f);
    glVertex2f(0.11f,0.21f);

    glEnd();

    glBegin(GL_POLYGON);
//4 back Right big
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.25f,0.21f);
    glVertex2f(0.25f,0.33f);
    glVertex2f(0.23f,0.29f);
    glVertex2f(0.23f,0.21f);
    glEnd();

    glBegin(GL_POLYGON);
//5 Fornt
    glColor3f (0.0f, 1.0f,1.0f);
    glVertex2f(0.23f,0.33f);
    glVertex2f(0.11f,0.33f);
    glVertex2f(0.10f,0.34f);
    glVertex2f(0.09f,0.38f);
    glVertex2f(0.25f,0.38f);
    glVertex2f(0.24f,0.34f);
    glEnd();

    glBegin(GL_POLYGON);
//6  Right light
    glColor3f (1.0f, 1.0f,1.0f);
    glVertex2f(0.23f,0.43f);
    glVertex2f(0.25f,0.43f);
    glVertex2f(0.23f,0.45f);

    glEnd();

    glBegin(GL_POLYGON);
//7 left light
    glColor3f (1.0f, 1.0f,1.0f);
    glVertex2f(0.12f,0.43f);
    glVertex2f(0.10f,0.43f);
    glVertex2f(0.12f,0.45f);
    glEnd();
    glPopMatrix();
    glLoadIdentity();

    glutSwapBuffers(); // Swap front and back buffers

}

/// bomb
void bomb()

{

    // Draw bomb body

    glPushMatrix();
    glTranslatef(-0.1+B1, B2, 0.0f); // Apply translation
    glScalef(0.38,0.38,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,154,0);
    glVertex2f(.47f,0.51f);
    glVertex2f(0.54f,0.53f);
    glVertex2f(0.48f,0.48f);
    glVertex2f(.52,0.42f);
    glVertex2f(.46f,0.46f);
    glVertex2f(0.42f,0.40f);
    glVertex2f(0.42f,0.46f);
    glVertex2f(.36f,0.42f);
    glVertex2f(.40f,0.50f);
    glVertex2f(0.36f,0.54f);
    glVertex2f(0.42f,0.52f);
    glVertex2f(.43f,0.60f);
    glVertex2f(.44f,0.52f);
    glVertex2f(0.50f,0.60f);
    glEnd();
    glPopMatrix();
    glLoadIdentity();
    glutSwapBuffers();

}

///live

void health(int a)
{

    glPushMatrix();
    glTranslatef(H1, position4, 0.0f); // Apply translation

    glColor3f(1.0f, 0.0f, 0.0f); // Red color for filling

    glScalef(0.1,0.1,0);

    glBegin(GL_POLYGON);

    glVertex2f(0,0.5);   //1

    glVertex2f(0.1248, 0.5541);   //2

    glVertex2f(0.2434, 0.5333); //3

    glVertex2f(0.3162, 0.4397);     //4

    glVertex2f(0.3162, 0.3273);    //5

    glVertex2f(0.2704, 0.2296);   //6

    glVertex2f(0.1914, 0.1318);//o

    glVertex2f(0.1144, 0.0444);//o

    glVertex2f(0, -0.0388);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,0.5);   //1
    glVertex2f(-0.1248, 0.5541);   //2
    glVertex2f(-0.2434, 0.5333); //3
    glVertex2f(-0.3162, 0.4397);     //4
    glVertex2f(-0.3162, 0.3273);    //5
    glVertex2f(-0.2704, 0.2296);   //6
    glVertex2f(-0.1914, 0.1318);//o
    glVertex2f(-0.1144, 0.0444);//o
    glVertex2f(0, -0.0388);

    glEnd();

    glPopMatrix();
    glLoadIdentity();

    glutSwapBuffers();

}

void update1(int value1) {

    // Unconditionally update positions of all cars and obstacles

    position1 -= speed1;

    position2 -= speed2;

    position3 -= speed3;

    position4 -= speed4;

    B2 -= speed4;

    // Check if any car is still on the road

    if (position1 > -1.0 || position2 > -1.0 || position3 > -1.0 || position4 > -1.0) {

        // Request a redraw

        glutPostRedisplay();

        // Schedule the next update

        glutTimerFunc(100, update1, 0);

    } else {

        // Generate a new random number to determine the type of car

        int randomCar = rand() % 4;

        // Update the position of the car and obstacles based on the random number

        if (randomCar == 0) {

            position1_x = 1.9f;

            B1 = 0.0f;

        } else if (randomCar == 1) {

            position1_x_1 = 1.5f;

        } else if (randomCar == 2) {

            position1_x_2 = 1.5f;

            B1 = 0.0f;

        } else if (randomCar == 3) {

            H1 = 1.5f;

        }

        // Reset positions

        position1 = 0.0f;
        position2 = 1.20f;
        position3 = 1.50f;
        position4 = 1.90f;
        B2 = 1.2f;

        // Request a redraw

        glutPostRedisplay();

        // Schedule the next update

        glutTimerFunc(100, update1, 0);

    }

}

///Cover Page
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void instruction()
{
    glClearColor(0.0f,0.0f,0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glColor3f(1.0,1.0,1.0);
    renderBitmapString(-0.1f, 0.22f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "INSTRUCTIOS");
    renderBitmapString(-0.32f, 0.15f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"Press S to start");
    renderBitmapString(-0.32f, 0.08f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"Press 'W' to speed");
    renderBitmapString(-0.32f, 0.01f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"Press 'UP, DOWN, LEFT, RIGHT' to move your car");


    renderBitmapString(0.0f, -0.4f, 0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"Press 'X' to go Exit");

    //glLoadIdentity();
    glFlush(); // Render now
}
void coverpage()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.33f, 0.82f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University, Bangladesh (AIUB)");
    renderBitmapString(-0.3f, 0.72f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "FACULTY OF SCIENCE AND TECHNOLOGY");
    renderBitmapString(-0.3f, 0.62f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "PROJECT ON : ROAD MASTER CAR RACING");
    renderBitmapString(-0.28, 0.52f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "COURSE NAME : COMPUTER GRAPHICS");
    renderBitmapString(-0.31f, 0.42f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "COURSE SUPERVISOR : MAHFUJUR RAHMAN");

    renderBitmapString(-0.1f, 0.22f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "GROUP MEMBER");
    renderBitmapString(-0.32f, 0.15f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"1.   SHA MOHAMAD YAHIA IDRIS           (ID:22-46787-1)");
    renderBitmapString(-0.32f, 0.08f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"2.   MD YEASIN NEWAZ                              (ID:22-46803-1)");
    renderBitmapString(-0.32f, 0.01f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"3.   RANGON KUMAR SHAHA                   (ID:22-46585-1)");
    renderBitmapString(-0.32f, -0.06f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"4.   MD. FAYSAL KABIR                               (ID:22-46783-1)");
    renderBitmapString(-0.32f, -0.13f, 0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"5.   MD. REZWAN MUJAHID RUDRO        (ID:22-46802-1)");

    renderBitmapString(0.0f, -0.6f, 0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"Press 'N' to go Next");
    renderBitmapString(0.0f, -0.4f, 0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"Press 'X' to go Exit");


    glFlush(); // Render now
}


///Scoreboard
void drawScoreboard()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    //glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glLoadIdentity();

    // Set position and size for the scoreboard box
    int posX = 20; // X-coordinate
    int posY = 20; // Y-coordinate
    int width = 200; // Width of the box
    int height = 80; // Height of the box

    // Draw the scoreboard box
    glColor3f(0.3f, 0.3f, 0.3f); // Gray color for the box
    glBegin(GL_QUADS);
    glVertex2i(posX, posY);
    glVertex2i(posX + width+12, posY);
    glVertex2i(posX + width+12, posY + height);
    glVertex2i(posX, posY + height);
    glEnd();


    //glPushMatrix();
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(posX, posY);
    glVertex2i(posX + width+12, posY);
    glVertex2i(posX + width+12, posY + height);
    glVertex2i(posX, posY + height);
    glEnd();
    //glPopMatrix();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(posX + width+12, posY + height);
    glVertex2i(posX + width+12, posY + height+30);
    glVertex2i(posX, posY + height+30);
    glVertex2i(posX, posY + height);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White color for text

    // Convert score and distance to strings
    std::string scoreStr = "Score: " + std::to_string(score);
    std::string distanceStr = "Distance: " + std::to_string(distancee)+ " KM";

    // Set position for text
    int textPosX = posX + 10; // X-coordinate for text
    int textPosY = posY + 30; // Y-coordinate for text

    // Draw score
    glRasterPos2i(textPosX, textPosY);
    for (char const &c : scoreStr)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    // Draw distance
    glRasterPos2i(textPosX, textPosY + 20);
    for (char const &c : distanceStr)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

}

///Scoreboard Update
void updateScoreboard(int value)
{
    // Increment score and distance
    if (lives > 0) {
    score++;
    distancee += 0.01f; // You can adjust this increment value according to your needs
    }

    glutPostRedisplay();
    glutTimerFunc(100, updateScoreboard, 0); // Update every 1 second
}

///game over
void gameoverPage()
{

 glClear(GL_COLOR_BUFFER_BIT);
 glClearColor(0.8f, 1.0f, 1.0f, 1.0f); // White

    // Draw game over title
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    renderBitmapString(-0.25f, 0.8f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");
    glPopMatrix();

    // Draw final score and distance
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White

    // Draw "Your Score" text with pulsating effect
    float pulse = sin(glutGet(GLUT_ELAPSED_TIME) / 200.0f);
    glColor3f(1.0f, 0.8f + 0.2f * pulse, 0.2f); // Yellow with pulsating alpha
    renderBitmapString(-0.45f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "YOUR SCORE");

    // Draw actual score with bouncing effect
    //float bounce = sin(glutGet(GLUT_ELAPSED_TIME) / 300.0f);
    char scoreText[20];
    sprintf(scoreText, "%d", score);
    glColor3f(0.9f, 1.0f, 0.2f); // Yellow-green
    renderBitmapString(-0.05f, 0.4f+ 0.1f ,0.0f , GLUT_BITMAP_TIMES_ROMAN_24,scoreText);

    // Draw "Distance Traveled" text with waving effect
    float wave = sin(glutGet(GLUT_ELAPSED_TIME) / 400.0f);
    glColor3f(1.0f, 0.8f + 0.1f * wave, 0.2f); // Yellow with waving alpha
    renderBitmapString(-0.6f, 0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "DISTANCE TRAVELED");

    // Draw actual distance with spinning effect
    float spin = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    char distanceText[30];
    sprintf(distanceText, "%.2f KM", distancee);
    glColor3f(0.9f, 1.0f, 0.2f); // Yellow-green
    glTranslatef(-0.15f, -0.1f, 0.0f);
    glRotatef(spin * 100.0f, 0.0f, 0.0f, 1.0f);
    renderBitmapString(0.0f, 0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,distanceText);
    glPopMatrix();

    // Draw flashing "Press Esc to Exit" text
    glPushMatrix();
    int flash = glutGet(GLUT_ELAPSED_TIME) / 500 % 2;
    if (flash) {
        glColor3f(0.8f, 0.8f, 0.8f);
    } else {
        glColor3f(1.0f, 1.0f, 1.0f); // White
    }
    renderBitmapString(-0.3f, -0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press X to Exit");
    glPopMatrix();

glutSwapBuffers();
}

void mmap()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(.70f,0.40f);
    glVertex2f(1.0f,0.40f);
    glVertex2f(1.0f,0.70f);
    glVertex2f(.70f,0.70f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(.79f,0.40f);
    glVertex2f(.80f,0.40f);
    glVertex2f(.80f,0.70f);
    glVertex2f(.79f,0.70f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(.89f,0.40f);
    glVertex2f(.90f,0.40f);
    glVertex2f(.90f,0.70f);
    glVertex2f(.89f,0.70f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(.74f,0.50f);
    glVertex2f(.78f,0.50f);
    glVertex2f(.78f,0.54f);
    glVertex2f(.74f,0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(.84f,0.50f);
    glVertex2f(.88f,0.50f);
    glVertex2f(.88f,0.54f);
    glVertex2f(.84f,0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f,0.670f,1.0f);
    glVertex2f(.94f,0.50f);
    glVertex2f(.98f,0.50f);
    glVertex2f(.98f,0.54f);
    glVertex2f(.94f,0.54f);
    glEnd();

    glFlush();
}

void display()
{

    glClearColor(0.2f, 0.8f, 0.2f, 1.0f); // Set background color to a shade of green

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    // Draw environment (grass, road, dividers, borders, etc.)

    env();

    if (lives > 0)
    {
        car1(0);
        glPushMatrix();
        glTranslatef(0.06, 0.0, 0.0f);
        car2(0);
        glLoadIdentity();
        glPopMatrix();

        car3(0);
        health(0);
        bomb();
        glLoadIdentity();
         // Draw main car
        Main_car();

        if (checkCollision())
        {
            if (lives <= 0)

            {
                glutDisplayFunc(gameoverPage);

            }

        }

    }

    else
    {

        glutDisplayFunc(gameoverPage);

    }

    glLoadIdentity();

    Tree(0.0,positiontree,0.0);
    glLoadIdentity();

    Home(0.0,positiontree,0.0);
    glLoadIdentity();

    Home(0.0,-0.4+positiontree,0.0);
    glLoadIdentity();

    Home(0.0,0.4+positiontree,0.0);
    glLoadIdentity();


    Home(0.0,1.0+positiontree,0.0);
    glLoadIdentity();

    Tree1(0.0, positiontree,0.0);
    glLoadIdentity();

    Home1(0.0,0.07+positiontree,0.0);
    glLoadIdentity();

    Home1(0.06,-0.3+positiontree,0.0);
    glLoadIdentity();

    Home1(0.0,0.45+positiontree,0.0);
    glLoadIdentity();

    Home1(0.0,0.8+positiontree,0.0);
    glLoadIdentity();

    glLoadIdentity();

    Tree(1.4,positiontree,0.0);
    glLoadIdentity();

    Home(1.4,positiontree,0.0);
    glLoadIdentity();

    Home(1.4,0.4+positiontree,0.0);
    glLoadIdentity();

    Home(1.7,-0.4+positiontree,0.0);
    glLoadIdentity();

    Home1(1.4,positiontree,0.0);
    glLoadIdentity();


    Home1(1.5,1.2+positiontree,0.0);
    glLoadIdentity();

    Home1(1.4,0.5+positiontree,0.0);
    glLoadIdentity();

    Home1(1.2,0.99+positiontree,0.0);
    glLoadIdentity();

    Tree1(1.4, positiontree,0.0);
    glLoadIdentity();

    drawHearts(); // Draw hearts representing lives left
    drawScoreboard();

    glTranslatef(-0.1, 0.1, 0.0f);
    mmap();
    glLoadIdentity();

    glFlush();

}

void keyboardInput(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'n':
            glutDisplayFunc(instruction);
            glutPostRedisplay();
            break;
        case 's':
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 'x':
            exit(0);
            break;
        default:
            // Handle other keys here if needed
            break;
    }
}
void sound()
{
    PlaySound("a.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

int main(int argc, char** argv)

{

    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(425, 0);
    glutCreateWindow("Road with Car");
    glutDisplayFunc(coverpage);

    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboardInput);
    glutFullScreen();
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(50, update, 0);
    glutTimerFunc(50, updateScoreboard, 0);
    sound();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutMainLoop();


    return 0;

}
