#include"stdio.h"
#include"conio.h"
#include"fstream"
#include "stdlib.h"
#include <iostream>
using namespace std;

#define dd  "filegoc.txt"
#define dd1  "day1.txt"
#define dd2  "day2.txt"
fstream a,b,c;

void Ghifile(fstream& f,char duongdan[20]){ //ghi cac ptu vao file
	int n; // tong so ptu can nhap
	int x;

	f.open(duongdan,ios::out);
	if(f==NULL){
		printf("\nKo tao duoc file.");
		exit(0);
	}
	
	printf("\n Nhap tong so luong phan tu: ");
	scanf("%d",&n);
//	fprintf(f,"%d \n",n);
//	f<<n<<endl;
	for(int i=0;i<n;i++){
		printf("\nNhap phan tu thu %d:  ",i);
		scanf("%3d",&x); // nhap tu phim
//		fprintf(f,"%3d",x); //in ra f
		f<<x<<" "; // in ra file f
	}
	cout<<"\nGhi file thanh cong! \n";
	f.close();
}

//void Docfile(fstream& f,char duongdan[20]){
//	int n; // tong so ptu can nhap
//	int x;
//	int j; // dem
//
//	f.open(duongdan,ios::in);
//	if(f==NULL) {
//	printf("\nKhong doc duoc file");
//	exit(0);
//	}
//	else{
//		
//		printf("\n\nTong sl phan tu la: ");
//		f>>n;//doc n
//		printf("%d",n); // in ra man hinh
//		printf("\nCac phan tu la: ");
//
//		j=0;
//		while( j<n){
//			
//			f>>x; // doc phan tu
//			printf("\n%d",x);
//			printf("  ");
//			j++;
//		}
//	f.close();		
//}
//}
void Docfilec(fstream& f,char duongdan[20]){
	int x;

	f.open(duongdan,ios::in);
	if(f==NULL) {
	printf("\nKhong doc duoc file");
	exit(0);
	}
	else{
		
		printf("\nCac phan tu trong day la: ");
		
		while(!f.eof() ){
			
			f>>x; // doc phan tu
			printf("\n%d",x);
			printf("  ");
			
		}
	f.close();		
  }
}
void Taofilengaunhien(fstream& f){
	
	int x, n;	
	
	f.open("filegoc.txt",ios::out); 	
				
		
	if(f==NULL)
	{
		printf("\nKhong tao duoc file.");
		getch();
		exit(0);
	}
									
	printf("Tao file ngau nhien - Hay nhap tong so phan tu, n:"); 	
	scanf("%d", &n);
	
	for (int j=0; j<n; j++)
	{
		
		x = rand()%51;
//		fprintf(f, "%3d", x); 	//ghi x vao file 
		f<<x<<" ";
	}
	f.close();
}

void Chia(fstream& a,fstream& b, fstream& c, int i){
	int	dem, x;

	a.open("filegoc.txt",ios::in); 	
	b.open("day1.txt",ios::out); 	
	c.open("day2.txt",ios::out); 	


	
	while (!a.eof())
	{ 	//chia i phan tu cho b
		dem	= 0;
		while ((dem<i) && (!a.eof()))
		{
//			fscanf(a,"%3d", &x);	//doc tu file a ra, gan x
//			fprintf(b,"%3d", x);	//ghi x qua file b
			a>>x;
			b<<x<<" ";
			dem++;			
		}
		
		//chia i phan tu cho c
			dem	= 0;
		while ((dem<i) && (!a.eof()))
		{
//			fscanf(a,"%3d", &x);	//doc tu file a ra, gan x
//			fprintf(c,"%3d", x);	//ghi x qua file b
			a>>x;
			c<<x<<" ";
			dem++;			
		}
	
	}	
		a.close();
		b.close();
		c.close();	
		
}

