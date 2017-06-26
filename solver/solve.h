#ifndef _IVP_SOLVER_SOLVE_H_
#define _IVP_SOLVER_SOLVE_H_

#include "steps.h"
#include <fun/fun.h>

namespace ivp {
namespace solver {

/**
 * stepper -> The stepper method to apply. It must be a function with the following parameters:
 *       stepper(f, ty)
	 * f    -> IVP Function, with the form y'(t) = f(t, y(t))
	 * ty   -> tuple<real, ytype> ot tuple<real, ytype, ...> where ytype is whatever y(t) returns
	 * returns -> tuple<real, ytype, ...> after a single step has been advanced
	      where ... stands for method-specific required stuff
 * f    -> IVP Function, with the form y'(t) = f(t, y(t))
 * t_ini-> initial t of a real type.
 * y_ini-> initial value of ytype (where ytype is whatever y(t) returns)
 * t_end-> target t, for which the corresponding y is obtained
 * returns -> ytype, the estimated value of y(t_end)
 **/
auto solve = fun::function<5>([] (const auto& stepper, const auto& f, 
		const auto& t_ini, const auto& y_ini, const auto& t_end)
{	
	//This algorithm is not functional because this way becomes more
	//efficient. 
	std::remove_const_t<std::remove_reference_t<decltype(t_ini)>> t, t_ant;
	std::remove_const_t<std::remove_reference_t<decltype(y_ini)>> y, y_ant;

	for (auto step : steps(stepper, f, std::make_tuple(t_ini, y_ini))) {
		std::tie(t,y) = step;
		if (t>t_end) break;
		t_ant=t; y_ant=y;
	}
	return y_ant + (y-y_ant)*(t_end-t_ant);	
});

}
}

#endif
