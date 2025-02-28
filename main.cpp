#include<raylib.h>
class board{
  private:
    int width;
    int height;
    Color maincolor;
    Color tilecolor;
    int tilewidth;
    int tileheight;
    Color colorarray[2]={{100,0,0,255},{0,100,0,255}};
    int iter;
    int grid[3][3]={5};
  public:
  int winner;
  board(int w,int h){
    width=w;height=h;
    tilewidth=w/3;tileheight=h/3;
    maincolor={75,75,75,100};
    tilecolor={100,100,100,100};
    iter=0;
    winner=5;
    for (int i=0;i<3;i++){
      for (int j=0;j<3;j++){
        grid[i][j]=5;
      }
    }
  }
  ~board(){
    ClearBackground(BLACK);{
      DrawText("GAME OVER",100,100,200,{200,75,255,255});
    }
  }
  int findWinner(){
    if((grid[1][1]==grid[0][0]&&grid[1][1]==grid[2][2])
    || (grid[1][1]==grid[2][0]&&grid[1][1]==grid[0][2])
    || (grid[1][1]==grid[1][0]&&grid[1][1]==grid[1][2])
    || (grid[1][1]==grid[0][1]&&grid[1][1]==grid[2][1])){
      return grid[1][1];
    }
    if((grid[0][0]==grid[0][1]&&grid[0][1]==grid[0][2])
    || (grid[0][0]==grid[1][0]&&grid[1][0]==grid[2][0])){
      return grid[0][0];
    }
    if((grid[2][2]==grid[2][1]&&grid[2][1]==grid[2][0])
    || (grid[2][2]==grid[1][2]&&grid[1][2]==grid[0][2])){
      return grid[2][2];
    }
    return 5;
}
  void draw(){if(findWinner()==5){
    DrawRectangle(0,0,width,height,maincolor);
    for(int i=0;i<3;i++){for(int j=0;j<3;j++){
      DrawRectangle(width*(j)/3+5,height*(i)/3+5,tilewidth-10,tileheight-10,tilecolor);
      if(grid[i][j]!=5){
        DrawCircle((width*j)/3+tilewidth/2,(height*i)/3+tileheight/2,tileheight/2-10,colorarray[grid[i][j]]);
      }
    }
    }}
    /*
    else if(isFull()==1&& findWinner()==5){
      DrawRectangle(0,0,width,height,maincolor);
    }*/
    else{
      DrawRectangle(0,0,width,height,maincolor);
      if(findWinner()==0){
        DrawText("Red Wins!",0,0,100,{255,255,255,255});
      }
      else if(findWinner()==1){
        DrawText("Green Wins!",0,0,100,{255,255,255,255});
      }
      else{
        DrawText("TicTacToe",0,0,100,{255,255,255,255});
      }
    }
  }
  void inputhandle(int n){
    switch(n){
      case 1:
      grid[2][0]=iter%2;
      iter++;
      break;
      case 2:
      grid[2][1]=iter%2;
      iter++;
      break;
      case 3:
      grid[2][2]=iter%2;
      iter++;
      break;
      case 4:
      grid[1][0]=iter%2;
      iter++;
      break;
      case 5:
      grid[1][1]=iter%2;
      iter++;
      break;
      case 6:
      grid[1][2]=iter%2;
      iter++;
      break;
      case 7:
      grid[0][0]=iter%2;
      iter++;
      break;
      case 8:
      grid[0][1]=iter%2;
      iter++;
      break;
      case 9:
      grid[0][2]=iter%2;
      iter++;
      break;
      default:
      break;
    }
  }
  void update(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
      int cl=7;
      int v=0;
      int h=0;
      Vector2 pos=GetMousePosition();
      h=(int)pos.x/tilewidth;
      v=(int)pos.y/tileheight;
      cl=cl+h-3*v;
      if(grid[v][h]==5){
        inputhandle(cl);
      }
    }
  }
};
int main(){
  const int screenwidth=800;
  const int screenheight=800;
  InitWindow(screenwidth,screenheight,"TicTacToe");
  board B(screenwidth,screenheight);
  B.winner=-1;
  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    B.draw();
    B.update();
    EndDrawing();
  }
  return 0;
}