#include <PhysX/core/actor/util/parent.hpp>
#include <PhysX/core/actor/remote.hpp>

phx::core::actor::remote::remote(sp::shared_ptr<phx::core::actor::util::parent> parent):
	neb::core::actor::base(parent),
	neb::core::actor::remote(parent),
	phx::core::actor::base(parent)
{
}
void				phx::core::actor::remote::release() {
	neb::core::actor::remote::release();
	phx::core::actor::base::release();
}
void				phx::core::actor::remote::init() {
	neb::core::actor::remote::init();
	phx::core::actor::base::init();
}
void				phx::core::actor::remote::step(neb::core::TimeStep const & ts) {
	neb::core::actor::remote::step(ts);
	phx::core::actor::base::step(ts);

}








