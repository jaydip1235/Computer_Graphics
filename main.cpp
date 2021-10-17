#include<iostream>
#include<graphics.h>
#include<math.h>
#include <stdlib.h>

using namespace std;

void DDA(){
	int x1,y1,x2,y2;
	cout<<"Enter starting x"<<endl;
	cin>>x1;
	cout<<"Enter starting y"<<endl;
	cin>>y1;
	cout<<"Enter ending x"<<endl;
	cin>>x2;
	cout<<"Enter ending y"<<endl;
	cin>>y2;
	int dx = x2-x1;
	int dy = y2-y1;
	int step =  abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float x_inc =  dx / (float) step;
    float y_inc =  dy / (float) step;
	for(int i=1;i<=step;i++){
		putpixel(round(x1),round(y1),YELLOW);
		x1+=x_inc;
		y1+=y_inc;
		delay(50);
	}
	getch();

}
void Bresenham(){
	int x1,y1,x2,y2;
	cout<<"Enter starting x"<<endl;
	cin>>x1;
	cout<<"Enter starting y"<<endl;
	cin>>y1;
	cout<<"Enter ending x"<<endl;
	cin>>x2;
	cout<<"Enter ending y"<<endl;
	cin>>y2;
	int x=x1,y=y1;
	int dx = x2-x1;
	int dy = y2-y1;
	int p = 2*dx - dy;
	while(x<=x2){
		putpixel(x,y,CYAN);
		x++;
		if(p<0)p+=2*dy;
		else{
		 p+=(2*dy)-(2*dx);
		 y++;
	}
	delay(75);
}
	getch();
}

void pixelSet(int xc,int yc,int x,int y)  
{  
    putpixel(x+xc,y+yc,LIGHTBLUE);  
    putpixel(x+xc,-y+yc,LIGHTBLUE);  
    putpixel(-x+xc,-y+yc,LIGHTBLUE);  
    putpixel(-x+xc,y+yc,LIGHTBLUE);  
    putpixel(y+xc,x+yc,LIGHTBLUE);  
    putpixel(y+xc,-x+yc,LIGHTBLUE);  
    putpixel(-y+xc,-x+yc,LIGHTBLUE);  
    putpixel(-y+xc,x+yc,LIGHTBLUE);  
}  

void PolyCircle(){
	int xc,yc,r;
	cout<<"X-coordinate of center"<<endl;
	cin>>xc;
	cout<<"Y-coordinate of center"<<endl;
	cin>>yc;
	cout<<"Radius of Circle"<<endl;
	cin>>r;
	int x=0,y=r;  
    int x2 = r/sqrt(2);  
    while(x<=x2)  
    {  
        y = sqrt(r*r - x*x);  
        pixelSet(xc,yc,x,y);  
        delay(75);
        x += 1;  
    }  
	getch();
}

main()
{
	initwindow(800,800);
	cout<<"Choose an algorithm"<<endl;
	cout<<"1.DDA"<<endl;
	cout<<"2.Bresehnam"<<endl;
	cout<<"3.Polynomial Method(Circle)"<<endl;
	cout<<"4.Quit"<<endl;
	int option;
	cin>>option;
	while(option!=10){
	switch(option){
		case 1:
			DDA();
			break;
		case 2:
			Bresenham();
			break;
		case 3:
			PolyCircle();
			break;
	}

	cout<<"Choose an algorithm"<<endl;
	cout<<"1.DDA(Line)"<<endl;
	cout<<"2.Bresehnam(Line)"<<endl;
	cout<<"3.Polynomial Method(Circle)"<<endl;
	cout<<"4.Quit"<<endl;
	cin>>option;
			
}
cout<<"Thanks";
}
