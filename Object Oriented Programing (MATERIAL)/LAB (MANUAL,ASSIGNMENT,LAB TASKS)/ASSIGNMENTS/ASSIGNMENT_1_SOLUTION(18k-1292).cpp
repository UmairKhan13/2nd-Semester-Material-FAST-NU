/*Task:								         	      			
Aliens exist and have attributes color, lifespan & planet they hail from. So far, two distinct alien races Kryptonian and Saiyan have been found. Both of these alien races are natural warriors and are known to be genuine fighters.
There is another similarity between these races, aggression increases their battle strength & PowerLevelLevelLevelLevelLevelLevel levels. Any "outside source" or a signal to "battle" can trigger their aggression and cause their Power to increase.
However, the Kryptonians are known to be more in control of their power. Their power level never goes above 50000 units. They only protect and don't destroy anything. They have an average lifespan 100 years more than that of the Saiyans.
The Saiyans are more brash and their power levels can reach up to 100000 units when they are triggered and become aggressive. They don't usually protect and only like to destroy. Furthermore, 
the Saiyans can also be of two different types SaiyanBlue & SaiyanRed. When an alien is SaiyanBlue, he can destroy as many as two whole planets with his power. SaiyanRed can destroy a single planet when enraged.
Implement this scenario, while identifying all possible attributes and functions. Test your code by making two Saiyan objects Goku and Vegeta and one Kryptonian object Clark.*/


#include<iostream>
using namespace std;
class Aliens
{
	protected:
	string color;
	double life;
	string planet;
	double strength;
	public:
		Aliens(string c,double l,string p,double s)
		{
			color=c;
			life=l;
			planet=p;
			strength=s;
		}
		Aliens()
		{
			
		}
		virtual void power()
		{
			
		}
		setstrength(double a)
		{
			strength=a;
		}
};
class Saiyans:public Aliens
{
    public:
    	Saiyans(string c,double l,string p,double s):Aliens(c,l,p,s)
    	{
    		
		}
		Saiyans()
		{
			
		}
		
		void PowerLevel()
		{
			int ch;
			cout<<"Enter 1 for outside attack" << " OR "<< "Enter 2 for battle" << endl;
			
			cin >> ch;
			
			if(ch==1)
			{
				strength=90000;
				cout<<"your saiyan is a Saiyan Red"<<endl;
			}
			else if(ch==2)
			{
				strength=100000;
				cout<<"Your Saiyan is a Saiyan blue"<<endl;
			}
		}
		
		void PlanetDestroyed()
		{
			if(strength>=90000 && strength<100000)
			{
				cout<<"one planet Destroyed";
			}
			if(strength>=100000)
			{
				cout<<"two planets Destroyed";
			}
		}
		
		Saiyans operator + (Saiyans add)
		{
			Saiyans fusion;
			fusion.strength=((strength+add.strength)*3);
			return fusion;
		}
		
		strengthget()
		{
			cout<<"strength of Gogeta: " << strength <<endl;
		}
};
class Kryptonian:public Aliens
{
	public:
		Kryptonian(string c,double l,string p,double s):Aliens(c,l,p,s)
    	{
    		
		}
	    void PowerLevel()
		{
			setstrength(48900);
		}	
		void protect()
		{
			cout<<"A Planet is saved by clark" << endl;
		}
};

int main(){

	Saiyans goku("green",99,"Vegeta",90000);
	Saiyans vegeta("darkGreen",78,"Vegeta",100000);
	

	Kryptonian clark("SeaGreen",268,"krypton",48900);
	
	goku.PowerLevel();
	vegeta.PowerLevel();
	clark.PowerLevel();
	
	goku.PlanetDestroyed();
	cout <<" by goku" << endl;

	vegeta.PlanetDestroyed();
	cout <<" by vegeta" << endl;
	
	clark.protect();
	
	Saiyans gogeta;
	gogeta=goku+vegeta;
	gogeta.strengthget();
	
	return 0;
}
