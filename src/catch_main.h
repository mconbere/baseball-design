// The Baseball Design Pattern: No function may return. Functions can only throw
// and catch.
//
// A simple wrapper exported by catch_main.h is provided to allow defining
// catch_main instead of main. catch_main should not be returned from, but
// rather the return value should be thrown.

#ifndef _BASEBALL_DESIGN_SRC_CATCH_MAIN_H_
#define _BASEBALL_DESIGN_SRC_CATCH_MAIN_H_

void catch_main(int argc, char** argv); // throw(int)

#endif // _BASEBALL_DESIGN_SRC_CATCH_MAIN_H_
