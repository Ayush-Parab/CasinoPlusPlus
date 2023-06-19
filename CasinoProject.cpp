#include<iostream>
#include<stdlib.h>

using namespace std;

class Player
{
    private:
    string name;
    int balance;

    public:
    Player();
    Player(string name, int balance);
    void setName(string name);
    void setBalance(int balance);
    string getName();
    int getBalance();

};

class Casino:public Player
{
    private:
    int bidamt;

    public:
    Casino();
    Casino(int bidamt);
    void setBidamt(int bidamt);
    int getBidamt();

};

void setRules()
{
    cout<<"These are the set of rules that you must follow:"<<endl;
    cout<<"1.Bid an amount of chips no more than the current balance."<<endl;
    cout<<"2.If you guess the correct number, you get 10X the chips you bid."<<endl;
    cout<<"3.If you guess the incorrect number, you lose all the chips that you bid."<<endl;
    cout<<endl;
}

string startplaying()
{
    string choice;
    cout<<"Start playing?"<<endl;    
    cout<<"Yes/No:";
    cin>>choice;
    cout<<endl;

    return choice;
}

int main()
{
    Player p;
    Casino c;
    string name,choice;
    int balance;
    int bidamt;
    int random;
    int num;
    int refill;

    cout<<"WELCOME TO THE CASINO"<<endl;
    cout<<endl;

    cout<<"Enter your name:";
    getline(cin,name);
    p.setName(name);
    cout<<"Enter the initial amount:";
    cin>>balance;
    while(balance<=0)
    {
        cout<<"Please enter a valid amount:";
        cin>>balance;
        cout<<endl;
    }
    p.setBalance(balance);
    cout<<endl;

    setRules();

    while(!(choice=="Yes") && !(choice=="yes") && !(choice=="No") && !(choice=="no"))
    {
        choice=startplaying();
    }
    
    if(choice=="Yes" || choice=="yes")
    {
        while(choice=="yes" || choice=="Yes")
        {
            cout<<endl;
            cout<<"Thank you for playing, "<<p.getName()<<endl;
            cout<<"Current balance:"<<p.getBalance()<<endl;
            cout<<endl;
            cout<<"Lets start!"<<endl;
            cout<<endl;
            srand(time(0));
            random=rand()%10;

            cout<<"Enter bid amount:";
            cin>>bidamt;
            while(bidamt>p.getBalance() || bidamt<=0)
            {
                cout<<"Please bid an amount no more than your balance"<<endl;
                cout<<"Current balance:"<<p.getBalance()<<endl;
                cout<<"Enter bid amount:";
                cin>>bidamt;
                cout<<endl;
            }
            c.setBidamt(bidamt);
            cout<<"Your bid is "<<c.getBidamt()<<endl;
            cout<<"Enter a number from 0 to 9:";
            cin>>num;
            cout<<endl;

            if(num==random)
            {
                p.setBalance(p.getBalance()+10*c.getBidamt());
                cout<<"Congratulations!!!";
                cout<<"Current balance:"<<p.getBalance()<<endl;
            }
            else
            {
                p.setBalance(p.getBalance()-c.getBidamt());
                cout<<"Better luck next time"<<endl;
                cout<<"The correct choice was:"<<random<<endl;
                cout<<endl;
            }
            choice.clear();
            cout<<"Continue playing?"<<endl;
            cout<<"Yes/No:";
            cin>>choice;
            cout<<endl;
        
            while(!(choice=="Yes") && !(choice=="yes") && !(choice=="No") && !(choice=="no"))
            {
                cout<<"Invalid entry, try again"<<endl;
                cout<<"Yes/No:";
                cin>>choice;
                cout<<endl;            
            }
        
        
            if(choice=="Yes" || choice=="yes")
            {
                if(p.getBalance()==0)
                {
                    cout<<"Sorry, you ran out of chips"<<endl;
                    cout<<"Please enter 1 if you wish to continue playing and enter 2 if you want to exit:";
                    cin>>refill;

                    if(refill==1)
                    {
                        cout<<"Enter the refill amount:";
                        cin>>balance;
                        while(balance<=0)
                        {
                            cout<<"Please enter a valid amount:";
                            cin>>balance;
                            cout<<endl;
                        }
                        p.setBalance(balance);
                    }
                    else
                    {
                        cout<<"Thank you for playing with us!"<<endl;
                        break;
                    }
                }
            }
            else if(choice=="No" || choice=="no")
            {
                cout<<"Thank you for your time"<<endl;
            }       
        }
    }
    else if(choice=="No" || choice=="no")
    {
        cout<<"Thank you for your time."<<endl;        
    }
    
    return 0;
}


Player::Player()
{
    name="null";
    balance=0;
}

Player::Player(string name, int balance)
{
    setName(name);
    setBalance(balance);
}

void Player::setName(string name)
{
    this->name=name;
}

void Player::setBalance(int balance)
{
    this->balance=balance;
}

string Player::getName()
{
    return name;
}

int Player::getBalance()
{
    return balance;
}

Casino::Casino()
{
    bidamt=0;
}

Casino::Casino(int bidamt)
{
    setBidamt(bidamt);
}

void Casino::setBidamt(int bidamt)
{
    this->bidamt=bidamt;
}

int Casino::getBidamt()
{
    return bidamt;
}