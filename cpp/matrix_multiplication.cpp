#include<iostream.h>
#include<fstream.h>
#include<conio.h>

class matrix{ int row,col;
		int **mat;
		public: matrix(){}

		 matrix(int r,int c)

		 { row=r;
		   col=c;
		   mat= new int *[row];
		   for (int i=0;i<row;i++)
		    mat[i]= new int[col];
		   }
	   //	int returnrow(){ return row;}
		int returncol(){return col;}


		matrix operator *( matrix a)
		{  matrix temp(row,col);

		   if(row==(a.returncol()))
		   for(int t=0;t<row;t++)
		    for(int x=0;x<col;x++)
		     temp.mat[t][x]+=(mat[t][x])*(a.mat[t][x]);

		   return (temp);
		}



		   friend ostream & operator << (ostream & out, matrix g);
		   friend istream & operator >> (istream & in, matrix g);


	   /*	void display()
		{    for(int k=0;k<row;k++) \
		    {cout<<endl;
		     for(int l=0;k<col;l++)
		       cout<<mat[k][l];
		    }
		   }       */

};
  ostream & operator << (ostream &out, matrix g)
		  {   for(int k=0;k<g.row;k++) \
		    {cout<<endl;
		     for(int l=0;l<g.col;l++)
		       out<<g.mat[k][l]<<"  " ;
		    }

		   }
  istream & operator >> (istream &in, matrix g)
		  {   for(int k=0;k<g.row;k++) \
		    {
		     for(int l=0;l<g.col;l++)
		       in>>g.mat[k][l];
		    }
		    cout<<endl;

		   }

int main(){
clrscr();
int r,c;
cout<<"Enter the dimensions for first matrix\n ";
cin>>r>>c;
 matrix m(r,c);
 cin>>m;
 cout<<m;
cout<<"\nEnter the dimension for second matrix";
cin>>r>>c;
matrix b(r,c);
cin>>b;
cout<<b;
matrix l(r,c);
cout<<"\n\nResult";
l=b*m;
cout<<l;


getch();
return 0;
}
