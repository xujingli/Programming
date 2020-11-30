#include "main.h"

#ifdef BA3    
              // ��main.h�и��� 
//#define _FILE_

#define P6   
             //  p1 ɾ������
			 //  p2 ���м������� 
			 //  P3 �������� 
             //  p4 ���ֱ������� 
             //  p5 fatmouse' trade
             //  p6 moving table 
             //  p7 ������� 
             //  p8 Northcott Game

#define STL  // ����STL���� 
       
#ifdef P1
///////////////ɾ������///////////////// 

#define MAXL  240

#ifndef STL

void del(char *str, int i)
{
    int j;
    for(j=i;j<strlen(str);j++)
    {
        str[j]=str[j+1];
    }    
}    

int main(int argc, char *argv[])
{  
  char *str=new char[240];
  int s, i=0;
  cout<<"str=";
  cin>>str;
  cout<<"s=";
  cin>>s;
  for(;s>0;--s)
  {
      while(i<strlen(str) && str[i]<=str[i+1])++i;
      del(str,i);      
      i=i>0?i-1:0;
  } 
  while(str[0]=='0' && strlen(str)>1)
  	del(str,0);
  
  cout<<str<<endl;
       
  system("PAUSE");	
  return 0;
}

#else

void del(string &str, int i)
{
    int j;
    for(j=i;j<str.length();j++)
    {
        str[j]=str[j+1];
    }    
}    

int main(int argc, char *argv[])
{  
  string str;  
  int s, i=0;
  cout<<"str=";
  cin>>str;
  cout<<"s=";
  cin>>s;
  for(;s>0;--s)
  {
      while(i<str.length() && str[i]<=str[i+1])++i;
      del(str,i); 
      i=i>0?i-1:0;     
  }
  
  while(str[0]=='0' && str.length()>1)
  	del(str,0);
  cout<<str<<endl;
       
  system("PAUSE");	
  return 0;
}  

#endif 

#endif

#ifdef P2
////////////////// ���м�������///////////////
/*
�����������ںڰ���д��n���������ų�һ�����У��������²�����ÿ�β�ȥ������������a��b��
Ȼ���������м���һ��a��b+1�������ȥֱ���ڰ���ʣ��һ�����������а����ֲ�����ʽ���õ�
�����У����ļ�Ϊmax����С�ļ���min��������еļ����Ϊm=max-min�� 
*/ 
//��������a��ǰn��Ԫ�����������Ԫ�ص��±� 
void max2(int a[], int n, int &m1, int &m2)
{
    int j;
    if(a[0]>=a[1])
    	m1=0, m2=1;
   	else
   		m1=1, m2=0;
    for(j=2; j<n;j++)
    {
        if(a[j]>a[m1])
        	m2=m1, m1=j;
       	else if(a[j]>a[m2])
       		m2=j;
    }    
    	
}    
//���㼫�����Сֵ 
int calculatemin(int a[], int n)
{	
    int m1, m2;
    while(n>1)
    {
        max2(a, n, m1, m2);
        a[m1]=a[m1]*a[m2]+1;
        a[m2]=a[n-1];
        n=n-1;
    }    
    return (a[0]);
} 
//��������a��ǰn��Ԫ������С����Ԫ�ص��±�  
void min2(int a[], int n, int &m1, int &m2)
{
    int j;
    if(a[0]<=a[1])
    	m1=0, m2=1;
   	else
   		m1=1, m2=0;
    for(j=2; j<n;j++)
    {
        if(a[j]<a[m1])
        	m2=m1, m1=j;
       	else if(a[j]<a[m2])
       		m2=j;
    }
}
 //���㼫������ֵ    
int calculatemax(int a[], int n)
{	
    int m1, m2;
    while(n>1)
    {
        min2(a, n, m1, m2);
        a[m1]=a[m1]*a[m2]+1;
        a[m2]=a[n-1];
        n=n-1;
    }    
    return (a[0]);
} 
 
int main(int argc, char *argv[])
{  
  int j, n, a[100], b[100], max, min;
  ifstream F;
  F.open("input1.dat");
  cout<<"How many data?"<<endl;
  cin>>n;  
  for(j=0; j<n; j++)
  {
  	F>>a[j];
  	b[j]=a[j];
  }
  min=calculatemin(a,n);
  max=calculatemax(b,n);
  cout<<"max-min="<<max-min<<endl;
    	
  F.close();
  system("PAUSE");	
  return 0;
}  

#endif 

////////////////////������������///////////////////////

#ifdef P3

