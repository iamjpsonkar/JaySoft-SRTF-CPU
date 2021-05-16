#include<iostream>

using namespace std;
int main()
{
    int a[10],b[10],x[10];
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    
    double avg=0,tt=0,end;

    // cout<<"\nEnter the number of Processes: ";  //input
    // cin>>n;
    n=4;
    int grantcharttime[n];
    int grantchartjob[n];
    for(int i=0;i<n;i+=1)
    {
      grantcharttime[i]=-1;
      grantchartjob[i]=-1;
    }

    // for(i=0; i<n; i++)
    // {
    //     cout<<"\nEnter arrival time of process "<<(i+1)<<": ";  //input
    //     cin>>a[i];
    // }
    a[0]=0;
    a[1]=1;
    a[2]=2;
    a[3]=4;

    // for(i=0; i<n; i++)
    // {
    //     cout<<"\nEnter burst time of process "<<(i+1)<<": ";  //input
    //     cin>>b[i];
    // }

    b[0]=5;
    b[1]=3;
    b[2]=4;
    b[3]=1;


    for(i=0; i<n; i++)
        x[i]=b[i];

    b[9]=9999;
    for(time=0; count!=n; time++)
    {
        cout<<endl<<"At Time "<<time<<" Arrived Remaining Jobs Are: "<<endl;
        cout<<"Process"<<"\tRemaining Time"<<endl;
        for(int kk=0;kk<n;kk+=1)
        {
          if(a[kk]<=time && b[kk]>0)
          {
            cout<<"\tp"<<kk+1<<"\t\t"<<b[kk]<<endl;
          }
        }
      
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;
        cout<<endl<<"Shortest Remaining Time Job : p"<<smallest+1<<", Executing for 1 Second"<<endl;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout<<endl<<endl<<endl<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"\tp"<<i+1<<"\t\t"<<x[i]<<"\t\t\t\t"<<a[i]<<"\t\t\t\t"<<waiting[i]<<"\t\t\t\t"<<turnaround[i]<<"\t\t\t\t"<<completion[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }


    int job[n];
    int Ctime[n];
    int temp;
    int ct=0;   

    for(int i=0;i<n;i+=1)
    {
      temp=i;
      
      for(int j=0;j<n;j+=1)
      {
        if(completion[j]<completion[temp])
        {
          temp=j;
        }
      }
      job[i]=temp;
      Ctime[i]=completion[temp];
      completion[temp]=99999;
    }

    cout<<endl<<"Grant Chart: "<<endl<<endl;
    cout<<"Start";
    for(int i=0;i<n;i+=1)
      cout<<"\t\tp"<<job[i]+1;
    cout<<endl;
    cout<<"\t"<<0;
    for(int i=0;i<n;i+=1)
      cout<<"\t\t"<<Ctime[i];
    

    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;
}


/*

4
0
1
2
4
5
3
4
1




*/