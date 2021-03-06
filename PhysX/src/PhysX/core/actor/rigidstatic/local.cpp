#include <Galaxy-Log/log.hpp>

#include <Nebula/debug.hh>
//#include <Nebula/Physics.hh>
#include <Nebula/core/shape/Base.hh>

#include <PhysX/app/base.hpp>
#include <PhysX/util/convert.hpp>
#include <PhysX/core/actor/util/parent.hpp>
#include <PhysX/core/actor/rigidstatic/local.hpp>
#include <PhysX/core/scene/base.hpp>

phx::core::actor::rigidstatic::local::local(sp::shared_ptr<phx::core::actor::util::parent> parent):
	neb::core::actor::base(parent),
	neb::core::actor::actor::base(parent),
	neb::core::actor::rigidactor::base(parent),
	neb::core::actor::local(parent),
	neb::core::actor::actor::local(parent),
	neb::core::actor::rigidactor::local(parent),
	neb::core::actor::rigidstatic::base(parent),
	neb::core::actor::rigidstatic::local(parent),
	phx::core::actor::base(parent),
	phx::core::actor::local(parent),
	phx::core::actor::actor::base(parent),
	phx::core::actor::actor::local(parent),
	phx::core::actor::rigidactor::base(parent),
	phx::core::actor::rigidactor::local(parent),
	phx::core::actor::rigidstatic::base(parent)
{
	BOOST_LOG_CHANNEL_SEV(lg, "phx core actor", debug) << __PRETTY_FUNCTION__;
}
void			phx::core::actor::rigidstatic::local::init() {
	BOOST_LOG_CHANNEL_SEV(lg, "phx core actor", debug) << __PRETTY_FUNCTION__;
	
	neb::core::actor::rigidstatic::local::init();
	phx::core::actor::rigidactor::local::init();
	phx::core::actor::rigidstatic::base::init();
}
void			phx::core::actor::rigidstatic::local::release() {
	BOOST_LOG_CHANNEL_SEV(lg, "phx core actor", debug) << __PRETTY_FUNCTION__;

	neb::core::actor::rigidstatic::local::release();
	phx::core::actor::rigidactor::local::release();
	phx::core::actor::rigidstatic::base::release();

}
void			phx::core::actor::rigidstatic::local::step(neb::core::TimeStep const & ts) {
	BOOST_LOG_CHANNEL_SEV(lg, "phx core actor", debug) << __PRETTY_FUNCTION__;

	neb::core::actor::rigidstatic::local::step(ts);
	phx::core::actor::rigidactor::local::step(ts);
	phx::core::actor::rigidstatic::base::step(ts);

}



