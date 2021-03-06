#ifndef PHYSX_APP_BASE_HPP
#define PHYSX_APP_BASE_HPP

#include <memory>

#include <PxPhysicsAPI.h>

#include <Nebula/config.hh>

#include <Nebula/app/Base.hh>
#include <Nebula/core/scene/Base.hh>

#include <PhysX/free.hpp>
#include <PhysX/core/scene/util/parent.hpp>

class DefaultErrorCallback:
	public physx::PxErrorCallback
{
	public:
		void reportError(
				physx::PxErrorCode::Enum code,
				char const * message,
				char const * file,
				int line);
};

physx::PxFilterFlags DefaultFilterShader(
		physx::PxFilterObjectAttributes attributes0,
		physx::PxFilterData filterData0,
		physx::PxFilterObjectAttributes attributes1,
		physx::PxFilterData filterData1,
		physx::PxPairFlags& pairFlags,
		const void* constantBlock,
		physx::PxU32 constantBlockSize );

namespace phx { namespace app {


	class base:
		virtual public neb::app::base,
		virtual public phx::core::scene::util::parent
	{
		public:
			friend void phx::init();
		public:
			base();
			void						init();
			void						release();
			
			static sp::shared_ptr<phx::app::base>		global();
			
			
			DefaultErrorCallback 				px_default_error_callback_;
			physx::PxDefaultAllocator 			px_default_allocator_callback_;
			physx::PxFoundation*				px_foundation_;
			physx::PxPhysics*				px_physics_;
			physx::PxProfileZoneManager*			px_profile_zone_manager_;
			physx::PxCooking*				px_cooking_;
			//physx::pxtask::CudaContextManager*		px_cuda_context_manager_;
			physx::PxControllerManager*			px_character_controller_manager_;
		private:
			static sp::shared_ptr<phx::app::base>		g_app_;
	};


}}


#endif
