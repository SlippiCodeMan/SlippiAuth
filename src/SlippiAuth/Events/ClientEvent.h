#pragma once

#include "Event.h"

namespace SlippiAuth {

    class ClientSpawnEvent : public Event
    {
    public:
        explicit ClientSpawnEvent(uint32_t clientId, std::string connectCode, std::string targetConnectCode)
            : m_ClientId(clientId),
            m_ConnectCode(std::move(connectCode)),
            m_TargetConnectCode(std::move(targetConnectCode)) {};

        [[nodiscard]] inline uint32_t GetClientId() const
        {
            return m_ClientId;
        }

        inline const std::string& GetConnectCode()
        {
            return m_ConnectCode;
        }

        inline const std::string& GetTargetConnectCode()
        {
            return m_TargetConnectCode;
        }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "ClientSpawn: " << "(" << m_ClientId << ", " << m_ConnectCode
               << ", " << m_TargetConnectCode << ")";
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategoryClient);
        EVENT_CLASS_TYPE(ClientSpawn);

    private:
        uint32_t m_ClientId;
        std::string m_ConnectCode;
        std::string m_TargetConnectCode;
    };

    class AuthenticatedEvent : public Event
    {
    public:
        explicit AuthenticatedEvent(uint32_t clientId, std::string targetConnectCode)
            : m_ClientId(clientId),
              m_TargetConnectCode(std::move(targetConnectCode)) {};

        [[nodiscard]] inline uint32_t GetClientId() const
        {
            return m_ClientId;
        }

        inline const std::string& GetTargetConnectCode()
        {
            return m_TargetConnectCode;
        }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "AuthenticatedEvent: " << "(" << m_ClientId
               << ", " << m_TargetConnectCode << ")";
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategoryClient);
        EVENT_CLASS_TYPE(Authenticated);

    private:
        uint32_t m_ClientId;
        std::string m_TargetConnectCode;
    };

}

