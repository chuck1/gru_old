#ifndef __GLUTPP_SCENE_REMOTE_H__
#define __GLUTPP_SCENE_REMOTE_H__

#include <vector>

//#include <Nebula/Flag.hh>
//#include <Nebula/util/Map.hh>
//#include <Nebula/util/Shared.hh>

#include <Nebula/util/decl.hpp>

#include <Nebula/core/scene/Base.hh>

//#include <Nebula/config.hh> // Nebula/config.hpp.in
#include <Nebula/gfx/glsl/program.hh>


//#include <Nebula/core/actor/Base.hh>
#include <Nebula/core/actor/Util/Parent.hh>

#include <Nebula/gfx/Camera/View/Base.hh>

//#include <glutpp/shader.h>

#define LIGHT_MAX 20

namespace neb { namespace core {
	namespace scene {
		class remote:
			virtual public neb::core::scene::base
		{
			void				step(neb::core::TimeStep const & ts);

			/** @name convenience functions
			 * @{
			 */
			/** @brief create rigidstatic
			 *
			 * @note typeof returned actor will be determined by final implementation of this
			 *
			 * @warning return actor is not initialized
			 */
			sp::weak_ptr<neb::core::actor::rigidstatic::base>	createActorRigidStaticUninitialized();
			/** @} */

		};
	}
}}

#endif





