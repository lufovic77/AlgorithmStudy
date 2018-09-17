#include <iostream>
using namespace std;
class sinCap{
public:	
	void Take() const{
		cout<<"for sinivel"<<endl;
	}
};
class sneezCap{
public:
	void Take() const{
		cout<<"for sneez"<<endl;
	}		
};
class snuffleCap{
public:
	void Take() const{
		cout<<"for snuffle"<<endl;
	}
};

class CONTAC{
	private:
		sinCap sin;
		sneezCap sneez;
		snuffleCap snu;
	public:
		void Take() const{
			sin.Take();
			sneez.Take();
			snu.Take();	 
		}
};
class coldPatient{
	public: 
		void takeCONTAC(const CONTAC & con) const{
			con.Take();
		}
};
int main(){
	coldPatient cold;
	CONTAC con;
	cold.takeCONTAC(con);
}
