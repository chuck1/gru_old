
#include <Nebula/gfx/Context/Base.hh>

#include <Nebula/config.hh>
//#include <nebula/camera/camera.hpp>
#include <PhysX/core/actor/control/rigidbody/base.hpp>

#include <PhysX/user.hh>

phx::user::user()
{}
void	phx::user::connect(sp::shared_ptr<neb::gfx::window::base> w) {
	printf("%s\n", __PRETTY_FUNCTION__);
	
	assert(control_);
	
	auto control = std::dynamic_pointer_cast<phx::core::actor::control::rigidbody::base>(control_);
	
	assert(w);
	assert(control);
	
	//printf("actor ref count = %i\n", (int)actor.use_count());
	
	
	control->conn_.key_fun_ = w->sig_.key_fun_.connect(std::bind(
				&phx::core::actor::control::rigidbody::base::key_fun,
				control,
				std::placeholders::_1,
				std::placeholders::_2,
				std::placeholders::_3,
				std::placeholders::_4,
				std::placeholders::_5));
	
	//printf("actor ref count = %i\n", (int)actor.use_count());

	//assert(control->conn_.key_fun_);
}
void phx::user::set_control(sp::shared_ptr<phx::core::actor::control::rigidbody::base> control) {
	//NEBULA_DEBUG_0_FUNCTION;

	control_ = control;
}





