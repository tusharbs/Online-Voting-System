
#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
using namespace std;
class candidate{
    private:
        string name,rno,post;
    public:
        int candidate_login()
        {
            ifstream file;
            file.open("clogin.txt");
            int flag=0;
            //char u[100],p[100];
            string u,p;
            string l;
            cout<<"Enter username and password: ";
            cin>>u>>p;
            //strcat(u," ");
            //strcat(u,p);
            u=u+" "+p;
            while(getline(file,l))
            {
                if (u.compare(l)==0)
                {
                    cout<<"Verified \n";
                    flag=1;
                    return 1;
                }
            }
            if (flag==0)
            {
                cout<<"Not verified \n";
                return 0;
            }

            file.close();
        }

        void enter_details()
        {
            char name[100],post[100],rno[100],x[100];
            int i;
            cout<<"Enter candidate name: ";
            cin>>name;
            strcpy(x,name);
            cout<<"Enter roll no.: ";
            cin>>rno;
            cout<<"Enter post: ";
            cin>>post;
            ofstream file;
            file.open("candidate.txt",ios::app);
            //file<<name<<"\n";
            //file<<rno<<"\n";
            //file<<post<<"\n";
            strcat(name," ");
            strcat(name,rno);
            strcat(name," ");
            strcat(name,post);
            strcat(name,"\n");
            file<<name;
            file.close();
            file.open("result.txt",ios::app);
            file<<x<<" "<<"0";
            file.close();
        }


        void result_status()
        {
            ifstream file;
            file.open("result.txt");
            string l;
            while(getline(file,l))
            {
                cout<<l<<"\n";
            }
            file.close();
        }
};

class admin{
private:
    string login, password;
public:
    int admin_login()

    {
        ifstream file;
        file.open("admin.txt");
        int flag=0;
        //char u[100],p[100];
        string u,p;
        string l;
        cout<<"Enter username and password: ";
        cin>>u>>p;
        //strcat(u," ");
        //strcat(u,p);
        u=u+" "+p;
        while(getline(file,l))
        {
            if (u.compare(l)==0)
            {
                cout<<"Verified \n";
                flag=1;
                return 1;
            }
        }
        if (flag==0)
        {
            cout<<"Not verified \n";
            return 0;
        }

        file.close();
    }


    void add_candidate()

    {
        string name,post,rno,x;
        cout<<"Enter candidate name: ";
        cin>>name;
        x=name;
        cout<<"Enter roll no.: ";
        cin>>rno;
        cout<<"Enter post: ";
        cin>>post;
        ofstream file;
        file.open("candidate.txt",ios::app);
        //file<<name<<"\n";
        //file<<rno<<"\n";
        //file<<post<<"\n";
        name=name+" "+rno+" "+post+"\n";
        //strcat(name," ");
        //strcat(name,rno);
        //strcat(name," ");
        //strcat(name,post);
        file<<name;
        file.close();
        file.open("result.txt",ios::app);
        file<<x<<" "<<"0";
        file.close();
    }


    void del_candidate()

    {
        string name,post,rno,l;
        cout<<"Enter candidate name: ";
        cin>>name;
        //strcat(name," ");
        //strcat(name,rno);
        //strcat(name," ");
        //strcat(name,post);
        ifstream file;
        ofstream file1;
        file.open("candidate.txt");
        file1.open("c1.txt");
        while(getline(file,l))
        {
            if (l.find(name)==-1)
                file1<<l<<"\n";
        }
        file.close(); file1.close();
        file1.open("candidate.txt");
        file.open("c1.txt");
        while(getline(file,l))
        {
            file1<<l<<"\n";
        }
        file.close();
        file1.close();

        file.open("result.txt");
        file1.open("c1.txt");
        while(getline(file,l))
        {
            if (l.find(name)==-1)
                file1<<l<<"\n";
        }
        file.close(); file1.close();
        file1.open("candidate.txt");
        file.open("c1.txt");
        while(getline(file,l))
        {
            file1<<l<<"\n";
        }
        file.close();
        file1.close();

    }


    void display_candidate()

    {
        ifstream file;
        int len,i;
        file.open("candidate.txt");
        string l;
        while(getline(file,l))
        {
            len=l.length();
            for(i=0;i<len;i++)
            {
                if(l[i]==' ')
                    cout<<"\n";
                else
                    cout<<l[i];
            }
            cout<<"\n \n";
        }
        file.close();
    }


    void display_voterlist()

    {
        ifstream file;
        int len,i;
        file.open("voter.txt");
        string l;
        while(getline(file,l))
        {
            len=l.length();
            for(i=0;i<len;i++)
            {
                if(l[i]==' ')
                    cout<<"\n";
                else
                    cout<<l[i];
            }
            cout<<"\n \n";
        }
        file.close();
    }


    void display_result()

    {
        ifstream file;
        file.open("result.txt");
        string l;
        while(getline(file,l))
        {
            cout<<l;
            cout<<"\n \n";
        }
        file.close();

    }


    int voter_verification()

    {
        ifstream file;
        file.open("vlogin.txt");
        int flag=0;
        //char u[100],p[100];
        string u,p;
        string l;
        cout<<"Enter username and password: ";
        cin>>u>>p;
        //strcat(u," ");
        //strcat(u,p);
        u=u+" "+p;
        while(getline(file,l))
        {
            if (u.compare(l)==0)
            {
                cout<<"Verified \n";
                flag=1;
                return 1;
            }
        }
        if (flag==0)
        {
            cout<<"Not verified \n";
            return 0;
        }

        file.close();
    }


