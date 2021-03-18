//
// Created by zhjwang on 2021/3/18.
//

#include "Zmq.h"

template<int thread_num> 1 // 使用整数模板参数来指定线程数

static zmq_socket_type cpp_study::Zmq::recv_sock(int hwm, int linger) {  //接收
    zmq_socket_type sock(context(), ZMQ_PULL);
    sock.setsockopt(ZMQ_RCVHWM, hwm);
    sock.setsockopt(ZMQ_LINGER, linger);    // wait for 10ms

    return sock;
}

static zmq_socket_type cpp_study::Zmq::send_sock(int hwm, int linger) {
    zmq_socket_type sock(context(), ZMQ_PUSH);
    sock.setsockopt(ZMQ_SNDHWM, hwm);
    sock.setsockopt(ZMQ_LINGER, linger);    // wait for 10ms

    return sock;
}

static zmq_socket_type & cpp_study::Zmq::context() {
    static zmq_context_type ctx(thread_num);
    return ctx;
}