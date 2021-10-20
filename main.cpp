#include<iostream>
#include<graphics.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
#define pi 3.14  

using namespace std;

void DDA(){
	int x1,y1,x2,y2;
	cout<<"Enter starting x"<<endl;
	cin>>x1;
	cout<<"Enter starting y"<<endl;
	cin>>y1;
	cout<<"Enter ending x"<<endl;
	cin>>x2;
	cout<<"Enter ending y "<<endl;
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

void BresenhamCircle(){
	int xc,yc,r;
	cout<<"X-coordinate of center"<<endl;
	cin>>xc;
	cout<<"Y-coordinate of center"<<endl;
	cin>>yc;
	cout<<"Radius of Circle"<<endl;
	cin>>r;
	int x=0,y=r;
	int d=3-(2*r); 
	pixelSet(xc,yc,x,y);   
	while(x<=y){
	if(d<=0)  
    {  
        d=d+(4*x)+6;  
    }  
    else  
    {  
        d=d+(4*x)-(4*y)+10;  
        y-=1;  
    }  
    x+=1;  
    pixelSet(xc,yc,x,y);  
    delay(75);
    }  
	getch();
	
}
void MidPointCircle(){
	
	int xc,yc,r;
	cout<<"X-coordinate of center"<<endl;
	cin>>xc;
	cout<<"Y-coordinate of center"<<endl;
	cin>>yc;
	cout<<"Radius of Circle"<<endl;
	cin>>r;
	int x=0,y=r;
	int d=1-r; 
	pixelSet(xc,yc,x,y);   
	while(x<=y){
	if(d<=0)  
    {  
        d=d+(2*x)+3;  
    }  
    else  
    {  
        d=d+2*(x-y)+5;  
        y-=1;  
    }  
    x+=1;  
    pixelSet(xc,yc,x,y);  
    delay(75);
    }  
	
	getch();
}

void EllipsePolar(){
	float xc,yc,a,b,step;
	cout<<"X-coordinate of center"<<endl;
	cin>>xc;
	cout<<"Y-coordinate of center"<<endl;
	cin>>yc;
	cout<<"Semi-Major axes"<<endl;
	cin>>a;
	cout<<"Semi-Minor axes"<<endl;
	cin>>b;
	cout<<"Enter step size"<<endl;
	cin>>step;
	float theta= 0;  
    float thetaend=(pi*90)/180;  
    while(theta<thetaend)  
    {  
        float x = a * cos (theta);  
        float y = b * sin (theta);  
        putpixel (x+xc, y+yc, RED);  
        putpixel (-x+xc, y+yc, RED);  
        putpixel (-x+xc, -y+yc, RED);  
        putpixel (x+xc, -y+yc, RED); 
        theta+=step;  
        delay(50);
    }  
    getch();
	
}

void EllipseBresenhamMidpoint(){
	float xc,yc,a,b;
	cout<<"X-coordinate of center"<<endl;
	cin>>xc;
	cout<<"Y-coordinate of center"<<endl;
	cin>>yc;
	cout<<"Semi-Major axes"<<endl;
	cin>>a;
	cout<<"Semi-Minor axes"<<endl;
	cin>>b;
	float x=0,y=b;
	float d1 =((b * b)-(a * a * b) + (a * a)/4);  
	float dx = 2 * b * b * x;
    float dy = 2 * a * a * y;
  
  	 while (dx < dy)
    {
    putpixel (x+xc, y+yc, RED);  
    putpixel (-x+xc, -y+yc, RED);  
    putpixel (x+xc, -y+yc, RED);  
    putpixel (-x+xc, y+yc, RED);
 
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * b * b);
            d1 = d1 + dx + (b * b);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d1 = d1 + dx - dy + (b * b);
        }
        delay(100);
    }
 
    float d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) +
         ((a * a) * ((y - 1) * (y - 1))) -
          (a * a * b * b);
 
   
    while (y >= 0)
    {
 
        putpixel (x+xc, y+yc, RED);  
    	putpixel (-x+xc, -y+yc, RED);  
    	putpixel (x+xc, -y+yc, RED);  
    	putpixel (-x+xc, y+yc, RED);
 
       
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * a * a);
            d2 = d2 + (a * a) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d2 = d2 + dx - dy + (a * a);
        }
    	delay(100);
    }
	getch();
}

void BoundaryFillHelper(int x, int y, int fill_color,int boundary_color)
{
    if(getpixel(x, y) == boundary_color || getpixel(x, y) == fill_color)return;
       
        putpixel(x, y, fill_color);
        BoundaryFillHelper(x + 1, y, fill_color, boundary_color);
        BoundaryFillHelper(x, y + 1, fill_color, boundary_color);
        BoundaryFillHelper(x - 1, y, fill_color, boundary_color);
        BoundaryFillHelper(x, y - 1, fill_color, boundary_color);
        BoundaryFillHelper(x - 1, y - 1, fill_color, boundary_color);
        BoundaryFillHelper(x - 1, y + 1, fill_color, boundary_color);
        BoundaryFillHelper(x + 1, y - 1, fill_color, boundary_color);
        BoundaryFillHelper(x + 1, y + 1, fill_color, boundary_color);
    
}
void BoundaryFill(){
	rectangle(200, 200, 400, 400);
	BoundaryFillHelper(250,312,4,15);
	
	getch();
}

