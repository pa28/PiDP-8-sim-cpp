//
// Created by richard on 2018-08-26.
//

#pragma once

/**
 * PiDP8 LED Control
 *
 * Each member of the data array controls up to 12 lights
 *  Program Counter     0
 *  Memory Address      1
 *  Memory Buffer       2
 *  Accumulator         3
 *  Multiplier Quotient 4
 *  AND                 5:11
 *  TAD                 5:10
 *  DCA                 5: 9
 *  ISZ                 5: 8
 *  JMS                 5: 7
 *  JMP                 5: 6
 *  IOT                 5: 5
 *  OPR                 5: 4
 *  Fetch               5: 3
 *  Execute             5: 2
 *  Defer               5: 1
 *  Word Count          5: 0
 *  Current Address     6:11
 *  Break               6:10
 *  ION                 6: 9
 *  Pause               6: 8
 *  Run                 6: 7
 *  Step Counter        6: 2-6
 *  Idle Detection      6: 1
 *
 *  Data Field          7: 1-3
 *  Inst Field          7: 4-6
 *  Link                7: 5
 */

/**
 * PiDP8 Switch status
 *  Switch Register    0:0-11
 *  Data Field         1:9-11
 *  Inst field         1:6-8
 *  Command Switches   2:6-11
 *  Start              2:11
 *  Load Addr          2:10
 *  Deposit            2: 9
 *  Examine            2: 8
 *  Continue           2: 7
 *  Stop               2: 6
 *  Single Step        2: 5
 *  Single Instruction 2: 4
 */

