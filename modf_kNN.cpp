# include <iostream>
# include <math.h>

 using namespace std;

 class assignclass
 {
      char *name;
      double aptitude;
      double communication;
      int classvalue;
    public:
      void getdata(char *AA, double a, double c, int cv);
      void putdata(void);
      double studapt(void);
      double studcomm(void);
      int studclass(void);
  };
  void assignclass :: getdata(char *AA, double a, double c, int cv)
  {
  name = AA;
  aptitude = a;
  communication = c;
  classvalue = cv;
  }
  void assignclass :: putdata(void)
  {
   cout<<"Name: "<<name<<"\n";
   cout<<"Aptitude: "<<aptitude<<"\n";
   cout<<"Communication: "<<communication<<"\n";
   if (classvalue == 1)
   cout<<"Class: "<<"Leader"<<"\n";
   else if (classvalue == 2)
   cout<<"Class: "<<"Speaker"<<"\n";
   else
   cout<<"Class: "<<"Worker"<<"\n";
   }
   double assignclass :: studapt(void)
   {
    return(aptitude);
   }
   double assignclass :: studcomm(void)
   {
    return(communication);
   }
   int assignclass :: studclass(void)
   {
    return(classvalue);
   }

   const int size=15;
   int main()
   {
    int i,j,jj,k;
    int l=0,m=0,n=0,min;
    int classv,distcount;
    double apt1,apt2,comm1,comm2;
    double dist[20],distmax[4],dist2[7],distmax2[4];
    double minall;
    assignclass student[size], student2[size-1];
    assignclass studentL[7], studentS[7], studentI[7];
    //Input
    student[0].getdata("A",4.0,7.0,2);
    student[1].getdata("B",8.0,3.0,3);
    student[2].getdata("C",2.0,5.0,2);
    student[3].getdata("D",7.0,2.5,3);
    student[4].getdata("E",8.0,6.0,1);
    student[5].getdata("F",6.0,7.0,1);
    student[6].getdata("G",5.0,4.5,3);
    student[7].getdata("H",2.0,6.0,2);
    student[8].getdata("I",7.0,6.0,1);
    student[9].getdata("J",5.0,3.0,3);
    student[10].getdata("K",3.0,5.5,2);
    student[11].getdata("L",9.0,7.0,1);
    student[12].getdata("M",6.0,5.5,1);
    student[13].getdata("N",6.0,4.0,3);
    student[14].getdata("O",6.0,2.0,3);

    cout<<endl;

    //Printing Data
    for(i=0;i<size;i++)
    student[i].putdata();

    //The Model
    i=0;

    //Selecting Test Data
    cout<<endl<<endl<<i;
    if(i==0)
    for(j=1;j<15;j++)
    student2[j-1]=student[j];
    else if(i!=(size-1))
    {
    for(j=0;j<i;j++)
    student2[j]=student[j];
    for(j=(i+1);j<size;j++)
    student2[j-1]=student[j];
    }
    else
    for(j=0;j<(size-1);j++)
    student2[j]=student[j];

    // Segregating Class
    for(j=0;j<(size-1);j++)
    {
    classv = student2[j].studclass();
    if(classv==1)
    {
    l=l+1;
    studentL[l-1]=student2[j];
    }
    else if(classv==2)
    {
    m=m+1;
    studentS[m-1]=student2[j];
    }
    else
    {
    n=n+1;
    studentI[n-1]=student2[j];
    }
    }

    //Calculating max distance in each class
    //Calculation for Leader
    for(k=1;k<20;k++)
    dist[k]=0.0;
    k=0;
    for(j=0;j<(l-1);j++)
    {apt1 = studentL[j].studapt();
    comm1 = studentL[j].studcomm();
    for(jj=j+1;jj<l;jj++)
    {
    apt2 = studentL[jj].studapt();
    comm2 = studentL[jj].studcomm();
    k=k+1;
    dist[k]=dist[k]+sqrt((apt1-apt2)*(apt1-apt2)+(comm1-comm2)*(comm1-comm2));
    }
    }
    distmax[1]=0.0;
    distcount = l*(l-1)/2;
    for(k=1;k<=distcount;k++)
    if(distmax[1]<dist[k])
    distmax[1]=dist[k];
    for(k=1;k<20;k++)
    dist[k]=0.0;


    //Calculation for Speaker
    k=0;
    for(j=0;j<(m-1);j++)
    {apt1 = studentS[j].studapt();
    comm1 = studentS[j].studcomm();
    for(jj=j+1;jj<m;jj++)
    {
    apt2 = studentS[jj].studapt();
    comm2 = studentS[jj].studcomm();
    k=k+1;
    dist[k]=dist[k]+sqrt((apt1-apt2)*(apt1-apt2)+(comm1-comm2)*(comm1-comm2));
    }
    }
    distmax[2]=0.0;
    distcount = m*(m-1)/2;
    for(k=1;k<=distcount;k++)
    if(distmax[2]<dist[k])
    distmax[2]=dist[k];
    for(k=1;k<20;k++)
    dist[k]=0.0;

    //Calculation for Worker
    k=0;
    for(j=0;j<(n-1);j++)
    {apt1 = studentI[j].studapt();
    comm1 = studentI[j].studcomm();
    for(jj=j+1;jj<n;jj++)
    {
    apt2 = studentI[jj].studapt();
    comm2 = studentI[jj].studcomm();
    k=k+1;
    dist[k]=dist[k]+sqrt((apt1-apt2)*(apt1-apt2)+(comm1-comm2)*(comm1-comm2));
    }
    }
    distmax[3]=0.0;
    distcount = n*(n-1)/2;
    for(k=1;k<=distcount;k++)
    if(distmax[3]<dist[k])
    distmax[3]=dist[k];
    for(k=1;k<20;k++)
    dist[k]=0.0;

    //Calculating max distance of test data in each class
    //Calculation for Leader
    for(k=0;k<7;k++)
    dist2[k]=0.0;
    apt1 = student[i].studapt();
    comm1 = student[i].studcomm();
    for(jj=0;jj<l;jj++)
    {
    apt2 = studentL[jj].studapt();
    comm2 = studentL[jj].studcomm();
    dist2[jj]=dist2[jj]+sqrt((apt1-apt2)*(apt1-apt2)+(comm1-comm2)*(comm1-comm2));
    }
    distmax2[1]=0.0;
    for(k=0;k<l;k++)
    if(distmax2[1]<dist2[k])
    distmax2[1]=dist2[k];
    for(k=0;k<7;k++)
    dist2[k]=0.0;

    //Calculation for Speaker
    for(jj=0;jj<m;jj++)
    {
    apt2 = studentS[jj].studapt();
    comm2 = studentS[jj].studcomm();
    dist2[jj]=dist2[jj]+sqrt((apt1-apt2)*(apt1-apt2)+(comm1-comm2)*(comm1-comm2));
    }
    distmax2[2]=0.0;
    for(k=0;k<m;k++)
    if(distmax2[2]<dist2[k])
    distmax2[2]=dist2[k];
    for(k=0;k<7;k++)
    dist2[k]=0.0;

    //Calculation for Worker
    for(jj=0;jj<n;jj++)
    {
    apt2 = studentI[jj].studapt();
    comm2 = studentI[jj].studcomm();
    dist2[jj]=dist2[jj]+sqrt((apt1-apt2)*(apt1-apt2)+(comm1-comm2)*(comm1-comm2));
    }
    distmax2[3]=0.0;
    for(k=0;k<n;k++)
    if(distmax2[3]<dist2[k])
    distmax2[3]=dist2[k];
    for(k=0;k<7;k++)
    dist2[k]=0.0;

    //Assigning Class Value to Test Data
    for(k=1;k<4;k++)
    {
    cout<<endl<<"distmax["<<k<<"]="<<distmax[k];
    cout<<endl<<"distmax2["<<k<<"]="<<distmax2[k];
    }
    if(distmax2[1]>distmax[1]&&distmax2[2]>distmax[2]&&distmax2[3]>distmax[3])
    {
    if(distmax2[1]==distmax2[2]&&distmax2[2]==distmax2[3])
    for(k=1;k<4;k++)
    distmax2[k]=(distmax2[k]-distmax[k])/distmax[k];
    else if(distmax2[1]==distmax2[2]&&distmax2[2]<distmax2[3])
    {
    distmax2[1]=(distmax2[1]-distmax[1])/distmax[1];
    distmax2[2]=(distmax2[2]-distmax[2])/distmax[2];
    }
    else if(distmax2[1]==distmax2[3]&&distmax2[3]<distmax2[2])
    {
    distmax2[1]=(distmax2[1]-distmax[1])/distmax[1];
    distmax2[3]=(distmax2[3]-distmax[3])/distmax[3];
    }
    else if(distmax2[2]==distmax2[3]&&distmax2[2]<distmax2[1])
    {
    distmax2[2]=(distmax2[2]-distmax[2])/distmax[2];
    distmax2[3]=(distmax2[3]-distmax[3])/distmax[3];
    }
    minall = 15.0;
    for(k=1;k<4;k++)
    {
    cout<<endl<<"distmax["<<k<<"]="<<distmax[k];
    cout<<endl<<"distmax2["<<k<<"]="<<distmax2[k];
    if(minall>distmax2[k])
    {
    minall=distmax2[k];
    min=k;
    }
    }
    }
    else
    {
    for(k=1;k<4;k++)
    {
    if(distmax2[k]>distmax[k])
    distmax2[k]=14.14;
    }
    minall = 14.14;
    for(k=1;k<4;k++)
    {
    if(minall>distmax2[k])
    {
    minall=distmax2[k];
    min=k;
    }
    }
    }
    cout<<endl;
    cout<<"Class Value of Test Data ="<<(i+1)<<" is : "<<min<<endl;
    return 0;
   }

