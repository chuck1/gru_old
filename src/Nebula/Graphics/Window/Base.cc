#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

#include <map>

//#include <GL/glew.h>
//#include <GL/glut.h>

#include <Galaxy-Log/log.hpp>

#include <Nebula/Scene/Util/Types.hh>

#include <Nebula/free.hh>
#include <Nebula/Actor/Base.hh>
#include <Nebula/App/Base.hh>
#include <Nebula/Graphics/Context/Base.hh>
#include <Nebula/Graphics/Light/Base.hh>
#include <Nebula/Graphics/Window/Base.hh>
#include <Nebula/Graphics/Window/Util/Parent.hh>


neb::gfx::Window::Base::Base():
	x_(0),
	y_(0),
	w_(600),
	h_(600)
{
}
neb::gfx::Window::Base::Base(sp::shared_ptr<neb::gfx::Window::Util::Parent> parent):
	parent_(parent),
	x_(0),
	y_(0),
	w_(600),
	h_(600)
{
}
neb::gfx::Window::Base::~Base() {
}
void neb::gfx::Window::Base::init() {
	neb::std::shared::init();
	
	BOOST_LOG_CHANNEL_SEV(lg, "neb", debug) << __PRETTY_FUNCTION__;

	auto app = neb::App::Base::global();
	assert(app);

	self_ = sp::dynamic_pointer_cast<neb::gfx::Window::Base>(shared_from_this());
	
	// create window
	window_ = glfwCreateWindow(
			w_,
			h_,
			title_.c_str(),
			NULL,
			NULL);

	if(window_ == NULL) {
		glfwTerminate();
		printf("error\n");
		exit(EXIT_FAILURE);
	}



	glfwMakeContextCurrent(window_);

	glfwSetWindowPosCallback(
			window_,
			neb::App::Base::static_window_pos_fun);
	glfwSetWindowSizeCallback(
			window_,
			neb::App::Base::static_window_size_fun);
	glfwSetWindowCloseCallback(
			window_,
			neb::App::Base::static_window_close_fun);
	glfwSetWindowRefreshCallback(
			window_,
			neb::App::Base::static_window_refresh_fun);
	glfwSetKeyCallback(
			window_,
			neb::App::Base::static_key_fun);
	glfwSetMouseButtonCallback(
			window_,
			neb::App::Base::static_mouse_button_fun);

	// add window to app's window map
	app->windows_glfw_[window_] = self_;
	
	
	//if(all(neb::App::Base::option::SHADERS)) create_programs();
	app->init_glew();
	app->create_programs();

	





	//printf("%s\n",glGetString(GL_SHADING_LANGUAGE_VERSION));

	//Check for necessary extensions
	if(!GL_ARB_depth_texture || !GL_ARB_shadow)
	{
		printf("I require ARB_depth_texture and ARB_shadow extensionsn\n");
		exit(0);//return false;
	}

	//Shading states
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//Depth states

	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);



	checkerror("unknown");
}
void		neb::gfx::Window::Base::release() {
	glfwDestroyWindow(window_);
}
void		neb::gfx::Window::Base::render() {

	glfwMakeContextCurrent(window_);

	/** @todo rendering multiple contexts in a window */

	typedef neb::gfx::Context::Util::Parent C;

	C::map_.for_each<0>([] (C::map_type::iterator<0> it) {
			auto context = sp::dynamic_pointer_cast<neb::gfx::Context::Base>(it->ptr_);
			assert(context);
			context->render();
			});

	glFinish();
	glfwSwapBuffers(window_);
}
void neb::gfx::Window::Base::callback_window_refresh_fun(GLFWwindow*) {
}
void			neb::gfx::Window::Base::step(neb::core::TimeStep const & ts) {
	//GLUTPP_DEBUG_1_FUNCTION;

	if(glfwWindowShouldClose(window_)) {
		parent_->erase(i_);
		return;
	}

	/** @todo wtf is this doing here?? */
	render();
}
void neb::gfx::Window::Base::callback_window_size_fun(GLFWwindow* window, int w, int h) {
	GLUTPP_DEBUG_0_FUNCTION;

	w_ = w;
	h_ = h;

	resize();

	callback_window_refresh_fun(window);
}
void neb::gfx::Window::Base::callback_window_pos_fun(GLFWwindow* window, int x, int y) {
	GLUTPP_DEBUG_0_FUNCTION;

	x_ = x;
	y_ = y;

	callback_window_refresh_fun(window);
}
void neb::gfx::Window::Base::callback_window_close_fun(GLFWwindow* window){
	GLUTPP_DEBUG_0_FUNCTION;

}
void neb::gfx::Window::Base::callback_mouse_button_fun(GLFWwindow* window, int button, int action, int mods) {
	GLUTPP_DEBUG_0_FUNCTION;
	
	sig_.mouse_button_fun_(self_, button, action, mods);
}
void neb::gfx::Window::Base::callback_key_fun(GLFWwindow* window, int key, int scancode, int action, int mods) {
	GLUTPP_DEBUG_0_FUNCTION;
	
	sig_.key_fun_(self_, key, scancode, action, mods);

}
void neb::gfx::Window::Base::resize() {


	glViewport(0, 0, w_, h_);

	typedef neb::gfx::Context::Util::Parent C;

	C::map_.for_each<0>([&] (C::map_type::iterator<0> it) {
			auto context = sp::dynamic_pointer_cast<neb::gfx::Context::Base>(it->ptr_);
			assert(context);
			context->resize(w_, h_);
			});

}




