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
	rectangle(400, 400, 600, 600);
	BoundaryFillHelper(450,512,4,15);
	
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

void Translation(){
	rectangle(200,100,500,400);
	getch();
	cout<<"Enter translation amount x and y"<<endl;
	int tx,ty;
	cin>>tx>>ty;
	setcolor(RED);
	rectangle(200+tx,100+ty,500+tx,400+ty);
	getch();
}
void Rotation(){
	double d1,xt,yt;
	int x1=100,y1=400,x2=400,y2=100;
	line(100,400,400,100);
	getch();
	cout<<"Enter rotation angle"<<endl;
	cin>>d1;
	d1 = (d1*3.14)/180.0;
	setcolor(RED);
	xt = x1+(x2-x1)*cos(d1) - (y2-y1)*sin(d1);
	yt = y1+(x2-x1)*sin(d1) + (y2-y1)*cos(d1);
	line(100,400,(int)xt,(int)yt);
	getch();
}

void Scaling(){
	rectangle(300,300,500,500);
	getch();
	cout<<"Enter the scaling factor(xs,ys):"<<endl;
	double xs,ys;
	cin>>xs>>ys;
	setcolor(RED);
	rectangle(300,300,500*xs,500*ys);
	getch();
}

void Shearing(){
	float x1=100,y1=100,x2=300,y2=100,x3=300,y3=200,x4=100,y4=200;
	float shx,shy;
	char ch;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);
	getch();
	cout<<"enter the direction of shear : ";
	cin>>ch;
	if(ch=='x')
	{
		cout<<"enter x-direction of shear : ";
		cin>>shx;
		x1=x1+shx*y1;
		x2=x2+shx*y2;
		setcolor(RED);
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x4,y4);
		line(x4,y4,x1,y1);
	}
	else
	{
		cout<<"enter y-direction of shear : ";
		cin>>shy;
		y2=y2+shy*x2;
		y3=y3+shy*x3;
		setcolor(RED);
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x4,y4);
		line(x4,y4,x1,y1);
	}

	getch();
}

void ReflectX(){
	int x1[3],y1[3],ry1[3];
	cout<<"Enter 3 points"<<endl;
	for(int i=0;i<3;i++){
		cin>>x1[i];
		cin>>y1[i];
	}
	int midx=getmaxx()/2;
	int midy=getmaxy()/2;
	
	for(int i=0;i<3;i++){
		x1[i]+=midx;
		if(y1[i]<0){
			y1[i]=-y1[i];
			y1[i]+=midy;
		}
		else{
			y1[i]=midy-y1[i];
		}
	}
	line(midx,0,midx,getmaxy());
	line(0,midy,getmaxx(),midy);
	
	line(x1[0],y1[0],x1[1],y1[1]);
	line(x1[1],y1[1],x1[2],y1[2]);
	line(x1[2],y1[2],x1[0],y1[0]);
	
	int diffy;
	for(int i=0;i<3;i++){
		if(y1[i]>midy){
			diffy = midy-y1[i];
			ry1[i]=midy-diffy;
		}
		if(y1[i]<midy){
			diffy = midy-y1[i];
			ry1[i]=midy+diffy;
		}
	}
	

	line(x1[0],ry1[0],x1[1],ry1[1]);
	line(x1[1],ry1[1],x1[2],ry1[2]);
	line(x1[2],ry1[2],x1[0],ry1[0]);
		
	getch();

}

