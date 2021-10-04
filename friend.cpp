#include <iostream>
using namespace std;
class Distance
{
	private:
		int feet;
		int inches;
	public:
		friend void add_via_friend(Distance, Distance, Distance);
		void set_distance()
		{
			cout<<"Enter feet: ";
			cin>>feet;
			cout<<"Enter inches: ";
			cin>>inches;
		}
		void get_distance()
		{
			cout<<"Distance is feet= "<<this->feet<<", inches= "<<this->inches<<endl;
		}
		void add(Distance d1, Distance d2)
		{
			feet = d1.feet + d2.feet;
			inches = d1.inches + d2.inches;
			feet = feet + (inches / 12);
			inches = inches % 12;
		}
};
void add_via_friend(Distance d1, Distance d2, Distance d4){
			d4.feet = d1.feet + d2.feet;
			d4.inches = d1.inches + d2.inches;
			d4.feet = d4.feet + (d4.inches / 12);
			d4.inches = d4.inches % 12;
}

int main()
{
	Distance d1, d2, d3,d4;
	d1.set_distance();
	d2.set_distance();
	d3.add(d1, d2);
	d3.get_distance();
	add_via_friend(d1,d2,d4);
	d4.get_distance();
	return 0;
}