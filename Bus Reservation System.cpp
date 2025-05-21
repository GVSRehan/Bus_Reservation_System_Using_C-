#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
int p = 0;
class a
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
  void Install_Bus_Information();
  void Reservation();
  void empty();
  void Show_reservation_information();
  void avail();
  void position(int i);
}
bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}
void a::Install_Bus_Information()
{
	cout<<"************************************************"<<endl;
  cout<<"Enter bus no: ";
  cin>>bus[p].busn;
  cout<<endl<<"Enter Driver's name: ";
  cin>>bus[p].driver;
  cout<<endl<<"Arrival time: ";
  cin>>bus[p].arrival;
  cout<<endl<<"Departure: ";
  cin>>bus[p].depart;
  cout<<endl<<"From: ";
  cin>>bus[p].from;
  cout<<endl<<"To: ";
  cin>>bus[p].to;
  cout<<"************************************************"<<endl<<"\t\t\tbus information entered";
  bus[p].empty();
  p++;
}
void a::Reservation()
{
  int seat;
  char number[5];
  top:
  cout<<"************************************************"<<endl;
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
    cout<<"************************************************"<<endl;
  }
void a::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}
void a::Show_reservation_information()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  cout<<"************************************************"<<endl;
  cout<<"Bus no: "<<bus[n].busn
  <<"\nDriver: "<<bus[n].driver<<"\nArrival time: "
  <<bus[n].arrival<<"\nDeparture time: "<<bus[n].depart
  <<"\nFrom: "<<bus[n].from<<"\tTo: "<<
  bus[n].to<<"\n";
  cout<<"************************************************"<<endl;
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}
void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }
void a::avail()
{
  for(int n=0;n<p;n++)
  {
  	cout<<"************************************************"<<endl;
    cout<<"Bus no: "<<bus[n].busn<<endl<<"Driver: "<<bus[n].driver<<endl
    <<"Arrival time:  "<<bus[n].arrival<<endl<<"Departure Time:  "
    <<bus[n].depart<<endl<<"From: "<<bus[n].from<<endl<<"To: "
    <<bus[n].to<<endl;
    cout<<"************************************************"<<endl;
    cout<<"_______________________________________________"<<endl;
    
  }
}
int main()
{
system("cls");
int w;
while(1)
{
//system("cls");
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t1.Install_Bus_Information\n\t\t\t"
  <<"2.Reservation\n\t\t\t"
  <<"3.Show Reservation Information\n\t\t\t"
  <<"4.Buses Available. \n\t\t\t"
  <<"5.Exit";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].Install_Bus_Information();
      break;
    case 2:  bus[p].Reservation();
      break;
    case 3:  bus[0].Show_reservation_information();
      break;
    case 4:  bus[0].avail();
      break;
    case 5:  exit(0);
  }
}
return 0;
}