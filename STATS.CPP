#include<math.h>

float mean(float a[],int n)  // mean(arrayname,arraysize)
{                             //returns arith. mean of elements of a[]
 float t=0.0;
for(int i=0;i<n;i++)
{
t+=a[i];
}

return (t/n);
}
/**********************************************************************/
float stdev(float a[],int n)   // format same as mean
{                               //returns standard deviation about mean
float t=0.0;
float m=mean(a,n);
for(int i=0;i<n;i++)
{
t+=(a[i]-m)*(a[i]-m);
}

return(sqrt(t/n));
}
/**********************************************************************/
float sumx(float a[],int n)     //format same as mean
{                                //returns äx
float t=0.0;
for(int i=0;i<n;i++)
{
t+=a[i];
}
return(t);
}
/**********************************************************************/
float sumx2(float a[],int n)  //format same as mean
{                               // returns äx square
float t=0.0;
for(int i=0;i<n;i++)
{
t+=a[i]*a[i];
}
return(t);
}
/**********************************************************************/
float sumx3(float a[],int n)      //format same as mean
{                                   //returns ä(x cube)
float t=0.0;
for(int i=0;i<n;i++)
{
t+=a[i]*a[i]*a[i];
}
return(t);
}
/**********************************************************************/
float sumx4(float a[],int n)         //returns ä(x to power 4)
{
float t=0.0;
for(int i=0;i<n;i++)
{
t+=a[i]*a[i]*a[i]*a[i];
}
return(t);
}

/***********************************************************************/
float sumxn(float a[],int c,int n) //sumxn(name,size,power)
{                                    //returns ä(x to power n)
float t=0.0;
for(int i=0;i<c;i++)
{
t+=pow(a[i],n);
}
return(t);
}
/**********************************************************************/
float sumxy(float a[],float b[],int n) //sumxy(name1,name2,size)
{                                       //returns äxy
float t=0.0;
for(int i=0;i<n;i++)
{
t+=a[i]*b[i];
}
return(t);
}
/**********************************************************************/
float sumxyz(float a[],float b[],float c[], int n) //sumxyz(name1,name2,name3,size)
{                                       //returns äxyz
float t=0.0;
for(int i=0;i<n;i++)
{
t+=a[i]*b[i]*c[i];
}
return(t);
}

/**********************************************************************/
float sumpqrs(float a[],float b[],float c[],float d[], int n) //sumpqrs(name1,name2,name3,name4,size)
{                                       //returns äpqrs
float t=0.0;
for(int i=0;i<n;i++)
{
t+=a[i]*b[i]*c[i]*d[i];
}
return(t);
}
/**********************************************************************/
float sumxnym(float a[],float b[],int c,int n,int m)
{             //sumxnym(nameofx,nameofy,their size,powerofx,powerofy)
float t=0.0;          //returns ä(x to power n)(y to power m)
for(int i=0;i<c;i++)
{
t+=pow(a[i],n)*pow(b[i],m);
}
return(t);
}
/**********************************************************************/
float sumxnymzp(float a[],float b[],float c[],int s,int n,int m,int p)
{             //sumxnymzp(nameofx,nameofy,nameofz,their size,powerofx,powerofy,powerofz)
float t=0.0;          //returns ä(x to power n)(y to power m)(z to power p)
for(int i=0;i<s;i++)
{
t+=pow(a[i],n)*pow(b[i],m)*pow(c[i],p);
}
return(t);
}
/**********************************************************************/
float cov(float a[],float b[],int n)    //returns covariance between
{                                        //elements of a & b
float t;
t=(sumxy(a,b,n)/n) - (mean(a,n)*mean(b,n));
return t;
}

/*********************************************************************/
float corcof(float a[], float b[],int n)   //returns coefficient of correlation
{
float t;
t=     ( n*sumxy(a,b,n) -  sumx(a,n)*sumx(b,n) )/
   (sqrt( (n*sumx2(a,n)-pow(sumx(a,n),2))*(n*sumx2(b,n)-pow(sumx(b,n),2)) ));

return t;
}

/*********************************************************************/
float cfrgyonx(float a[],float b[],int n)
{                               //returns correlation coeff. of a on b
float t;
t= (cov(a,b,n)/pow(stdev(b,n),2));
return t;
}



//////////////////////////////////////////////////////////////////////////
///////////////////////// other functions ////////////////////////////////
//////////////////////////////////////////////////////////////////////////



/************************************************************************/

float factorial(int n)

{
 if(n==0||n==1) return (1);
 else return ( float(n*factorial(n-1)) );
}
/**********************************************************************/
int ncr(int n, int r)
{
 return(     factorial(n)/
	 (factorial(r)*factorial(n-r))
       );
}
/**********************************************************************/
//adapted from "cmbntrcs.cpp"

void combinate(int n,int a[][300][10])
{
 int array[10],temp[10];        // n= 10 max.
 int i,j,k,r,tem,m,s,changetemp;

 //***************************** input and initialisations

 for(i=0;i<10;i++)
  {
   array[i]=i+1;
   temp[i]=0;
  }

 for(i=0;i<10;i++)
  for(j=0;j<300;j++)
   for(k=0;k<10;k++)
    a[i][j][k]=0;

//*********************************** processing
 for(r=1,i=0;  r<=n  ;r++,i++)   //i is redundant but is used for clarity (using r is more easy theoretically,using i is more easy for array-filling)
				 // ie. i=r+1
  {

   tem=0;
   changetemp=1;

   for(j=0;j<ncr(n,r);j++)
    {

     if(r==1)
	{
	 for(k=0;k<r;k++)
	  {
	   a[i][j][k]=array[j];
	  }
	}
     else
      {
       if(changetemp)
	{
	 changetemp=0;

	 checknext:

	 if(a[i-1][tem][r-2]==n) { tem++; goto checknext; }

	 for(m=0;m<r-1;m++)
	  {
	   temp[m]=a[i-1][tem][m];
	  }
	 s=array[ temp[m-1]  ];
	}

       temp[r-1]=s++;

       if(s==(n+1))
	{
	 changetemp=1;
	 tem++;
	}

       for(k=0;k<r;k++)
       {
	a[i][j][k]=temp[k];
       }
      }//else
    }//j
  }//i
return;
}//combinate ends

/**************************************************************************/


