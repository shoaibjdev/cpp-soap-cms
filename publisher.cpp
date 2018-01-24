
#include "publisher.h"
#include <activemq/util/Config.h>
#include <decaf/lang/System.h>
#include <decaf/lang/Runnable.h>
#include <decaf/lang/Integer.h>
#include <activemq/core/ActiveMQConnectionFactory.h>
#include <activemq/library/ActiveMQCPP.h>
#include <cms/Connection.h>
#include <cms/Session.h>
#include <cms/Destination.h>
#include <cms/MessageProducer.h>
#include <cms/TextMessage.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include <sstream>

using namespace cms;
using namespace activemq;
using namespace activemq::core;
using namespace decaf;
using namespace decaf::lang;


std::string CMSPublisher::send_to_queue(std::string payload){

    activemq::library::ActiveMQCPP::initializeLibrary();

    std::string user = "admin";
    std::string password = "password";
    std::string host =  "192.168.99.1";
    int port = Integer::parseInt("61616");

    std::string destination = "_event";
    std::string strDestination =  "_reply_event";

    //std::string body = "<payload goes here>";

    std::string correlation_id = "AZCorrelationId";

    {
        ActiveMQConnectionFactory factory;
        factory.setBrokerURI(std::string("tcp://") + host + ":" + Integer::toString(port));

        std::auto_ptr<TextMessage> message;
        std::auto_ptr<Connection> connection(factory.createConnection(user, password));
        std::auto_ptr<Session> session(connection->createSession());
        connection->start();

        std::auto_ptr<Destination> dest(session->createQueue(destination));

        std::auto_ptr<MessageProducer> producer(session->createProducer(dest.get()));
        producer->setDeliveryMode(DeliveryMode::NON_PERSISTENT);

        message.reset(session->createTextMessage(payload));
        message->setCMSCorrelationID(correlation_id);
        producer->send(message.get());


        connection->close();
    }


    activemq::library::ActiveMQCPP::shutdownLibrary();
    return correlation_id;
}

