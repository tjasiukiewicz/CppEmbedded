#pragma once

extern int value;

void foo(void);
void __real_foo(void);
void __wrap_foo(void);