    void result_status()

    {
        ifstream file;
        file.open("result.txt");
        string l;
        while(getline(file,l))
        {
            cout<<l;
        }
        file.close();
    }



    int candidate_verification()

    {
        ifstream file;
        file.open("clogin.txt");
        int flag=0;
        //char u[100],p[100];
        string u,p;
        string l;
        cout<<"Enter username and password: ";
        cin>>u>>p;
        //strcat(u," ");
        //strcat(u,p);
        u=u+" "+p;
        while(getline(file,l))
        {
            if (u.compare(l)==0)
            {
                cout<<"Verified \n";
                flag=1;
                return 1;
            }
        }
        if (flag==0)
        {
            cout<<"Not verified \n";
            return 0;
        }

        file.close();
    }

};

class voter
{
private:
    string username,password,rollno;
public:

        int voter_login()
    {
        ifstream file;
        file.open("vlogin.txt");
        int flag=0;
        //char u[100],p[100];
        string u,p;
        string l;
        cout<<"Enter username and password: ";
        cin>>u>>p;
        //strcat(u," ");
        //strcat(u,p);
        u=u+" "+p;
        while(getline(file,l))
        {
            if (u.compare(l)==0)
            {
                cout<<"Verified \n";
                flag=1;
                return 1;
            }
        }
        if (flag==0)
        {
            cout<<"Not verified \n";
            return 0;
        }

        file.close();
    }

    void display_candidate()

    {
        ifstream file;
        int len,i;
        file.open("candidate.txt");
        string l;
        while(getline(file,l))
        {
            len=l.length();
            for(i=0;i<len;i++)
            {
                if(l[i]==' ')
                    cout<<"\n";
                else
                    cout<<l[i];
            }
            cout<<"\n\n";
        }
        file.close();
    }

    void cast_vote()

    {
        string name,l;
        char x[3],a[3],y;
        int i,len,j,c=0,z,k=0;
        fstream file,file1;
        file.open("result.txt");
        file1.open("temp.txt");
        cout<<"Enter candidate name: ";
        cin>>name;
        while(getline(file,l))
        {
            if(l.find(name)!=-1)
            {

                len=l.length();
                for(i=0;i<len;i++)
                    if(l[i]==' ')
                        break;
                j=i+1;
                for(i=j;i<len;i++)
                {
                    x[i-j]=l[i];
                }

                len=len-j;
                for(i=len-1;i>=0;i--)
                {
                    c=c+pow(10,(len-1-i))*(x[i]-48);
                }
                c++;
                cout<<c<<"\n";
                while(c)
                {
                    z=c%10;
                    c=c/10;
                    y=z+48;
                    a[k]=y;
                    k++;
                }
                for (i=0;i<len/2;i++)
                {
                    y=a[i];
                    a[i]=a[len-i-1];
                    a[len-i-1]=y;
                }
            }
        }
        file.close();
        file1.close();
        file.open("result.txt");
        file1.open("c1.txt");
        while(getline(file,l))
        {
            if(l.find(name)!=-1)
            {

                file1<<name<<" ";
                for(i=0;i<len;i++)
                    file1<<a[i];
                file1<<"\n";
            }
            else
                file1<<l<<"\n";

        }
        file.close();
        file1.close();
        file.open("result.txt");
        file1.open("c1.txt");
        while(getline(file1,l))
        {
            file<<l<<"\n";
        }
        file.close();
        file1.close();


    }
};

int main()
{
    int c,c1;
    cout<<"Your options are: \n";
    cout<<"1. Admin login \n";
    cout<<"2. Candidate login \n";
    cout<<"3. User login \n";
    while(1)
    {
        cin>>c;
        if (c==1)
        {
            admin a;
            if(a.admin_login())
            {
                cout<<"Your options are: \n";
                cout<<"1. Add candidate \n";
                cout<<"2. Del candidate \n";
                cout<<"3. Display candidate \n";
                cout<<"4. Display voters \n";
                cout<<"5. Display result \n";
                cout<<"6. Logout \n";
                while(1)
                {
                    cin>>c1;
                    if (c1==1)
                        a.add_candidate();
                    if (c1==2)
                        a.del_candidate();
                    if (c1==3)
                        a.display_candidate();
                    if (c1==4)
                        a.display_voterlist();
                    if (c1==5)
                        a.display_result();
                    if (c1==6)
                        break;
                }
            }

        }

        else if (c==2)
        {
            candidate a;
            if(a.candidate_login())
            {
                cout<<"Your options are: \n";
                cout<<"1. Enter details \n";
                cout<<"2. Show result \n";
                cout<<"3. Logout \n";
                while(1)
                {
                    cin>>c1;
                    if (c1==1)
                        a.enter_details();
                    if (c1==2)
                        a.result_status();
                    if (c1==3)
                        break;
                }
            }
        }

        else if (c==3)
        {
            voter a;
            if(a.voter_login())
            {
                cout<<"Your options are: \n";
                cout<<"1. Display candidate \n";
                cout<<"2. Cast vote \n";
                cout<<"3. Logout \n";
                while(1)
                {
                    cin>>c1;
                    if (c1==1)
                        a.display_candidate();
                    if (c1==2)
                        a.cast_vote();
                    if (c1==3)
                        break;
                }
            }
         }

         else
            break;
    }
    return 0;

}