void FloodFillHelper(int x, int y, int old_color,int new_color){
	if(getpixel(x, y)==old_color){
	putpixel(x, y, new_color);
    FloodFillHelper(x + 1, y, old_color, new_color);
    FloodFillHelper(x, y + 1, old_color, new_color);
    FloodFillHelper(x - 1, y, old_color, new_color);
    FloodFillHelper(x, y - 1, old_color, new_color);
    FloodFillHelper(x - 1, y - 1, old_color, new_color);
    FloodFillHelper(x - 1, y + 1, old_color, new_color);
    FloodFillHelper(x + 1, y - 1, old_color, new_color);
    FloodFillHelper(x + 1, y + 1, old_color, new_color);
}
}

void FloodFill(){
	line(200,200,400,200);
	setcolor(GREEN);
	line(400,200,400,400);
	setcolor(WHITE);
	line(400,400,200,400);
	setcolor(BLUE);
	line(200,400,200,200);
	setcolor(BROWN);
	FloodFillHelper(250,312,0,14);
	getch();
}

void ScanLineFill(){
	int points[30][2],xi[30];
	float slope[30];
	cout<<"No. of edges of polygon:"<<endl;
	int n;
	cin>>n;
	int col=0;
	cout<<"Enter the X and Y co-ordinate of the points"<<endl;
	for(int i=0;i<n;i++){
		cin>>points[i][0]>>points[i][1];
	}
	points[n][0]=points[0][0];
	points[n][1]=points[0][1];
	
	for(int i=0;i<n;i++){
		col=(col+1)%12;
		line(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
		setcolor(col);
	}
	
	for(int i=0;i<n;i++){
		int dy = points[i+1][1]-points[i][1];
		int dx = points[i+1][0]-points[i][0];
		if(dy==0)slope[i]=1.0;
		if(dx==0)slope[i]=0.0;
		if(dy!=0 && dx!=0){
			slope[i]=(float)dx/dy;
		}
	}
	
	for(int y=800;y>0;y--){
		int p=0;
		for(int i=0;i<n;i++){
			if((points[i][1]<=y && points[i+1][1]>y)||(points[i+1][1]<=y && points[i][1]>y)){
				xi[p]=(int)(points[i][0])+slope[i]*(y-points[i][1]);
				p++;
			}
		}
		
		for(int j=0;j<p-1;j++){
			for(int i=0;i<p-1;i++){
				if(xi[i]>xi[i+1]){
					int temp = xi[i];
					xi[i]=xi[i+1];
					xi[i+1]=temp;
				}
			}
		}
		setcolor(col+1);

		for(int i=0;i<p;i+=2){
			line(xi[i],y,xi[i+1]+1,y);delay(10);
			}
			
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
	cout<<"4.Bresenham Method(Circle)"<<endl;
	cout<<"5.Midpoint Method(Circle)"<<endl;
	cout<<"6. Polar Method(Ellipse)"<<endl;
	cout<<"7. Bresenham Midpoint Method(Ellipse)"<<endl;
	cout<<"8. Boundary Fill algorithm"<<endl;
	cout<<"9. Flood Fill algorithm"<<endl;
	cout<<"10. Scanline Fill algorithm"<<endl;
	cout<<"11.Quit"<<endl;
	int option;
	cin>>option;
	while(option!=11){
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
		case 4:
			BresenhamCircle();
			break;
		case 5:
			MidPointCircle();
			break;
		case 6:
			EllipsePolar();
			break;
		case 7:
			EllipseBresenhamMidpoint();
			break;
		case 8:
			BoundaryFill();
			break;
		case 9:
			FloodFill();
			break;
		case 10:
			ScanLineFill();
			break;
	}
	cout<<"Choose an algorithm"<<endl;
	cout<<"1.DDA"<<endl;
	cout<<"2.Bresehnam"<<endl;
	cout<<"3.Polynomial Method(Circle)"<<endl;
	cout<<"4.Bresenham Method(Circle)"<<endl;
	cout<<"5.Midpoint Method(Circle)"<<endl;
	cout<<"6. Polar Method(Ellipse)"<<endl;
	cout<<"7. Bresenham Midpoint Method(Ellipse)"<<endl;
	cout<<"8. Boundary Fill algorithm"<<endl;
	cout<<"9. Flood Fill algorithm"<<endl;
	cout<<"10. Scanline Fill algorithm"<<endl;
	cout<<"11.Quit"<<endl;
	cin>>option;
			
}
cout<<"Thanks";
}