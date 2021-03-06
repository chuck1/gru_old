#include <Galaxy-Log/log.hpp>

#include <Nebula/gfx/Viewport.hpp>
#include <Nebula/util/typedef.hpp>

neb::gfx::Viewport::Viewport():
	x_(0),
	y_(0),
	w_(0),
	h_(0),
	aspect_(0)
{}
void		neb::gfx::Viewport::load() {
	glViewport(x_, y_, w_, h_);
}
void		neb::gfx::Viewport::resize(int w, int h) {
	BOOST_LOG_CHANNEL_SEV(lg, "neb gfx", debug) << __PRETTY_FUNCTION__;

	w_ = w;
	h_ = h;
	
	aspect_ = (real)w_ / (real)h_;
}

