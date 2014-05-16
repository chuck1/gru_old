#include <tinyxml2.h>

#include <string>
#include <algorithm>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Nebula/Types.hpp>
#include <Nebula/Graphics/window/window.hpp>
#include <Nebula/renderable.hpp>
#include <Nebula/Graphics/gui/object/object_factory.hpp>
#include <Nebula/Graphics/gui/object/object.hpp>
#include <Nebula/Graphics/gui/object/edittext.hpp>

#include <Nebula/Graphics/gui/layout.hpp>




Neb::gui::layout::layout()
{

}
void Neb::gui::layout::init(Neb::renderable_w renderable)
{
	//jess::clog << NEB_FUNCSIG << std::endl;
	assert(renderable);
	renderable_ = renderable;
}
Neb::window::window_w Neb::gui::layout::get_window() {
	auto s = renderable_.lock();
	return s->getWindow();
}
/*
void Neb::gui::layout::load_xml(tinyxml2::XMLElement* element)
{
	assert(element);
	tinyxml2::XMLElement* e = element->FirstChildElement("object");
	while(e != NULL){
		create_object(e);
		e = e->NextSiblingElement("object");
	}
}*/
/*
void Neb::gui::layout::create_object(tinyxml2::XMLElement* element) {

	assert(element);

	auto object = Neb::master::Global()->object_factory_->create(element);

	objects_.push_back(object);
}*/
void Neb::gui::layout::render(double time) {
	//auto p = Neb::master::Global()->use_program(Neb::program_name::e::TEXT);

	//Restore other states
	//glDisable(GL_LIGHTING);
	//glDisable(GL_ALPHA_TEST);

	//Set matrices for ortho
	//glMatrixMode(GL_PROJECTION);
	//glLoadMatrixf(ortho_);
	//gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	draw();
}
void Neb::gui::layout::draw() {
	//jess::clog << NEB_FUNCSIG << std::endl;
	//jess::clog << "objects_.size()=" << objects_.map_.size() << std::endl;

	for(auto it = objects_.map_.begin(); it != objects_.map_.end(); ++it) {
		it->second->draw();
	}
}
void Neb::gui::layout::connect() {
	printf("%s\n", __PRETTY_FUNCTION__);

	Neb::window::window_s w = get_window().lock();
	
	assert(w);

	conns_.key_fun_ = w->sig_.key_fun_.connect(
			std::bind(&Neb::gui::layout::key_fun,
				this,
				std::placeholders::_1,
				std::placeholders::_2,
				std::placeholders::_3,
				std::placeholders::_4
				));

	conns_.mouse_button_fun_ = w->sig_.mouse_button_fun_.connect(
			std::bind(&Neb::gui::layout::mouse_button_fun,
				this,
				std::placeholders::_1,
				std::placeholders::_2,
				std::placeholders::_3
				));

}
int Neb::gui::layout::key_fun(int key, int scancode, int action, int mode) {
	return 0;
}
int Neb::gui::layout::mouse_button_fun(int button, int action, int mods) {
	printf("%s\n", __PRETTY_FUNCTION__);

	switch(action)
	{
		case GLFW_PRESS:
			switch(button)
			{
				case GLFW_MOUSE_BUTTON_LEFT:
					search(button, action, mods);
					break;
			}
			break;
		default:
			return 0;
	}
	
	return 0;
}
int Neb::gui::layout::search(int button, int action, int mods) {
	printf("%s\n", __PRETTY_FUNCTION__);

	auto s_window = get_window().lock();
	assert(s_window);

	double x, y;
	int w, h;
	glfwGetCursorPos(s_window->window_, &x, &y);
	glfwGetWindowSize(s_window->window_, &w, &h);

	printf("%f %f %i %i\n", x, y, w, h);

	x = x / (float)w * 2.0 - 1.0;
	y = y / (float)h * 2.0 - 1.0;

	printf("%f %f\n", x, y);

	for(auto it = objects_.map_.begin(); it != objects_.map_.end(); ++it) {

		//auto o = (*it).second;
		
		printf("object %f %f %f %f\n",
				it->second->data_.x_,
				it->second->data_.y_,
				it->second->data_.w_,
				it->second->data_.h_);	
		
		if(x <   it->second->data_.x_) continue;
		if(x > ( it->second->data_.x_ + it->second->data_.w_)) continue;
		if(y >  -it->second->data_.y_) continue;
		if(y < (-it->second->data_.y_ - it->second->data_.h_)) continue;

		return it->second->mouse_button_fun(button, action, mods);
	}

	return 0;
}






