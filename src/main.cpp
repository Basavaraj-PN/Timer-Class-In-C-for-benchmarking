#include <iostream>
#include <chrono>
class Timer{
	public:
		Timer(){

			 m_StartTimepoint = std::chrono::high_resolution_clock::now();
		}
		~Timer(){
			Stop();
		}
		void Stop(){
			auto endTimepoint = std::chrono::high_resolution_clock::now();
			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
			auto end  = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
			auto duration = end - start;
			double ms  = duration * 0.001; 
			std::cout << duration <<" micro second "<<" ( "<<ms<<" ) "<<" mili second "<<std::endl;
		}

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;

};



int main(int argc, char *argv[])
{ 	
	long int value = 0;
	{ 
		Timer timer;
		for(long int i =0;i<=1000000000;i++)
			value += i +2 ;

	
	}
	
}