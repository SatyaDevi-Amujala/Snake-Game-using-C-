#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

bool GameOver;
const int w=20;
const int h=20;
int x,y,fruitx,fruity,score;
enum Dir {Stop=0, Up, Down,Left, Right };
Dir dir;
int tx[100], ty[100],n;
void Setup(){
GameOver=false;
x=w/2;
y=h/2;
fruitx=rand()%(w-2)+1;
fruity=rand()%(h-2)+1;
dir=Stop;
};
void Draw(){
    system("CLS");
    for(int i=0;i<w;i++){
        cout<<"#";
    }cout<<"\n";
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(j==0 || j==w-1){
                cout<<"#";}
            else if(i==x && j==y){
                cout<<"O";
            }
            else if(fruitx==i && fruity==j){
                cout<<"F";
            }
            else{
            bool print=false;
            for(int k=0;k<n;k++){
                if(i==tx[k] && j==ty[k]){
                    cout<<"o";
                    print=true;
                }
            }
            if(!print)cout<<" ";}
            
    
        }cout<<"\n";
    }
    for(int i=0;i<w;i++){
        cout<<"#";
    }
    cout<<"\n";
    cout<<"Score="<<score<<"\n";
};
void Input(){
    if(kbhit()){
        switch(getch()){
            case 'w':dir=Up;
                    break;
             case 'a':dir=Left;
                    break;
             case 's':dir=Down;
                    break;
             case 'd':dir=Right;
                    break;
                default:break;
        }
    }
};
void Logic(){
    int prevx=tx[0];
    int prevy=ty[0];
    tx[0]=x;
    ty[0]=y;
    int prevx1,prevy1;
    for(int i=1;i<n;i++){
        prevx1=tx[i];
        prevy1=ty[i];
        tx[i]=prevx;
        ty[i]=prevy;
        prevx=prevx1;
        prevy=prevy1;

    }
    switch(dir){
            case Up:x--;
                    break;
             case Left:y--;
                    break;
             case Down:x++;
                    break;
             case Right:y++;
                    break;
                default:break;
        }
        if(x<0 || x>w-1 || y<0 ||y>h-1){
            GameOver=true;
        }
        for(int i=0;i<n;i++){
            if(tx[i]==x && ty[i]==y){
                GameOver=true;
            }
        }
        if(x==fruitx && y==fruity){
                score=score+1;
                n++;
                fruitx=rand()%(w-2)+1;
                fruity=rand()%(h-2)+1;
        }
};

int main(){
    Setup();
    while(!GameOver){
        Draw();
        Input();
        Logic();
        Sleep(400);
    }

}