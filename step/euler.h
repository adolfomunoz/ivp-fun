#ifndef _IVP_STEP_EULER_H_
#define _IVP_STEP_EULER_H_

#include <fun/fun.h>

namespace ivp {
namespace step {
/**
 * step -> step size - real number
 * f    -> IVP Function, with the form y'(y) = f(t, y(t))
 * ty   -> tuple<real, ytype> where ytype is whatever y(t) returns
 * returns -> tuple<real, ytype> after a single step has been advanced
 **/
auto euler  = fun::function<3>([] (const auto& step, const auto& f, const auto& ty)
{	return std::make_tuple(fun::fst(ty)+step,fun::snd(ty)+step*f(fun::fst(ty),fun::snd(ty)));	});

}

}
}