int main(int argc, char *argv[])
{  
  int a, b, c;
  cout<<"input element:";
  cin>>a;
  cout<<"input denominator:";
  cin>>b;
  if(a>=b)
    cout<<"input error"<<endl;
  else if(a==1 || b%a==0)
  	cout<<a<<'/'<<b<<'='<<1<<'/'<<b/a<<endl;
  else
  {
      while(a!=1)
      {
          c=b/a+1;
          a=a*c-b;
          b=b*c;
          cout<<"1/"<<c;
          if(a>1)
             cout<<'+';
          if(b%a==0 || a==1)
     	  {
     	      cout<<"1/"<<b/a;
     	      a=1;
     	  }    
      } 
      cout<<endl;   
  }    
  system("PAUSE");	
  return 0;
}  

#endif 

#ifdef P4

///////////////���ֱ�������///////////////

#define MAXN 1000
struct node
{
    int k;  //��Ʒ�ı�� 
    float w,v,vper;  //��������ֵ��ÿ����ֵ 
}; 

//////����������Ʒÿ����ֵ�ݼ����õ���Ʒ���кϲ� 
void Merge(node list[],int p,int q, int r)
{
    node lt[MAXN];
    int i=p,j=q+1,t=p;
    while(t<=r)
    {
        if(i<=q && ( j>r || list[i].vper>=list[j].vper) )
        	lt[t]=list[i], ++i;
        else
        	lt[t]=list[j], ++j;
        ++t;      
    } 
    for(i=p; i<=r;i++)
    	list[i]=lt[i];   
} 

void Sort(node list[], int m, int n)  // �ϲ����� 
{
    int t;
    if(m!=n)
    {
        t=(m+ n - 1)/2;
        Sort(list, m, t);
        Sort(list, t+1, n);
        Merge(list, m, t, n);
    }    
}          
 int main(int argc, char *argv[])
{  
 	ifstream F;
 	float W, V;   //������Ʒ�������������������ͼ�ֵ 
    const int N=4;			//ʵ�������
    int i;
    
    node List[N];
    
    F.open("input.dat");
    F>>W>>V;
    
    for(i=0; i<N; i++)
    {
        F>>List[i].w>>List[i].v;
        List[i].k=i;
        List[i].vper=List[i].v/List[i].w;
    }
    int K=0;
    Sort(List, 0, N-1);
    
    V=0, i=0;
    cout<<"Num"<<'\t'<<"Weight"<<'\t'<<"value"<<endl;
    
    while(W>List[i].w)
    {
        W=W-List[i].w;
        V=V+List[i].v;
        cout<<List[i].k<<'\t'<<List[i].w<<'\t'<<List[i].v<<endl;
        i++;
    } 
    V=V+W*List[i].vper;
    cout<<List[i].k<<'\t'<<W<<'\t'<<W*List[i].vper<<endl;      
       
    F.close();
    system("PAUSE");	
    return 0;
}



#endif

////////////////fatmouse' trade ///////////////////////
#ifdef P5

int main(int argc, char *argv[])
{
    int m;
     int n;    
     int jav[1001];    
     int fat[1001];    
     double v[1001];    
     int jtemp;    
     int ftemp;    
     double vtemp;    
     double sum;
    
     int i;    
     int j;
     
     ifstream F;
     F.open("input3.dat");
     F>>m>>n;
    
     while(!(n==-1&&m==-1))    
     {    
        for(i=0;i<n;i++)    
        {    
             F>>jav[i]>>fat[i];    
             v[i]=(double)jav[i]/fat[i];
        }
        for(i=0;i<n;i++)     // ��V��jav�������� 
         for(j=i+1;j<n;j++)
          if(v[j]>v[i])
          {
               vtemp=v[i];
               v[i]=v[j];   
               v[j]=vtemp;
               
               jtemp=jav[i]; 
               jav[i]=jav[j]; 
               jav[j]=jtemp;
               
               ftemp=fat[i];
               fat[i]=fat[j];
               fat[j]=ftemp;
          }
         sum=0;
         for(i=0;i<n;i++)
         {
             if(m>fat[i])
             {
                 sum=jav[i]+sum;
                 m=m-fat[i];
             } 
             else
             {
                 sum=sum+v[i]*m;
                 break;
             }
         }
         std::cout.precision(3); 
         cout<<setiosflags(ios::fixed)<<sum<<endl;
         F>>m>>n;
     }
     
    system("PAUSE");	
    return 0;

}

#endif 


////////////////////// Moving table /////////////// 
#ifdef P6

#ifdef _FILE_
#include<iostream>
using namestd;
int main(int argc, char *argv[]) 
{ 
    int t,i,j,N,P[200];
    int s,d,temp,k,min; 
    ifstream F;
    F.open("input4.dat"); 
    F>>t; 
    for(i=0;i<t;i++) 
    { 
         for(j=0;j<200;j++) 
              P[j]=0; 
         F>>N; 
  	    for(j=0;j<N;j++) 
        { 
           F>>s>>d; 
           s=(s-1)/2; 
           d=(d-1)/2;
           if(s>d) 
           { 
               temp=s; 
               s=d; 
               d=temp; 
           } 
           for(k=s;k<=d;k++) 
              P[k]++; 
        } 
         min=-1;     //  ����ص��� 
         for(j=0;j<200;j++) 
            if(P[j]>min)   min=P[j]; 
         cout<<min*10<<endl; 
      } 
      
    F.close(); 
   system("PAUSE");
   return 0; 
} 

