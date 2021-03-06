#ifndef PHYSX_CORE_ACTOR_REMOTE_HPP
#define PHYSX_CORE_ACTOR_REMOTE_HPP

#include <Nebula/core/actor/Remote.hh>

#include <PhysX/core/actor/base.hpp>
#include <PhysX/core/actor/util/decl.hpp>

namespace phx { namespace core { namespace actor {


	class remote:
		virtual public neb::core::actor::remote,
		virtual public phx::core::actor::base
	{
		public:
			remote(sp::shared_ptr<phx::core::actor::util::parent> parent);

			virtual void		init();
			virtual void		release();
			virtual void		step(neb::core::TimeStep const & ts);



			void		hit();
			void		damage();




			float		health_;

	};


}}}

#endif
