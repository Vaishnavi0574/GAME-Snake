#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=20,height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100],ntail;
enum edirection{STOP=0,LEFT,RIGHT,UP,DOWN};
edirection dir;

void setup(){
    gameover=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
}
void draw(){
    system("cls");
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0){
                cout<<"#";
            }
            if(i==y && j==x){
                cout<<"O";
            }
            else if(i==fruitY && j==fruitX){
                cout<<"*";
            }
            else{
                bool print=false;
                for(int k=0;k<ntail;k++){
                    if(j==tailX[k] && i==tailY[k]){
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print){
                    cout<<" ";
                }
            }    
            if(j==width-1){
                cout<<"#";
            }
        }
        cout<<endl;
    }
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"Score: "<<score<<endl;
}
void input(){
    if(kbhit()){
        switch(getch()){
        case 'a':
            dir=LEFT;
            break;
        case 'd':
            dir=RIGHT;
            break;
        case 'w':
            dir=UP;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'x':
            gameover=true;
            break;                
        }
    }
}
void logic(){
    int prevx=tailX[0];
    int prevy=tailY[0];
    int prev2x,prev2y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<ntail;i++){
        prev2x=tailX[i];
        prev2y=tailY[i];
        tailX[i]=prevx;
        tailY[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(dir){
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break; 
        default:
            break;                   
    }
    if(x>=width){
        x=0;
    }
    else if(x<0){
        x=width-1;
    }
    if(y<0){
        y=height-1;
    }
    else if(y>=height){
        y=0;
    }
    for(int i=0;i<ntail;i++){
        if(x==tailX[i] && y==tailY[i]){
            gameover=true;
        }
    }
    if(x==fruitX && y==fruitY){
        ntail++;
        score=score+10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
} 
int main(){
    setup();
    while(!gameover){
        draw();
        input();
        logic();
        Sleep(100);
    }   
    return 0;
}