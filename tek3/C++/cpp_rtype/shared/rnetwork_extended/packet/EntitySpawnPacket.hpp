#ifndef CPP_RTYPE_ENTITYSPAWNPACKET_HPP
#define CPP_RTYPE_ENTITYSPAWNPACKET_HPP

#include <Position.hpp>
#include "rnetwork/packet/PacketBase.hpp"
#include "utils/Pos.hpp"
#include "shared/rnetwork/config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API EntitySpawnPacket : public rnetwork::packet::PacketBase
        {
        private:

        public:
            static constexpr const std::size_t idOffset = HEADER_SIZE;
            static constexpr const std::size_t typeOffset = idOffset + sizeof(uint32_t);
            static constexpr const std::size_t posXOffset = typeOffset + sizeof(uint16_t);
            static constexpr const std::size_t posYOffset = posXOffset + sizeof(float);
            static constexpr const std::size_t Size = posYOffset + sizeof(float) - HEADER_SIZE;

            EntitySpawnPacket();
            EntitySpawnPacket(const PacketBase& p);
            EntitySpawnPacket(uint32_t id, uint16_t type, rtype::ct::Position const& pos);
            EntitySpawnPacket(const EntitySpawnPacket &entitySpawnPacket) = default;
            virtual ~EntitySpawnPacket() override = default;

            void setId(uint32_t id);
            uint32_t getId() const;

            void setType(uint16_t type);
            uint16_t getType() const;

            void setPos(rtype::ct::Position const& pos);

            rtype::ct::Position getpos() const;

            EntitySpawnPacket &operator=(const EntitySpawnPacket &entitySpawnPacket) = default;
        };
    }
}


#endif //CPP_RTYPE_ENTITYSPAWNPACKET_HPP
