#include <cstring>
#include <algorithm>

#include <glutpp/gui/object/object.h>

glutpp::gui::object::object::object():
	label_(0)
{
	label_ = new char[16];
	
	memset( (void *)label_, '\0', 16 );
}
void	glutpp::gui::object::object::set_label( char const * cstr )
{
	memcpy( (void *)label_, (const void *)cstr, std::min( strlen( cstr ), strlen( label_ ) ) );
}
