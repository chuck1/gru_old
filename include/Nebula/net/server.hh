#ifndef NEBULA_NETWORK_SERVER_HPP
#define NEBULA_NETWORK_SERVER_HPP

#include <Galaxy-Network/server.hpp>

#include <Nebula/net/communicating.hh>

namespace neb {
	namespace Network {
		class Server: public gal::net::server<neb::Network::Communicating> {
			public:
				/** @brief ctor
*
				 * @param io_service boost asio io service
				 */
				Server(
						boost::asio::io_service& io_service,
						ip::tcp::endpoint const & endpoint);
				void			accept(sp::shared_ptr<neb::Network::Communicating>);
				void			write(sp::shared_ptr<gal::net::omessage> omessage);
			private:
				::std::vector< sp::shared_ptr< neb::Network::Communicating > >	clients_;

		};
	}
}

#endif



