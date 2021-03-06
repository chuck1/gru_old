
#include <Galaxy-Standard/registry.hpp>

#include <Nebula/core/actor/Base.hh>

#include <Nebula/message/Actor/Event/Base.hh>
#include <Nebula/core/scene/Base.hh>


#include <PhysX/core/actor/actor/base.hpp>
#include <PhysX/message/actor/event/Base.hh>

/*
void		neb::message::actor::Event::serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) {
	ar & event_;
}*/
void		phx::message::actor::event::IFire::serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version) {
	neb::message::actor::IBase::serialize(ar, version);
	
	auto actor = sp::dynamic_pointer_cast<phx::core::actor::actor::base>(gal::std::shared::registry_.get(index_));
	assert(actor);
	
	//auto scene = actor->getScene();
	//assert(scene);
	
	/** @todo this event should be a weapon::event, not an actor::event */

	//scene->fire(actor);
	//actor->fire();
}
void		phx::message::actor::event::OFire::serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) {

	neb::message::actor::OBase::serialize(ar, version);
	
	//auto actor = sp::dynamic_pointer_cast<phx::core::actor::actor::base>(gal::std::shared::registry_.get(index_));
	//assert(actor);
	
	//auto scene = actor->getScene();
	//assert(scene);
	
	/** @todo this event should be a weapon::event, not an actor::event */

	//scene->fire(actor);
	//actor->fire();
}






