#ifndef __NEBULA_CONTENT_ACTOR_PHYSICS_CONTROLLER_HPP__
#define __NEBULA_CONTENT_ACTOR_PHYSICS_CONTROLLER_HPP__

#include <Nebula/core/actor/Base.hh>

namespace neb { namespace core { namespace actor {


	class Controller: public neb::core::actor::base {
		public:
			Controller(sp::shared_ptr<neb::core::actor::util::parent>);
			virtual void		init();
			virtual void		release();
			virtual void		step(neb::core::TimeStep const & ts);
	};
}
}}



#endif

