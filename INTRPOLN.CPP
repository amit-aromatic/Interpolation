#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include"graphics.cpp"
#include"stats.cpp"

void findpolynomial(int ,float [],float [],float []);
void findsumprodroots_with_sign(int ,float [] ,float []);

void main()
{
float x[50],y[50],askd,res,p;
int n,i,j,k;
char a;

//------------------------------ input
clrscr();
a='a';

printf("                              INTERPOLATION \n");
for(i=0;i<80;i++)
printf("Ä");
printf("Enter no. of entries (max 50) :");
scanf("%d",&n);


for(i=0;i<n;i++)
{
printf("x%d : ",i+1);
scanf("%g",&x[i]);
printf("y%d : ",i+1);
scanf("%g",&y[i]);
printf("\n");
}

//-------------------------------------- acknowledgement and input

cout<<"\ni              xi              yi\n\n";

for(i=0;i<n;i++)
{
cout<<i+1<<"              "<<x[i]<<"              "<<y[i]<<endl;
if((i+1)%24==0) getch();
}



//-------------------------------------- processing and output
int repeat=1;
while(repeat)
{

repeat=0;

float start,end,step;

cout<<"\nEnter start of interval   : ";
cin>>start;

cout<<"\nEnter end   of interval   : ";
cin>>end;

cout<<"\nEnter step between points : ";
cin>>step;

int count=1;
for(askd=start;askd<=end;askd+=step,count++)
 {
  res=0.0;
  for(i=0;i<n;i++)
   {
    p=1.0;
    for(j=0;j<n;j++)
      {
       if(j!=i)
	{
	 p*=((askd-x[j])/(x[i]-x[j]));
	}
      }
    res+=p*y[i];
  }

 if(count%20==0) getch();

 printf("\n x = %12.3g            y = %12.3g",askd,res);
}
// find polynomial if degree<=10

if(n>1 && n<=11)
 {
  cout<<"\nPress any key to see polynomial...";
  getch();

  float cof[11];
  findpolynomial(n,x,y,cof);
  cout<<endl;
  hline();
  cout<<"\nThe polynomial is : \n";
  for(i=0;i<n;i++)
   {
     cout<<"\nPower of x : "<<n-i-1<<"    Coefficient : "<<cof[i];
   }
  cout<<endl;
 }

ag1:

cout<<"\n Verify or Modify INPUT Data ? y/n\n"
    <<">";

scanf(" %c",&a);

switch(a)
{
 case 'y':
 case 'Y':

  int temp;
     cout<<"\nPress any key to see current values...";
     getch();
     clrscr();
     cout<<"Srno.		x  		       y\n";
     for(i=0;i<n;i++)
      {
       cout<<i+1<<"		"<<x[i]<<"		"<<y[i]<<endl;
       if( (i+1%22==0) ) getch();
      }
     cout<<"\nEnter the serial no. of entry to be modified : ";
     cin>>temp;
     cout<<"Enter new value of x : " ;
     cin>>x[temp-1];
     cout<<"Enter new value of y : ";
     cin>>y[temp-1];

   repeat=1;
   break;

 case 'n':
 case 'N':
     break;

 default:
  cout<<"\nERROR !!!";
  goto ag1;
}
}//while(repeat) loop ends

cout<<"\nPress any key to exit...";
getch();

 cbab();

}// main ends
/***********************************************************************/

void findpolynomial(int n,float x[],float y[],float cof[])
{
 int i,j,k;
 float p,roots[10],sumprodroots_with_sign[11];
 //sumprodroots_with_sign array is not only sum of products of roots to be used
 //but also the coeff. of highest degree term (ie. 1 )

 for(i=0;i<n;i++)
  {
   cof[i]=0;
   roots[i]=0;
  }

// cof[0]=1;


 for(i=0;i<n;i++)
  {
    p=1.0;

    for(j=0;j<n;j++)
      {
       if(j!=i)
	{
	 p*=1/(x[i]-x[j]);
	}
      }
    p*=y[i];

    for(j=0,k=0;j<n;j++)
      {
       if(j!=i)
	{
	 roots[k++]=x[j];
	}
      }

    findsumprodroots_with_sign(n-1,roots,sumprodroots_with_sign);

    for(j=0;j<n;j++)
      {
       cof[j]+=sumprodroots_with_sign[j]*p;
      }
  }
return;
}
/*************************************************************************/

void findsumprodroots_with_sign(int _n,float roots[] ,
				float sumprodroots_with_sign[])
{
 //    _n=n-1

 int i,i1,j,k,address[10][300][10],negsign;
 float p,s;

 combinate( _n ,address);

 sumprodroots_with_sign[0]=1;
 negsign=1;

 for(i1=1, i=0;         i1<= _n ;     i1++, i++    )
  {
   s=0;

   for( j=0;j<ncr( _n,i1 );j++)
    {
     p=1.0;
     for( k=0;k<i1;k++)
      {
       p*=roots[ address[i][j][k] -1 ];     // note '-1'. see cmbntrcs.cpp for explanation
      }
     s+=p;
    }
   // determination of sign
   if(negsign)
    {
     s=-1*s;
     negsign=0;
    }
   else
    {
     negsign=1;
    }

   sumprodroots_with_sign[i1]=s;

  }

 return;
}
