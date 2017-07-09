#ifndef _IVP_SOLVER_STEPS_H_
#define _IVP_SOLVER_STEPS_H_

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
 * ini  -> initial step, tuple<real, ytype> where ytype is whatever y(t) returns
 * returns -> list of tuple<real, ytype, ...> with all the steps
 *        where ... stands for method-specific data that can be ignored
 **/
auto steps = fun::function<2>([] (const auto& stepper, const auto& f)
{	 return fun::iterate(stepper(f));		});

}
}

#endif