void Tron(fstream& a, fstream& b, fstream& c, int i){ 	 //i la so luong ptu (bat dau tu 1 va tang dan)
	int		stop, x, y, l, r;

	a.open("filegoc.txt",ios::out); 	
	b.open("day1.txt",ios::in); 	
	c.open("day2.txt",ios::in); 
	
	

	while ((!b.eof() && !c.eof())){
		l = 0;	//so phan tu cua b da ghi len a
		r = 0;	//so phan tu cua c da ghi len a
		
//		fscanf(b, "%3d", &x);	//doc 1 phan tu tu b gan vao bien x
//		fscanf(c, "%3d", &y);	//doc 1 phan tu tu c gan vao bien y
		b>>x;
		c>>y;
		
		stop = 0;
		
		while ((l!=i) && (r!=i) && (!stop))
		{
			if (x<y)			//ghi file b da doc ra  bien x vao truoc
			{
//				fprintf(a,"%3d", x);		//ghi x ra file	a
				a<<x<<" ";
				l++;
				
				if ((l<i)&& (!b.eof()))		//l<i, chua du i phan tu va chua het file b
//					fscanf(b, "%3d", &x);	//doc tiep 1 phan tu tu b vao bien x, de lan sau lap sau ghi vao a
				 	b>>x;
				else 						//da xong b(du i phan tu hoac ket thuc), ==> ghi c vao a
				{
//					fprintf(a,"%3d", y);	//ghi y ra file	a
					a<<y<<" ";
					r++;
					if (b.eof())			//neu b da ket thuc thi dung viec phan phoi
						stop =1;
				}
			}
			
			else 		//ghi file c da doc ra bien y vao truoc
			{
				
//				fprintf(a,"%3d", y);		//ghi y ra file	a
				a<<y<<" ";
				r++;
				
				if ((r<i)&& (!c.eof()))			//r<i, chua du i phan tu va chua het file b
//					fscanf(c, "%3d", &y);		//doc tiep 1 phan tu tu b vao bien x, de lan sau lap sau ghi vao a
					c>>y;
					
				else 						//da xong c (du p phan tu hoac ket thuc), ==> ghi  b vao a
				{
//					fprintf(a,"%3d", x);			//ghi x ra file	a
					a<<x<<" ";
					l++;
					if (c.eof())			//neu b da ket thuc thi dung viec phan phoi
						stop =1;
				}							
			}	
		}
		//ghi tiep phan con lai cua i phan tu tren b vao a
		while ((l<i)&& (!b.eof()))	
		{
//			fscanf(b, "%3d", &x);
//			fprintf(a,"%3d", x);
			b>>x;
			a<<x<<" ";	
			l++;
		}
		
		//ghi tiep phan con lai cua i phan tu tren c vao a
		while ((r<i)&& (!c.eof()))	
		{
//			fscanf(c, "%3d", &y);
//			fprintf(a,"%3d", y);
			c>>y;
			a<<y<<" ";	
			r++;
		}
				
	}
	
	if(!b.eof())			// neu b con phan tu -> chep phan con lai cua b len a
	{
		
			while (!b.eof())
			{	
//				fscanf(b, "%3d", &x);
//				fprintf(a,"%3d", x);
				b>>x;
				a<<x<<" ";	
			}
	}
	
	
	if(!c.eof())			// neu c con phan tu -> chep phan con lai cua i phan tu tu c len a 
			while (!c.eof())
			{	
//				fscanf(c, "%3d", &y);
//				fprintf(a,"%3d", y);	
				c>>y;
				a<<y<<" ";
			}
	
	a.close();
	b.close();
	c.close();	
	}


int main(){

	int n=5;
	int i=1;

	Ghifile(a,dd);
//	Docfile(a,dd);
//	Taofilengaunhien(a);
		
//	Docfilec(a,dd);
/*	while	(i<n)
	{
		Chia(a,b,c,i);
		
		printf("\n File 1: "); 	
		Docfilec(b,dd1);  
		
		printf("\n File 2: ");
		
		Docfilec(c,dd2);  
		
		Tron(a,b,c,i);
		printf("\n File nguon sau khi tron:");
		Docfilec(a,dd); 
		
		i = i*2;		
	}
	
	
*/	
	getch();
}
