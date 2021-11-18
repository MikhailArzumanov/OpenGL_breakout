#include "net.hpp"

const point net_size{ 70,23 };
const Color net_color{ 177,103,12 };


Net::Net(point c_):Rectangle(c_,net_size,net_color){
}