void ReflectY(){
	int x1[3],y1[3],rx1[3];
	cout<<"Enter 3 points"<<endl;
	for(int i=0;i<3;i++){
		cin>>x1[i];
		cin>>y1[i];
	}
	int midx=getmaxx()/2;
	int midy=getmaxy()/2;
	
	for(int i=0;i<3;i++){
		x1[i]+=midx;
		if(y1[i]<0){
			y1[i]=-y1[i];
			y1[i]+=midy;
		}
		else{
			y1[i]=midy-y1[i];
		}
	}
	line(midx,0,midx,getmaxy());
	line(0,midy,getmaxx(),midy);
	
	line(x1[0],y1[0],x1[1],y1[1]);
	line(x1[1],y1[1],x1[2],y1[2]);
	line(x1[2],y1[2],x1[0],y1[0]);
	
	int diff;
	for(int i=0;i<3;i++){
		if(x1[i]>midx){
			diff = x1[i]-midx;
			rx1[i]=midx-diff;
		}
		if(x1[i]<midx){
			diff = midx-x1[i];
			rx1[i]=midx+diff;
		}
	}
	

	line(rx1[0],y1[0],rx1[1],y1[1]);
	line(rx1[1],y1[1],rx1[2],y1[2]);
	line(rx1[2],y1[2],rx1[0],y1[0]);
		
	getch();

}
static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xmin,xmax,ymin,ymax;
int getcode(int x, int y){
	int code = 0;
	if(y>ymax)code|=TOP;
	if(y<ymin)code|=BOTTOM;
	if(x<xmin)code|=LEFT;
	if(x>xmax)code|=RIGHT;
	return code;
}

void CohenSutherlandLine(){
	cout<<"Enter rectangular window minimum and maximum values(xmin,ymin,xmax,ymax) : "<<endl;
	cin>>xmin>>ymin>>xmax>>ymax;
	rectangle(xmin,ymin,xmax,ymax);
	int x1,y1,x2,y2;
	cout<<"Enter End point of a line:"<<endl;
	cin>>x1>>y1>>x2>>y2;
	line(x1,y1,x2,y2);
	getch();
	int outcode1 = getcode(x1,y1);
	int outcode2 = getcode(x2,y2);
	int accept = 0;
	while(1){
		float m=(float)(y2-y1)/(x2-x1);
		if(outcode1==0 && outcode2==0){
			accept=1;
			break;
		}
		else if((outcode1 & outcode2)!=0){
			break;
		}
		else{
			int x,y;
			int temp;
			if(outcode1==0)temp=outcode2;
			else temp=outcode1;
			if(temp & TOP){
				x=x1+(ymax-y1)/m;
				y=ymax;
			}
			else if(temp & BOTTOM){
				x=x1+(ymin-y1)/m;
				y=ymin;
			}
			else if(temp & LEFT){
				x=xmin;
				y=y1+m*(xmin-x1);
			}
			else if(temp & RIGHT){
				x=xmax;
				y=y1+m*(xmax-x1);
			}
			if(temp==outcode1){
				x1=x;
				y1=y;
				outcode1=getcode(x1,y1);
			}
			else{
				x2=x;
				y2=y;
				outcode2 = getcode(x2,y2);
			}
			
		}
	}
	
	if(accept){
		cleardevice();
		setcolor(RED);
		rectangle(xmin,ymin,xmax,ymax);	
		line(x1,y1,x2,y2);
	}
	getch();
}
void mulMat(int mat1[][3], int mat2[][3]) {
    int rslt[3][3];
 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            rslt[i][j] = 0;
 
            for (int k = 0; k < 3; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    int x1=rslt[0][0];
    int y1=rslt[1][0];
    int x2=rslt[0][1];
    int y2=rslt[1][1];
    int x3=rslt[0][2];
    int y3=rslt[1][2];
//    for(int i=0;i<3;i++){
//		for(int j=0;j<3;j++){
//			cout<<rslt[i][j]<<" ";
//		}
//		cout<<endl;
//	}
    
 	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
}
void AnyLineReflection(){
	int x1,y1,x2,y2,x3,y3,m,c;
	cout<<"Enter 3 points of triangle"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	getch();
	cout<<"Enter the value of m and c"<<endl;
	setcolor(GREEN);
	cin>>m>>c;
	int yy = m*1 + c;
	int yy2 = m*799+c;
	line(1,yy,799,yy2);
	getch();
	setcolor(RED);
	int tm[3][3];
	tm[0][0]=(1-m*m)/(1+m*m);
	tm[0][1]=(2*m)/(1+m*m);
	tm[0][2]=(-1*2*c*m)/(1+m*m);
	tm[1][0]=(2*m)/(1+m*m);
	tm[1][1]=(m*m-1)/(1+m*m);
	tm[1][2]=(2*c)/(1+m*m);
	tm[2][0]=0;
	tm[2][1]=0;
	tm[2][2]=1;
//for(int i=0;i<3;i++){
//		for(int j=0;j<3;j++){
//			cout<<tm[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	int mat[3][3];
	mat[0][0]=x1;
	mat[0][1]=x2;
	mat[0][2]=x3;
	mat[1][0]=y1;
	mat[1][1]=y2;
	mat[1][2]=y3;
	mat[2][0]=1;
	mat[2][1]=1;
	mat[2][2]=1;
//		for(int i=0;i<3;i++){
//		for(int j=0;j<3;j++){
//			cout<<mat[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//		cout<<endl;
	mulMat(tm,mat);
	
	getch();
}


void mulMat2(double mat1[][3], double mat2[][3]) {
    double rslt[3][3];
 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            rslt[i][j] = 0;
 
            for (int k = 0; k < 3; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    double x1=rslt[0][0];
    double y1=rslt[0][1];
    double x2=rslt[1][0];
    double y2=rslt[1][1];
    double x3=rslt[2][0];
    double y3=rslt[2][1];
    for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<rslt[i][j]<<" ";
		}
		cout<<endl;
	}
    
 	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
}


