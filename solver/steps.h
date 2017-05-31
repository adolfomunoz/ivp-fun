#ifndef _IVP_SOLVER_STEPS_H_
#define _IVP_SOLVER_STEPS_H_

#include <fun/fun.h>

namespace ivp {
namespace solver {

/**
 * stepper -> The stepper method to apply. It must be a function with the following parameters:
 *       stepper(f, ty)
	 * f    -> IVP Function, with the form y'(t) = f(t, y(t))
	 * ty   -> tuple<real, ytype> where ytype is whatever y(t) returns
	 * returns -> tuple<real, ytype> after a single step has been advanced
 * f    -> IVP Function, with the form y'(t) = f(t, y(t))
 * ini  -> initial step, tuple<real, ytype> where ytype is whatever y(t) returns
 * returns -> list of tuple<real, ytype> with all the steps
 **/
auto steps = fun::function<1>([] (const auto& stepper)
{	 return fun::iterate(stepper);		}

}
}

#endif
