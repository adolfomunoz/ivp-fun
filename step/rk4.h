#ifndef _IVP_STEP_RK4_H_
#define _IVP_STEP_RK4_H_

#include <fun/fun.h>

namespace ivp {
namespace step {

/**
 * step -> step size - real number
 * f    -> IVP Function, with the form y'(y) = f(t, y(t))
 * ty   -> tuple<real, ytype> where ytype is whatever y(t) returns
 * returns -> tuple<real, ytype> after a single step has been advanced
 **/
auto rk4  = fun::function<3>([] (const auto& step, const auto& f, const auto& ty)
{  	
	auto k1 = step*f(fun::fst(ty),fun::snd(ty));
	auto k2 = step*f(fun::fst(ty)+0.5*step, fun::snd(ty)+0.5*k1);
	auto k3 = step*f(fun::fst(ty)+0.5*step, fun::snd(ty)+0.5*k2);
	auto k4 = step*f(fun::fst(ty)+step, fun::snd(ty)+k3);
	return std::make_tuple(fun::fst(ty)+step,fun::snd(ty)+(1.0/6.0)*k1 + (1.0/3.0)*k2 + (1.0/3.0)*k3 + (1.0/6.0)*k4);
});

}
}