void ArbitraryPointRotation(){
	int x1,y1,x2,y2,x3,y3,xp,yp;
	double d1;
	cout<<"Enter the triangle coordinates"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	
	getch();
	
	cout<<"Enter the arbitraty point"<<endl;
	cin>>xp>>yp;
	cout<<"Enter rotation angle"<<endl;
	cin>>d1;
	d1 = (d1*3.14)/180.0;
	double tm[3][3];
	tm[0][0]=cos(d1);
	tm[0][1]=sin(d1);
	tm[0][2]=0;
	tm[1][0]=(-1)*sin(d1);
	tm[1][1]=cos(d1);
	tm[1][2]=0;
	tm[2][0]=((-1)*xp*cos(d1))+(yp*sin(d1))+xp;
	tm[2][1]=((-1)*xp*sin(d1))+((-1)*yp*cos(d1))+yp;
	tm[2][2]=1;
	
	double mat[3][3];
	mat[0][0]=x1;
	mat[0][1]=y1;
	mat[0][2]=1;
	mat[1][0]=x2;
	mat[1][1]=y2;
	mat[1][2]=1;
	mat[2][0]=x3;
	mat[2][1]=y3;
	mat[2][2]=1;
	mulMat2(mat,tm);
	
	getch();
}

void mulMat3(int mat1[][3], int mat2[][3]) {
    int rslt[3][3];
 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            rslt[i][j] = 0;
 
            for (int k = 0; k < 3; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    int x1=rslt[0][0];
    int y1=rslt[1][0];
    int x2=rslt[0][1];
    int y2=rslt[1][1];
    int x3=rslt[0][2];
    int y3=rslt[1][2];
   
    
 	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
}

void ArbitraryPointScaling(){
	
	int x1,y1,x2,y2,x3,y3,h,k,sx,sy;
	cout<<"Enter 3 points of triangle"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	getch();
	cout<<"Enter the point"<<endl;
	cin>>h>>k;
	cout<<"Enter Sx amd Sy"<<endl;
	cin>>sx>>sy;
	int tm[3][3];
	tm[0][0]=sx;
	tm[0][1]=0;
	tm[0][2]=h*(1-sx);
	tm[1][0]=0;
	tm[1][1]=sy;
	tm[1][2]=k+sy-(k*sy);
	tm[2][0]=0;
	tm[2][1]=0;
	tm[2][2]=1;
	
	int mat[3][3];
	mat[0][0]=x1;
	mat[0][1]=x2;
	mat[0][2]=x3;
	mat[1][0]=y1;
	mat[1][1]=y2;
	mat[1][2]=y3;
	mat[2][0]=1;
	mat[2][1]=1;
	mat[2][2]=1;
	mulMat3(tm,mat);
	getch();
	
}


void SutherlandHodgeman(){
	int n,*x,i,k=0;
	int w[]={220,140,420,140,420,340,220,340,220,140};
	setcolor(RED); 
	drawpoly(5,w); 
	cout<<"Enter the no. of vertices of polygon: "<<endl;
	cin>>n;
	x =new int[2*n+1];
	cout<<"Enter the coordinates of points:\n"<<endl;
	k=0;
	for(i=0;i<n*2;i+=2) 
	{
		cin>>x[i]>>x[i+1];
		k++;
	}
	x[n*2]=x[0]; 
	x[n*2+1]=x[1];
	setcolor(WHITE);
	drawpoly(n+1,x);
	cout<<"\nPress a button to clip a polygon.."<<endl;
	getch();
 	setcolor(RED);
 	drawpoly(5,w);
 	setfillstyle(SOLID_FILL,BLACK);
 	floodfill(2,2,RED);
 	getch();
	
}

main()
{
	initwindow(800,800);
	cout<<"Choose an algorithm"<<endl;
	cout<<"1.DDA(Line)"<<endl;
	cout<<"2.Bresehnam(Line)"<<endl;
	cout<<"3.Polynomial Method(Circle)"<<endl;
	cout<<"4.Bresenham Method(Circle)"<<endl;
	cout<<"5.Midpoint Method(Circle)"<<endl;
	cout<<"6. Polar Method(Ellipse)"<<endl;
	cout<<"7. Bresenham Midpoint Method(Ellipse)"<<endl;
	cout<<"8. Boundary Fill algorithm"<<endl;
	cout<<"9. Flood Fill algorithm"<<endl;
	cout<<"10. Scanline Fill algorithm"<<endl;
	cout<<"11.Translation"<<endl;
	cout<<"12.Rotation"<<endl;
	cout<<"13.Scaling"<<endl;
	cout<<"14.Shearing"<<endl;
	cout<<"15.Reflection about x-axis"<<endl;
	cout<<"16.Reflection about y-axis"<<endl;
	cout<<"17.Reflection about an arbitrary line"<<endl;
	cout<<"18.Rotation about an arbitrary point"<<endl;
	cout<<"19.Scaling about an arbitrary point"<<endl;
	cout<<"20.Cohen-Sutherland Line Clipping"<<endl;
	cout<<"21.Sutherland-Hodgeman Polygon Clipping"<<endl;
	cout<<"22.Quit"<<endl;
	
	
	int option;
	cin>>option;
	while(option!=22){
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
		case 11:
			Translation();
			break;
		case 12:
			Rotation();
			break;
		case 13:
			Scaling();
			break;
		case 14:
			Shearing();
			break;
		case 15:
			ReflectX();
			break;
		case 16:
			ReflectY();
			break;
		case 17:
			AnyLineReflection();
			break;
		case 18:
			ArbitraryPointRotation();
			break;
		case 19:
			ArbitraryPointScaling();
			break;
		case 20:	
			CohenSutherlandLine();
			break;
		case 21:
			SutherlandHodgeman();
			break;
	}
cout<<"Choose an algorithm"<<endl;
	cout<<"1.DDA(Line)"<<endl;
	cout<<"2.Bresehnam(Line)"<<endl;
	cout<<"3.Polynomial Method(Circle)"<<endl;
	cout<<"4.Bresenham Method(Circle)"<<endl;
	cout<<"5.Midpoint Method(Circle)"<<endl;
	cout<<"6. Polar Method(Ellipse)"<<endl;
	cout<<"7. Bresenham Midpoint Method(Ellipse)"<<endl;
	cout<<"8. Boundary Fill algorithm"<<endl;
	cout<<"9. Flood Fill algorithm"<<endl;
	cout<<"10. Scanline Fill algorithm"<<endl;
	cout<<"11.Translation"<<endl;
	cout<<"12.Rotation"<<endl;
	cout<<"13.Scaling"<<endl;
	cout<<"14.Shearing"<<endl;
	cout<<"15.Reflection about x-axis"<<endl;
	cout<<"16.Reflection about y-axis"<<endl;
	cout<<"17.Reflection about an arbitrary line"<<endl;
	cout<<"18.Rotation about an arbitrary point"<<endl;
	cout<<"19.Scaling about an arbitrary point"<<endl;
	cout<<"20.Cohen-Sutherland Line Clipping"<<endl;
	cout<<"21.Sutherland-Hodgeman Polygon Clipping"<<endl;
	cout<<"22.Quit"<<endl;
	cin>>option;
			
}
cout<<"Thanks";
}