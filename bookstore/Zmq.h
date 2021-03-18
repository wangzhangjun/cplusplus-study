//
// Created by zhjwang on 2021/3/18.
//

#ifndef BOOKSTORE_ZMQ_H
#define BOOKSTORE_ZMQ_H

#include "cpplang.h"
#include "zmq.hpp"

BEGIN_NAMESPACE(cpp_study)
class Zmq {
public:
    using zmq_context_type  = zmq::context_t;
    using zmq_socket_type   = zmq::socket_t;
    using zmq_message_type  = zmq::message_t;
public:
    static zmq_context_type & context();
    static zmq_socket_type recv_sock(int hwm = 1000, int linger = 10);
    static zmq_socket_type send_sock(int hwm = 1000, int linger = 10);
public:
    Zmq() = default;
    ~Zmq() = default;
private:
};
END_NAMESPACE(cpp_study)

#endif //BOOKSTORE_ZMQ_H