#include "../ivp.h"

using fun::_;

int main(int argc, char** argv)
{
	//Solve the equation y' = y, starting at (t,y) = (0,1) at point t=1. This has the solution y = e^t. 
	auto f = [] (double t, double y) { return y; };
	double final_t = 1.0;
	//auto f = flip * constant
	
	std::cout<<"euler -> "<<fun::map(fun::snd, fun::takeWhile((_<final_t)*fun::fst, 
			ivp::solver::steps(ivp::step::euler(0.1), f,std::make_tuple(0.0,1.0))))<<std::endl;
	std::cout<<"rk2   -> "<<fun::map(fun::snd, fun::takeWhile((_<final_t)*fun::fst,
			ivp::solver::steps(ivp::step::rk2(0.1),   f,std::make_tuple(0.0,1.0))))<<std::endl;
	std::cout<<"rk4   -> "<<fun::map(fun::snd, fun::takeWhile((_<final_t)*fun::fst,
			ivp::solver::steps(ivp::step::rk4(0.1),   f,std::make_tuple(0.0,1.0))))<<std::endl;
}
