#ifndef _IVP_STEP_RK2_H_
#define _IVP_STEP_RK2_H_

#include <fun/fun.h>

namespace ivp {
namespace step {

/**
 * step -> step size - real number
 * f    -> IVP Function, with the form y'(y) = f(t, y(t))
 * ty   -> tuple<real, ytype> where ytype is whatever y(t) returns
 * returns -> tuple<real, ytype> after a single step has been advanced
 **/
auto rk2  = fun::function<3>([] (const auto& step, const auto& f, const auto& ty)
{ 
	auto k1 = step*f(fun::fst(ty),fun::snd(ty));
	auto k2 = step*f(fun::fst(ty)+0.5*step, fun::snd(ty)+0.5*k1);
	return std::make_tuple(fun::fst(ty)+step,fun::snd(ty)+k2);	
});

}
}

#endif