#else
#include<iostream>
using namespace std;
int main(int argc, char *argv[]) 
{ 
    int t,i,j,N,P[200];
    int s,d,temp,k,min; 
   
    cin>>t; 
    for(i=0;i<t;i++) 
    { 
         for(j=0;j<200;j++) 
              P[j]=0; 
         cin>>N; 
  	    for(j=0;j<N;j++) 
        { 
           cin>>s>>d; 
           s=(s-1)/2; 
           d=(d-1)/2;
           if(s>d) 
           { 
               temp=s; 
               s=d; 
               d=temp; 
           } 
           for(k=s;k<=d;k++) 
              P[k]++; 
        } 
         min=-1;     //  ����ص��� 
         for(j=0;j<200;j++) 
            if(P[j]>min)   min=P[j]; 
         cout<<min*10<<endl; 
      }       
  
   system("PAUSE");
   return 0; 
} 
#endif

#endif

///////////////////// ������� /////////////// 
#ifdef P7

// ��c�е�Ԫ���������� 
void sort(int *c, int n)
{
     int i, j, t;
     for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        {
            if(c[i]>c[j])
                t=c[i], c[i]=c[j], c[j]=t; 
        }       
} 

int main()   
{   
    int n,i; 
    ifstream F;
    F.open("input5.dat");
    F>>n;  
    while (n)   
    {   
        int *tian = new int[n];   
        int *king = new int[n];   
           
        for (i = 0; i < n; i++)   
            F>>tian[i];   
        for (i = 0; i < n; i++)   
            F>>king[i];   
           
        sort(tian,n);   
        sort(king,n);   
        int st = n-1;   
        int sk = n-1;   
        int et = 0;   
        int ek = 0;   
        int mon = 0;   
           
        for (i = 0; i < n; i++)   
        {   
            if (tian[st] > king[sk])   //��������� �� ���������� ��  ��ƥ������� 
            {   
                mon++;   
                st--;   
                sk--;   
            }   
            else if (tian[st] < king[sk])   // ��������� �� ���������� �� ������������������������� 
            {   
                mon--;   
                sk--;   
                et++;   
            }   
            else  // ��������� �� ���������� ���� 
            {   
                if (tian[et] > king[ek])   // ����������� �� ������������ ��  �����Ǳ��� 
                {   
                    mon++;   
                    et++;   
                    ek++;   
                }   
                else if (tian[et] < king[ek])   // ����������� �� ������������ ��  ��������������������������� 
                {   
                    mon--;   
                    et++;   
                    sk--;   
                }   
                else  // ����������� �� ������������ ����  ��������������������������� 
                {   
                    if (tian[et] != king[sk])   //  ����������� �� ���������� ������
                        mon--;   
                    et++;   
                    sk--;   
                }   
            }   
        }   
           
        cout<<mon*200<<endl;
        F>>n; 
    }
    F.close(); 
     system("PAUSE");   
    return 0;   
}  

#endif


/////////////////////// Northcott Game ////////////////
#ifdef P8

int main(int argc, char *argv[])
{  
 	ifstream F;
  	int m, n, i, move;
    int *b, *w, *flag;    
    F.open("input6.dat");
    F>>m>>n;
    while(!F.eof() )
    {
        move=0;				// �ڷ����ƶ� 
        b=new int[m];
        w=new int[m];
        flag=new int[m];
        for(i=0; i<m; i++)
        {
        	F>>b[i]>>w[i];
        	if(b[i]<w[i])   // �ڷ��ڰ׷������ 
        		flag[i]=-1;
       		else			// �ڷ��ڰ׷����Ҳ� 
       			flag[i]=1;
       	}   	
       	while(1)
       	{
       	    for(i=0; i<m; i++)
       	    {
       	        if(abs(b[i]-w[i])>1)
       	        {
       	            if(!move)
       	            {
       	            	b[i]=b[i]-(abs(b[i]-w[i])-1)*flag[i];
       	            	move=1;
  	            	}   	
  	            	else
  	            	{
  	            		w[i]=w[i]+(abs(b[i]-w[i])-1)*flag[i];
  	            		move=0;
  	                }  		
          		    break;
                }     
       	        
       	    }
            if(i==m)
            {
                if(!move) cout<<"BAD LUCK!"<<endl;
                else      cout<<"I WIN!"<<endl;
                break;
            }        
       	} 
       	
       	
       	delete []b;
       	delete []w;
       	F>>m>>n;       
        
    }    
    
    F.close();
    system("PAUSE");	
    return 0;
}

#endif 

#endif
