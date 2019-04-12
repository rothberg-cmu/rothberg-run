#ifndef ROTHBERG_GAMEPLAYER_HEADER
#define ROTHBERG_GAMEPLAYER_HEADER

#include <fslazywindow.h>
#include "ysclass.h"
#include <vector>



//class CubeVertexArray
//{
//public:
//    std::vector <float> vtx;
//    std::vector <float> col;
//};

// add a player class
class GamePlayer
{
    
private:
    bool aliveStatus;
    YsVec3 position;
    float velocity;
    float angle;     // orientation
    int jumpMode;    // 0: not jump; 1:jump up; 2: jump down
    
    YsVec3 viewTarget;
    YsMatrix4x4 viewRot;
    double viewDistance;
    double nearZ,farZ;

public:
    std::vector <float> vtx;
    std::vector <float> col;
    std::vector <float> nom;
    std::vector <float> uv;
    double step=0.1;
    
public:
    GamePlayer();
    ~GamePlayer();
    void CleanUp();
    void setPosition(float x1, float y1, float z1);
    YsVec3& getPosition();
    std::vector <float>& getVtx();
    std::vector <float>& getNom();
    void setAngle(float angle1);
    float getAngle();
    bool getAliveStatus();
    void setJumpMode(int status);
    int getJumpMode();
    void move(float x1, float y1, float z1);
    void draw();
    void rotate(float angle1);
    void rotateByStep(float angle1);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveWithAngle();
    void moveLeftWithAngle();
    void moveRightWithAngle();
    void jump(float height);
    void GetBoundingBox(YsVec3 &min,YsVec3 &max,const std::vector <float> &vtx);
    void LoadBinary();
    void LoadObject();
    void SetUpHeadLight(void);
    void moveAlongX(float deltaX);
    void moveAlongY(float deltaY);
    void moveAlongZ(float deltaZ);
    void scale(float scaleFactor);
};

//CubeVertexArray MakeCubeVertexArray(float x1,float y1,float z1,float x2,float y2,float z2);

#endif
