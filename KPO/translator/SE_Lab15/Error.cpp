#include "stdafx.h"
#include "Error.h"
namespace Error {
    // Error series: 0 - 99 - system errors
    //              100 - 109 - parameter errors
    //              110 - 119 - file open and read errors

    ERROR errors[ERROR_MAX_ENTRY] =
    {
        ERROR_ENTRY(0, "Invalid error code"),
        ERROR_ENTRY(1, "System failure"),
        ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
        ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
        ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
        ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
        ERROR_ENTRY(100, "Parameter -in must be specified"),
        ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
        ERROR_ENTRY(104, "Input parameter length exceeded"),
        ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
        ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
        ERROR_ENTRY(110, "Error opening source code file (-in)"),
        ERROR_ENTRY(111, "Invalid character in the source file (-in)"),
        ERROR_ENTRY(112, "Error creating log file (-log)"),
        ERROR_ENTRY_NODEF(113), ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115),
        ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
        ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
        ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
        ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
        ERROR_ENTRY_NODEF100(600), ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
    };
    // Used in the ERROR_THROW macro
    ERROR geterror(int id)
    {
        if (id > 0 && id < ERROR_MAX_ENTRY)
            return errors[id];
        else
            return errors[0];
    }

    // Used in the ERROR_THROW_IN macro
    ERROR geterrorin(int id, int line = -1, int col = -1)
    {
        if (id > 0 && id < ERROR_MAX_ENTRY) {
            // Forming the ERROR structure
            errors[id].inext.col = col; // line number
            errors[id].inext.line = line; // position in the line
            return errors[id];
        }
        else {
            return errors[0];
        }
    }
}
