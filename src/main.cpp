#include <iostream>
#include <thread>
#include "chassis.h"
#include "DK8EA.h"

using namespace std;
using namespace pdp8;

int main() {
    auto cpu_chassis = chassis::make_chassis();

/*
    cpu_chassis->cpu->core[000] = 01010;
    cpu_chassis->cpu->core[001] = 03011;
    cpu_chassis->cpu->core[002] = 02005;
    cpu_chassis->cpu->core[003] = 05000;
    cpu_chassis->cpu->core[005] = 00001;
    cpu_chassis->cpu->core[010] = 01234;

    cpu_chassis->cpu->pause_flag = false;

    if (cpu_chassis->cpu->joinable())
        cpu_chassis->cpu->join();
*/

/*
    cpu_chassis->cpu->core[000] = 01010;
    cpu_chassis->cpu->core[001] = 03011;
    cpu_chassis->cpu->core[002] = 02015;
    cpu_chassis->cpu->core[003] = 05000;
    cpu_chassis->cpu->core[004] = 02016;
    cpu_chassis->cpu->core[005] = 05000;
    cpu_chassis->cpu->core[006] = 07402;
    cpu_chassis->cpu->core[015] = 00000;
    cpu_chassis->cpu->core[016] = 07777;
    cpu_chassis->cpu->core[010] = 01234;

    cpu_chassis->cpu->pc_boundary = 007;
*/

    cpu_chassis->cpu->core[000] = 06056;
    cpu_chassis->cpu->core[001] = 06053;
    cpu_chassis->cpu->core[002] = 05001;
    cpu_chassis->cpu->core[003] = 07402;

    cpu_chassis->cpu->pc_boundary = 004;

    cpu_chassis->add_device<DK8EA>(INT_V_CLK);
    cpu_chassis->initialize();
    cpu_chassis->start_threads();
    cpu_chassis->reset();
    cpu_chassis->start();

//    std::this_thread::sleep_for(30s);

    cpu_chassis->cpu->cpuThread->sim_time.start_total();
    for (size_t n = 0; n < 50; n++) {
        std::this_thread::sleep_for(20000us);
    }

    cpu_chassis->stop();

    if (cpu_chassis->cpu->cpuThread) {
        auto[sim_time, real_time, sleep_time] = cpu_chassis->cpu->cpuThread->sim_time.check_total();
        cout << dec << sim_time.count() << ", "
             << real_time.count() << ", "
             << sleep_time.count() << endl;
    }

    cpu_chassis->stop_threads();

//    cout << cpu_chassis->cpu->acl << endl;
//    cout << cpu_chassis->cpu->core(015) << endl;
//    cout << cpu_chassis->cpu->core(016) << endl;

    return 0;
}